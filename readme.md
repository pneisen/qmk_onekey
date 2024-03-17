# OneKey keyboard QMK firmware 

The OneKey keyboard is a one key keyboard I built for my kids. It is powered by QMK running on a Seeed Studio RP2040 XIAO. The case is custom 3d printed.

![Image of OneKey keyboards](https://github.com/pneisen/qmk_onekey/blob/main/pics/onekeys.jpg)

The firmware can be changed to have the key do anything or multiple things that a keyboard can do. By default, the firmware will output a random pallindrome phrase. If the key is held down for 5 seconds, the microcontroller will enter the bootloader allowing new firmware to be flashed. 
