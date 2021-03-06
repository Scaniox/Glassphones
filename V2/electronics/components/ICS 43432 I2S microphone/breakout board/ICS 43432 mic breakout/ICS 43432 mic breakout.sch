EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L ICS-43432:ICS-43432 U1
U 1 1 61BDE1CD
P 4925 3275
F 0 "U1" H 5175 3340 50  0000 C CNN
F 1 "ICS-43432" H 5175 3249 50  0000 C CNN
F 2 "ICS 43432 I2S microphone:ICS_43432" H 5175 3225 50  0001 C CNN
F 3 "https://www.digikey.co.uk/htmldatasheets/production/1744375/0/0/1/ics-43432.html" H 5175 3225 50  0001 C CNN
	1    4925 3275
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x07 J1
U 1 1 61BDFFF9
P 6325 3875
F 0 "J1" H 6405 3917 50  0000 L CNN
F 1 "Conn_01x07" H 6405 3826 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x07_P2.54mm_Vertical" H 6325 3875 50  0001 C CNN
F 3 "~" H 6325 3875 50  0001 C CNN
	1    6325 3875
	1    0    0    -1  
$EndComp
Wire Wire Line
	5575 3575 6125 3575
Wire Wire Line
	5575 3475 5725 3475
Wire Wire Line
	4775 3725 4775 4175
Wire Wire Line
	4775 4175 6125 4175
Wire Wire Line
	4775 3625 4700 3625
Wire Wire Line
	4700 3625 4700 3975
Wire Wire Line
	4775 3525 4575 3525
Wire Wire Line
	4575 3525 4575 4075
Wire Wire Line
	4575 4075 6125 4075
Wire Wire Line
	4700 3975 6125 3975
Wire Wire Line
	5575 3675 6125 3675
$Comp
L Device:C C1
U 1 1 61BDE73A
P 5725 3625
F 0 "C1" H 5840 3671 50  0000 L CNN
F 1 "10uf" H 5840 3580 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.08x0.95mm_HandSolder" H 5763 3475 50  0001 C CNN
F 3 "~" H 5725 3625 50  0001 C CNN
	1    5725 3625
	1    0    0    -1  
$EndComp
Wire Wire Line
	5575 3775 5725 3775
Wire Wire Line
	6125 3875 5725 3875
Wire Wire Line
	5725 3875 5725 3775
Connection ~ 5725 3775
Wire Wire Line
	5725 3475 6050 3475
Wire Wire Line
	6050 3475 6050 3775
Wire Wire Line
	6050 3775 6125 3775
Connection ~ 5725 3475
$EndSCHEMATC
