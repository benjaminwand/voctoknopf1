#!/bin/bash
before=$(mktemp)
ls /dev/ > $before
echo “insert usb device, press enter when done”
read
after=$(mktemp)
ls /dev/ -> $after
echo “new devices”
diff $before $after
rm $before
rm $after

