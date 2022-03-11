Apple Newton to USB keyboard protocol converter
===============================================
The target MCU is the ATMega32u4 but other USB capable AVR microcontrollers will also work.


README FIRST
------------
This converter was developed with an ANSI Apple Newton keyboard, Model X0044.

Unimap is the only keymap supported. Changes if necessary can be made in standard Unimap fashion.
The default keymap only does what's printed on the keys, with no function layers.


Connector
---------
On host/converter:

    8Pin mini DIN
       ___ ___
      /  |_|  \
     / 8  7  6 \
    | 5   4   3 |
     \_ 2   1 _/
       \_____/
     (receptacle/female side)
DO NOT FORGET TO MIRROR FOR MALE CONENCTOR ON KEYBOARD CABLE !


The MCU data pin here is for the hardware USART, but this can be changed in config.h. Note: Software UART has not been tested.

    Pin mini DIN        MCU
    ----------------------------------
    2   5V              VCC
    4   GND             GND (Also connected to shield)
    8   DATA            PD2 (Most likely marked "RX" on your board)

    All others should be left N/C




Protocol
--------
Signal: Asynchronous, Positive logic, 9600baud, Least bit first
Frame format: 1-Start bit(Lo), 8-Data bits, non-Parity, 1-Stop bit



Build Firmware
--------------
Just use 'make' to bild firmware for the TMK Newton converter.

    $ make -f Makefile.unimap clean
    $ make -f Makefile.unimap

If you are using an ATMega32u2 board instead of a 32U4 board, use following commands:

    $ make -f Makefile.unimap.32u2 clean
    $ make -f Makefile.unimap.32u2
    $ make -f Makefile.unimap.32u2 dfu
