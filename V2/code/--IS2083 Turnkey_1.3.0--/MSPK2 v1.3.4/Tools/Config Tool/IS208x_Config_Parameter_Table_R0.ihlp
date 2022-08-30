272
Name
Help;;help_end;;
ID
UART Command
Enable this option to support UART interface which is necessary for host MCU mode.
option value auto changed according to "Host MCU Mode" or "Embedded Mode", not changeable.
;;help_end;;
ENABLE_UART_INTERFACE
UART Baudrate
The baud rate configuration of UART. Unit : bps.
This option is choosable only if choose item "Host MCU Mode"
\par
Baud rate definitions:
0x00: 921600
0x01: 460800
0x02: 230400
0x03: 115200
0x04: 57600
0x05: 38400
0x06: 28800
0x07: 19200
0x08: 14400
0x09: 9600
0x0A: 4800
0x0B: 2400
;;help_end;;
SYS_CFG_KEY_HCI_BAUD_RATE_INDEX
CPU Idle Mode
If this option is set, it will enter 32K clock mode when system is idle.
;;help_end;;
ENABLE_CPU_IDLE_MODE
Wake Up Host MCU Delay Time
The waiting time to start UART TX after wakeup mcu. That is, it is the guard time for MCU wakeup.
The value 0x00 means the speaker doesn't need to wake up MCU before sending data to MCU. (unit in 0.3125ms)
;;help_end;;
SYS_CFG_KEY_MCU_WAKEUP_TIME
Disable Waiting for ACK
If this option is set, it will not wait the ACK of UART event from MCU after reporting
transparent data (UART event ID 0x22) to MCU. It is usually used in throughput sensitive case and MCU
has capability to process burst data.
;;help_end;;
DISABLE_UART_ACK_CONFIRM
OTA DFU Key
OTA DFU key is used for encryption. For more details, you can search document "AN3118" on Microchip website
;;help_end;;
SYS_CFG_KEY_OTA_DFU_KEY
OTA DFU Service
set to 1 to disable OTA DFU service
;;help_end;;
DISABLE_OTA_DFU_SERVICE
Vendor Data
1. Vendor Data can be used to save information, e.g., developer configuration version information.
2. You can use the UART command 0x31 to get that information.
;;help_end;;
SYS_CFG_KEY_VENDOR_DATA
Device Name
1. Device name is the classic Bluetooth name that would show on your phone if you did the BT searching
on your phone and the device respond to your phone searching.
2. The max. device name which BM83 can support is 64 char.
;;help_end;;
BT_CFG_KEY_DEVICE_NAME
Enable Inquiry Scan In Standby
Open Inquiry scan window in when the speaker is in standby mode. That is,
if this option is enabled the speaker is discoverable in not only pairing mode but also standby mode.
1: enabled, 0:disabled
;;help_end;;
ENABLE_INQUIRY_SCAN_IN_STANDBY
Enable Power On Enter Pairing
If this options is enabled and the speaker meets below two conditions, it will enter pairing mode when power on.
Condition1: The speaker doesn't try to create CSB link when power on
Condition2: The speaker doesn't need to reconnect to remove device (no paired record or ENABLE_POWER_ON_LINK_BACK is not enabled) when power on
;;help_end;;
ENABLE_POWER_ON_ENTER_PAIRING
Suspend Stream When SCO Estabblished
The option is used in multiple link. When the speaker has a SCO link with one phone,
it will send AVDTP_SUSPEND to the other phone that is playing music. 1: enabled, 0: disabled.
;;help_end;;
SCO_SUSPEND_STREAM_ENABLE
BT Class of Device
The class of device/service field (CoD) of the device configuration.
;;help_end;;
SYS_CFG_KEY_CLASS
Report Battery Status to Smart Phone
Report speaker/hs battery status via AT command base on HFP to mobile phone
;;help_end;;
BATTERY_REPORT_VIA_AT_CMD_ENABLE
Link Application
0 : support 1HF+1A2DP links
1 : support 1HF+3A2DP links
;;help_end;;
SUPPORT_MULTILINK_MULTIPROFILE
Always Answer Incoming Call
If this option is enabled (set to 1) and HFP connection exists, it will always answer incoming calls automatically.
;;help_end;;
ALWAYS_AUTO_ANSWER_INCOMING_CALL_ENABLE
Auto Answer Incoming Call When Link Back
when the speaker links back HF link and call status is incoming call, then it will answer the call automatically if this option is enabled (set to 1).
;;help_end;;
AUTO_ANSWER_INCOMING_CALL_AS_CONNECTED_ENABLE
Shut Down Power in Off State
Cut off the power when the speaker enter off state if this option is enabled (set to 1)
;;help_end;;
ENABLE_SHUTDOWN_POWER
Enter Pairing When Power On Link Back Fail
Enable this option (set to 1) to enter pairing automatically if it fails to reconnect to phone when power on.
;;help_end;;
LINK_BACK_FAIL_ENTER_PAIRING
Only Accept Paired Device
If this option is set, the speaker only accepts the connect request from paired devices when it is not in pairing mode.
;;help_end;;
ENABLE_ONLY_ACCEPT_PAIRED_DEVICE
Disconnect All In Pairing
Disconnect all classic BT links when the speaker enters pairing mode.
;;help_end;;
ENABLE_DISCONNECT_ALL_IN_PAIRING
Keep BLE In Power Off
Keep BLE link or ADV active when the speaker is in off state.
;;help_end;;
ENABLE_KEEP_BLE_IN_POWEROFF
Wide Band Speech Enable(mSBC)

The feature that BTM supported for HF profile, it is BRSF bit definition. Please refer to HFP spec. for the detail.
Bit0:EC_AND_OR_NR_FUNCTION
Bit1:CALL_WAITING_AND_THREE_WAY_CALLING
Bit2:CLI_PRESENTATION_CAPABILITY
Bit3:VOICE_RECOGNITION_ACTIVATION
Bit4:REMOTE_VOLUME_CONTROL
Bit5: ENHANCE_CALL_STATUS
Bit6: ENHANCE_CALL_CONTROL
Bit7: CODEC_NEGOTIATION
Bit8: HF_INDICATORS
Bit9: ESCO_S4_SETTINGS
;;help_end;;
BT_CFG_KEY_HF_SUPPORT_FEATURE
AVRCP Version
AVRCP version selection.
0: AVRCP 1.3
1: AVRCP 1.6
;;help_end;;
AVRCP_VERSION
Auto Unsniff in Data Transmission
After system enters sniff mode, it would not auto exit sniff mode if received packets or send packets.
;;help_end;;
DISABLE_AUTO_UNSNIFF
Enable AVRCP Browsing Feature
Enable AVRCP browsing feature.
;;help_end;;
ENABLE_AVRCP_BROWSING
Allow Users to Enable Device Under Test Mode
This item is used to let the device enter test mode
so that user can do Bluetooth related hardware and certification test.
If you enable this item you can let the device switch to test mode by
placing device in pairing mode and combine with either one of the following event.
Besides, you don't need pull low some dedicated GPIO anymore.
Button trigger: triple click MFB
UART Command: MMI_Action(0x02)+Action ID(0x03)
;;help_end;;
ENABLE_EDUTM
Auto Role Switch to BT Master
Role switch to be BT Master in piconet if current link is BT Slave. For multi-link scheme, enable this option to have a better performance.
;;help_end;;
ENABLE_ROLE_SWITCH_MASTER
Enable Role Switch in Link Policy
Enable role switch in linkpolicy when BT link connected.
;;help_end;;
ENABLE_ROLE_SWITCH_POLICY
Force as BT Slave role
Role switch to be BT Slave in piconet if current link is BT Master. This option is exclusive with ENABLE_ROLE_SWITCH_MASTER.
;;help_end;;
FORCE_AS_BT_SLAVE
Phone Provide NR and EC Function
This option is used to determine NREC function is enabled/disabled in remote phone.
It might cause voice distortion if the NREC function is enabled in both of remote phone and BM83.
BM83 can send the AT command to disable the NREC function of remote phone.
1(disable phone NREC): send AT command to disable phone's NR, EC function
0(enable phone NREC): don't send AT command to disable phone's NR, EC function
;;help_end;;
PHONE_PROVIDE_NREC
Disable Link Back When Remote No Link Key
0 : Enable link back to remote device which has no link key
1 : Disable link back to remote device which has no link key
;;help_end;;
DISABLE_LINKBACK_WHEN_REMOTE_NO_LINKKEY
Factory Default Timer
if the power button is pressed over this time in OFF state, the speaker will clear some configuration parameters to default values.
1. line_in_gain_level
2. Device_List_Table
3. device_speaker_gain
4. device_absolute_volume
5. linked_priority
6. app_function_status
7. hf_device_index
8. a2dp_device_index
9. mic_gain_level
10. CSB_DIAC (if PAIRING_WITH_MIAC is enabled)
11. clear the options LAST_MODE_N_SPK_MASTER and LAST_MODE_N_SPK_SLAVE (if the option BACK_TO_LAST_MODE is enabled.)
12. NSPK_channel
13. LE paired record
;;help_end;;
BTN_GPIO_CFG_KEY_RESET_TO_DEAFULT_TIMER
Power On Link Back Setting
Enable link back feature when power on.
1:enabled, 0:disabled.
;;help_end;;
ENABLE_POWER_ON_LINK_BACK
Seach Paired Device Pattern Setting
0 : link back last device only
1 : power on link back based on link priority and with loop
;;help_end;;
ENABLE_LINK_BACK_BY_PRIORITY
Power On Link Back Profile(s) Setting

This is used for power on reconnection.
0 : LINK_SCENARIO_LAST_DEVICE, only reconnect to last device no matter SUPPORT_MULTILINK_MULTIPROFILE and ENABLE_LINK_BACK_BY_PRIORITY are enabled or not.
1 : LINK_SCENARIO_HF_BASE, reconnect to the highest priority device with HFP profile.
The priority is ordered by HFP link, the speaker updates the priority as the highest when HFP link is created.
If the option ENABLE_LINK_BACK_BY_PRIORITY is enabled, it will try next priority device once the speaker fails to the highest device.
If the option SUPPORT_MULTILINK_MULTIPROFILE is enabled, it will try to connect second device.
2 : LINK_SCENARIO_A2DP_BASE,  reconnect to the highest priority device with A2DP profile.
The priority is ordered by A2DP link, the speaker updates the priority as the highest when A2DP link is created.
If the option ENABLE_LINK_BACK_BY_PRIORITY is enabled, it will try next priority device once the speaker fails to the highest device.
If the option SUPPORT_MULTILINK_MULTIPROFILE is enabled, it will try to connect second device.
;;help_end;;
LINK_SCENARIO
Link Loss Reconnect Time
The timeout to reconnecting to link loss device.
0x00 : don't reconnect
0xFF : recover without timeout
other : (unit in 5 second)
;;help_end;;
BT_CFG_KEY_LINK_LOSS_RECONNECT_TIME
Page HS Time
The timeout value for reconnecting HF/HS device (unit in 5 second), 0 means no timeout.
;;help_end;;
BT_CFG_KEY_PAGE_HS_TIME
Page A2DP Time
page A2DP device time out value(unit in 5 second), o means no timeout.
;;help_end;;
BT_CFG_KEY_PAGE_A2DP_TIME
Pairing Timeout
The timeout value for pairing mode(unit in 30 second), 0 means no timeout.
;;help_end;;
BT_CFG_KEY_PAIRING_TIMEOUT
Power On
when in OFF mode, the power button is pressed over this time, system will power on (unit in 80ms)
PS: the real power on time will larger than this interval around 1second due to system initialization.
;;help_end;;
BTN_GPIO_CFG_KEY_POWER_ON_INTERVAL
Power Off
When in ON mode, the power button is press over this time, system will power off (unit in 80ms)
;;help_end;;
BTN_GPIO_CFG_KEY_POWER_OFF_INTERVAL
BT Classic Pairing
If the power button is pressed over this time in OFF mode, the speaker will enter pairing mode (unit in 80ms)
PS: the real time will larger than this interval around 1second due to system initialization.
;;help_end;;
BTN_GPIO_CFG_KEY_ENTER_PAIRING_PRESS_TIME
No Service Warning Time
When mobile phone can not receive the signal from base station, headset alert user periodically with this interval(unit in 640 ms).
This function is through HFP.
;;help_end;;
BT_CFG_KEY_NO_SERVICE_WARNING_TIME
Low Battery Warning Time
When the voltage battery is lower than Warning_Battery_Level (the voltage setting for low battery),
the speaker alerts users periodically with this interval(unit in 640 ms).
;;help_end;;
POWER_CFG_KEY_LOW_BATTERY_WARNING_TIME
Microphone Mute Alarm Interval
If the speaker has calls and its microphone is muted , it will ring the mute tone to alert user
periodically with this interval(unit in 640 ms)
;;help_end;;
SYS_CFG_KEY_MUTE_ALARM_TIME
Auto Power Off
;;help_end;;

Pairing Timeout Shut Down Directly
If this option is set, the speaker will shut down automatically when pairing timeout.
;;help_end;;
ENABLE_SHUT_DOWN_AS_PAIRING_TO
Auto Power Off Enable
When system enter standby state, then set auto_power_off_time to shut down power.
There are some conditions will disable this function:
1. In charging.
2. MSPK link exists (for MSPK Slave role).
3. Aux-in is plugged in and not silent.
4. The speaker is reconnecting.
5. A2DP streaming.
6. The speaker isn't in standby state.
;;help_end;;
ENABLE_STANDBY_AUTO_POWER_OFF
A2DP Link Silence
If this option is set, then system will be shut down automatically when it meets all of below conditions.
A2DP/AVRCP is only one link
Auto Power Off Timer has been timeout
No button is pressed
No power adapter plug in
BT device doesn't receive any audio packet from AG any more.
;;help_end;;
ENABLE_NO_STREAM_AUTO_OFF
Auto Power Off Time
The timer of auto power off for power saving.
;;help_end;;
SYS_CFG_KEY_AUTO_POWER_OFF_TIME
Max BT Sniff Interval
Max BT sniff interval
;;help_end;;
MAX_BT_SNIFF_INTERVAL
Min BT Sniff Interval
Min BT sniff interval
;;help_end;;
MIN_BT_SNIFF_INTERVAL
Inquiry TX Power Level.
The inquiry TX power level. Level 0 ~ 6 (max)
The max reference power is 10 dBm and decrease 5 dBm for each following level.
The actual power is upon calibration in MP process.
;;help_end;;
BT_INQUIRY_RF_TX_POWER_LEVEL
BT Connected TX Power Level.
The BT connected TX power level. Level 0 ~ 6 (max)
The max reference power is 10 dBm and decrease 5 dBm for each following level.
The actual power is upon calibration in MP process.
;;help_end;;
BT_CONNECTED_RF_TX_POWER_LEVEL
LED2 Brightness
The brightness setting of LED2
;;help_end;;
LED2_BRIGHTNESS
LED1 Brightness
The brightness setting of LED1
;;help_end;;
LED1_BRIGHTNESS
dedicate charger led enable
Use GPIO as acive low to indicate charging complete if this option is enabled (set to 1).
Please refer to GPIO configuration to check which pin is used.
This Option is automatically set according to "Charge OK Led Ind." in "Function Enable and GPIO Assignment".
It is not for manually set.
;;help_end;;
DEDICATE_CHARGER_LED_ENABLE
Charging Complete LED Indication Setting
0: charger release LED control(back to normal display)
1: LED1 ON and then charger release LED control
2: LED1 always ON, LED2 normal display
3: LED1 always OFF, LED2 normal display.
;;help_end;;
CHARGING_COMPLETE_LED_INDICATION_SETTING
Charging Error LED Indication Setting
0: same as charger complete
1: LED1 always OFF and LED2 flash
;;help_end;;
CHARGEING_ERROR_LED_INDICATION_SETTING
dedicate charger led enable
Use GPIO as acive low to indicate charging complete if this option is enabled (set to 1).
Please refer to GPIO configuration to check which pin is used.
This Option is automatically set according to "Charge OK Led Ind." in "Function Enable and GPIO Assignment".
It is not for manually set.
;;help_end;;
DEDICATE_CHARGER_LED_ENABLE
Setting Tone Mask
Tone set mask (bit0 ~ bit3) to indicate support which set of tone settings:

;;help_end;;
TONE_CFG_KEY_TONE_SET_MASK
Configure Tone Set
which tone set been used : currently support max 4 tone sets:(0~3).
;;help_end;;
TONE_CFG_KEY_TONE_SET
Power On Tone
Tone type for power on event
;;help_end;;
POWER_ON_TONE
Power Off Tone
Tone type for power off event
;;help_end;;
POWER_OFF_TONE
Enter Pairing Tone
Tone type for entering pairing event
;;help_end;;
ENTER_PAIRING_TONE
Pairing Complete Tone
Tone type for pairing complete event
;;help_end;;
PAIRING_COMPLETE_TONE
Pairing Not Complete Tone
Tone type for pairing failure event
;;help_end;;
PAIRING_INCOMPLETE_TONE
Incoming Call Tone
Tone type for incoming call event
;;help_end;;
INCOMING_CALL_TONE
Reject Call Tone
Tone type for rejecting call event
;;help_end;;
REJECT_CALL_TONE
Call Active Tone
Tone type for call active event
;;help_end;;
CALL_ACTIVE_TONE
Call End Tone
Tone type for call end event
;;help_end;;
CALL_END_TONE
Charging Initiate Tone
Tone type for charging initate event
;;help_end;;
CHARGING_INITIATE_TONE
Charging Complete Tone
Tone type for charging complete event
;;help_end;;
CHARGING_COMPLETE_TONE
Low Battery Tone
Tone type for low battery warning
;;help_end;;
LOW_BATTERY_TONE
Battery Level 1 Tone
Tone type for the indication of battery level 1
;;help_end;;
BATTERY_LEVEL1_TONE
Battery Level 2 Tone
Tone type for the indication of battery level 2
;;help_end;;
BATTERY_LEVEL2_TONE
Battery Level 3 Tone
Tone type for the indication of battery level 3
;;help_end;;
BATTERY_LEVEL3_TONE
Battery Level 4 Tone
Tone type for the indication of battery level 4
;;help_end;;
BATTERY_LEVEL4_TONE
Battery Level 5 Tone
Tone type for the indication of battery level 5
;;help_end;;
BATTERY_LEVEL5_TONE
Battery Level 6 Tone
Tone type for the indication of battery level 6
;;help_end;;
BATTERY_LEVEL6_TONE
Full Battery Tone
Tone type for the indication of battery full
;;help_end;;
FULL_BATTERY_TONE
Max Vol Tone
Tone type for the event which the volume reaches to maximum volume
;;help_end;;
MAX_VOL_TONE
Min Vol Tone
Tone type for the event which the volume reaches to minimum volume
;;help_end;;
Min_VOL_TONE
HFP Connected Tone
Tone type for HFP connected tone
;;help_end;;
HFP_CONNECTED_TONE
Music Mode Ready Tone
Tone type for the event which the volume reaches to minimum volume
;;help_end;;
A2DP_CONNECTED_TONE
Link Loss Tone
Tone type for BT ACL link loss event
;;help_end;;
LINK_LOSS_TONE
BT Link Disconnect Tone
Tone type for BT ACL link disconnected event.
;;help_end;;
LINK_DISCONNECTED_TONE
Tone Set Changed Tone
Tone type for the tone set changed event
;;help_end;;
TONE_SET_CHANGED_TONE
Voice Dial Tone
Tone type for the event which voice dial is triggered.
;;help_end;;
VOICE_DIAL_TONE
Last Number Redial Tone
Tone type for the event which last number redial is triggered
;;help_end;;
LAST_NUMBER_REDIAL_TONE
Short Press Tone
Tone type for button short press.
It is uesd if the option ALL_BUTTON_FORCE_ALARM_ENABLE is enabled or
the triggered button event is related to HFP or voice functions such as voice dial and redial.
;;help_end;;
TONE_CFG_KEY_SHORT_PRESS_TONE
Long Press Tone
Tone type for button long press. It is used for below conditions:
1. If the option ALL_BUTTON_FORCE_ALARM_ENABLE is enabled, it rings for any button that is long pressed
2. If the triggered button event is related to HFP or voice functions
3. If the option BUTTON_0_FORCE_ALARM_ENABLE is enabled, it rings for button 0 that is long pressed
;;help_end;;
TONE_CFG_KEY_LONG_PRESS_TONE
Double Click Tone
Tone type for button double click. It is uesd if the option ALL_BUTTON_FORCE_ALARM_ENABLE is enabled
or the triggered button event is related to HFP or voice functions such as voice dial and redial.
;;help_end;;
TONE_CFG_KEY_DOUBLE_CLICK_TONE
No Service Tone
Tone type for the event which phone can't communicate with base station and have call service.
;;help_end;;
NO_CALL_SERVICE_TONE
Microphone Mute Tone
Tone type for the warning which microphone is muted.
;;help_end;;
MIC_MUTE_TONE
Button Lock Tone
Tone type for button lock state.
;;help_end;;
BUTTON_LOCK_TONE
Setting Function Alarm Tone
tone mode for some function indication, such NFC…
;;help_end;;
TONE_CFG_KEY_FUNCTION_ALARM_TONE
Quality Warning Tone
Tone type for bad signal of Bluetooth connection.
;;help_end;;
TONE_CFG_KEY_LINK_QUALITY_WARNING_TONE
Enable Connected Tone_2
when ENABLE_USE_CONNECTED_TONE2 is enable, then generate this tone for 2nd profile connected
;;help_end;;
TONE_CFG_KEY_CONNECTED_TONE2
Setting CSB Enter Pairing Tone
The tone rings when the speaker enters CSB pairing.
;;help_end;;
TONE_CFG_KEY_CSB_ENTER_PAIRING_TONE
Setting CSB Connection Tone
The tone rings when the CSB link is connected.
If Master of CSB link is playing music at this moment, it won’t ring the tone.
;;help_end;;
TONE_CFG_KEY_CSB_CONNECTION_TONE
Setting CSB Disconnection Tone
The tone rings when the CSB link is disconnected.
;;help_end;;
TONE_CFG_KEY_CSB_DISCONNECTION_TONE
Enable Fix Ring Tone Volume
If this option is enabled (set to 1), the gain level of ring tone gain will use fixed value
(refer to the RingTone_Volume parameter). Otherwise, it has two conditions:
1. The ring tone volume will follow the volume of playing sound.
2. The ring tone gain level will use the level of SCO if no sound is playing.
;;help_end;;
FIX_RING_TONE_VOL_ENABLE
Ring Tone Volume
Gain level(0~15) for fix ring tone volume usage
1.If user enable "enable Fix Ring Tone Volume", then they can have different tone volume from current A2DP or HFP volume.
If this is disabled, then Ring Tone Volume item is not available.
2.User can change tone volume after they enable "enable Fix Ring Tone Volume"
;;help_end;;
TONE_CFG_KEY_RINGTONE_VOLUME
Enable Force All Button Alarm
Always ring a tone when button(s) is pressed.
The tone type depends on pressing behavior, it may be short press tone, long press tone and double click tone.
1:enabled, 0:disabled.
;;help_end;;
ALL_BUTTON_FORCE_ALARM_ENABLE
Enable Force Button_0 Alarm
Always ring a long press tone when button 0 is pressed over the time of Long_Button_Press_time parameter.
The button 0 is MFB button. 1: enabled, 0:disabled.
;;help_end;;
BUTTON_0_FORCE_ALARM_ENABLE
Enable Use Connected Tone2
0 : use dedicate profile connected tone setting
1 : use connected_tone2 as 2nd connected profile indication tone
;;help_end;;
ENABLE_USE_CONNECTED_TONE2
Report Battery Status By Voice Prompt
If this option is enabled, prompt battery status by tones when trigger MMI event "SHS_INDICATE_BATTERY_STATUS".
Otherwise, indicate battery status by LED.
;;help_end;;
ENABLE_VOICE_PROMPT_BATT_STATUS
Power On Prompt Battery Level
If this option is enabled, it will prompt battery status by tones when power on.
;;help_end;;
ENABLE_POWERON_PROMPT_BATT_LEVEL
Battery Detection Enable
Enable/Disable polling the battery voltage.
1: eanbled, 0:disabled.
;;help_end;;
ENABLE_BATTERY_VOLTAGE_DETECT
Low Battery Warning Level

The lowest voltage level that device can work well,when battery voltage is under this value,
device will generate some warning, such as tone, LED and buzzer (if buzzer is enabled).
Range:(3V-to-3.6V) or( 3000 to 3600)
Unit :Voltage, Size:2bytes
3000 (3.0V)
3100 (3.1V)
3200 (3.2V)
3300 (3.3V)
3400 (3.4V)
3500 (3.5V)
3600 (3.6V)
;;help_end;;
POWER_CFG_KEY_WARNING_BATTERY_LEVEL
Battery Shutdown Level

When the battery voltage level is lower this value, the speaker will shutdown automatically.
The value definitionl is the same with Warning_Battery_Level.
Range:(3V-to-3.6V) or( 3000 to 3600)
Unit :Voltage
3000 (3.0V)
3100 (3.1V)
3200 (3.2V)
3300 (3.3V)
3400 (3.4V)
3500 (3.5V)
3600 (3.6V)
;;help_end;;
POWER_CFG_KEY_SHUTDOWN_BATTERY_LEVEL
Low Battery Debounce
If this option is set to 1, the low battery warning will keep until power adaptor in or power cycle.
;;help_end;;
ENABLE_LOW_BATTERY_DEBOUNCE
Charger Detect
Enable/disable charger function.
1: enabled, 0: disabled.
;;help_end;;
ENABLE_CHARGER_DETECT
1st CC Maximum Charging Voltage
The max voltage of constant current charging stage 0.
Range:(2V-to-4.2V) or( 2000 to 4200)
Unit :Voltage. Size:2bytes
2000(2.0V)
2500(2.5V)
3000 (3.0V)
3100 (3.1V)
3200 (3.2V)
3300 (3.3V)
3400 (3.4V)
3500 (3.5V)
3600 (3.6V)
3700 (3.7V)
3800 (3.8V)
3900 (3.9V)
4000 (4.0V)
4100 (4.1V)
4200 (4.2V)
;;help_end;;
FIRST_STAGE_CC_MODE_MAX_VOLTAGE
1st Max Charging Time
When cc mode over protective time expired, charging will be completed and stop charging.
CC Mode protective timer stage 0 (unit in min). Range:0-254 Size 1 byte
;;help_end;;
FIRST_STAGE_CC_MODE_PROTECT_TIME
1st CC Charging Current Setting
Charging current for charging stage 0
Unit :mA
Range :0 - Max 350mA.
;;help_end;;
FIRST_STAGE_CC_MODE_CHARGING_CURRENT
2nd CC Maximum Charging Voltage
The max voltage of constant current charging stage 1.
Range:(2V-to-4.2V) or( 2000 to 4200)
Unit :Voltage. Size:2bytes
2000(2.0V)
2500(2.5V)
3000 (3.0V)
3100 (3.1V)
3200 (3.2V)
3300 (3.3V)
3400 (3.4V)
3500 (3.5V)
3600 (3.6V)
3700 (3.7V)
3800 (3.8V)
3900 (3.9V)
4000 (4.0V)
4100 (4.1V)
4200 (4.2V)
;;help_end;;
SECOND_STAGE_CC_MODE_MAX_VOLTAGE
2nd Max Charging Time
When cc mode over protective time expired, charging will be completed and stop charging.
CC Mode protective timer stage 1 (unit in min). Range:0-254 Size 1 byte
;;help_end;;
SECOND_STAGE_CC_MODE_PROTECT_TIME
2nd CC Charging Current Setting
Charging current for charging stage 1
Unit :mA
Range :0 - Max 350mA.
;;help_end;;
SECOND_STAGE_CC_CHARGING_CURRENT
3rd CC Maximum Charging Voltage
The max voltage of constant current charging stage 2.
Range:(2V-to-4.2V) or( 2000 to 4200)
Unit :Voltage. Size:2bytes
2000(2.0V)
2500(2.5V)
3000 (3.0V)
3100 (3.1V)
3200 (3.2V)
3300 (3.3V)
3400 (3.4V)
3500 (3.5V)
3600 (3.6V)
3700 (3.7V)
3800 (3.8V)
3900 (3.9V)
4000 (4.0V)
4100 (4.1V)
4200 (4.2V)
;;help_end;;
THIRD_STAGE_CC_MODE_MAX_VOLTAGE
3rd Max Charging Time
When cc mode over protective time expired, charging will be completed and stop charging.
CC Mode protective timer stage 2 (unit in min). Range:0-254 Size 1 byte
;;help_end;;
THIRD_STAGE_CC_MODE_PROTECT_TIME
3rd CC Charging Current Setting
Charging current for charging stage 2
Unit :mA
Range :0 - Max 350mA.
;;help_end;;
THIRD_STAGE_CC_MODE_CHARGING_CURRENT
4th CC Maximum Charging Voltage
The max voltage of constant current charging stage 3.
Range:(2V-to-4.2V) or( 2000 to 4200)
Unit :Voltage. Size:2bytes
2000(2.0V)
2500(2.5V)
3000 (3.0V)
3100 (3.1V)
3200 (3.2V)
3300 (3.3V)
3400 (3.4V)
3500 (3.5V)
3600 (3.6V)
3700 (3.7V)
3800 (3.8V)
3900 (3.9V)
4000 (4.0V)
4100 (4.1V)
4200 (4.2V)
;;help_end;;
FORTH_STAGE_CC_MODE_MAX_VOLTAGE
4th Max Charging Time
When cc mode over protective time expired, charging will be completed and stop charging.
CC Mode protective timer stage 3 (unit in min). Range:0-254 Size 1 byte
;;help_end;;
FOURTH_STAGE_CC_MODE_PROTECT_TIME
4th CC Charging Current Setting
Charging current for charging stage 3
Unit :mA
Range :0 - Max 350mA.
;;help_end;;
FORTH_STAGE_CC_MODE_CHARGING_CURRENT
Maximum Charging Time
Protect time in constant voltage charging mode(unit in min).
;;help_end;;
POWER_CFG_KEY_CV_PROTECT_TIME
Maximum CV Charging Current
Maximum charging current, when cc mode enter to cv mode
Unit :mA
(100 - Max 350mA)
;;help_end;;
POWER_CFG_KEY_MAX_CV_CHARGING_CURRENT
Stop Charging Current
Charging stops, when charging current less than the current.
Unit :mA
(0 - Max 80mA)
*Should not exceed min value of Max Charging current
;;help_end;;
POWER_CFG_KEY_CV_SOTP_CHARGING_CURRENT
First Half Battery Monitor Counter
If charging current during CV Mode is configured larger than 252 mA, this monitor counter will be applied.
Charging current decreases 8mA, if the voltage has been monitored exceeded the fourth stage of CC mode voltage up to mentioned battery monitor count.
Range : 1 ~ 20
Unit : 100ms
Count 1 is equal to = 100 msec.
;;help_end;;
POWER_CFG_KEY_CV_FIRST_HALF_BATTERY_MONITOR_COUNT
Second Half Battery Monitor Counter
If charging current is less than 252 mA, this monitor counter will be applied.
Charging current decreases 4mA if the voltage has been monitored exceeded the fourth stage of CC mode voltage up to mentioned battery monitor count.
Range : 1 ~ 20
Unit : 100ms
Count 1 is equal to = 100 msec.
;;help_end;;
POWER_CFG_KEY_CV_SECOND_HALF_BATTERY_MONITOR_COUNT
Maximum CV Re-charging Current
Maximum re-charging current.
Unit :mA
(0 - Max 350mA)
;;help_end;;
POWER_CFG_KEY_MAX_CV_RECHARGING_CURRENT
Continue Charging As Battery Full
If this option is set to 1,If the Battery detection is enabled in UI and battery voltage drops below 0.1V of the fourth stage of the CC charging,
the charging will restart based on UI parameter “Restart charging”.
(E.g.: If battery charging successful at 4.2V  then re-charging will start when the battery voltage drops to 4.1V).
;;help_end;;
CONTINUE_CHARGING_AS_BATTERY_FULL
Working Temperature
If this option is set to 1:
In operation mode: Once the ambient temperature is out of working temperature range,app code will process power off procedure.
In power off mode: If the ambient temperature is out of working temperature range, product powered on.
;;help_end;;
ENABLE_AMBIENTEMP_FOR_OPERATING
Stop Working SAR Min
The minimum SAR value for product working range.
The value represents temperature up to circuit design
0x00C3: 35 degree C
0x00A7: 40 degree C
0x0092: 45 degree C
0x0082: 50 degree C
0x0073: 55 degree C
;;help_end;;
POWER_CFG_KEY_STOP_WORKING_SAR_MIN
Stop Working SAR Max
The maximum SAR value for product working range.
The value represents temperature up to circuit design.
0x0331: -5 degree C
0x02B0: 0 degree C
0x0239: 5 degree C
0x01D6: 10 degree C
0x0186: 15 degree C
;;help_end;;
POWER_CFG_KEY_STOP_WORKING_SAR_MAX
Ambient Temperature Charging Detection
Enable ambient temperture detection in charging.
;;help_end;;
ENABLE_AMBIENT_TEMP_AS_CHARGING
Stop Charging SAR Min
The minimum SAR value for charger working range. The value represents temperature up to circuit design.
Degree:
0x00C3: 35 degree C
0x00A7: 40 degree C
0x0092: 45 degree C
0x0082: 50 degree C
0x0073: 55 degree C
Customize:0000~FFFF
;;help_end;;
POWER_CFG_KEY_STOP_CHARGING_SAR_MIN
Resart Charging SAR Min
The minimum SAR value of range to restart charging.
It is for ambient temperature detection function. If the temperature over working range,
it will stop charger and keep detecting the temperature and restart charger when the temperature back to this assigned range .
It needs hardware circuit support and translates the temperature to voltage.
Degree:
0x00E4: 35 degree C
0x00C3: 40 degree C
0x00A7: 45 degree C
0x0092 50 degree C
0x0082: 55 degree C
Customize:0000~FFFF
;;help_end;;
POWER_CFG_KEY_RESTART_CHARGING_SAR_MIN
Stop Charging SAR Max
The maximum SAR value for charger working range.
The value represents temperature up to circuit design.
Degree:
0x0331: -5 degree C
0x02B0: 0 degree C
0x0239: 5 degree C
0x01D6: 10 degree C
0x0186: 15 degree C
Customize:0000~FFFF
;;help_end;;
POWER_CFG_KEY_STOP_CHARGING_SAR_MAX
Resart Charging SAR Max
The maximum SAR value of range to restart charging. It is for ambient temperature detection function. If the temperature over working range,
it will stop charger and keep detecting the temperature and restart charger when the temperature back to this assigned range .
It needs hardware circuit support and translates the temperature to voltage.
Degree:
0x02B0: -5 degree C
0x0239: 0 degree C
0x01D6: 5 degree C
0x0186: 10 degree C
0x0144: 15 degree C
Customize:0000~FFFF
;;help_end;;
POWER_CFG_KEY_RESTART_CHARGING_SAR_MAX
Enable LR Sound Channel Swap
Swap left and right audio channel (only for A2DP) if this option is enabled (set to 1).
;;help_end;;
ENABLE_LR_SOUND_CHANNEL_SWAP
Enable LR Sound Mix
0x00 : The speaker outputs the audio from source without process.
0x01 : The speaker outputs left channel of audio source in both channels.
0x02 : The speaker outputs right channel of audio source in both channels.
0x03 : The speaker output the mixed audio of left and right channel.
;;help_end;;
AUD_MCU_CFG_KEY_AUDIO_OUTPUT_CHANNEL_STYLE
DSP CODEC Always On Enable
If this option is enabled (set to 1), it will never ask codec and DSP power down.
If this option is enabled (set to 1) and the MIC loopback is also enabled, it supports AMIC only and can not support DMIC input.
;;help_end;;
DSP_CODEC_ALWAYS_ON_ENABLE
Close CODEC Time
when DSP in SBC decode state, and FW do not receive any stream data,
FW will set this timer to cut off codec(unit in 640ms)
;;help_end;;
AUD_MCU_CFG_KEY_CLOSE_CODEC_TIME
CODEC Type
External Codec: Digital output, need an external codec.
Internal Codec: Analog output.
;;help_end;;
CODEC_OUTPUT_TYPE
Audio SRC
44.1K to 48K for A2DP audio if codec typs is I2S
;;help_end;;
AUDIO_SRC_ENABLE
Voice SRC
8K/16K to 48K for ring tone or SCO voice if codec typs is I2S
;;help_end;;
VOICE_SRC_ENABLE
Voice Stereo
Enable the function that voice outputs both of L and R channel.
;;help_end;;
VOICE_STEREO_ENABLE
Tone Stereo
Enable the function that single tone and VP output both of L and R channel.
;;help_end;;
TONE_STEREO_ENABLE
Output Volume Scaling Method
The output volume scaling method is to determine how to adjust volume.
0: Codec DAC gain,
1: I2S scale,
2: Codec DAC + I2S scale,
;;help_end;;
AUD_MCU_CFG_KEY_OUTPUT_VOLUME_SCALE_METHOD
Line In / SBC Priority
Enable this option to set the priority of Aux-in is higher than A2DP.
When Aux-in and A2DP streaming coexist,
the speaker will output the audio with higher priority.
;;help_end;;
ENABLE_LINE_IN_SUPPRESS_SBC
Line In Mute/Unmute
set this bit to 1 to mute/unmute the music from line-in when the priority of line-in is higher than A2DP or it has no A2DP link.
;;help_end;;
LINE_IN_MUTE_UNMUTE_CONTROL_ENABLE
Line In Silence Detect
Detect silence status for Aux-in signal if this option is enabled.
The duration to determine the Aux-in is silence is about 33 seconds.
0: disabled
1: enabled
;;help_end;;
ENABLE_LINE_IN_SILENCE_DETECTION
Line In Indicate LED
Use the GPIO pin to indicate Aux-in status if this option is enabled (set to 1).
The pin is low active, 0 means the speaker is in Aux-in mode. Please refer to GPIO configuration to check which pin is used for this function.
This one is effective only when you enable it and assign a GPIO in item "AUX-IN Led Ind".
;;help_end;;
DEDICATE_LINEIN_LED_ENABLE
Line In CSB
Enable MSPK Aux-in mode
;;help_end;;
ENABLE_AUX_IN_CSB
Line In Latency
Line-in latency adjustment. The latency is max to 80ms before firmware v1.3.4 and can be max to 160ms later than v1.3.4. (unit: 16 audio samples, 1/3 ms in 48K sample rate).
ex: 0xF0 => 240 * 1/3 = 80 ms
For usage in MSPK mode, only recommended to use 80ms (default) and above
For line-in loopback, <80ms is accepted
;;help_end;;
AUD_MCU_CFG_KEY_LINE_IN_LATENCY
Initial Line In SPK Gain
default gain level for line in mode
;;help_end;;
AUD_MCU_CFG_KEY_LINE_IN_GAIN
Enable MIC Loopback As Line In
Enable MIC input as Line-in and if this option is enabled (set to 1).
;;help_end;;
ENABLE_MIC_LOOPBACK_AS_LINE_IN
A2DP Mix Line-In Option
Select A2DP mix line-In feature option, include disable feature, default off and default on.
Once mix feature was enabled, A2DP priority is higher than Line-In no matter what "Line In / SBC Priority" option selected.
0x00 : Disable. Mix feature is disable.
0x01 : Default off. Mix feature is enable but only activated by MMI or UART command.
0x02 : Default on. Mix feature is enable and auto activated after power on.
;;help_end;;
A2DP_MIX_LINEIN_OPTION
Line-In ADC Input Gain Level
Line-In ADC Input gain level
;;help_end;;
LINE_IN_ADC_INPUT_GAIN_LEVEL
Line-in Sampling Rate
The line in sampling rate usage:
1. MSPK line-in mode supported : only 48K is allowed
2. A2DP Mix Line-In enabled : only 44.1K and 48K are allowed
3. AT TX mode : 44.1K and 48K can be selected
4. Loopback mode only: all sampling rate are supported
;;help_end;;
BT_CFG_KEY_LINE_IN_SAMPLING_RATE
Cut Off Amplifier When Mute
When the speaker stop outputing sound, the codec state will change from ACTIVE state to MUTE state and then wait about 10 seconds to enter RESET state.
It will cut off amplifier when codec enters MUTE state if this option is enabled (set to 1).
Otherwise, the speaker cuts off amplifier when CODEC is changing to RESET state.
;;help_end;;
ENABLE_CODEC_MUTE_TURN_OFF_AMP
Amplifier Control Time 0
When codec mute, set this timer to turn off amplifier, if this value set to 0, then turn off amplifier directly.
unit in 1s
;;help_end;;
AMP_CTRL_TIME_0
Enable SBC DECODE
Enable SBC DECODE. This is Mandatory chosen not alterable.
;;help_end;;
ENABLE_SBC_DECODE
Enable AAC DECODE
Enable AAC DECODE.
;;help_end;;
ENABLE_AAC_DECODE
Equalizer Function Enable
Audio TX equalizer. 0: disabled, 1: enabled
Audio equalizer does not support LDAC codec even this function is enabled.
;;help_end;;
ENABLE_AUDIO_TX_EQ
TX EQ MODE
default equalizer mode for audio
0:EQ_MODE_OFF,
1:EQ_MODE_SOFT,
2:EQ_MODE_BASS,
3:EQ_MODE_TREBLE,
4:EQ_MODE_CLASSICAL,
5:EQ_MODE_ROCK,
6:EQ_MODE_JAZZ,
7:EQ_MODE_POP,
8:EQ_MODE_DANCE,
9:EQ_MODE_RNB,
10:EQ_MODE_USER.
;;help_end;;
AUD_MCU_CFG_KEY_TX_EQ_MODE
Off
Off mode. 0: disabled, 1: enabled
;;help_end;;
EQ_MODE_OFF
Soft
Soft mode. 0: disabled, 1: enabled
;;help_end;;
EQ_MODE_SOFT
Bass
Bass mode. 0: disabled, 1: enabled
;;help_end;;
EQ_MODE_BASS
Treble
Treble mode. 0: disabled, 1: enabled
;;help_end;;
EQ_MODE_TREBLE
Classic
Classical mode. 0: disabled, 1: enabled
;;help_end;;
EQ_MODE_CLASSICAL
Rock
Rock mode. 0: disabled, 1: enabled
;;help_end;;
EQ_MODE_ROCK
Jazz
Jazz mode. 0: disabled, 1: enabled
;;help_end;;
EQ_MODE_JAZZ
Pop mode
Pop mode. 0: disabled, 1: enabled
;;help_end;;
EQ_MODE_POP
Dance
Dance mode. 0: disabled, 1: enabled
;;help_end;;
EQ_MODE_DANCE
RnB
R&B mode. 0: disabled, 1: enabled
;;help_end;;
EQ_MODE_RNB
Custom
Customized EQ by users. 0: disabled, 1: enabled
;;help_end;;
EQ_MODE_USER
CVSD Speaker EQ
Speaker EQ index.
;;help_end;;
AUD_MCU_CFG_KEY_CVSD_TX_EQ_MODE
CVSD MIC EQ
MIC EQ index.
;;help_end;;
AUD_MCU_CFG_KEY_CVSD_RX_EQ_MODE
mSBC Speaker EQ
Speaker EQ index.
;;help_end;;
AUD_MCU_CFG_KEY_MSBC_TX_EQ_MODE
mSBC MIC EQ
MIC EQ index.
;;help_end;;
AUD_MCU_CFG_KEY_MSBC_RX_EQ_MODE
ADC Path
reference to DSP document
Bit 0~3:dolphin DAC output selection
0:none(ADC off)
1:Reserved
2:Reserved
3:Single channel(MIC2 to L).
4:Dual channel(MIC2 to L, MIC1 to R).
5:Single channel(MIC1 to L).
6:Dual channel(MIC1 to L, MIC2 to R).
7:Codec Bypass: MIC1 to L channel MIC2 to R channel.
8:Codec Bypass: MIC2 to L channel MIC1 to R channel.
Bit 4:ADC off.
Bit 5: 0.
Bit 6:switch on the Mic bias current
(Set as 0 in case of digital mic; Set as 1 in case of analog mic)
Bit:7: 0.
;;help_end;;
AUD_MCU_CFG_KEY_CODEC_ADC_PATH
Digital Mic
Enable/Disable digital microphone. 0:digital mic disabled, 1:digital mic enabled
;;help_end;;
ENABLE_DIGITAL_MIC
Digital Mic Mode
The same with the 10th byte of  AUD_MCU_CFG_KEY_CODEC_PARAMETER.
0b000 : Mono Raising
0b001 : Mono Falling
0b100 : L Rising - R Falling stereo
0b101 : L Falling - R Rising stereo
This one is efective only if option item "Digital Mic" chosen "Enable".
;;help_end;;
DIGITAL_MIC_MODE
Analog Microphone Gain Level
Microphone gain level. This one is efective only if option item "Digital Mic" chosen "Disable".
;;help_end;;
AUD_MCU_CFG_KEY_MICROPHONE_GAIN_LEVEL
Digital Microphone Gain Level
Microphone digital gain level
Range: 0x00 ~0x0F (16 levels); 0x00 means mute.
This one is efective only if option item "Digital Mic" chosen "Enable".
;;help_end;;
AUD_MCU_CFG_KEY_MICROPHONE_DIGITAL_GAIN_LEVEL
Enable Auto Launch APP
Enable to send APP launch request to auto lauch APP after identification and authentication process complete.
;;help_end;;
iAP_AUTO_LAUNCH_APP_ENABLE
iAP
Response iAP in SDP query, The speaker support Apple iAP protocol if this bit is enabled (set to 1).
;;help_end;;
RSP_SDP_IAP
Bundle Seed ID Pref Token
This string identifies the accessory’s preferred application.
;;help_end;;
IAP_CFG_KEY_BONDLESEEDIDPREFTOKEN
SDK Protocol Token
This information is used to establish communication channels to the application.
;;help_end;;
IAP_CFG_KEY_SDKPROTOCOLTOKEN
APP Bundle ID
The accessory sends this command to an iPod to request that it launch a specific application. The accessory passes an Application Bundle ID string,
such as 'com.mycompany.myapp', to specify which application to launch.
;;help_end;;
IAP_CFG_KEY_APPBUNDLE_ID
Accessory Name
Accessory name(in ASCII).
;;help_end;;
IAP_CFG_KEY_ACC_NAME
Accessory Firmware Version
Accessory firmware version.
;;help_end;;
IAP_CFG_KEY_ACC_FW_VER
Accessory Hardware Version
Accessory hardware version.
;;help_end;;
IAP_CFG_KEY_ACC_HW_VER
Accessory Manufacturer
Accessory manufacturer(in ASCII).
;;help_end;;
IAP_CFG_KEY_ACC_MANU
Accessory Model Number
Accessory model number(in ASCII).
;;help_end;;
IAP_CFG_KEY_ACC_MODEL_NUM
Accessory Serial Number
Accessory serial number(in ASCII).
;;help_end;;
IAP_CFG_KEY_ACC_SERIAL_NUM
SDK Protocol Token2
This information is used to establish communication channels to the application.
This is for the second data section.
;;help_end;;
IAP_CFG_KEY_SDKPROTOCOLTOKEN2
Accessory Product Plan UID
accessory's 16 character Product Plan UID.
;;help_end;;
IAP_CFG_KEY_PRODUCT_PLAN_UID
Transparent Service UUID
The UUID of transparent service
;;help_end;;
BLE_CFG_KEY_TRANSPARENT_SRV_UUID
Transparent TX UUID
The UUID of transparent TX characteristic
;;help_end;;
BLE_CFG_KEY_TRANSPARENT_TX_UUID
Transparent RX UUID
The UUID of transparent RX characteristic
;;help_end;;
BLE_CFG_KEY_TRANSPARENT_RX_UUID
Authentication Request
Set to 1 to enable authentication for transparent service
;;help_end;;
AUTH_REQUEST_IN_TRANSPARENT
BLE Application in Embedded Mode

;;help_end;;
ENABLE_BLE_APPLICATION
Connected TX Power Level.
The BLE connected TX power level. Level 0 ~ 6 (max)
The max reference power is 5 dBm and decrease 5 dBm for each following level.
The actual power is upon calibration in MP process.
;;help_end;;
BLE_CONNECTED_RF_TX_POWER_LEVEL
Advertising TX Power Level.
The ADV TX power level. Level 0 ~ 6 (max)
The max reference power is 5 dBm and decrease 5 dBm for each following level.
The actual power is upon calibration in MP process.
;;help_end;;
BLE_ADV_RF_TX_POWER_LEVEL
Google Fast Pair
Enable or disable Google Fast Pair.
;;help_end;;
ENABLE_GOOGLE_FAST_PAIR
Google Fast Pair Model ID
Each provider device has a 24-bit model ID,
which is provided by Google during model registration.
;;help_end;;
BT_CFG_KEY_GFPS_MODELID
Google Fast Pair Private Key
A 256-bit Anti-Spoofing Private Key distributed from Google
after model registration.
;;help_end;;
BT_CFG_KEY_GFPS_PRIVATE_KEY
Google Fast Pair TX Power
TX Power shown on Google Fast Pair Advertising.
;;help_end;;
BT_CFG_KEY_GFPS_TX_POWER
Battery Notification
Enable or disable Battery Notification for Non-discoverable advertising.
;;help_end;;
ENABLE_BATTERY_NOTIFICATION
ADV DATA
LE advertising data. The max length is 0x1C
Format:
{
{(u8) length1, (u8) type1, data1[length1]},
{(u8) length2, (u8) type2, data2[length2]},
...
}
;;help_end;;
BLE_CFG_KEY_ADV_DATA
Beacon data in advertising data.

;;help_end;;
BEACON_DATA_IN_ADV_DATA
SCAN RSP DATA
LE scan response data. The max length is 0x1F
Format:
{
{(u8) length1, (u8) type1, data1[length1]},
{(u8) length2, (u8) type2, data2[length2]},
...
}
;;help_end;;
BLE_CFG_KEY_SCAN_RSP_DATA
Beacon data in scan resp data.

;;help_end;;
BEACON_DATA_IN_SCAN_RESP_DATA
LE Reconnection Timeout
If no data is transmitted over this time, disconnect LE connection.
Unit:min, 0 means this function is disabled.
;;help_end;;
BLE_CFG_KEY_AUTO_DISCONNECT_TIME
Min. LE Connection Interval
This parameter is used to set LE min connection interval if EMBEDDED_SPP_ENABLE is enabled.
The value 0x0000 means Dual Speaker won't issue parameter update request command.
Valid range:0x0000, 0x0008~0x0C80
Unit: 1.25ms
;;help_end;;
BLE_CFG_KEY_CONNECTION_INTERVAL_MIN
Max. LE Connection Interval
This parameter is used to set LE max connection interval if EMBEDDED_SPP_ENABLE is enabled.
The value 0x0000 means Dual Speaker won't issue parameter update request command.
Valid range:0x0000, 0x0010~0x0C80
Unit: 1.25ms
;;help_end;;
BLE_CFG_KEY_CONNECTION_INTERVAL_MAX
LE Slave Latency
This parameter is used to set LE slave latency
;;help_end;;
BLE_CFG_KEY_SLAVE_LATENCY
LE Supervision Timeout
This parameter is used to set LE supervision timeout
Unit: 10ms
Apple recommended parameters:
* connectionIntervalMax * (slaveLatency + 1) <= 2 seconds
* connectionIntervalMin >= 20 ms
* connectionIntervalMin + 20 ms <= connectionIntervalMax
* slaveLatency <= 4
* supervisionTimeout <= 6 seconds
* connectionIntervalMax * slaveLatency + 1) * 3 < supervisionTimeout
If the parameters don't follow these rules, iOS may reject the connection parameter update request.
;;help_end;;
BLE_CFG_KEY_SUPERVISION_TIMEOUT
Manufacture Name
This parameter is used to configure the name of the manufacturer of the device
;;help_end;;
BLE_CFG_KEY_MANUFACTURE_NAME_STRING
Model Name
Thisparameter is used to configure the model number that is assigned by the device vendor
;;help_end;;
BLE_CFG_KEY_MODEL_NAME_STRING
Serial Number
This parameter is used to configure the serial number for a particular instance of the device.
;;help_end;;
BLE_CFG_KEY_SERIAL_NUMBER_STRING
Software Revision
This parameter is used to configure the software revision for the software within the device
;;help_end;;
BLE_CFG_KEY_SOFTWARE_REVISION_STRING
LE Fast Advertising Timeout
the advertising timeout for fast advertising (shorter advertising interval)
0: no timeout
unit: 10.24ms
It's used only if  EMBEDDED_SPP_ENABLE is enabled
;;help_end;;
BLE_CFG_KEY_FAST_ADV_TIMEOUT
LE Reduced Power Advertising Timeout
the advertising timeout for reduced power advertising (longer advertising interval)
0: no timeout
unit: 10.24s
It's used only if EMBEDDED_SPP_ENABLE is enabled
;;help_end;;
BLE_CFG_KEY_REDUCED_POWER_ADV_TIMEOUT
LE Reduced Power Advertising Interval
reduced power advertising interval
unit: 0.625ms
It's used only if EMBEDDED_SPP_ENABLE is enabled
;;help_end;;
BLE_CFG_KEY_REDUCED_POWER_ADV_INTERVAL
Enable MSPK Role By Config Setting
This option is to pre-assign MSPK role in configuration settings. If this option is enabled (set to 1),
it will check MSPK_MASTER_BY_CONFIG and MSPK_SLAVE_BY_CONFIG option to determine which role should be used when the speaker power on.
;;help_end;;
ENABLE_MSPK_ROLE_BY_CONFIG_SETTING
Enable MSPK Back To Last Mode
If this option is enabled (set to 1), the speaker will store the MSPK role in configuration when it power off.
Once the speaker power on again, the role and CSB link will be recovered if need.
All above three options are checked when the speaker power on. If they conflict, the highest priority is MSPK_ROLE_BY_CONFIG_SETTING,
second is MSPK_ROLE_BY_GPIO and the last is MSPK_BACK_TO_LAST_MODE.
;;help_end;;
ENABLE_MSPK_BACK_TO_LAST_MODE
Predefined MSPK Master By Config Setting
Predefine MSPK role as master role. This is used when the option
ENABLE_MSPK_ROLE_BY_CONFIG_SETTING is enabled.
;;help_end;;
MSPK_MASTER_BY_CONFIG
Predefined MSPK Slave By Config Setting
Predefine MSPK role as slave role. This is used when the option
ENABLE_MSPK_ROLE_BY_CONFIG_SETTING is enabled.
;;help_end;;
MSPK_SLAVE_BY_CONFIG
MSPK Pairing Duration
The CSB pairing timeout. Unit: 5s
;;help_end;;
MSPK_CFG_KEY_CSB_SYNC_TIMEOUT
MSPK Aux. Pairing Duration
The CSB pairing timeout of Slave role in One_Key_Operation.
When the One_Key_Operation is triggered, it enters CSB pairing as Slave role first
and then change to Master role after this timeout occurs.
Unit 2s
;;help_end;;
MSPK_CFG_KEY_CSB_SYNC_ONEKEY_SLAVE_TIMEOUT
General MSPK Mode Group Code
The group code for general CSB pairing.
1. This is used to ensure the device which has the same Group code can pair
with others.
2. It is just for concert mode, that means you can have more than 1 slaves.
;;help_end;;
MSPK_CFG_KEY_CSB_GROUP_ID
Stereo Mode Model ID
The model ID is used with MSPK_CFG_KEY_CSB_GROUP_ID as a group ID for Stereo Mode.
1. This is used to ensure the device which has the same Group code can pair
with others.
2. It is just for stereo mode, that means you can just have 1 slave.
;;help_end;;
MSPK_CFG_KEY_MODEL_ID
Recover MSPK Link As Link Loss
If this option is enabled (set to 1), the speaker will try to recover the CSB link
when the CSB link disconnects abnormally. Only for Stereo mode.
;;help_end;;
MSPK_RECOVERY_CSB_LINK_AS_LINKLOSS
Default MSPK Mode
Use to indicate current CSB mode.
0: Stereo mode.
1: Concert mode.
;;help_end;;
DEFAULT_MSPK_MODE
Concert Mode Resync
Enable audio resync function in Concert Mode.
This one is used to sync the audio output of the concert mode Master and Slave.
;;help_end;;
ENABLE_CONCERT_MODE_RESYNC
Enable Back To Last Mode for Concert Mode
Enable Back To Last Mode for Concert Mode
;;help_end;;
ENABLE_CONCERT_BACK_To_LAST_MODE
ADV Policy in Concert Slave.
The Advertising policy for the Concert Mode Slave.
0000 - Disable (No BLE Advertising in Concert Mode Slave)
0001 - Non-Connectable Advertising in Concert Mode Slave
0010 - Scannable Advertising in Concert Mode Slave
0011 - Connectable Advertising in Concert Mode Slave
;;help_end;;
CONCERT_MODE_SLAVE_ADV_POLICY
ADV Policy in Stereo Slave.
The Advertising policy for the Stereo Mode Slave.
0000 - Disable (No BLE Advertising in TWS Slave)
0001 - Non-Connectable Advertising in TWS Slave
0010 - Scannable Advertising in TWS Slave
0011 - Connectable Advertising in TWS Slave
;;help_end;;
STEREO_MODE_SLAVE_ADV_POLICY
A2DP Latency
a2dp latency, unit: ms
For Single mode, Stereo mode: recommended 240ms (editable in configure tool)
For Concert mode: add extra 100ms based on above latency
If lower latency is used, audio performance may be affected
Shorter latency might be easier to cause sound breaks and less anti-interference.
;;help_end;;
AUD_MCU_CFG_KEY_A2DP_LATENCY
Enable AAC Codec in MSPK
enable AAC codec in MSPK.
;;help_end;;
ENABLE_AAC_IN_CSB
Save MSPK Role When Connected
Save MSPK role setting once CSB is connected.
;;help_end;;
SAVE_MSPK_ROLE_WHEN_CONNECTED
MSPK Power Saving Grouping Interval
CSB Maseter power saving (endless grouping) connection interval (unit: 625us).
;;help_end;;
MSPK_CFG_KEY_CSB_POWER_SAVING_CONN_INT
Enable Audio Seamless Resync
Enable seamless audio resync that can keep audio sync
in CSB master and other slaves with audio breaks
when a new slave is added.
;;help_end;;
ENABLE_SEAMLESS_AUDIO_RESYNC
Allow Voice Prompt in MSPK Slave
Set this option to allow voice prompt in MSPK slave(s).
Please note that it might cause audio unsync after MSPK slave rings voice prompts
;;help_end;;
ENABLE_VP_TONE_IN_MSPK_SLAVE
Endless Grouping GAC Interval
CSB endless grouping connection GAC interval (unit: 5sec)
1.This is used to let Master add new Slave(s)
2.If you enable the below item, the Master will periodically wait for new slave(s)
to join in the Concert mode.
(refer to item name : "Enable Concert Mode Master SPK Endless Grouping")
Please find the details in document "AN3118"
;;help_end;;
Endless_Grouping_GAC_Interval
Endless Grouping DAC Interval
CSB endless grouping connection DAC interval (unit: 5sec)
1. This is used to let a slave can link back to Master.
2. If you enable the below item, the Master will periodically wait for the slave(s)
to join in the Concert mode.
(refer to item name : "Enable Concert Mode Master SPK Endless Grouping")
Please find the details in document "AN3118"
;;help_end;;
Endless_Grouping_DAC_Interval
Enable Concert Mode Master SPK Endless Grouping
Enable Concert mode Master SPK Endless Grouping.
;;help_end;;
ENALBE_CONCERT_MODE_ENDLESS_GROUPING
Enable Slave Concert Mode Endless Grouping
Enable Concert mode Slave SPK Endless Grouping.
;;help_end;;
ENALBE_SLAVE_CONCERT_MODE_ENDLESS_GROUPING
Enable Link back BT in MSPK Aux-in mode
Enable Link back BT in MSPK Aux-in mode, this will impact Aux-in CSB performance if enabled.
;;help_end;;
ENABLE_BT_LINKBACK_IN_AUX_IN_CSB
MSPK Audio Channel
audio channel setting for multi-speaker
Bit0 ~ bit3: the channel setting for Slave role in multi-speaker, the range is 0 ~ 3
Bit4 ~ bit7: the channel setting for Master role in multi-speaker, the range is 0 ~ 3
The channel definition:
0: No Mixing, (L, R)
1: only output audio from left channel ,(L, L)
2: only output audio from right channel, (R,R)
3: mix the audio of left channel and right channel, ( (L + R)/2 , (L + R)/2 )
;;help_end;;
MSPK_CFG_KEY_NSPK_CHANNEL
MSPK SHS STATE AFTER CSB MASTER OK
Bit[0:1] The action after CSB link is created while CSB connection process is triggered in SHS STANDBY.
Bit[2:3] The action after CSB link is created while CSB connection process is triggered in SHS CONNECTED.
Bit[4:5] The action after CSB link is created while CSB connection process is triggered in SHS PAGING.
Bit[6:7] The action after CSB link is created while CSB connection process is triggered in SHS PAIRING.
Actions for above options.
00: enter SHS STANDBY mode.
01: reconnect to last device if have and go to SHS CONNECTED mode.
10: reconnect to last device if have.
11: enter SHS PAIRING mode.

;;help_end;;
MSPK_CFG_KEY_SHS_STATE_AFTER_CSB_MASTER_OK
MSPK SHS STATE AFTER CSB NG
Bit[0:1] The action after CSB creation fails or CSB link disconnects while CSB connection process is triggered in SHS STANDBY.
Bit[2:3] The action after CSB creation fails or CSB link disconnects while CSB connection process is triggered in SHS CONNECTED.
Bit[4:5] The action after CSB creation fails or CSB link disconnects while CSB connection process is triggered in SHS PAGING.
Bit[6:7]  The action after CSB creation fails or CSB link disconnects while CSB connection process is triggered in SHS PAIRING.
Actions for above options.
00: enter SHS STANDBY mode.
01: reconnect to last device if have and go to SHS CONNECTED mode.
10: reconnect to last device if have.
11: enter SHS PAGING mode
;;help_end;;
MSPK_CFG_KEY_SHS_STATE_AFTER_CSB_NG
Sound Effect
The drop-down list disables/enables the checkboxes "Audio Effect Mask Selection".
Please enable "Sound effect" to use existing audio effects.
Note : Audio effect does not support LDAC codec even this function is enabled.
;;help_end;;
ENABLE_SOUND_EFFECT
All Off
All audio effect are disabled.
;;help_end;;
ALL_AUDIO_EFFECT_OFF
MB-DRC
Enable MB-DRC function.
;;help_end;;
ENABLE_AUDIO_EFFECT_MBDRC
AW
Enable AW function.
;;help_end;;
ENABLE_AUDIO_EFFECT_AW
All On
All audio effect are enabled.
;;help_end;;
ALL_AUDIO_EFFECT_ON
Default Audio Effect
The checkboxes are used to set the default Audio Effect mode after the device is powered on.
;;help_end;;
AUD_MCU_CFG_KEY_EFFECT
AEC MODE
The drop-down list disables/enables AEC/AES(Acoustic Echo Cancellation/Acoustic Echo Suppression)
on Voice function page on DSP Tool panel.
;;help_end;;
AUD_MCU_CFG_KEY_AEC_MODE
NR Function Enable
This drop-down list disables/enables NR(Noise Reduction) on
Voice function page on DSP Tool panel.
Note: You have to disable the NR/AEC function on phone by the following steps:
Sys. Setup2 -> "Phone Provide NR and EC Function": Disable.
;;help_end;;
ENABLE_CVSD_RX_NR
Default Gain Level
the gain level for audio
;;help_end;;
THE_GAIN_LEVEL_FOR_AUDIO
AUDIO GAIN TABLE
Audio speaker gain
;;help_end;;
AUD_MCU_CFG_KEY_AUDIO_GAIN_TABLE
Default Gain Level
the gain level for voice
;;help_end;;
THE_GAIN_LEVEL_FOR_VOICE
VOICE GAIN TABLE
voice speaker gain
;;help_end;;
AUD_MCU_CFG_KEY_VOICE_GAIN_TABLE
Output I2S Gain Table
he output I2S gain table.
;;help_end;;
AUD_MCU_CFG_KEY_OUTPUT_I2S_GAIN_TABLE
