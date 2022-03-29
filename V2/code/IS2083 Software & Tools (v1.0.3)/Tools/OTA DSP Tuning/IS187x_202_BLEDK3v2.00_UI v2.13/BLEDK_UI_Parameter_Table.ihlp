99
Name
Help;;help_end;;
ID
Name Fragment
NameFragment is a local device name. If a remote device requires a local name, a local device replies the local device name.;;help_end;;
IDC_STATIC_NAME_FRAGMENT
HCI Baud Rate Index
Baud rate index of the HCI UART port.;;help_end;;
IDC_STATIC_HCI_BAUD_RATE_INDEX
H/W Flow Control
UART H/W flow control (CTS).
This parameter need to be set as disable if MCU not support flow control.
If Operation Pattern select Manual Pattern, the flow control will be set as disable automatically.;;help_end;;
IDC_STATIC_CTS_RTS_FLOW_CONTROL
Rx Notify Length
The time interval that BLEDK3 checks the received data buffer.
When set as IDC_STATIC_CHECK_RX_DATA_INTERVAL
UART RX_IND
Enable / Disable UART RX IND ;;help_end;;
IDC_STATIC_UART_RX_IND
UART Parity
Enable/Disable UART parity.;;help_end;;
IDC_STATIC_UART_PARITY
Parity Mode
;;help_end;;
IDC_STATIC_UART_PARITY_MODE
Stop Bit
;;help_end;;
IDC_STATIC_STOP_BIT
Operation Pattern
This parameter is used to set the operation pattern between Auto Pattern and Manual Pattern.;;help_end;;
IDC_STATIC_OPERATION_PATTERN
Configure Mode Timeout
This parameter is used to set BLEDK3 configure mode timeout period in Auto Pattern Tool option.;;help_end;;
IDC_STATIC_CONFIGURE_MODE_TIMEOUT
Power On Standby Time
The standby time duration after power on.
Device will enter Shut Down mode when time is up.
0x00~0xFE: Standby time parameter range.
0xFF: Disable Enter shut down mode.;;help_end;;
IDC_STATIC_POWER_ON_STANDBY_TIME
Disconnection Standby Time
The standby time duration after link disconnected.
Device will enter shut down mode when time is up.
0x00~0xFE: Standby time parameters.
0xFF: Disable enter shut down mode.;;help_end;;
IDC_STATIC_REMOTE_DISCONNECT_STANDBY_TIME
Wakeup Externel MCU Wait Time
The time interval between UART_TX_IND enabled and UART_TXD start transmit data.;;help_end;;
IDC_STATIC_WAKEUP_EXTERNAL_MCU_WAIT_TIME
Wakeup Pin Option
This parameter is used to decide BLEDK3 can be woken up from shutdown mode by wakeup pin or not. If option is enabled, GPIO P2_3 will be configured as wakeup Pin.;;help_end;;
IDC_STATIC_WAKEUP_PIN_OPTION
Inquiry Timeout Value
;;help_end;;
IDC_STATIC_INQUIRY_TIMEOUT_VALUE
Specific Pattern
This parameter is used to configure specific pattern for auto connection feature.;;help_end;;
IDC_STATIC_MANUFACTURE_DATA
BLE Security
This parameter is used to set BLE Security. Refer to BLUETOOTH SPECIFICATION 4.0 or latest version for the detail.;;help_end;;
IDC_STATIC_BLE_SECURITY
Trust Device Connection
This parameter is used to enable/disable trust (paired) device connection.;;help_end;;
IDC_STATIC_TRUST_DEVICE_CONNECTION
IO Capability
This parameter is used to configure IO Capability. Refer to BLUETOOTH SPECIFICATION 4.0 or latest version for the detail.;;help_end;;
IDC_STATIC_IO_CAPABILITY
BLE User Confirm Option
This parameter is used to enable/disable LE(Low Energy) user confirmation referring to passkey. The passkey must set 6 digits if enabled.;;help_end;;
IDC_STATIC_BLE_USER_CONFIRM_OPTION
Passkey
The Passkey which is six byte ASCII code and be used in passkey confirm.;;help_end;;
IDC_STATIC_PASSKEY
LE Secure Connections Only Mode
This parameter is used to enable/disable bluetooth 4.2 LE secure connections only mode.;;help_end;;
IDC_STATIC_LE_SECURE_CONNECTIONS
Privacy
If enabled the option, BLEDK3 will broadcast random address.;;help_end;;
IDC_STATIC_PRIVACY
Random Address Interval
This parameter is used to configure random address interval.
Valid only when "Privacy" is enabled.;;help_end;;
IDC_STATIC_PRIVATE_ADDRESS_DIVERSIFICATION_TIME
Manual Handle Value Confirmation
This parameter is used to enable/disable Manual Handle Value Conrifmation.If this parameter is enable, ATT stack will be configured as manual transmission of confirmation when an indication is received. ;;help_end;;
IDC_STATIC_ATT_SETTING1
 eFlash Footprint
The 16 ASCII characters for the customers' version control code. The download tool can check by this code and reject to download the eFlash if it's mismatch.;;help_end;;
IDC_STATIC_FOOTPRINT
Link Quality Detection
Enable/Disable link quality detection.
The RF_Tx_Power_Control_feature will be disabled if Enable this parameter.;;help_end;;
IDC_STATIC_LINK_QUALITY_DETECTION
RSSI Normal Threshold
RSSI: RF Signal Strength Indication. This parameter is used to set RSSI normal threshold value
If detected RSSI value greater or lower than normal threshold level, the configured RSSI_IND GPIO pin will output high or low level respectively.;;help_end;;
IDC_STATIC_RSSI_NORMAL_THRESHOLD
RSSI Weak Threshold
If detected RSSI value greater or lower than weak threshold level, the configured RSSI_IND GPIO pin will output high or low level respectively.;;help_end;;
IDC_STATIC_RSSI_WEAK_THRESHOLD
Battery Detection  Interval
This parameter is used to set battery detection interval.;;help_end;;
IDC_STATIC_BATTERY_DETECTION
High Battery Level
High battery level.;;help_end;;
IDC_STATIC_HIGH_BATTERY_LEVEL
Normal Battery Level
This parameter is defined a normal voltage value of a battery. When the voltage is lower than this value,the device will start low battery warring.;;help_end;;
IDC_STATIC_NORMAL_BATTERY_LEVEL
Low Battery Level
This parameter is defined a low voltage value of a battery. When the voltage is lower than this value, the configured IDC_STATIC_LOW_BATTERY_LEVEL
Dangerous Battery Level
When the voltage is lower than Dangerous Battery Level, the device will enter shutdown mode.;;help_end;;
IDC_STATIC_DANGEROUS_BATTERY_LEVEL
Low Battery Into Shutdown Time
This parameter is used to set the waiting time befor enter into shutdown mode if low battery happens.
(0x00: Disable enter into shutdown mode when low battery happens);;help_end;;
IDC_STATIC_LOW_BATTERY_INTO_POWER_DOWN_TIME
RF Class
The RF_Class is the RF class type. If class 1 is selected, GPIO P1_0 and P2_4 will be set as TX and RX control respectively (High Enable).;;help_end;;
IDC_STATIC_RF_CLASS
P36
Configure function to the GPIO pins. For detail description please refer to the BLEDK3 release note in IDC_STATIC_P36
P10
;;help_end;;
IDC_STATIC_P10
P00
;;help_end;;
IDC_STATIC_P00
P31
;;help_end;;
IDC_STATIC_P31
P32
;;help_end;;
IDC_STATIC_P32
P33
;;help_end;;
IDC_STATIC_P33
P34
;;help_end;;
IDC_STATIC_P34
P07
;;help_end;;
IDC_STATIC_P07
P11
;;help_end;;
IDC_STATIC_P11
P22
;;help_end;;
IDC_STATIC_P22
P24
;;help_end;;
IDC_STATIC_P24
P35
;;help_end;;
IDC_STATIC_P35
P12
;;help_end;;
IDC_STATIC_P12
P13
;;help_end;;
IDC_STATIC_P13
P16
;;help_end;;
IDC_STATIC_P16
P17
;;help_end;;
IDC_STATIC_P17
LE Connection Parameter Update Request
The LE Connection Setting will be assigned by remote side if select disable.
If Enable, device will sent the LE connection parameter update request.;;help_end;;
IDC_STATIC_LE_CONNECTION_PARAMETER_UPDATE
Min LE Connection Interval
This parameter is used to set LE min connection interval;;help_end;;
IDC_STATIC_MIN_LE_CONNECTION_INTERVAL
Max LE Connection Interval
This parameter is used to set LE max connection interval;;help_end;;
IDC_STATIC_MAX_LE_CONNECTION_INTERVAL
LE Slave Latency
This parameter is used to set LE slave latency.
Slave Latency allows a slave to use a reduced number of connection events.
The LE Slave Latency parameter defines the number of consecutive connection events that the slave device 
is not required to listen for the master.
More latency, more power saving but reduced connection event.

For example,
If slave latency=3, Connection event interval is 100msec,
Slave device will wake up every 400msec. (100*(1+3)=400). 
That is slave only has one Connection event while master already have three connection events.;;help_end;;
IDC_STATIC_LE_SLAVE_LATENCY
LE Supervision Timeout
This parameter is used to set LE supervision timeout ;;help_end;;
IDC_STATIC_LE_SUPERVISION_TIMEOUT
LE Fast Advertising Interval
This parameter is used to set IDC_STATIC_LE_FAST_ADVERTISING_INTERVAL
LE Reduced Power Advertising Interval
This parameter is used to set LE reduced power advertising interval. The interval is longer than IDC_STATIC_LE_REDUCED_POWER_ADVERTISING
LE Fast Advertising Timeout
This parameter is uesd to set LE fast advertising timeout value;;help_end;;
IDC_STATIC_LE_FAST_ADVERTISING_TIMEOUT
Power On LE Reduced Power Advertising Timeout
This parameter is uesd to show Power On LE Reduced Power Advertising timeout value.
Power On LE Reduced Power Advertising timeout = Power on Standby Time - LE Fast Advertising Timeout.;;help_end;;
IDC_STATIC_POWER_ON_LE_REDUCED_POWER_ADVERTISING_TIMEOUT
Disconnection LE Reduced Power Advertising Timeout
This parameter is uesd to show Disconnection LE Reduced Power Advertising Timeout value.
Disconnection LE Reduced Power Advertising Timeout  = Disconnection Standby Time - LE Fast Advertising Timeout;;help_end;;
IDC_STATIC_DISCONNECTION_LE_REDUCED_POWER_ADVERTISING_TIMEOUT
Advertising Prefered Power Level
Preferred Tx power level when advertising. There are six power level can be selected.(0,-5,-10,-15,-20,-25 dBm);;help_end;;
IDC_STATIC_ADVERTISING_TX_POWER_LEVEL
Connected Prefered Power Level
Preferred TX power level when connected. (0,-5,-10,-15,-20,-25 dBm);;help_end;;
IDC_STATIC_CONNECTED_TX_POWER_LEVEL
Advertising Data Setting
This parameter is uesd to set advertising data.;;help_end;;
IDC_STATIC_ADVERTISING_DATA_SETTING
Scan Response Data Setting
This parameter is uesd to set scan response data;;help_end;;
IDC_STATIC_SCAN_RESPONSE_DATA_SETTING
Type
The LED0(P0_2)display type setting for Standby, Link, Power On and Low Battery mode. There are 3 types are selectable: Always OFF, Always ON and Flash. The Flash method is set as below:;;help_end;;
IDC_STATIC_LED_TYPE
On Duration
The LED on time during flash.;;help_end;;
IDC_STATIC_LED_ON_TIME
Off Duration
The LED off time during flash.;;help_end;;
IDC_STATIC_LED_OFF_TIME
Count
This is the number of the flashing times for a cycle.;;help_end;;
IDC_STATIC_LED_COUNT
Interval
This is the time interval of a cycle.;;help_end;;
IDC_STATIC_LED_INTERVAL
Type
The LED0(P0_2)display type setting for Standby, Link, Power On and Low Battery mode. There are 3 types are selectable: Always OFF, Always ON and Flash. The Flash method is set as below:;;help_end;;
IDC_STATIC_LED_TYPE
On Duration
The LED on time during flash.;;help_end;;
IDC_STATIC_LED_ON_TIME
Off Duration
The LED off time during flash.;;help_end;;
IDC_STATIC_LED_OFF_TIME
Count
This is the number of the flashing times for a cycle.;;help_end;;
IDC_STATIC_LED_COUNT
Interval
This is the time interval of a cycle.;;help_end;;
IDC_STATIC_LED_INTERVAL
Type
The LED0(P0_2)display type setting for Standby, Link, Power On and Low Battery mode. There are 3 types are selectable: Always OFF, Always ON and Flash. The Flash method is set as below:;;help_end;;
IDC_STATIC_LED_TYPE
On Duration
The LED on time during flash.;;help_end;;
IDC_STATIC_LED_ON_TIME
Off Duration
The LED off time during flash.;;help_end;;
IDC_STATIC_LED_OFF_TIME
Count
This is the number of the flashing times for a cycle.;;help_end;;
IDC_STATIC_LED_COUNT
Interval
This is the time interval of a cycle.;;help_end;;
IDC_STATIC_LED_INTERVAL
Type
The LED0(P0_2)display type setting for Standby, Link, Power On and Low Battery mode. There are 3 types are selectable: Always OFF, Always ON and Flash. The Flash method is set as below:;;help_end;;
IDC_STATIC_LED_TYPE
On Duration
The LED on time during flash.;;help_end;;
IDC_STATIC_LED_ON_TIME
Off Duration
The LED off time during flash.;;help_end;;
IDC_STATIC_LED_OFF_TIME
Count
This is the number of the flashing times for a cycle.;;help_end;;
IDC_STATIC_LED_COUNT
Type
The LED0(P0_2)display type setting for Standby, Link, Power On and Low Battery mode. There are 3 types are selectable: Always OFF, Always ON and Flash. The Flash method is set as below:;;help_end;;
IDC_STATIC_LED_TYPE
On Duration
The LED on time during flash.;;help_end;;
IDC_STATIC_LED_ON_TIME
Off Duration
The LED off time during flash.;;help_end;;
IDC_STATIC_LED_OFF_TIME
Count
This is the number of the flashing times for a cycle.;;help_end;;
IDC_STATIC_LED_COUNT
Interval
This parameter is uesd to set LED warning time interval if low battery happens;;help_end;;
IDC_STATIC_LOW_BATTERY_LED_INTERVAL
Beacon Feature
Enable/Disable Beacon function;;help_end;;
IDC_STATIC_BEACON_FEATURE
Beacon Admin Mode
Enable/Disable Beacon administration mode.;;help_end;;
IDC_STATIC_BEACON_ADMIN_MODE
Beacon Admin Timeout
This parameter is used to configure Beacon administration timeout value
0x00: Disable Beacon Administration Feature
Range: 0x01~0xFF, Unit: 640mS;;help_end;;
IDC_STATIC_BEACON_ADMIN_TIMEOUT
Beacon In Connection
This option is enabled when BeaconThings function enabled on UI Feature page.
If BeaconThings function is enabled:
 Stop Beacon Advertising: Stop beacon advertising when LE connection is established.
 Beacon Advertising: Continue beacon advertising when LE connection is established.;;help_end;;
IDC_STATIC_BEACON_IN_CONNECTION
Beacon Advertising Interval
This parameter is used to configure the advertising interval for Beacon.;;help_end;;
IDC_STATIC_BEACON_ADVERTISING_INTERVAL
Beacon Advertising Data Length
This paraeter is used to configure advertising data length for Beacon using;;help_end;;
IDC_STATIC_BEACON_ADVERTISING_DATA_LENGTH
Beacon Advertising Data
This paraeter is used to configure advertising data for Beacon using;;help_end;;
IDC_STATIC_BEACON_ADVERTISING_DATA
Beacon Secret Key
This parameter is used to configure Secret key for Beacon Admin usage;;help_end;;
IDC_STATIC_BEACON_SECRET_KEY
