The **keycaps** are: <https://github.com/benjaminwand/Cherry-MX-keycaps/blob/master/with%20LED/gothic.FCStd>, 20 * 33,5 mm for the composite mode buttons and 25 * 25 mm for the camera/channel buttons and the take button. Please adjust the side lengths in the spreadsheet of the file.

Lessons learnt after PCB production V 1.0: 
* wrong footprint for resistors, too short
* wrong footprint for cherry switches, contacts for LEDs are too far apart
* the Cherry MX from reichelt.de aren’t for PCB mount, be more careful when shopping
* wrong footprint for StreamOn switch, fix: bend up two diagonal contacts
* 1.5k ohm pull-up-resistors are required between A4 and 5V and A5 and 5V
* the buttons would look more evenly illuminated if the LED was behind the switches -> turn the Cherry MX around 180°

Shopping list:
* 1 arduino nano (clone)
* 1 ethernet-shield for arduino nano
* 12 Cherry MX switches with holes for LEDs, for PCB mount. I used ‘clear’ and would go for ‘brown’ next time.
* 12 3mm LEDs, 4 red, 4 blue, 4 other color (yellow). alternatively there are probably special LEDs für Cherry MX but I didn’t have the time for searching
* 1 tact switch for StreamOn-button 
* 1 5mm LED red
* 1 5mm LED green
* 14 resistors 220
* 13 resistors 10k
* 2 resistors 1.5k