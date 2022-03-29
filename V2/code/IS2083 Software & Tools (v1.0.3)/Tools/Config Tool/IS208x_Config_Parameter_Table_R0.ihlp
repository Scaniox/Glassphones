335
Name
Help;;help_end;;
ID
Power Switch Type
Display with picture.;;help_end;;
IDC_STATIC_POWER_SWITCH_SETTING1
UART Command
(in Mainfeature Window)
Enable HCI UART
Enable/Disable Application to use HCI UART.;;help_end;;
IDC_STATIC_UART_SETTING1
UART Baudrate
The UART Baudrate is the baud rate index of the HCI UART. (Unit: BPS);;help_end;;
IDC_STATIC_UART_SETTING2
CPU Idle Mode
Disable/Enable BT CPU idle function.;;help_end;;
IDC_STATIC_UART_SETTING5
Wake Up Delay Time
Waiting time to start BT UART TX after wakeup MCU;;help_end;;
IDC_STATIC_UART_SETTING4
Disable Wait for ACK
If this option is enabled, it will not wait the ACK of UART event from MCU after reporting transparent data (UART event ID 0x22) to MCU. It is usually used in throughput sensitive case and MCU has capability to process burst data.;;help_end;;
IDC_STATIC_UART_SETTING9
OTA DFU Key
The encryption key for OTA DFU.;;help_end;;
IDC_STATIC_OTA_DFU_SETTING1
OTA DFU service
Enable/disable OTA DFU service.;;help_end;;
IDC_STATIC_OTA_DFU_SETTING2
Name Fragment
Name Fragment is your bluetooth product name that will be shown on a remote device,ex:a phone;;help_end;;
IDC_STATIC_NAME1
Simple Pairing
Enable: Use simple pairing method when pairing.
Disable: A PIN Code will be required when pairing.;;help_end;;
IDC_STATIC_MISC_OPTION7
PIN Code
The PIN code which is four-byte ASCII code is a fixed PIN code of a local device.
The local device replies the remote devices using the PIN code when remote devices send a PIN code request command.;;help_end;;
IDC_STATIC_PIN_CODE
Enable Pairing as Standby Mode
Open Inquiry scan window in when the speaker is in standby mode. 
That is, if this option is enabled the speaker is discoverable in not only pairing mode but also standby mode. ;;help_end;;
IDC_STATIC_MISC_OPTION4
Enter Pairing Mode When Power On
If the speaker doesn't try to create CSB link when power on or doesn't need to reconnect to remove device when power on, then it will enter pairing mode when power on.;;help_end;;
IDC_STATIC_MISC_OPTION5
Suspend Stream When SCO Established
This setting use for multi link status.
If system build multi link with A and B mobile phone and have a A2DP stream with A, when phone B have a incoming call, system send "Suspend" command to phone A before establish SCO link with phone B.;;help_end;;
IDC_STATIC_MISC_OPTION9
Class of Device
The Class is the class of device/service field (CoD). It is indicated using the 'Format Type field' within the CoD.
The value could be 0x040424(HS) or 0x001F00(Uncategorized);;help_end;;
IDC_STATIC_MISC_OPTION11
Report Battery Status to Smart Phone
Report speaker/hs battery status via AT command base on HFP  to mobile phone.;;help_end;;
IDC_STATIC_MISC_OPTION14
Link Application
Single-link: Only one HF link exists.
Multi-link: Two HF links exist.;;help_end;;
IDC_STATIC_MISC_OPTION8
Always Answer Incoming Call
If this option is enabled and HFP connection exists, it will always answer incoming calls automatically.;;help_end;;
IDC_STATIC_MISC_OPTION18
Auto Answer Incoming Call When Link Back
When the speaker links back HF link and call status is incoming call, then it will answer the call automatically if this option is enabled.;;help_end;;
IDC_STATIC_MISC_OPTION24
Hang Up a Call When Switch Off
Hang up all calls when the speaker is turned off by slide switch.;;help_end;;
IDC_STATIC_MISC_OPTION20
Shut Down Power in Off State
Cut off the power when the speaker enter off state.;;help_end;;
IDC_STATIC_MISC_OPTION21
Enter Pairing when Power On Link Back Failed
Enable this option to enter pairing automatically if it fails to reconnect to phone when power on.;;help_end;;
IDC_STATIC_MISC_OPTION23
Only Accept Paired Device
If this option is enabled, the speaker only accepts the connect request from paired devices when it is not in pairing mode.;;help_end;;
IDC_STATIC_MISC_OPTION25
Disconnect All In Pairing
Enable/Disable disconnect all link when SPK in pairing state.;;help_end;;
IDC_STATIC_MISC_OPTION26
Keep BLE In Power Off
Enable/Disable keep BLE connection when SPK in power off state.;;help_end;;
IDC_STATIC_MISC_OPTION27
Wide Band Speech Enable (mSBC)
;;help_end;;
IDC_STATIC_MISC_OPTION29
AVRCP Version Option
Select to use AVRCP v1.6 or AVRCP v1.3.;;help_end;;
IDC_STATIC_MISC_OPTION31
Auto Unsniff in Data Transmission
After system enter sniff mode, it would not auto exit sniff mode if received packets or send packets. ;;help_end;;
IDC_STATIC_MISC_OPTION32
Factory Default Timer
If system in off mode and power button been pressed over this time, 
system will clear some EEPROM parameter to default value.
(It call "MASTER RESET", too. This timer must bigger than Enter Pairing Press Duration);;help_end;;
IDC_STATIC_FACTORY_DEFAULT_SETTING2
Power On Link Back Setting
Enable link back feature when power on.;;help_end;;
IDC_STATIC_CONNECTION_SETTING8
Enable Save Max.Number of Paired Devices
The max number of paired device that the speaker stores in EEPROM.
FW basically support 8 device records, and use this parameter for application to set really max paired records.;;help_end;;
IDC_STATIC_CONNECTION_SETTING3
Search Paired Devices Pattern Setting
If select All Devices,then Search all devices in paired device list and link back to one of all devices.
If select Last Device Only,then only find the last disconnected device in Paired list and link it back.;;help_end;;
IDC_STATIC_CONNECTION_SETTING10
Power On Link Back Profile(s) Setting
Select link back profils when power on.;;help_end;;
IDC_STATIC_CONNECTION_SETTING6
Link Loss Reconnect Timeout
When HF link loss, it will try to link back until page fail times reached this value;;help_end;;
IDC_STATIC_CONNECTION_SETTING2
Link HF Timeout
The timeout to reconnecting to link loss device.
0x00 : don't reconnect
0xFF : recover without timeout
other : (unit in 5 second);;help_end;;
IDC_STATIC_CONNECTION_SETTING7
Link A2DP Timeout
A2DP device page fail retry duration;;help_end;;
IDC_STATIC_CONNECTION_SETTING4
Pairing Timeout
System will close pairing mode when time out(unit in 30 second), 0 means no timeout.;;help_end;;
IDC_STATIC_CONNECTION_SETTING1
Power On
This is the time interval to turn on the power after pressing power button;;help_end;;
IDC_STATIC_BUTTON_PRSEE_TIME1
Power Off
This is the time interval to turn off the power after pressing power button;;help_end;;
IDC_STATIC_BUTTON_PRSEE_TIME2
Enter Pairing
The parameter is the time to enter the paring mode from the power on state.
The total time  from power off state to enter pairing mode = "Enter Pairing" time + "Power On" time";;help_end;;
IDC_STATIC_BUTTON_PRSEE_TIME3
No Service Warning Time
When mobile phone can not receive the signal from base station, headset alert user periodically with this interval(unit in 640 ms). 
This function is through HFP.;;help_end;;
IDC_STATIC_WARRING_TIME1
Low Battery Warning Time
When the voltage battery is lower than Warning_Battery_Level (the voltage setting for low battery), the speaker alerts users periodically with this interval(unit in 640 ms).;;help_end;;
IDC_STATIC_WARRING_TIME2
Mute Alarm Time
If the speaker has calls and its microphone is muted , it will ring the mute tone to alert user periodically with this interval(unit in 640 ms).;;help_end;;
IDC_STATIC_WARRING_TIME3
Auto Power Off Time
Set the Auto Power Off timer.The minimum is 1;;help_end;;
IDC_STATIC_POWER_SAVE1
Auto Power Off Enable
When system enter standby state, then set 'Auto Power Off Time' to shut down power.;;help_end;;
IDC_CHECK_AUTO_POWER_OFF_MASK1
Pairing Timeout Shut Down Directly Enable
When system pairing timeout, then shut down system directly if enable this option.;;help_end;;
IDC_CHECK_AUTO_POWER_OFF_MASK2
A2DP Link Silence
If Enable this one, then system will be shut down automatically, when A2DP/AVRCP is only one link?'Auto Power Off Timer' has been timeout?no key is pressed?no adapter plug in 
and BT device doesn't receive any audio packet from AG any more.;;help_end;;
IDC_CHECK_AUTO_POWER_OFF_MASK3
Max Sniff Interval
;;help_end;;
IDC_STATIC_POWER_SAVE4
Min Sniff Interval
;;help_end;;
IDC_STATIC_POWER_SAVE5
Inquiry TX Power Level
The inquiry TX power level is selectable from 0 to 6.
For level 6, the default TX power is around 10dBm. While decrease the level number, the TX power will degrade around 5 dB for one step. ;;help_end;;
IDC_STATIC_RF_TX_POWER_SETTING1
BT Connected TX Power Level
The BT connected TX power level is selectable from 0 to 6.
For level 6, the default TX power is around 10dBm. While decrease the level number, the TX power will degrade around 5 dB for one step.;;help_end;;
IDC_STATIC_RF_TX_POWER_SETTING2
LED1 Brightness
The brightness setting of LED1;;help_end;;
IDC_STATIC_LED_BRIGHTNESS_SETTING1
LED2 Brightness
The brightness setting of LED2;;help_end;;
IDC_STATIC_LED_BRIGHTNESS_SETTING2
Type
Select one LED display type for specific function;;help_end;;
IDC_STATIC_LED_TYPE
On Duration
This the LED turn on duration for flash;;help_end;;
IDC_STATIC_LED_ON_TIME
Off Duration
This the LED turn off duration for flash;;help_end;;
IDC_STATIC_LED_OFF_TIME
Count
This is the number of the flash times for a round;;help_end;;
IDC_STATIC_LED_COUNT
Type
Select one LED display type for specific function;;help_end;;
IDC_STATIC_LED_TYPE
On Duration
This the LED turn on duration for flash;;help_end;;
IDC_STATIC_LED_ON_TIME
Off Duration
This the LED turn off duration for flash;;help_end;;
IDC_STATIC_LED_OFF_TIME
Count
This is the number of the flash times for a round;;help_end;;
IDC_STATIC_LED_COUNT
Type
Select one LED display type for specific function;;help_end;;
IDC_STATIC_LED_TYPE
On Duration
This the LED turn on duration for flash;;help_end;;
IDC_STATIC_LED_ON_TIME
Off Duration
This the LED turn off duration for flash;;help_end;;
IDC_STATIC_LED_OFF_TIME
Count
This is the number of the flash times for a round;;help_end;;
IDC_STATIC_LED_COUNT
Interval
This is the time interval for a round;;help_end;;
IDC_STATIC_LED_INTERVAL
Type
Select one LED display type for specific function;;help_end;;
IDC_STATIC_LED_TYPE
On Duration
This the LED turn on duration for flash;;help_end;;
IDC_STATIC_LED_ON_TIME
Off Duration
This the LED turn off duration for flash;;help_end;;
IDC_STATIC_LED_OFF_TIME
Count
This is the number of the flash times for a round;;help_end;;
IDC_STATIC_LED_COUNT
Type
Select one LED display type for specific function;;help_end;;
IDC_STATIC_LED_TYPE
On Duration
This the LED turn on duration for flash;;help_end;;
IDC_STATIC_LED_ON_TIME
Off Duration
This the LED turn off duration for flash;;help_end;;
IDC_STATIC_LED_OFF_TIME
Count
This is the number of the flash times for a round;;help_end;;
IDC_STATIC_LED_COUNT
Interval
This is the time interval for a round;;help_end;;
IDC_STATIC_LED_INTERVAL
Type
Select one LED display type for specific function;;help_end;;
IDC_STATIC_LED_TYPE
On Duration
This the LED turn on duration for flash;;help_end;;
IDC_STATIC_LED_ON_TIME
Off Duration
This the LED turn off duration for flash;;help_end;;
IDC_STATIC_LED_OFF_TIME
Count
This is the number of the flash times for a round;;help_end;;
IDC_STATIC_LED_COUNT
Interval
This is the time interval for a round;;help_end;;
IDC_STATIC_LED_INTERVAL
Type
Select one LED display type for specific function;;help_end;;
IDC_STATIC_LED_TYPE
On Duration
This the LED turn on duration for flash;;help_end;;
IDC_STATIC_LED_ON_TIME
Off Duration
This the LED turn off duration for flash;;help_end;;
IDC_STATIC_LED_OFF_TIME
Count
This is the number of the flash times for a round;;help_end;;
IDC_STATIC_LED_COUNT
Interval
This is the time interval for a round;;help_end;;
IDC_STATIC_LED_INTERVAL
Type
Select one LED display type for specific function;;help_end;;
IDC_STATIC_LED_TYPE
On Duration
This the LED turn on duration for flash;;help_end;;
IDC_STATIC_LED_ON_TIME
Off Duration
This the LED turn off duration for flash;;help_end;;
IDC_STATIC_LED_OFF_TIME
Count
This is the number of the flash times for a round;;help_end;;
IDC_STATIC_LED_COUNT
Interval
This is the time interval for a round;;help_end;;
IDC_STATIC_LED_INTERVAL
Type
Select one LED display type for specific function;;help_end;;
IDC_STATIC_LED_TYPE
On Duration
This the LED turn on duration for flash;;help_end;;
IDC_STATIC_LED_ON_TIME
Off Duration
This the LED turn off duration for flash;;help_end;;
IDC_STATIC_LED_OFF_TIME
Count
This is the number of the flash times for a round;;help_end;;
IDC_STATIC_LED_COUNT
Interval
This is the time interval for a round;;help_end;;
IDC_STATIC_LED_INTERVAL
Type
Select one LED display type for specific function;;help_end;;
IDC_STATIC_LED_TYPE
On Duration
This the LED turn on duration for flash;;help_end;;
IDC_STATIC_LED_ON_TIME
Off Duration
This the LED turn off duration for flash;;help_end;;
IDC_STATIC_LED_OFF_TIME
Count
This is the number of the flash times for a round;;help_end;;
IDC_STATIC_LED_COUNT
Type
Select one LED display type for specific function;;help_end;;
IDC_STATIC_LED_TYPE
On Duration
This the LED turn on duration for flash;;help_end;;
IDC_STATIC_LED_ON_TIME
Off Duration
This the LED turn off duration for flash;;help_end;;
IDC_STATIC_LED_OFF_TIME
Count
This is the number of the flash times for a round;;help_end;;
IDC_STATIC_LED_COUNT
Interval
This is the time interval for a round;;help_end;;
IDC_STATIC_LED_INTERVAL
Type
Select one LED display type for specific function;;help_end;;
IDC_STATIC_LED_TYPE
On Duration
This the LED turn on duration for flash;;help_end;;
IDC_STATIC_LED_ON_TIME
Off Duration
This the LED turn off duration for flash;;help_end;;
IDC_STATIC_LED_OFF_TIME
Count
This is the number of the flash times for a round;;help_end;;
IDC_STATIC_LED_COUNT
Interval
This is the time interval for a round;;help_end;;
IDC_STATIC_LED_INTERVAL
Type
Select one LED display type for specific function;;help_end;;
IDC_STATIC_LED_TYPE
On Duration
This the LED turn on duration for flash;;help_end;;
IDC_STATIC_LED_ON_TIME
Off Duration
This the LED turn off duration for flash;;help_end;;
IDC_STATIC_LED_OFF_TIME
Count
This is the number of the flash times for a round;;help_end;;
IDC_STATIC_LED_COUNT
Interval
This is the time interval for a round;;help_end;;
IDC_STATIC_LED_INTERVAL
Type
Select one LED display type for specific function;;help_end;;
IDC_STATIC_LED_TYPE
On Duration
This the LED turn on duration for flash;;help_end;;
IDC_STATIC_LED_ON_TIME
Off Duration
This the LED turn off duration for flash;;help_end;;
IDC_STATIC_LED_OFF_TIME
Count
This is the number of the flash times for a round;;help_end;;
IDC_STATIC_LED_COUNT
Interval
This is the time interval for a round;;help_end;;
IDC_STATIC_LED_INTERVAL
Type
Select one LED display type for specific function;;help_end;;
IDC_STATIC_LED_TYPE
On Duration
This the LED turn on duration for flash;;help_end;;
IDC_STATIC_LED_ON_TIME
Off Duration
This the LED turn off duration for flash;;help_end;;
IDC_STATIC_LED_OFF_TIME
Count
This is the number of the flash times for a round;;help_end;;
IDC_STATIC_LED_COUNT
Charging  Led Indication Setting
Don't indicate the charging status in LED1 and LED2 if this option is enabled.;;help_end;;
IDC_STATIC_CHARGING_LED_SETTING1
Charging Complete Led Indication Setting
0x00:Normal, No extra action to indicate.
0x01:LED1 flash one time then return to normal.
0x02:LED1 always On.
0x03:LED1 always Off;;help_end;;
IDC_STATIC_CHARGING_LED_SETTING2
Charging Error Led Indication Setting
0x00 Same as charge Complete, The LED behavior is the same as charging complete.
0x01 LED2 keeping flash and LED1 always off;;help_end;;
IDC_STATIC_CHARGING_LED_SETTING3
Extra Charging Complete Led
Use GPIO as acive low to indicate charging complete.
;;help_end;;
IDC_STATIC_CHARGING_LED_SETTING4
Type
Select one LED display type for specific function;;help_end;;
IDC_STATIC_LED_TYPE
On Duration
This the LED turn on duration for flash;;help_end;;
IDC_STATIC_LED_ON_TIME
Off Duration
This the LED turn off duration for flash;;help_end;;
IDC_STATIC_LED_OFF_TIME
Count
This is the number of the flash times for a round;;help_end;;
IDC_STATIC_LED_COUNT
Type
Select one LED display type for specific function;;help_end;;
IDC_STATIC_LED_TYPE
On Duration
This the LED turn on duration for flash;;help_end;;
IDC_STATIC_LED_ON_TIME
Off Duration
This the LED turn off duration for flash;;help_end;;
IDC_STATIC_LED_OFF_TIME
Count
This is the number of the flash times for a round;;help_end;;
IDC_STATIC_LED_COUNT
Interval
This is the time interval for a round;;help_end;;
IDC_STATIC_LED_INTERVAL
Type
Select one LED display type for specific function;;help_end;;
IDC_STATIC_LED_TYPE
On Duration
This the LED turn on duration for flash;;help_end;;
IDC_STATIC_LED_ON_TIME
Off Duration
This the LED turn off duration for flash;;help_end;;
IDC_STATIC_LED_OFF_TIME
Count
This is the number of the flash times for a round;;help_end;;
IDC_STATIC_LED_COUNT
Interval
This is the time interval for a round;;help_end;;
IDC_STATIC_LED_INTERVAL
Type
Select one LED display type for specific function;;help_end;;
IDC_STATIC_LED_TYPE
On Duration
This the LED turn on duration for flash;;help_end;;
IDC_STATIC_LED_ON_TIME
Off Duration
This the LED turn off duration for flash;;help_end;;
IDC_STATIC_LED_OFF_TIME
Count
This is the number of the flash times for a round;;help_end;;
IDC_STATIC_LED_COUNT
Interval
This is the time interval for a round;;help_end;;
IDC_STATIC_LED_INTERVAL
Type
Select one LED display type for specific function;;help_end;;
IDC_STATIC_LED_TYPE
On Duration
This the LED turn on duration for flash;;help_end;;
IDC_STATIC_LED_ON_TIME
Off Duration
This the LED turn off duration for flash;;help_end;;
IDC_STATIC_LED_OFF_TIME
Count
This is the number of the flash times for a round;;help_end;;
IDC_STATIC_LED_COUNT
Interval
This is the time interval for a round;;help_end;;
IDC_STATIC_LED_INTERVAL
Type
Select one LED display type for specific function;;help_end;;
IDC_STATIC_LED_TYPE
On Duration
This the LED turn on duration for flash;;help_end;;
IDC_STATIC_LED_ON_TIME
Off Duration
This the LED turn off duration for flash;;help_end;;
IDC_STATIC_LED_OFF_TIME
Count
This is the number of the flash times for a round;;help_end;;
IDC_STATIC_LED_COUNT
Interval
This is the time interval for a round;;help_end;;
IDC_STATIC_LED_INTERVAL
Type
Select one LED display type for specific function;;help_end;;
IDC_STATIC_LED_TYPE
On Duration
This the LED turn on duration for flash;;help_end;;
IDC_STATIC_LED_ON_TIME
Off Duration
This the LED turn off duration for flash;;help_end;;
IDC_STATIC_LED_OFF_TIME
Count
This is the number of the flash times for a round;;help_end;;
IDC_STATIC_LED_COUNT
Interval
This is the time interval for a round;;help_end;;
IDC_STATIC_LED_INTERVAL
Type
Select one LED display type for specific function;;help_end;;
IDC_STATIC_LED_TYPE
On Duration
This the LED turn on duration for flash;;help_end;;
IDC_STATIC_LED_ON_TIME
Off Duration
This the LED turn off duration for flash;;help_end;;
IDC_STATIC_LED_OFF_TIME
Count
This is the number of the flash times for a round;;help_end;;
IDC_STATIC_LED_COUNT
Interval
This is the time interval for a round;;help_end;;
IDC_STATIC_LED_INTERVAL
Type
Select one LED display type for specific function;;help_end;;
IDC_STATIC_LED_TYPE
On Duration
This the LED turn on duration for flash;;help_end;;
IDC_STATIC_LED_ON_TIME
Off Duration
This the LED turn off duration for flash;;help_end;;
IDC_STATIC_LED_OFF_TIME
Count
This is the number of the flash times for a round;;help_end;;
IDC_STATIC_LED_COUNT
Interval
This is the time interval for a round;;help_end;;
IDC_STATIC_LED_INTERVAL
Tone Set1
Tone set mask(English).;;help_end;;
IDC_CHK_TONE_SET1
Tone Set2
Tone set mask(Chinese).;;help_end;;
IDC_CHK_TONE_SET2
Tone Set3
Tone set mask(Spanish).;;help_end;;
IDC_CHK_TONE_SET3
Tone Set4
Tone set mask(French).;;help_end;;
IDC_CHK_TONE_SET4
Use Tone Set
which tone set been used : currently support max 4 tone sets:(0~3);;help_end;;
IDC_STATIC_TONE_SETTING23
Power On Tone
Tone type for power on;;help_end;;
IDC_STATIC_TONE_SETTING10
Power Off Tone
Tone type for power off;;help_end;;
IDC_STATIC_TONE_SETTING11
Enter Pairing Tone
Tone type for enter pairing mode;;help_end;;
IDC_STATIC_TONE_SETTING12
Pairing Complete Tone
Tone type for pariring complete;;help_end;;
IDC_STATIC_TONE_SETTING6
Pairing Not Complete Tone
Tone type for pairing fail;;help_end;;
IDC_STATIC_TONE_SETTING29
Incoming Call Tone
Tone type for incoming call;;help_end;;
IDC_STATIC_TONE_SETTING7
Reject Incoming Call Tone
Tone type for rejecting an incoming call;;help_end;;
IDC_STATIC_TONE_SETTING34
Call Actvie Tone
Tone type for answering a call;;help_end;;
IDC_STATIC_TONE_SETTING4
End Call Tone
Tone type for ending a call;;help_end;;
IDC_STATIC_TONE_SETTING5
Charging Initiate Tone
Tone type for charger initialize;;help_end;;
IDC_STATIC_TONE_SETTING35
Charging Complete Tone
Tone type for charging is completed;;help_end;;
IDC_STATIC_TONE_SETTING36
Low Battery Tone
Tone type for battery low;;help_end;;
IDC_STATIC_TONE_SETTING8
Battery Level 1 Tone
Tone type for battery level one.(>=3.5v);;help_end;;
IDC_STATIC_TONE_SETTING37
Battery Level 2 Tone
Tone type for battery level two.(>=3.6v);;help_end;;
IDC_STATIC_TONE_SETTING38
Battery Level 3 Tone
Tone type for battery level three.(>=3.7v);;help_end;;
IDC_STATIC_TONE_SETTING39
Battery Level 4 Tone
Tone type for battery level four.(>=3.8v);;help_end;;
IDC_STATIC_TONE_SETTING40
Battery Level 5 Tone
Tone type for battery level five.(>=3.9v);;help_end;;
IDC_STATIC_TONE_SETTING41
Battery Level 6 Tone
Tone type for battery level six.(>=4.0v);;help_end;;
IDC_STATIC_TONE_SETTING42
Full Battery Tone
Tone type when battery is full.(>=4.1v);;help_end;;
IDC_STATIC_TONE_SETTING43
Max Volume Tone
Tone type when volume level is maximum;;help_end;;
IDC_STATIC_TONE_SETTING44
Min Volume Tone
Tone type when volume level is minimum;;help_end;;
IDC_STATIC_TONE_SETTING45
HF Connected Tone
Tone type for HF Connected;;help_end;;
IDC_STATIC_TONE_SETTING27
Music Mode Ready Tone
Tone type when A2DP linked;;help_end;;
IDC_STATIC_TONE_SETTING17
Link Loss Tone
Tone type for link lost;;help_end;;
IDC_STATIC_TONE_SETTING18
Link Disconnect Tone
Tone type for normal ACL link disconnect;;help_end;;
IDC_STATIC_TONE_SETTING13
Toggle Tone Set Tone
Tone type when changing tone set.;;help_end;;
IDC_STATIC_TONE_SETTING46
Voice Dial Tone
Tone type when initiate voice dial.;;help_end;;
IDC_STATIC_TONE_SETTING47
Last Number Redial Tone
Tone type when redialing last phone number.;;help_end;;
IDC_STATIC_TONE_SETTING48
Short Press Tone
Tone type for button short press. It is uesd if the option 'Button Press Alarm' is enabled or the triggered button event is related to HFP or voice functions such as voice dial and redial.;;help_end;;
IDC_STATIC_TONE_SETTING1
Long Press Tone
Tone type for button long press.;;help_end;;
IDC_STATIC_TONE_SETTING2
Double Click Tone
Tone type for button double click. It is uesd if the option 'Button Press Alarm' is enabled or the triggered button event is related to HFP or voice functions such as voice dial and redial.;;help_end;;
IDC_STATIC_TONE_SETTING3
No Service Tone
Tone type for no service waring tone.;;help_end;;
IDC_STATIC_TONE_SETTING9
Mute Tone
Tone type when micphone mute.;;help_end;;
IDC_STATIC_TONE_SETTING15
Button Lock Tone
Tone type when button lock.;;help_end;;
IDC_STATIC_TONE_SETTING16
Master Reset Tone
Tone type when specific function be triggered;;help_end;;
IDC_STATIC_TONE_SETTING32
Link Quality Warning Tone
Tone type when out of range;;help_end;;
IDC_STATIC_TONE_SETTING28
Connected Second Profile Tone
Select the tone type for the second profile connected;;help_end;;
IDC_STATIC_TONE_SETTING62
CSB Enter Pairing Tone
The tone rings when the speaker enters CSB pairing.;;help_end;;
IDC_STATIC_TONE_SETTING53
CSB Connect Tone
The tone rings when the CSB link is connected. 
If Master of CSB link is playing music at this moment, it won’t ring the tone.;;help_end;;
IDC_STATIC_TONE_SETTING54
CSB Disconnect Tone
The tone rings when the CSB link is disconnected.;;help_end;;
IDC_STATIC_TONE_SETTING55
Fixed Ring Tone Volume
If enabled, the gain level of ring tone gain will use fixed value. Otherwise, it has two conditions: 
1. The ring tone volume will follow the volume of playing sound.
2. The ring tone gain level will use the level of SCO if no sound is playing.;;help_end;;
IDC_STATIC_TONE_SETTING19
Ring Tone Volume
Gain level(0~15) for fix ring tone volume usage;;help_end;;
IDC_STATIC_TONE_SETTING20
Button Press Alarm
Always ring a tone when button(s) is pressed. The tone type depends on pressing behavior, it may be short press tone, long press tone and double click tone.;;help_end;;
IDC_STATIC_TONE_SETTING21
MFB Long Press Force Alarm
Always ring a long press tone when button 0 is pressed over the time of Long Button Press. 
The button 0 is MFB button.;;help_end;;
IDC_STATIC_TONE_SETTING22
Use 2nd Connected Tone
Disable: Use dedicate profile connected tone setting.
Enable: Use connected_tone2 as 2nd connected profile indication tone;;help_end;;
IDC_STATIC_TONE_SETTING50
Battery Status Prompt When Button Triggered
Enable/Disable Battery status prompt when triggered by MMI event;;help_end;;
IDC_STATIC_TONE_SETTING51
Battery Status Prompt When Power On
Enable/Disable Battery Status Prompt When Power On;;help_end;;
IDC_STATIC_TONE_SETTING52
Battery Detection Enable
Enable/Disable polling the battery voltage.;;help_end;;
IDC_STATIC_BATTERY_DETECTION1
Low Battery Warning Level
The lowest voltage level that device can work well,when battery voltage is under this value, device will generate some warning, such as tone, LED and buzzer (if buzzer is enabled).
Range:(3V-to-4.2V) or( 3000 to 4200);;help_end;;
IDC_STATIC_BATTERY_DETECTION2
Battery Shut Down Level
When the battery voltage level is lower this value, the speaker will shutdown automatically.
The value definitionl is the same with Warning_Battery_Level.
Range:(3V-to-4.2V) or( 3000 to 4200);;help_end;;
IDC_STATIC_BATTERY_DETECTION3
Low Battery Debounce
If this option is enabled, the low battery warning will keep until power adaptor in or power cycle.;;help_end;;
IDC_STATIC_BATTERY_DETECTION9
Charging Detect Enable
Enable/disable charger function.;;help_end;;
IDC_STATIC_CHARGING_SETTING1
Re-Charging As Charge Complete
If this option is enabled, the speaker will check the battery voltage every minute after charging complete. 
If the battery voltage is less than 4.1V, it will start charging again.;;help_end;;
IDC_STATIC_CHARGING_SETTING3
Constant Current of Charging Complete
;;help_end;;
IDC_STATIC_CHARGING_SETTING5
Voltage Level for First Charging Stage
Constant current voltage for charging stage 0.
Range:(3V-to-4.2V) or( 3000 to 4200)
Unit :Voltage. Size:2bytes;;help_end;;
IDC_STATIC_CHARGING_SETTING6
Constant Current Protect Time for First Charging Stage
When cc mode over protective time expired, charging will be completed and stop charging.
CC Mode protective timer stage 0 (unit in min);;help_end;;
IDC_STATIC_CHARGING_SETTING9
Maximum Charging Current for First Charging Stage
Maximum charging current(unit :mA) for charging stage 0 
Unit :mA
Range :0 - Max 455mA.;;help_end;;
IDC_STATIC_CHARGING_SETTING8
Voltage Level for Second Charging Stage
Constant current voltage for charging stage 1.
Range:(3V-to-4.2V) or( 3000 to 4200)
Unit :Voltage. Size:2bytes;;help_end;;
IDC_STATIC_CHARGING_SETTING16
Constant Current Protect Time for Second Charging Stage
When cc mode over protective time expired, charging will be completed and stop charging.
CC Mode protective timer stage 1 (unit in min);;help_end;;
IDC_STATIC_CHARGING_SETTING21
Maximum Charging Current for Second Charging Stage
Maximum charging current(unit :mA) for charging stage 1
Unit :mA
(0 - Max 455mA);;help_end;;
IDC_STATIC_CHARGING_SETTING22
Voltage Level for Third Charging Stage
Constant current voltage for charging stage 2.
Range:(3V-to-4.2V) or( 3000 to 4200)
Unit :Voltage. Size:2bytes;;help_end;;
IDC_STATIC_CHARGING_SETTING7
Constant Current Protect Time for Third Charging Stage
When cc mode over protective time expired, charging will be completed and stop charging.
CC Mode protective timer stage 2 (unit in min);;help_end;;
IDC_STATIC_CHARGING_SETTING23
Maximum Charging Current for Third Charging Stage
Maximum charging current(unit :mA) for charging stage 2
Unit :mA
(0 - Max 455mA);;help_end;;
IDC_STATIC_CHARGING_SETTING12
Voltage Level for Fourth Charging Stage
Constant current voltage for charging stage 3.
Range:(3V-to-4.2V) or( 3000 to 4200)
Unit :Voltage. Size:2bytes;;help_end;;
IDC_STATIC_CHARGING_SETTING24
Constant Current Protect Time for Fourth Charging Stage
When cc mode over protective time expired, charging will be completed and stop charging.
CC Mode protective timer stage 3 (unit in min);;help_end;;
IDC_STATIC_CHARGING_SETTING26
Maximum Charging Current for Fourth Charging Stage
Maximum charging current(unit :mA) for charging stage 3
Unit :mA
(0 - Max 455mA);;help_end;;
IDC_STATIC_CHARGING_SETTING25
Constant Voltage Protect Time
Protect time in constant voltage charging mode.
Charger will stop charging function when over this time.;;help_end;;
IDC_STATIC_CHARGING_SETTING10
Ambient Temperature Charging Detection
Enable/Disable ambient temperature detection during charging.;;help_end;;
IDC_STATIC_CHARGING_SETTING13
Stop Working SAR Min
The minimum SAR voltage for ambient temperature detection to stop charger.;;help_end;;
IDC_STATIC_CHARGING_SETTING30
Stop Working SAR Max
The maximum SAR voltage for ambient temperature detection to stop charger.;;help_end;;
IDC_STATIC_CHARGING_SETTING32
Stop Charging SAR Min
The minimum SAR voltage for ambient temperature detection to stop charger.;;help_end;;
IDC_STATIC_CHARGING_SETTING17
Restart Charging SAR Min
The minimum SAR voltage for ambient temperature detection to restart charger.;;help_end;;
IDC_STATIC_CHARGING_SETTING18
Stop Charging SAR Max
The maximum SAR voltage for ambient temperature detection to stop charger.;;help_end;;
IDC_STATIC_CHARGING_SETTING19
Restart Charging SAR Max
The maximum SAR voltage for ambient temperature detection to restart charger.;;help_end;;
IDC_STATIC_CHARGING_SETTING20
Speaker Output
Capless: Speaker output without a DC blocking capacitor.
Single end: Speaker output with a DC blocking capacitor;;help_end;;
IDC_STATIC_CODEC_FUNC1
Enable LR Sound Channel Swap
Swap left and right channel speaker output(only for A2DP);;help_end;;
IDC_STATIC_CODEC_FUNC4
Enable LR Sound Mix
Mix left and right channel speaker output to mono speaker output.;;help_end;;
IDC_STATIC_CODEC_FUNC5
DSP CODEC Always On Enable
Never power down codec and DSP if this function be enabled;;help_end;;
IDC_STATIC_CODEC_FUNC9
Close CODEC Time
When DSP in SBC decode state, and FW do not receive any stream data,it will close CODEC after this time;;help_end;;
IDC_STATIC_CODEC_FUNC10
CODEC Output Type
Select to use external codec or internal codec.;;help_end;;
IDC_STATIC_CODEC_FUNC12
Audio SRC
44.1K to 48K for A2DP audio;;help_end;;
IDC_STATIC_CODEC_FUNC13
Voice SRC
8K/16K to 48K for ring tone or SCO voice;;help_end;;
IDC_STATIC_CODEC_FUNC14
Voice Stereo
Enable the function that voice outputs both of L and R channel.;;help_end;;
IDC_STATIC_CODEC_FUNC15
Tone Stereo
Enable the function that single tone and VP output both of L and R channel.;;help_end;;
IDC_STATIC_CODEC_FUNC16
Line In Priority
This parameter is used to set the priority of Aux-in is higher than A2DP. 
When Aux-in and A2DP streaming coexist, the speaker will output the audio with higher priority.;;help_end;;
IDC_STATIC_LINE_IN_SETTING2
Line In Mute/Unmute
Enable mute/unmute feature by Play/Pause event when Line In priority;;help_end;;
IDC_STATIC_LINE_IN_SETTING3
Line In Silence Detect
Detect silence status for Aux-in signal if this option is enabled. The duration to determine the Aux-in is silence is about 33 seconds. ;;help_end;;
IDC_STATIC_LINE_IN_SETTING6
Line In Indicate Led
Use the GPIO pin to indicate Aux-in status.;;help_end;;
IDC_STATIC_LINE_IN_SETTING5
Line In CSB
Enable/Disable Broadcast/2-SPK Aux-in mode.;;help_end;;
IDC_STATIC_LINE_IN_SETTING7
Line In Latency
Line-in latency adjustment (unit: *1/3 ms)
ex: 0xF0 => 240 * 1/3 = 80 ms;;help_end;;
IDC_STATIC_LINE_IN_SETTING9
Initial Line In SPK Gain
Default gain level for line in mode.
"Initial Line In SPK Gain" should be between max and min level.;;help_end;;
IDC_STATIC_LINE_IN_SETTING10
Cut Off Amplifier When Mute
Off amplifier when CODEC is mute.;;help_end;;
IDC_STATIC_AMP_CONTROL_SETTING1
Off Amplifier T0
when codec mute, set this timer to turn off external amplifier, 
if this value set to 0, then turn off external amplifier directly;;help_end;;
IDC_STATIC_AMP_CONTROL_SETTING2
Off Amplifier T1
when config codec ACTIVE, wait this time to turn on external amplifier, if this value is 0, then wait 100ms.;;help_end;;
IDC_STATIC_AMP_CONTROL_SETTING3
Off Amplifier T2
when AMP_CTRL_T1 expired, then wait at least this time to start play audio.
Notice: AMP_ENABLE means external amplifier enable pin;;help_end;;
IDC_STATIC_AMP_CONTROL_SETTING4
SBC
;;help_end;;
IDC_CHK_SBC_CODEC_MASK
AAC
;;help_end;;
IDC_CHK_AAC_CODEC_MASK
Equalizer Function Enable
Open EQ module if Enable.;;help_end;;
IDC_STATIC_EQUIZER_SETTING1
Initial Equalizer Mode
For audio(A2DP), similar to voice setting.;;help_end;;
IDC_STATIC_EQUIZER_SETTING2
Digital Mic
Enable/disable digital MIC.;;help_end;;
IDC_STATIC_GAIN_LEVEL_SETTING4
Analog Microphone Gain Level
To set the analog mic gain.;;help_end;;
IDC_STATIC_GAIN_LEVEL_SETTING1
Digital Microphone Gain Level
To set the digital mic gain.;;help_end;;
IDC_STATIC_GAIN_LEVEL_SETTING2
Burst iAP Transmission
If this option is enabled, the accessory even no receiving a successful acknowledgment of an AccessoryDataTransfer command, the accessory may immediately send a new command containing available data for any session ID.;;help_end;;
IDC_STATIC_MFI_TRANS_SETTING1
iAP Data Transmission
Enable/Disable data retransmission.;;help_end;;
IDC_STATIC_MFI_TRANS_SETTING2
Enable Auto Launch APP
Enable/Disable auto launch APP.;;help_end;;
IDC_STATIC_MFI_TRANS_SETTING3
Bondle Seed ID Pref Token
Please refer to the \"MFi Accessory Firmware specification\".;;help_end;;
IDC_STATIC_MFI_DESCRIPTION_SETTING1
SDK Protocol Token
;;help_end;;
IDC_STATIC_MFI_DESCRIPTION_SETTING2
APP Boundle ID
;;help_end;;
IDC_STATIC_MFI_DESCRIPTION_SETTING3
Accessory Name
;;help_end;;
IDC_STATIC_MFI_DESCRIPTION_SETTING4
Accessory FW Version
;;help_end;;
IDC_STATIC_MFI_DESCRIPTION_SETTING5
Accessory HW Version
;;help_end;;
IDC_STATIC_MFI_DESCRIPTION_SETTING6
Accessory Manu
;;help_end;;
IDC_STATIC_MFI_DESCRIPTION_SETTING7
Accessory Model Number
;;help_end;;
IDC_STATIC_MFI_DESCRIPTION_SETTING8
Accessory Serial Number
;;help_end;;
IDC_STATIC_MFI_DESCRIPTION_SETTING9
SDK Protocol Token
;;help_end;;
IDC_STATIC_MFI_DESCRIPTION_SETTING11
Transparent Service UUID
This parameter is used to config the sepcific Transparent Service UUID.;;help_end;;
IDC_STATIC_UART_SERVICE_UUID
Transparent TX UUID
This parameter is used to config the sepcific Transparent TX UUID.;;help_end;;
IDC_STATIC_UART_TX_UUID
Transparent RX UUID
This parameter is used to config the sepcific Transparent RX UUID.;;help_end;;
IDC_STATIC_UART_RX_UUID
Initiate Pairing Request in BLE Connected
Enable/disable authentication for transparent service.;;help_end;;
IDC_STATIC_PAIRING_REQEST_IN_BLE_CONNECTED
BLE Application in Embedded Mode
;;help_end;;
IDC_STATIC_BLE_APPLICATION_SETTING1
Advertising Data Length
This parameter is uesd to set advertising data.;;help_end;;
IDC_STATIC_ADVERTISING_DATA_SETTING
Audio Beacon
Enable/disable audio beacon. Put some information in Service data in advertising data such as battery level, BTM status.
This option is used in Embedded mode.;;help_end;;
IDC_STATIC_ADDITIONAL_DATA_IN_ADVERTISING
Scan Response Data Length
This feature is uesd to set scan response data, the information will be sent to a LE scaner.;;help_end;;
IDC_STATIC_SCAN_RESPONSE_DATA_SETTING
Audio Beacon
Enable/disable audio beacon. Put some information in Service data to scan response data such as battery level, BTM status.
This option is used in Embedded mode.;;help_end;;
IDC_STATIC_ADDITIONAL_DATA_IN_SCAN_RESPONSE
Min. LE Connection Interval
This parameter is used to set LE min connection interval. (Unit: 1.25ms)
The value 0x0000 means Speaker won't issue parameter update request command.;;help_end;;
IDC_STATIC_MIN_LE_CONNECTION_INTERVAL
Max. LE Connection Interval
This parameter is used to set LE max connection interval. (Unit: 1.25ms)
The value 0x0000 means Dual Speaker won't issue parameter update request command.;;help_end;;
IDC_STATIC_MAX_LE_CONNECTION_INTERVAL
LE Slave Latency
This parameter is used to set LE slave latency.;;help_end;;
IDC_STATIC_LE_SLAVE_LATENCY
LE Supervision Timeout
This parameter is used to set LE supervision timeout. (Unit: 10ms);;help_end;;
IDC_STATIC_LE_SUPERVISION_TIMEOUT
LE Reconnection Timeout
If no data is transmitted over this time, disconnect LE connection. (Unit: min, 0 means this function is disabled);;help_end;;
IDC_STATIC_LE_RECONNECTION_TIMEOUT
Manufacture Name
This parameter is used to configure the name of the manufacturer of the device.;;help_end;;
IDC_LE_DIS_SETTING_MANUNAME
Model Name
Thisparameter is used to configure the model number that is assigned by the device vendor.;;help_end;;
IDC_LE_DIS_SETTING_MODELNAME
Serial Number
This parameter is used to configure the serial number for a particular instance of the device.;;help_end;;
IDC_LE_DIS_SETTING_SERIALNO
Software Revision
This parameter is used to configure the software revision for the software within the device.;;help_end;;
IDC_LE_DIS_SETTING_SW_REV
Connected TX Power Level
The BLE connected TX power level. Level 0 ~ 6 (max)
The max reference power is 5 dBm and decrease 5 dBm for each  following level.
The actual power is upon calibration in MP process.;;help_end;;
IDC_STATIC_CONNECTED_TX_POWER_LEVEL
Advertising TX Power Level
The ADV TX power level. Level 0 ~ 6 (max)
The max reference power is 5 dBm and decrease 5 dBm for each  following level.
The actual power is upon calibration in MP process.;;help_end;;
IDC_STATIC_ADVERTISING_TX_POWER_LEVEL
Master Role
Select to be slave role.;;help_end;;
IDC_RDO_TWIN_MASTER
Slave Role
Select to be master role.;;help_end;;
IDC_RDO_TWIN_SLAVE
Twin Pairing Duration
The CSB pairing timeout. (Unit: 5s);;help_end;;
IDC_STATIC_NSPK_SETTING2
Twin Aux. Pairing Duration
The CSB pairing timeout of Slave role in One_Key_Operation.  (Unit: 2s)
When the One_Key_Operation is triggered, it enters CSB pairing as Slave role first and then change to Master role after this timeout occurs.;;help_end;;
IDC_STATIC_NSPK_SETTING4
General Twin Mode Group Code
The group code for general CSB pairing;;help_end;;
IDC_STATIC_NSPK_SETTING9
Recover MSPK Link As Twin Speaker Link Loss
If this option is enabled, the speaker will try to recover the CSB link when the CSB link disconnects abnormally.;;help_end;;
IDC_STATIC_NSPK_SETTING6
Default Multi Speaker Mode
Select to use stereo mode or concert mode.;;help_end;;
IDC_STATIC_NSPK_SETTING18
Stereo Model ID
The model ID is used with "General Twin Mode Group Code" for Stereo Mode.
It will disallow the speakers with different model IDs form the connection of Stereo Mode.;;help_end;;
IDC_STATIC_NSPK_SETTING19
A2DP Latency
To set a2dp latency timer. (Unit: ms);;help_end;;
IDC_STATIC_MULTI_SPK_SETTING3
Concert Mode Resync
Enable audio resync function in Concert Mode.;;help_end;;
IDC_STATIC_MULTI_SPK_SETTING5
Concert Mode Link Status Record
Enable/Disable broadcast back to last mode.;;help_end;;
IDC_STATIC_MULTI_SPK_SETTING6
ADV Policy in Concert Mode Slave
The Advertising policy for the Concert Mode Slave.;;help_end;;
IDC_STATIC_MULTI_SPK_SETTING7
ADV Policy in Stereo Slave
The Advertising policy for the TWS Slave.;;help_end;;
IDC_STATIC_MULTI_SPK_SETTING8
Enable AAC Codec in CSB
;;help_end;;
IDC_STATIC_MULTI_SPK_SETTING9
MSPK Audio Channel
Audio channel setting for multi-speaker.;;help_end;;
IDC_STATIC_NSPK_STEREO_SETTING2
At Bluetooth Standby State
SHS state after CSB creation complete while CSB is trigged in SHS STANDBY;;help_end;;
IDC_STATIC_TWIN_PAIRING_SUCCESS_SETTING1
At Bluetooth Connected State
SHS state after CSB creation complete while CSB is trigged in SHS CONNECTED;;help_end;;
IDC_STATIC_TWIN_PAIRING_SUCCESS_SETTING2
At Bluetooth Link Back State
SHS state after CSB creation complete while CSB is trigged in SHS PAGING;;help_end;;
IDC_STATIC_TWIN_PAIRING_SUCCESS_SETTING3
At Bluetooth Pairing State
SHS state after CSB creation complete while CSB is trigged in SHS PAIRING;;help_end;;
IDC_STATIC_TWIN_PAIRING_SUCCESS_SETTING4
At Bluetooth Standby State
SHS state after CSB creation complete while CSB is trigged in SHS STANDBY;;help_end;;
IDC_STATIC_TWIN_PAIRING_FAILED_SETTING1
At Bluetooth Connected State
SHS state after CSB creation complete while CSB is trigged in SHS CONNECTED;;help_end;;
IDC_STATIC_TWIN_PAIRING_FAILED_SETTING2
At Bluetooth Link Back State
SHS state after CSB creation complete while CSB is trigged in SHS PAGING;;help_end;;
IDC_STATIC_TWIN_PAIRING_FAILED_SETTING3
At Bluetooth Pairing State
SHS state after CSB creation complete while CSB is trigged in SHS PAIRING;;help_end;;
IDC_STATIC_TWIN_PAIRING_FAILED_SETTING4
