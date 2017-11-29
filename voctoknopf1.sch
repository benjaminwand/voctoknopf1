EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:arduino
LIBS:microchip_pic12mcu
LIBS:cherry
LIBS:keyboard_components
LIBS:voctoknopf1-cache
EELAYER 25 0
EELAYER END
$Descr User 10237 7087
encoding utf-8
Sheet 1 1
Title "voctoknopf1"
Date "2017-11-29"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L R R4
U 1 1 5A16E4D6
P 2550 1900
F 0 "R4" V 2630 1900 50  0000 C CNN
F 1 "10 k" V 2550 1900 50  0000 C CNN
F 2 "" V 2480 1900 50  0001 C CNN
F 3 "" H 2550 1900 50  0001 C CNN
	1    2550 1900
	-1   0    0    1   
$EndComp
$Comp
L R R3
U 1 1 5A16E6E5
P 2350 1900
F 0 "R3" V 2430 1900 50  0000 C CNN
F 1 "220" V 2350 1900 50  0000 C CNN
F 2 "" V 2280 1900 50  0001 C CNN
F 3 "" H 2350 1900 50  0001 C CNN
	1    2350 1900
	-1   0    0    1   
$EndComp
$Comp
L MCP23017 U1
U 1 1 5A16E83C
P 5000 1950
F 0 "U1" H 4900 2975 50  0000 R CNN
F 1 "MCP23017" H 4900 2900 50  0000 R CNN
F 2 "" H 5050 1000 50  0001 L CNN
F 3 "" H 5250 2950 50  0001 C CNN
	1    5000 1950
	1    0    0    -1  
$EndComp
$Comp
L MCP23017 U2
U 1 1 5A16E8C4
P 4750 5350
F 0 "U2" H 4650 6375 50  0000 R CNN
F 1 "MCP23017" H 4650 6300 50  0000 R CNN
F 2 "" H 4800 4400 50  0001 L CNN
F 3 "" H 5000 6350 50  0001 C CNN
	1    4750 5350
	1    0    0    -1  
$EndComp
$Comp
L R R6
U 1 1 5A1E8001
P 3250 1900
F 0 "R6" V 3330 1900 50  0000 C CNN
F 1 "10 k" V 3250 1900 50  0000 C CNN
F 2 "" V 3180 1900 50  0001 C CNN
F 3 "" H 3250 1900 50  0001 C CNN
	1    3250 1900
	-1   0    0    1   
$EndComp
$Comp
L R R5
U 1 1 5A1E8041
P 3050 1900
F 0 "R5" V 3130 1900 50  0000 C CNN
F 1 "220" V 3050 1900 50  0000 C CNN
F 2 "" V 2980 1900 50  0001 C CNN
F 3 "" H 3050 1900 50  0001 C CNN
	1    3050 1900
	-1   0    0    1   
$EndComp
$Comp
L R R2
U 1 1 5A1E8129
P 1850 1900
F 0 "R2" V 1930 1900 50  0000 C CNN
F 1 "10 k" V 1850 1900 50  0000 C CNN
F 2 "" V 1780 1900 50  0001 C CNN
F 3 "" H 1850 1900 50  0001 C CNN
	1    1850 1900
	-1   0    0    1   
$EndComp
$Comp
L R R1
U 1 1 5A1E812F
P 1650 1900
F 0 "R1" V 1730 1900 50  0000 C CNN
F 1 "220" V 1650 1900 50  0000 C CNN
F 2 "" V 1580 1900 50  0001 C CNN
F 3 "" H 1650 1900 50  0001 C CNN
	1    1650 1900
	-1   0    0    1   
$EndComp
$Comp
L ARDUINO_NANO ARDUINO2
U 1 1 5A1E84AB
P 7250 3950
F 0 "ARDUINO2" H 7250 4800 70  0000 C CNN
F 1 "Nano Ethernet Shield" V 7250 3950 70  0000 C CNN
F 2 "" H 7250 3950 60  0000 C CNN
F 3 "" H 7250 3950 60  0000 C CNN
	1    7250 3950
	0    -1   -1   0   
$EndComp
$Comp
L MX_D SW2
U 1 1 5A1E8A84
P 2150 1400
F 0 "SW2" H 2150 1500 60  0000 C CNN
F 1 "MX_D" H 2150 1400 60  0000 C CNN
F 2 "" H 2150 1400 60  0001 C CNN
F 3 "" H 2150 1400 60  0001 C CNN
	1    2150 1400
	1    0    0    -1  
$EndComp
$Comp
L MX_D SW1
U 1 1 5A1E8B0E
P 1450 1400
F 0 "SW1" H 1450 1500 60  0000 C CNN
F 1 "MX_D" H 1450 1400 60  0000 C CNN
F 2 "" H 1450 1400 60  0001 C CNN
F 3 "" H 1450 1400 60  0001 C CNN
	1    1450 1400
	1    0    0    -1  
$EndComp
$Comp
L ARDUINO_NANO ARDUINO1
U 1 1 5A1E8DE8
P 7250 1850
F 0 "ARDUINO1" H 7250 2700 70  0000 C CNN
F 1 "ARDUINO_NANO" V 7250 1850 70  0000 C CNN
F 2 "" H 7250 1850 60  0000 C CNN
F 3 "" H 7250 1850 60  0000 C CNN
	1    7250 1850
	0    -1   -1   0   
$EndComp
$Comp
L MX_D SW3
U 1 1 5A1ED9D8
P 2850 1400
F 0 "SW3" H 2850 1500 60  0000 C CNN
F 1 "MX_D" H 2850 1400 60  0000 C CNN
F 2 "" H 2850 1400 60  0001 C CNN
F 3 "" H 2850 1400 60  0001 C CNN
	1    2850 1400
	1    0    0    -1  
$EndComp
$Comp
L R R13
U 1 1 5A1EDF8E
P 2250 3450
F 0 "R13" V 2330 3450 50  0000 C CNN
F 1 "10 k" V 2250 3450 50  0000 C CNN
F 2 "" V 2180 3450 50  0001 C CNN
F 3 "" H 2250 3450 50  0001 C CNN
	1    2250 3450
	-1   0    0    1   
$EndComp
$Comp
L R R12
U 1 1 5A1EDF94
P 2050 3450
F 0 "R12" V 2130 3450 50  0000 C CNN
F 1 "220" V 2050 3450 50  0000 C CNN
F 2 "" V 1980 3450 50  0001 C CNN
F 3 "" H 2050 3450 50  0001 C CNN
	1    2050 3450
	-1   0    0    1   
$EndComp
$Comp
L R R15
U 1 1 5A1EDF9A
P 2950 3450
F 0 "R15" V 3030 3450 50  0000 C CNN
F 1 "10 k" V 2950 3450 50  0000 C CNN
F 2 "" V 2880 3450 50  0001 C CNN
F 3 "" H 2950 3450 50  0001 C CNN
	1    2950 3450
	-1   0    0    1   
$EndComp
$Comp
L R R14
U 1 1 5A1EDFA0
P 2750 3450
F 0 "R14" V 2830 3450 50  0000 C CNN
F 1 "220" V 2750 3450 50  0000 C CNN
F 2 "" V 2680 3450 50  0001 C CNN
F 3 "" H 2750 3450 50  0001 C CNN
	1    2750 3450
	-1   0    0    1   
$EndComp
$Comp
L R R11
U 1 1 5A1EDFA6
P 1550 3450
F 0 "R11" V 1630 3450 50  0000 C CNN
F 1 "10 k" V 1550 3450 50  0000 C CNN
F 2 "" V 1480 3450 50  0001 C CNN
F 3 "" H 1550 3450 50  0001 C CNN
	1    1550 3450
	-1   0    0    1   
$EndComp
$Comp
L R R10
U 1 1 5A1EDFAC
P 1350 3450
F 0 "R10" V 1430 3450 50  0000 C CNN
F 1 "220" V 1350 3450 50  0000 C CNN
F 2 "" V 1280 3450 50  0001 C CNN
F 3 "" H 1350 3450 50  0001 C CNN
	1    1350 3450
	-1   0    0    1   
$EndComp
$Comp
L MX_D SW5
U 1 1 5A1EDFB2
P 1850 2750
F 0 "SW5" H 1850 2850 60  0000 C CNN
F 1 "MX_D" H 1850 2750 60  0000 C CNN
F 2 "" H 1850 2750 60  0001 C CNN
F 3 "" H 1850 2750 60  0001 C CNN
	1    1850 2750
	1    0    0    -1  
$EndComp
$Comp
L MX_D SW4
U 1 1 5A1EDFB8
P 1150 2750
F 0 "SW4" H 1150 2850 60  0000 C CNN
F 1 "MX_D" H 1150 2750 60  0000 C CNN
F 2 "" H 1150 2750 60  0001 C CNN
F 3 "" H 1150 2750 60  0001 C CNN
	1    1150 2750
	1    0    0    -1  
$EndComp
$Comp
L MX_D SW6
U 1 1 5A1EDFBE
P 2550 2750
F 0 "SW6" H 2550 2850 60  0000 C CNN
F 1 "MX_D" H 2550 2750 60  0000 C CNN
F 2 "" H 2550 2750 60  0001 C CNN
F 3 "" H 2550 2750 60  0001 C CNN
	1    2550 2750
	1    0    0    -1  
$EndComp
$Comp
L R R17
U 1 1 5A1EE0D4
P 3750 3450
F 0 "R17" V 3830 3450 50  0000 C CNN
F 1 "10 k" V 3750 3450 50  0000 C CNN
F 2 "" V 3680 3450 50  0001 C CNN
F 3 "" H 3750 3450 50  0001 C CNN
	1    3750 3450
	-1   0    0    1   
$EndComp
$Comp
L R R16
U 1 1 5A1EE0DA
P 3550 3450
F 0 "R16" V 3630 3450 50  0000 C CNN
F 1 "220" V 3550 3450 50  0000 C CNN
F 2 "" V 3480 3450 50  0001 C CNN
F 3 "" H 3550 3450 50  0001 C CNN
	1    3550 3450
	-1   0    0    1   
$EndComp
$Comp
L MX_D SW7
U 1 1 5A1EE0E0
P 3350 2750
F 0 "SW7" H 3350 2850 60  0000 C CNN
F 1 "MX_D" H 3350 2750 60  0000 C CNN
F 2 "" H 3350 2750 60  0001 C CNN
F 3 "" H 3350 2750 60  0001 C CNN
	1    3350 2750
	1    0    0    -1  
$EndComp
$Comp
L R R21
U 1 1 5A1EE44E
P 1950 5150
F 0 "R21" V 2030 5150 50  0000 C CNN
F 1 "10 k" V 1950 5150 50  0000 C CNN
F 2 "" V 1880 5150 50  0001 C CNN
F 3 "" H 1950 5150 50  0001 C CNN
	1    1950 5150
	-1   0    0    1   
$EndComp
$Comp
L R R20
U 1 1 5A1EE454
P 1700 5150
F 0 "R20" V 1780 5150 50  0000 C CNN
F 1 "220" V 1700 5150 50  0000 C CNN
F 2 "" V 1630 5150 50  0001 C CNN
F 3 "" H 1700 5150 50  0001 C CNN
	1    1700 5150
	-1   0    0    1   
$EndComp
$Comp
L R R23
U 1 1 5A1EE45A
P 2650 5150
F 0 "R23" V 2730 5150 50  0000 C CNN
F 1 "10 k" V 2650 5150 50  0000 C CNN
F 2 "" V 2580 5150 50  0001 C CNN
F 3 "" H 2650 5150 50  0001 C CNN
	1    2650 5150
	-1   0    0    1   
$EndComp
$Comp
L R R22
U 1 1 5A1EE460
P 2400 5150
F 0 "R22" V 2480 5150 50  0000 C CNN
F 1 "220" V 2400 5150 50  0000 C CNN
F 2 "" V 2330 5150 50  0001 C CNN
F 3 "" H 2400 5150 50  0001 C CNN
	1    2400 5150
	-1   0    0    1   
$EndComp
$Comp
L R R19
U 1 1 5A1EE466
P 1250 5150
F 0 "R19" V 1330 5150 50  0000 C CNN
F 1 "10 k" V 1250 5150 50  0000 C CNN
F 2 "" V 1180 5150 50  0001 C CNN
F 3 "" H 1250 5150 50  0001 C CNN
	1    1250 5150
	-1   0    0    1   
$EndComp
$Comp
L R R18
U 1 1 5A1EE46C
P 1000 5150
F 0 "R18" V 1080 5150 50  0000 C CNN
F 1 "220" V 1000 5150 50  0000 C CNN
F 2 "" V 930 5150 50  0001 C CNN
F 3 "" H 1000 5150 50  0001 C CNN
	1    1000 5150
	-1   0    0    1   
$EndComp
$Comp
L MX_D SW9
U 1 1 5A1EE472
P 1500 4550
F 0 "SW9" H 1500 4650 60  0000 C CNN
F 1 "MX_D" H 1500 4550 60  0000 C CNN
F 2 "" H 1500 4550 60  0001 C CNN
F 3 "" H 1500 4550 60  0001 C CNN
	1    1500 4550
	1    0    0    -1  
$EndComp
$Comp
L MX_D SW8
U 1 1 5A1EE478
P 800 4550
F 0 "SW8" H 800 4650 60  0000 C CNN
F 1 "MX_D" H 800 4550 60  0000 C CNN
F 2 "" H 800 4550 60  0001 C CNN
F 3 "" H 800 4550 60  0001 C CNN
	1    800  4550
	1    0    0    -1  
$EndComp
$Comp
L MX_D SW10
U 1 1 5A1EE47E
P 2200 4550
F 0 "SW10" H 2200 4650 60  0000 C CNN
F 1 "MX_D" H 2200 4550 60  0000 C CNN
F 2 "" H 2200 4550 60  0001 C CNN
F 3 "" H 2200 4550 60  0001 C CNN
	1    2200 4550
	1    0    0    -1  
$EndComp
$Comp
L R R25
U 1 1 5A1EE484
P 3400 5150
F 0 "R25" V 3480 5150 50  0000 C CNN
F 1 "10 k" V 3400 5150 50  0000 C CNN
F 2 "" V 3330 5150 50  0001 C CNN
F 3 "" H 3400 5150 50  0001 C CNN
	1    3400 5150
	-1   0    0    1   
$EndComp
$Comp
L R R24
U 1 1 5A1EE48A
P 3150 5150
F 0 "R24" V 3230 5150 50  0000 C CNN
F 1 "220" V 3150 5150 50  0000 C CNN
F 2 "" V 3080 5150 50  0001 C CNN
F 3 "" H 3150 5150 50  0001 C CNN
	1    3150 5150
	-1   0    0    1   
$EndComp
$Comp
L MX_D SW11
U 1 1 5A1EE490
P 2950 4550
F 0 "SW11" H 2950 4650 60  0000 C CNN
F 1 "MX_D" H 2950 4550 60  0000 C CNN
F 2 "" H 2950 4550 60  0001 C CNN
F 3 "" H 2950 4550 60  0001 C CNN
	1    2950 4550
	1    0    0    -1  
$EndComp
$Comp
L R R26
U 1 1 5A1EF91E
P 3100 6000
F 0 "R26" V 3180 6000 50  0000 C CNN
F 1 "10 k" V 3100 6000 50  0000 C CNN
F 2 "" V 3030 6000 50  0001 C CNN
F 3 "" H 3100 6000 50  0001 C CNN
	1    3100 6000
	0    -1   -1   0   
$EndComp
$Comp
L R R27
U 1 1 5A1EF924
P 3600 6350
F 0 "R27" V 3680 6350 50  0000 C CNN
F 1 "220" V 3600 6350 50  0000 C CNN
F 2 "" V 3530 6350 50  0001 C CNN
F 3 "" H 3600 6350 50  0001 C CNN
	1    3600 6350
	0    -1   -1   0   
$EndComp
$Comp
L MX_D SW12
U 1 1 5A1EF92A
P 3050 6300
F 0 "SW12" H 3050 6400 60  0000 C CNN
F 1 "MX_D" H 3050 6300 60  0000 C CNN
F 2 "" H 3050 6300 60  0001 C CNN
F 3 "" H 3050 6300 60  0001 C CNN
	1    3050 6300
	1    0    0    -1  
$EndComp
Text Label 4400 3200 0    60   ~ 0
GND
Text Label 3450 800  0    60   ~ 0
5V
Text Label 3450 700  0    60   ~ 0
GND
Text Label 5800 3600 0    60   ~ 0
5V
Text Label 3250 3900 0    60   ~ 0
GND
Text Label 3200 4050 0    60   ~ 0
5V
Text Label 1350 5600 0    60   ~ 0
GND
Text Label 1350 2500 0    60   ~ 0
5V
Text Label 1250 2250 0    60   ~ 0
GND
$Comp
L LED D2
U 1 1 5A2062E7
P 8850 1400
F 0 "D2" H 8850 1500 50  0000 C CNN
F 1 "LED" H 8850 1300 50  0000 C CNN
F 2 "" H 8850 1400 50  0001 C CNN
F 3 "" H 8850 1400 50  0001 C CNN
	1    8850 1400
	0    1    1    0   
$EndComp
$Comp
L LED D1
U 1 1 5A2063A3
P 8450 1400
F 0 "D1" H 8450 1500 50  0000 C CNN
F 1 "LED" H 8450 1300 50  0000 C CNN
F 2 "" H 8450 1400 50  0001 C CNN
F 3 "" H 8450 1400 50  0001 C CNN
	1    8450 1400
	0    1    1    0   
$EndComp
$Comp
L R R9
U 1 1 5A2069C6
P 9200 2950
F 0 "R9" V 9280 2950 50  0000 C CNN
F 1 "10 k" V 9200 2950 50  0000 C CNN
F 2 "" V 9130 2950 50  0001 C CNN
F 3 "" H 9200 2950 50  0001 C CNN
	1    9200 2950
	-1   0    0    1   
$EndComp
$Comp
L R R8
U 1 1 5A2069CC
P 8850 1850
F 0 "R8" V 8930 1850 50  0000 C CNN
F 1 "220" V 8850 1850 50  0000 C CNN
F 2 "" V 8780 1850 50  0001 C CNN
F 3 "" H 8850 1850 50  0001 C CNN
	1    8850 1850
	-1   0    0    1   
$EndComp
$Comp
L R R7
U 1 1 5A2083E1
P 8450 1850
F 0 "R7" V 8530 1850 50  0000 C CNN
F 1 "220" V 8450 1850 50  0000 C CNN
F 2 "" V 8380 1850 50  0001 C CNN
F 3 "" H 8450 1850 50  0001 C CNN
	1    8450 1850
	-1   0    0    1   
$EndComp
$Comp
L Conn_01x02 J1
U 1 1 5A20964F
P 9400 1500
F 0 "J1" H 9400 1600 50  0000 C CNN
F 1 "Conn_01x02" H 9400 1300 50  0000 C CNN
F 2 "" H 9400 1500 50  0001 C CNN
F 3 "" H 9400 1500 50  0001 C CNN
	1    9400 1500
	1    0    0    -1  
$EndComp
Wire Wire Line
	3850 3900 600  3900
Wire Wire Line
	3850 2250 3850 3900
Wire Wire Line
	1650 1450 1650 1750
Wire Wire Line
	1250 700  8850 700 
Wire Wire Line
	1250 700  1250 1450
Wire Wire Line
	1650 2050 1650 2200
Wire Wire Line
	7700 4700 7700 4550
Wire Wire Line
	6300 4700 7700 4700
Wire Wire Line
	6300 2600 6300 4700
Wire Wire Line
	7700 2600 6300 2600
Wire Wire Line
	7700 2450 7700 2600
Wire Wire Line
	7800 4850 7800 4550
Wire Wire Line
	6250 4850 7800 4850
Wire Wire Line
	6250 2750 6250 4850
Wire Wire Line
	7800 2750 6250 2750
Wire Wire Line
	7800 2450 7800 2750
Wire Wire Line
	8200 4550 7900 4550
Wire Wire Line
	8200 2550 8200 4550
Wire Wire Line
	7900 2550 8200 2550
Wire Wire Line
	7900 2450 7900 2550
Wire Wire Line
	6600 3200 6600 3350
Wire Wire Line
	6050 3200 6050 1100
Wire Wire Line
	3850 3200 9200 3200
Wire Wire Line
	6050 1100 6600 1100
Wire Wire Line
	6600 700  6600 1250
Wire Wire Line
	7800 3250 7800 3350
Wire Wire Line
	8150 3250 7800 3250
Wire Wire Line
	8150 1150 8150 3250
Wire Wire Line
	7800 1150 8150 1150
Wire Wire Line
	7800 1250 7800 1150
Wire Wire Line
	8100 3350 7900 3350
Wire Wire Line
	8100 1250 8100 3350
Wire Wire Line
	7900 1250 8100 1250
Wire Wire Line
	6800 800  6800 1250
Wire Wire Line
	1350 800  9200 800 
Wire Wire Line
	1350 800  1350 1200
Wire Wire Line
	2050 800  2050 1200
Connection ~ 2050 800 
Wire Wire Line
	2750 1200 2750 800 
Connection ~ 2750 800 
Connection ~ 3850 3200
Wire Wire Line
	7400 -8600 13400 -8600
Wire Wire Line
	1950 1450 1950 700 
Connection ~ 1950 700 
Wire Wire Line
	2650 700  2650 1450
Connection ~ 2650 700 
Wire Wire Line
	3050 2100 3050 2050
Wire Wire Line
	1650 2200 3550 2200
Wire Wire Line
	3550 2200 3550 1250
Wire Wire Line
	3550 1250 4500 1250
Wire Wire Line
	3050 2100 3750 2100
Wire Wire Line
	3750 2100 3750 1650
Wire Wire Line
	3750 1650 4500 1650
Wire Wire Line
	1850 1350 1850 1750
Wire Wire Line
	1850 1600 3500 1600
Wire Wire Line
	1850 1350 1650 1350
Wire Wire Line
	3500 1600 3500 1150
Wire Wire Line
	3500 1150 4500 1150
Connection ~ 1850 1600
Wire Wire Line
	2350 1350 2550 1350
Wire Wire Line
	3600 1650 3600 1350
Wire Wire Line
	3600 1350 4500 1350
Wire Wire Line
	3050 1350 3250 1350
Wire Wire Line
	3700 1550 4500 1550
Wire Wire Line
	2350 1750 2350 1450
Wire Wire Line
	3050 1750 3050 1450
Wire Wire Line
	2550 1350 2550 1750
Connection ~ 2550 1650
Wire Wire Line
	2550 1650 3600 1650
Wire Wire Line
	3250 1350 3250 1750
Connection ~ 3250 1700
Wire Wire Line
	3250 1700 3700 1700
Wire Wire Line
	3700 1700 3700 1550
Wire Wire Line
	2350 2050 2350 2150
Wire Wire Line
	2350 2150 3650 2150
Wire Wire Line
	3650 2150 3650 1450
Wire Wire Line
	3650 1450 4500 1450
Wire Wire Line
	1850 2250 1850 2050
Wire Wire Line
	950  2250 3850 2250
Wire Wire Line
	2550 2050 2550 2250
Connection ~ 2550 2250
Wire Wire Line
	3250 2050 3250 2250
Connection ~ 3250 2250
Wire Wire Line
	5800 4050 5800 800 
Connection ~ 5800 800 
Wire Wire Line
	1050 2550 1050 2500
Wire Wire Line
	1750 2550 1750 2500
Connection ~ 1750 2500
Wire Wire Line
	2450 2500 2450 2550
Connection ~ 2450 2500
Wire Wire Line
	3250 2500 3250 2550
Connection ~ 3250 2500
Wire Wire Line
	3150 2800 3150 2250
Connection ~ 3150 2250
Wire Wire Line
	2350 2800 2350 2250
Connection ~ 2350 2250
Wire Wire Line
	1650 2800 1650 2250
Connection ~ 1850 2250
Wire Wire Line
	950  2250 950  2800
Connection ~ 1650 2250
Connection ~ 3750 3900
Connection ~ 2950 3900
Connection ~ 2250 3900
Connection ~ 1550 3900
Wire Wire Line
	3550 2800 3550 3300
Wire Wire Line
	2750 2800 2750 3300
Wire Wire Line
	2050 2800 2050 3300
Wire Wire Line
	1350 2800 1350 3300
Wire Wire Line
	3550 3600 3550 3650
Wire Wire Line
	2750 3600 2750 3700
Wire Wire Line
	2050 3600 2050 3750
Wire Wire Line
	1350 3600 1350 3800
Wire Wire Line
	3750 3900 3750 3900
Wire Wire Line
	3750 3900 3750 3600
Wire Wire Line
	2950 3900 2950 3900
Wire Wire Line
	2950 3900 2950 3600
Wire Wire Line
	2250 3900 2250 3900
Wire Wire Line
	2250 3900 2250 3600
Wire Wire Line
	1550 3900 1550 3600
Wire Wire Line
	1350 2700 1450 2700
Wire Wire Line
	1450 2700 1450 2950
Wire Wire Line
	1450 2950 3900 2950
Wire Wire Line
	3900 2950 3900 1750
Wire Wire Line
	1550 2950 1550 3300
Connection ~ 1550 2950
Wire Wire Line
	2050 2700 2100 2700
Wire Wire Line
	2100 2700 2100 3000
Wire Wire Line
	2100 3000 4000 3000
Wire Wire Line
	4000 3000 4000 2050
Wire Wire Line
	2250 3000 2250 3300
Connection ~ 2250 3000
Wire Wire Line
	2750 2700 2850 2700
Wire Wire Line
	2850 2700 2850 3050
Wire Wire Line
	2850 3050 4100 3050
Wire Wire Line
	2950 3050 2950 3300
Connection ~ 2950 3050
Wire Wire Line
	1350 3800 3950 3800
Wire Wire Line
	3950 3800 3950 1850
Wire Wire Line
	2050 3750 4050 3750
Wire Wire Line
	4050 3750 4050 2150
Wire Wire Line
	3550 2700 3750 2700
Wire Wire Line
	3750 2700 3750 3300
Wire Wire Line
	4100 3050 4100 2250
Wire Wire Line
	2750 3700 4150 3700
Wire Wire Line
	4150 3700 4150 2350
Wire Wire Line
	4200 2450 4200 3250
Wire Wire Line
	4200 3250 3750 3250
Connection ~ 3750 3250
Wire Wire Line
	3550 3650 4250 3650
Wire Wire Line
	4250 3650 4250 2550
Connection ~ 6050 3200
Wire Wire Line
	5000 950  5000 800 
Connection ~ 5000 800 
Wire Wire Line
	5000 2950 5000 3200
Connection ~ 5000 3200
Wire Wire Line
	5500 1150 5500 800 
Connection ~ 5500 800 
Connection ~ 6600 1100
Wire Wire Line
	5500 2750 6050 2750
Connection ~ 6050 2750
Wire Wire Line
	5500 2650 6050 2650
Connection ~ 6050 2650
Wire Wire Line
	5500 2550 6050 2550
Connection ~ 6050 2550
Wire Wire Line
	5700 1150 5700 4200
Wire Wire Line
	5700 1150 7100 1150
Wire Wire Line
	7100 1150 7100 1250
Wire Wire Line
	5500 2350 5750 2350
Wire Wire Line
	5750 4300 5750 1200
Wire Wire Line
	5750 1200 7200 1200
Wire Wire Line
	7200 1200 7200 1250
Wire Wire Line
	3150 4600 3150 5000
Wire Wire Line
	1700 4600 1700 5000
Wire Wire Line
	1000 4600 1000 5000
Wire Wire Line
	700  4050 5800 4050
Wire Wire Line
	1300 4600 1300 3900
Connection ~ 1300 3900
Wire Wire Line
	2000 4600 2000 3900
Connection ~ 2000 3900
Connection ~ 2750 3900
Wire Wire Line
	600  3900 600  4600
Wire Wire Line
	2750 4600 2750 3900
Wire Wire Line
	700  4050 700  4350
Wire Wire Line
	1400 4350 1400 4050
Connection ~ 1400 4050
Wire Wire Line
	2100 4350 2100 4050
Connection ~ 2100 4050
Wire Wire Line
	2850 4350 2850 4050
Connection ~ 2850 4050
Wire Wire Line
	1000 4500 1250 4500
Wire Wire Line
	1250 4500 1250 5000
Wire Wire Line
	1250 4750 3450 4750
Wire Wire Line
	3450 4750 3450 4550
Wire Wire Line
	3450 4550 4250 4550
Connection ~ 1250 4750
Wire Wire Line
	1700 4500 1950 4500
Wire Wire Line
	1950 4500 1950 5000
Wire Wire Line
	3500 4750 4250 4750
Wire Wire Line
	3500 4800 1950 4800
Connection ~ 1950 4800
Wire Wire Line
	2650 4500 2400 4500
Wire Wire Line
	3400 4500 3400 5000
Wire Wire Line
	3400 4500 3150 4500
Wire Wire Line
	3550 4950 4250 4950
Wire Wire Line
	3550 4950 3550 4850
Wire Wire Line
	3500 5150 4250 5150
Wire Wire Line
	3500 5150 3500 4900
Wire Wire Line
	3500 4900 3400 4900
Connection ~ 3400 4900
Wire Wire Line
	3500 4800 3500 4750
Wire Wire Line
	1000 5300 1000 5350
Wire Wire Line
	1000 5350 3600 5350
Wire Wire Line
	3600 5350 3600 4650
Wire Wire Line
	3600 4650 4250 4650
Wire Wire Line
	1700 5300 1700 5400
Wire Wire Line
	1700 5400 3650 5400
Wire Wire Line
	3650 5400 3650 4850
Wire Wire Line
	3650 4850 4250 4850
Wire Wire Line
	2400 5300 2400 5450
Wire Wire Line
	2400 5450 3700 5450
Wire Wire Line
	3700 5450 3700 5050
Wire Wire Line
	3700 5050 4250 5050
Wire Wire Line
	3150 5300 3150 5500
Wire Wire Line
	3150 5500 3750 5500
Wire Wire Line
	3750 5500 3750 5250
Wire Wire Line
	3750 5250 4250 5250
Wire Wire Line
	3800 5600 3800 3900
Connection ~ 3800 3900
Wire Wire Line
	3850 4050 3850 6100
Connection ~ 3850 4050
Wire Wire Line
	1250 5600 3800 5600
Wire Wire Line
	1250 5600 1250 5300
Wire Wire Line
	1950 5300 1950 5600
Connection ~ 1950 5600
Wire Wire Line
	2650 5300 2650 6350
Connection ~ 2650 5600
Wire Wire Line
	3400 5300 3400 5600
Connection ~ 3400 5600
Wire Wire Line
	3850 6100 2950 6100
Wire Wire Line
	2650 6350 2850 6350
Wire Wire Line
	3450 6350 3250 6350
Wire Wire Line
	3750 6350 4000 6350
Wire Wire Line
	4000 6350 4000 5550
Wire Wire Line
	4000 5550 4250 5550
Wire Wire Line
	3950 6000 3250 6000
Wire Wire Line
	3950 5450 3950 6000
Wire Wire Line
	3950 5450 4250 5450
Wire Wire Line
	3250 6000 3250 6250
Connection ~ 3250 6000
Wire Wire Line
	3900 1750 4500 1750
Wire Wire Line
	3950 1850 4500 1850
Wire Wire Line
	4000 2050 4500 2050
Wire Wire Line
	4050 2150 4500 2150
Wire Wire Line
	4100 2250 4500 2250
Wire Wire Line
	4150 2350 4500 2350
Wire Wire Line
	4200 2450 4500 2450
Wire Wire Line
	3050 2500 3050 4050
Connection ~ 3050 2500
Connection ~ 3050 4050
Wire Wire Line
	1050 2500 3250 2500
Wire Wire Line
	4250 2550 4500 2550
Wire Wire Line
	2950 6000 2950 5600
Connection ~ 2950 5600
Wire Wire Line
	2650 4500 2650 5000
Wire Wire Line
	2400 4600 2400 5000
Wire Wire Line
	3550 4850 2650 4850
Connection ~ 2650 4850
Wire Wire Line
	4750 4350 4700 4350
Wire Wire Line
	4700 4350 4700 4050
Connection ~ 4700 4050
Wire Wire Line
	4750 6350 4750 6550
Wire Wire Line
	4750 6550 2400 6550
Wire Wire Line
	2400 6550 2400 5600
Connection ~ 2400 5600
Wire Wire Line
	5250 5950 5300 5950
Wire Wire Line
	5300 5950 5300 4050
Connection ~ 5300 4050
Wire Wire Line
	5250 6050 5350 6050
Wire Wire Line
	5350 3200 5350 6150
Connection ~ 5350 3200
Wire Wire Line
	5350 6150 5250 6150
Connection ~ 5350 6050
Wire Wire Line
	5250 5650 5400 5650
Wire Wire Line
	5400 5650 5400 4200
Wire Wire Line
	5400 4200 5700 4200
Connection ~ 5700 2250
Wire Wire Line
	5250 5750 5450 5750
Wire Wire Line
	5450 5750 5450 4300
Wire Wire Line
	5450 4300 5750 4300
Connection ~ 5750 2350
Wire Wire Line
	5250 4550 5300 4550
Connection ~ 5300 4550
Wire Wire Line
	8450 700  8450 1250
Connection ~ 6600 700 
Wire Wire Line
	8850 700  8850 1250
Connection ~ 8450 700 
Wire Wire Line
	8450 1700 8450 1550
Wire Wire Line
	8850 1700 8850 1550
Wire Wire Line
	7400 2450 7400 2650
Wire Wire Line
	7400 2650 8450 2650
Wire Wire Line
	8450 2650 8450 2000
Wire Wire Line
	7300 2450 7300 2700
Wire Wire Line
	7300 2700 8850 2700
Wire Wire Line
	8850 2700 8850 2000
Wire Wire Line
	7200 2450 7200 2800
Wire Wire Line
	7200 2800 9200 2800
Connection ~ 6800 800 
Wire Wire Line
	9200 3200 9200 3100
Connection ~ 6600 3200
Wire Wire Line
	9200 800  9200 1500
Wire Wire Line
	9200 2800 9200 1600
NoConn ~ 7600 4550
NoConn ~ 7500 4550
NoConn ~ 7400 4550
NoConn ~ 7300 4550
NoConn ~ 7200 4550
NoConn ~ 7100 4550
NoConn ~ 7000 4550
NoConn ~ 6900 4550
NoConn ~ 6800 4550
NoConn ~ 6700 4550
NoConn ~ 6600 4550
NoConn ~ 6500 4550
NoConn ~ 4250 6150
NoConn ~ 4250 6050
NoConn ~ 4250 5950
NoConn ~ 4250 5850
NoConn ~ 4250 5750
NoConn ~ 4250 5650
NoConn ~ 4500 2750
NoConn ~ 4500 2650
NoConn ~ 7700 1250
NoConn ~ 7600 1250
NoConn ~ 7500 1250
NoConn ~ 7400 1250
NoConn ~ 7300 1250
NoConn ~ 7000 1250
NoConn ~ 6900 1250
NoConn ~ 6700 1250
NoConn ~ 6500 1250
NoConn ~ 6500 2450
NoConn ~ 6600 2450
NoConn ~ 6700 2450
NoConn ~ 6800 2450
NoConn ~ 6900 2450
NoConn ~ 7000 2450
NoConn ~ 7100 2450
NoConn ~ 7500 2450
NoConn ~ 7600 2450
NoConn ~ 7700 3350
NoConn ~ 7600 3350
NoConn ~ 7500 3350
NoConn ~ 7400 3350
NoConn ~ 7300 3350
NoConn ~ 7200 3350
NoConn ~ 7100 3350
NoConn ~ 7000 3350
NoConn ~ 6900 3350
NoConn ~ 6800 3350
NoConn ~ 6700 3350
NoConn ~ 6500 3350
NoConn ~ 5250 5050
NoConn ~ 5250 4950
NoConn ~ 5500 1650
NoConn ~ 5500 1550
Wire Wire Line
	5500 2250 5700 2250
Text Notes 9250 1900 0    60   ~ 0
StreamOn
Text Notes 550  1650 0    60   ~ 0
composite_modes
Text Notes 600  2850 0    60   ~ 0
a
Text Notes 650  4900 0    60   ~ 0
b
Text Notes 2100 6150 0    60   ~ 0
TAKE
$EndSCHEMATC
