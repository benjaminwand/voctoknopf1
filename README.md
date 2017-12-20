The keycaps are: <github.com/benjaminwand/Cherry-MX-keycaps/blob/master/gothic.FCStd>, 20 * 33,5 mm for the composite mode buttons and 25 * 25 mm for the camera/channel buttons and the take button. Please adjust the side lengths in the spreadsheet of the file.

Lessons learnt after PCB production: 
* wrong footprint for resistors, too short
* wrong footprint for cherry switches, contacts for LEDs are too far apart
* the Cherry MX from reichelt.de aren’t for PCB mount, be more careful when shopping
* wrong footprint for StreamOn switch, needs to bend up two diagonal contacts
* 1.5k ohm pull-up-resistors are required between A4 and 5V and A5 and 5V

Shopping list:
* 1 arduino nano (clone)
* 1 ethernet-shield for arduino nano
* 12 Cherry MX switches with holes for LEDs, for PCB mount
* 12 3mm LEDs, 4 red, 4 blue, 4 other color (yellow). alternatively there are probably special LEDs für Cherry MX but I didn’t have the time for searching
* 1 switch for StreamOn-button
* 1 5mm LED red
* 1 5mm LED green
* 14 resistors 220
* 13 resistors 10k
* 2 resistors 1.5k