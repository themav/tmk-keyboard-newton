TMK Keyboard for Apple Newton
=============================
This repository includes my Apple Newton converter project built with the [`tmk_core`](https://github.com/tmk/tmk_core) keyboard firmware library.

This firmware is expected to support all of the features available to TMK protocol converters. If you have any issues, please open a bug. Additionally, comments or suggestions are welcome in the discussions tab.

The latest TMK source code is available here: <http://github.com/tmk/tmk_keyboard>



Documentation
-------------
See the [`README.md`](./converter/newton_usb/README.md) for wiring and build instructions, as well as further information about the converter.


Refer to the wiki pages for further info on TMK:

https://github.com/tmk/tmk_keyboard/wiki



License
-------
**GPLv2** or later. Some protocol files are under **Modified BSD License**.

Third party libraries like LUFA, PJRC and V-USB have their own license respectively.



FAQ
---
Q1. Will you port this converter to the QMK firmware project?  
 A. At some point I am very likely to redo this to eliminate the dependency on AVR, and, at that time I will likely consider porting to QMK.
