#include <main.h>

char prompt_buffer[30] = "";

void setup() {
  pinMode(MFB_PIN, OUTPUT);
  digitalWrite(MFB_PIN, LOW);

  Serial1.begin(115200); // bm83 serial
  Serial.begin(115200); // debug serial

  while (!Serial)
  {
    delay(1);
  }
  delay(500);
  Serial.println("PC connection established");
}

void loop() {
  if(Serial.available() > 0){
    serialEvent();
  }
}

void serialEvent(){
  String c = Serial.readStringUntil('\n');
  
  if(c.equals("pair")){
    Serial.println("\nattempt to pair");
    pair();
  }
  else if (c.equals("e")){
    Serial.println("\nevent check:");
    event_check();
  } 
  else if (c.equals("connect")){
    Serial.println("\nattempt to connect");
    connect_previous();
  } 
  else if (c.equals("discover")){
    Serial.println("\nattempt to discover");
    discover();
  }

  else if (c.equals("disconnect")){
    Serial.println("\nattempt to disconnect");
    disconnect();
  }

  else if (c.equals("play")){
    Serial.println("\nattempt to play");
    play();
  }

  else if (c.equals("pause")){
    Serial.println("\nattempt to pause");
    pause();
  }

  else if (c.equals("play pause")){
    Serial.println("\nattempt to play pause");
    play_pause();
  }

}

void event_check(){
  char opcode;
  char data[10];
  int data_len = 10;
  while(read_event(&opcode, data, &data_len)){
    Serial.printf("event opcode: %X data:", opcode);

    for(int i=0; i<data_len; i++){
      Serial.printf(" 0x%X", data[i]);
    }
    Serial.println();
  }
  Serial.println("event queue exhausted");
}

void pair(){
  char params[] = {0x00, 0x5D};
  send_command(0x02, params, 2);
}

void discover(){
  char params[] = {0x00, 10, 2, 0x00, 0x00, 0x80};
  send_command(0x44, params, 6);
}

void connect_previous(){
  char params[] = {0x02};
  send_command(0x17, params, 1);
}

void disconnect(){
  char params[] = {0xFF};
  send_command(0x18, params, 1);
}

void pause(){
  char params[] = {0x00, 0x06};
  send_command(0x04, params, 2);
}

void play(){
  char params[] = {0x00, 0x05};
  send_command(0x04, params, 2);
}

void play_pause(){
  char params[] = {0x00, 0x07};
  send_command(0x04, params, 2);
}


void send_command(char opcode, char *data, int data_len){
  uint16_t length = data_len + 1;

  //compute crc
  uint8_t crc = (length >> 8) + length + opcode; // length (upper) + length(lower) + opcode + data
  for(int i = 0; i < data_len; i++){
    crc += data[i];
  }
  crc = 0x100 - crc; 


  // send data
  Serial1.write(0xAA);
  Serial1.write(length >> 8);
  Serial1.write(length);
  Serial1.write(opcode);
  Serial1.write(data, data_len);
  Serial1.write(crc);

  // clear MFB
  delay(1);
  digitalWrite(MFB_PIN, LOW);
}

bool read_event(char *opcode, char data[], int *buffer_len){
  char ack = 0x00;
  while (ack != 0xAA){
    if(Serial1.available() == 0){
      return false;
    }

    ack = Serial1.read();
  }
  while (Serial1.available() < 2);
  uint16_t len_h = Serial1.read();
  uint16_t len_l = Serial1.read();

  uint16_t length = len_l + (len_h << 8);
  if(length - 1 < *buffer_len){
    //Serial.println("spare space in event read buffer");
    *buffer_len = length - 1;
  }

  while (Serial1.available() < *buffer_len + 1);
  *opcode = Serial1.read();
  
  for(int data_index = 0; data_index < *buffer_len; data_index++ ){
    data[data_index] = Serial1.read();
  }

  uint8_t read_crc = Serial1.read();
  uint8_t crc_calc = (*buffer_len >> 8) + *buffer_len + *opcode; // length (upper) + length(lower) + opcode + data
  for(int i = 0; i < *buffer_len; i++){
    crc_calc += data[i];
  }
  crc_calc = ~crc_calc; 
  if(crc_calc != read_crc){
    Serial.printf("crc error: got: %X, calc: %X,  \n", read_crc, crc_calc);
  }

  // send event ack command
  //send_command(0x14, opcode, 1);

  return true;
}
