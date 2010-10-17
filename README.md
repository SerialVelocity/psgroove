PSGroove
========

This is the PSGroove, an open-source reimplementation of the psjailbreak exploit for
non-USB AVR microcontrollers which use the V-USB library.

It is configured to work on:

- Arduino Mega
- Arduino Duemilanove

**This software is not intended to enable piracy, and such features
have been disabled.  This software is intended to allow the execution
of unsigned third-party apps and games on the PS3.**

Cloning
-------
The repository uses the PL3 repository as a submodule.  To clone, use something like:

    git clone git://github.com/SerialVelocity/psgroove.git
    cd psgroove
    git submodule init
    git submodule update


Configuring
-----------
Chip and board selection can usually be handled in the Makefile.
In particular, update the MCU, BOARD, and F_CPU lines.  Suggested values:

Arduino Mega:
 
    MCU = atmega1280
    BOARD = ArduinoMega
    F_CLOCK = 16000000

Arduino Duemilanove with ATMega328p chip:

    MCU = atmega328p
    BOARD = ArduinoDuemilanove
    F_CLOCK = 16000000

Arduino Duemilanove with ATMega168 chip

    MCU = atmega168
    BOARD = ArduinoDuemilanove
    F_CLOCK = 16000000

Building
--------
On Linux, use the AVR GCC toolchain (Debian/Ubuntu package: gcc-avr).
On Windows, WinAVR should do the trick.

    make clean
    make


Programming
-----------
Now program psgroove.hex into your board and you're ready to go.

Windows:
    Follow instructions on timwu's repository
Linux: Install avrdude and run:
    make program

Using
-----
To use this exploit:
  
* Hard power cycle your PS3 (using the switch in back, or unplug it)
* Plug the dongle into your PS3.
* Press the PS3 power button, followed quickly by the eject button.

After a few seconds, the first LED on your dongle should light up.
After about 5 seconds, the second LED will light up (or the LED will
just go off, if you only have one).  This means the exploit worked!
You can see the new "Install Package Files" menu option in the game
menu.


Notes
-----
A programmed dongle won't enumerate properly on a PC, so don't worry
about that.

This branch has a modified payload that adds peek and poke syscalls 
to the lv2 kernel. A userspace application can use these syscalls to 
dump out the entire memory space of the kernel, or patch the kernel
as it is running.  

