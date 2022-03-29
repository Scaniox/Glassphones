#include <Arduino.h>

#define MFB_PIN 20

void setup();

void loop();

void serialEvent();

void send_command(char opcode, char *data, int data_len);

bool read_event(char *opcode, char *data, int *buffer_len);

void event_check();

void pair();

void discover();

void connect_previous();

void disconnect();

void pause();

void play();

void play_pause();

void powerup();