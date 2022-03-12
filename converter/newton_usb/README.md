Apple Newton to USB Keyboard Protocol Converter
===============================================
While the target MCU is the ATMega32U4, other USB capable AVR microcontrollers also work.


README FIRST
------------
This converter was developed with an ANSI Apple Newton keyboard, model X0044.

Unimap is the only keymap supported. Changes if necessary can be made in the standard Unimap fashion, including the TMK website's keymap editor.

The default keymap only does what's printed on the keys, with the exception of grave swapped for escape.
That being said, a layer 1 with grave, F1-F12 and forward delete is provided. Press left and right shift simultaneously, then press the 1 key to switch to this layer. When done with those keys, press left/right shift simultaneously again and press 0 to return to the default layer.


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
    8   DATA            PD2 (Most likely marked "RX1" on your board)

    All others should be left N/C




Protocol
--------
Signal: Asynchronous serial, Positive logic, 9600baud, Least bit first.
Frame format: 1-Start bit(Lo), 8-Data bits, non-Parity, 1-Stop bit.



Build Firmware
--------------
Use 'make' to build the firmware for the TMK Newton converter:

    $ make -f Makefile.unimap clean
    $ make -f Makefile.unimap

If you are using an ATMega32U2 board instead of a 32U4 board, use following commands:

    $ make -f Makefile.unimap.32u2 clean
    $ make -f Makefile.unimap.32u2
