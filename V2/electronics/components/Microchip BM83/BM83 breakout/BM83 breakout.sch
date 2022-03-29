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
L Microchip_BM83:BM83 U1
U 1 1 61BF8B7F
P 4075 2425
F 0 "U1" H 4725 2856 98  0000 C CNN
F 1 "BM83" H 4725 2618 197 0000 C CNN
F 2 "BM83:BM83" V 4675 1375 50  0001 C CNN
F 3 "https://ww1.microchip.com/downloads/en/DeviceDoc/70005402C.pdf" V 4675 1375 50  0001 C CNN
	1    4075 2425
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x25 J2
U 1 1 61C01F44
P 6225 3675
F 0 "J2" H 6143 2250 50  0000 C CNN
F 1 "Conn_01x25" H 6143 2341 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x25_P2.54mm_Vertical" H 6225 3675 50  0001 C CNN
F 3 "~" H 6225 3675 50  0001 C CNN
	1    6225 3675
	1    0    0    1   
$EndComp
$Comp
L Connector_Generic:Conn_01x25 J1
U 1 1 61C0551A
P 3225 3675
F 0 "J1" H 3143 5092 50  0000 C CNN
F 1 "Conn_01x25" H 3143 5001 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x25_P2.54mm_Vertical" H 3143 5000 50  0001 C CNN
F 3 "~" H 3225 3675 50  0001 C CNN
	1    3225 3675
	-1   0    0    -1  
$EndComp
Wire Wire Line
	5475 2475 6025 2475
Wire Wire Line
	5475 2575 6025 2575
Wire Wire Line
	5475 2675 6025 2675
Wire Wire Line
	5475 2775 6025 2775
Wire Wire Line
	5475 2875 6025 2875
Wire Wire Line
	5475 2975 6025 2975
Wire Wire Line
	5475 3075 6025 3075
Wire Wire Line
	5475 3175 6025 3175
Wire Wire Line
	5475 3275 6025 3275
Wire Wire Line
	5475 3375 6025 3375
Wire Wire Line
	5475 3475 6025 3475
Wire Wire Line
	5475 3575 6025 3575
Wire Wire Line
	5475 3675 6025 3675
Wire Wire Line
	5475 3775 6025 3775
Wire Wire Line
	5475 3875 6025 3875
Wire Wire Line
	5475 3975 6025 3975
Wire Wire Line
	5475 4075 6025 4075
Wire Wire Line
	5475 4175 6025 4175
Wire Wire Line
	5475 4275 6025 4275
Wire Wire Line
	5475 4375 6025 4375
Wire Wire Line
	5475 4475 6025 4475
Wire Wire Line
	5475 4575 6025 4575
Wire Wire Line
	5475 4675 6025 4675
Wire Wire Line
	5475 4775 6025 4775
Wire Wire Line
	3425 2475 3975 2475
Wire Wire Line
	3425 2575 3975 2575
Wire Wire Line
	3425 2675 3975 2675
Wire Wire Line
	3425 2775 3975 2775
Wire Wire Line
	3425 2875 3975 2875
Wire Wire Line
	3425 2975 3975 2975
Wire Wire Line
	3425 3075 3975 3075
Wire Wire Line
	3425 3175 3975 3175
Wire Wire Line
	3425 3275 3975 3275
Wire Wire Line
	3425 3375 3975 3375
Wire Wire Line
	3425 3475 3975 3475
Wire Wire Line
	3425 3575 3975 3575
Wire Wire Line
	3425 3675 3975 3675
Wire Wire Line
	3425 3775 3975 3775
Wire Wire Line
	3425 3875 3975 3875
Wire Wire Line
	3425 3975 3975 3975
Wire Wire Line
	3425 4075 3975 4075
Wire Wire Line
	3425 4175 3975 4175
Wire Wire Line
	3425 4275 3975 4275
Wire Wire Line
	3425 4375 3975 4375
Wire Wire Line
	3425 4475 3975 4475
Wire Wire Line
	3425 4575 3975 4575
Wire Wire Line
	3425 4675 3975 4675
Wire Wire Line
	3425 4775 3975 4775
Wire Wire Line
	3425 4875 3975 4875
Text Label 3575 2475 0    50   ~ 0
DR1
Text Label 3575 2575 0    50   ~ 0
RFS1
Text Label 3575 2675 0    50   ~ 0
SCLK1
Text Label 3575 2775 0    50   ~ 0
DT1
Text Label 3575 2875 0    50   ~ 0
MCLK1
Text Label 3575 2975 0    50   ~ 0
AOHPR
Text Label 3575 3075 0    50   ~ 0
AOHPM
Text Label 3575 3175 0    50   ~ 0
AOHPL
Text Label 3575 3275 0    50   ~ 0
MICN2
Text Label 3575 3375 0    50   ~ 0
MICP2
Text Label 3575 3475 0    50   ~ 0
AIR
Text Label 3575 3575 0    50   ~ 0
AIL
Text Label 3575 3675 0    50   ~ 0
MICN1
Text Label 3575 3775 0    50   ~ 0
MICP1
Text Label 3575 3875 0    50   ~ 0
MICBIAS
Text Label 3575 3975 0    50   ~ 0
GND
Text Label 5500 4875 0    50   ~ 0
GND
Text Label 3525 4075 0    50   ~ 0
DMIC1_CLK
Text Label 3525 4175 0    50   ~ 0
DMIC1_R
Text Label 3525 4275 0    50   ~ 0
DMIC1_L
Text Label 3525 4375 0    50   ~ 0
P3_2
Text Label 3525 4475 0    50   ~ 0
P2_6
Text Label 3525 4575 0    50   ~ 0
ADAP_IN
Text Label 3525 4675 0    50   ~ 0
BAT_IN
Text Label 3525 4775 0    50   ~ 0
SYS_PWR
Text Label 3525 4875 0    50   ~ 0
VDD_IO
Text Label 5500 4775 0    50   ~ 0
P0_0
Text Label 5500 4675 0    50   ~ 0
P3_7
Text Label 5500 4575 0    50   ~ 0
P1_3
Text Label 5500 4475 0    50   ~ 0
P1_2
Text Label 5500 4375 0    50   ~ 0
P0_7
Text Label 5500 4275 0    50   ~ 0
P0_1
Text Label 5500 4175 0    50   ~ 0
RST_N
Text Label 5500 4075 0    50   ~ 0
P2_3
Text Label 5500 3975 0    50   ~ 0
P1_6
Text Label 5500 3875 0    50   ~ 0
P0_5
Text Label 5500 3775 0    50   ~ 0
P2_7
Text Label 5500 3675 0    50   ~ 0
P0_3
Text Label 5500 3575 0    50   ~ 0
DP
Text Label 5500 3475 0    50   ~ 0
DN
Text Label 5500 3375 0    50   ~ 0
P0_6
Text Label 5500 3275 0    50   ~ 0
LED2
Text Label 5500 3175 0    50   ~ 0
P0_2
Text Label 5500 3075 0    50   ~ 0
LED1
Text Label 5500 2975 0    50   ~ 0
P3_4
Text Label 5500 2875 0    50   ~ 0
P8_5
Text Label 5500 2775 0    50   ~ 0
P8_6
Text Label 5500 2675 0    50   ~ 0
SK2_KEY_AD
Text Label 5500 2575 0    50   ~ 0
SK1_AMB_DET
Text Label 5500 2475 0    50   ~ 0
PWR(MFB)
$Comp
L power:GND #PWR0101
U 1 1 61C20535
P 5775 5025
F 0 "#PWR0101" H 5775 4775 50  0001 C CNN
F 1 "GND" H 5780 4852 50  0000 C CNN
F 2 "" H 5775 5025 50  0001 C CNN
F 3 "" H 5775 5025 50  0001 C CNN
	1    5775 5025
	1    0    0    -1  
$EndComp
Wire Wire Line
	5775 4875 5775 5025
Wire Wire Line
	5775 4875 6025 4875
Wire Wire Line
	5775 4875 5475 4875
Connection ~ 5775 4875
Wire Wire Line
	8475 2075 9000 2075
Text Label 8650 2075 0    50   ~ 0
VDD_IO
Wire Wire Line
	8475 2225 8475 2075
Wire Wire Line
	8475 2600 9000 2600
Connection ~ 8475 2600
Wire Wire Line
	8475 2525 8475 2600
Wire Wire Line
	8275 2600 8475 2600
$Comp
L Device:R R1
U 1 1 61C2F1DC
P 8475 2375
F 0 "R1" H 8545 2421 50  0000 L CNN
F 1 "4R7" H 8545 2330 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad0.98x0.95mm_HandSolder" V 8405 2375 50  0001 C CNN
F 3 "~" H 8475 2375 50  0001 C CNN
	1    8475 2375
	1    0    0    -1  
$EndComp
Text Label 8650 2600 0    50   ~ 0
RST_N
Wire Wire Line
	7700 2600 7875 2600
Wire Wire Line
	7700 2775 7700 2600
$Comp
L power:GND #PWR0102
U 1 1 61C2A48B
P 7700 2775
F 0 "#PWR0102" H 7700 2525 50  0001 C CNN
F 1 "GND" H 7705 2602 50  0000 C CNN
F 2 "" H 7700 2775 50  0001 C CNN
F 3 "" H 7700 2775 50  0001 C CNN
	1    7700 2775
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW2
U 1 1 61BFC36C
P 8075 2600
F 0 "SW2" H 8075 2885 50  0000 C CNN
F 1 "RESET" H 8075 2794 50  0000 C CNN
F 2 "TL3365_button:TL3365_button" H 8075 2800 50  0001 C CNN
F 3 "~" H 8075 2800 50  0001 C CNN
	1    8075 2600
	1    0    0    -1  
$EndComp
Wire Wire Line
	7825 3325 7825 3500
Wire Wire Line
	7825 3650 8075 3650
Wire Wire Line
	7825 3500 7450 3500
Connection ~ 7825 3500
Wire Wire Line
	7825 3500 7825 3650
Text Label 7450 3500 0    50   ~ 0
SYS_PWR
Wire Wire Line
	8375 3325 8675 3325
Wire Wire Line
	8375 3650 8675 3650
Text Label 8450 3325 0    50   ~ 0
LED1
Text Label 8450 3650 0    50   ~ 0
LED2
$Comp
L Device:LED D2
U 1 1 61C56D23
P 8225 3650
F 0 "D2" H 8218 3867 50  0000 C CNN
F 1 "LED2" H 8218 3776 50  0000 C CNN
F 2 "LED_SMD:LED_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 8225 3650 50  0001 C CNN
F 3 "~" H 8225 3650 50  0001 C CNN
	1    8225 3650
	-1   0    0    -1  
$EndComp
Wire Wire Line
	8075 3325 7825 3325
$Comp
L Device:LED D1
U 1 1 61C564D1
P 8225 3325
F 0 "D1" H 8218 3542 50  0000 C CNN
F 1 "LED1" H 8218 3451 50  0000 C CNN
F 2 "LED_SMD:LED_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 8225 3325 50  0001 C CNN
F 3 "~" H 8225 3325 50  0001 C CNN
	1    8225 3325
	-1   0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW1
U 1 1 61C796FE
P 8250 1700
F 0 "SW1" H 8250 1985 50  0000 C CNN
F 1 "PWR MFB" H 8250 1894 50  0000 C CNN
F 2 "TL3365_button:TL3365_button" H 8250 1900 50  0001 C CNN
F 3 "~" H 8250 1900 50  0001 C CNN
	1    8250 1700
	1    0    0    -1  
$EndComp
Wire Wire Line
	8050 1700 7650 1700
Text Label 7650 1700 0    50   ~ 0
PWR(MFB)
Text Label 8500 1700 0    50   ~ 0
SYS_PWR
Wire Wire Line
	8450 1700 8900 1700
$Comp
L Device:Jumper_NO_Small JP1
U 1 1 61C7E13D
P 8150 4125
F 0 "JP1" H 8150 3940 50  0000 C CNN
F 1 "Jumper_NO_Small" H 8150 4031 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 8150 4125 50  0001 C CNN
F 3 "~" H 8150 4125 50  0001 C CNN
	1    8150 4125
	1    0    0    1   
$EndComp
Wire Wire Line
	8050 4125 7725 4125
Wire Wire Line
	8250 4125 8575 4125
Text Label 7725 4125 0    50   ~ 0
GND
Text Label 8350 4125 0    50   ~ 0
P3_4
$Comp
L Connector:USB_B_Micro J3
U 1 1 61CEBDB7
P 7950 5125
F 0 "J3" H 8007 5592 50  0000 C CNN
F 1 "USB_B_Micro" H 8007 5501 50  0000 C CNN
F 2 "Connector_USB:USB_Micro-B_Molex-105017-0001" H 8100 5075 50  0001 C CNN
F 3 "~" H 8100 5075 50  0001 C CNN
	1    7950 5125
	1    0    0    -1  
$EndComp
Wire Wire Line
	8250 4925 8625 4925
Wire Wire Line
	8250 5125 8625 5125
Wire Wire Line
	8250 5225 8625 5225
Wire Wire Line
	7850 5525 7950 5525
$Comp
L power:GND #PWR0103
U 1 1 61CF7782
P 7950 5625
F 0 "#PWR0103" H 7950 5375 50  0001 C CNN
F 1 "GND" H 7955 5452 50  0000 C CNN
F 2 "" H 7950 5625 50  0001 C CNN
F 3 "" H 7950 5625 50  0001 C CNN
	1    7950 5625
	1    0    0    -1  
$EndComp
Wire Wire Line
	7950 5625 7950 5525
Connection ~ 7950 5525
Text Label 8275 4925 0    50   ~ 0
ADAP_IN
Text Label 8275 5125 0    50   ~ 0
DP
Text Label 8275 5225 0    50   ~ 0
DN
$EndSCHEMATC
