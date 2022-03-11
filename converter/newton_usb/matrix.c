/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Modifications made by Themav.

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdint.h>
#include <stdbool.h>
#include <avr/io.h>
#include <util/delay.h>
#include "print.h"
#include "util.h"
#include "matrix.h"
#include "led.h"
#include "debug.h"
#include "protocol/serial.h"


/*
 * Matrix Array usage:
 *
 * ROW: 16(4bits)
 * COL:  8(3bits)
 *
 *    8bit wide
 *   +---------+
 *  0|00 ... 07|
 *  1|08 ... 0F|
 *  :|   ...   |
 *  :|   ...   |
 *  E|70 ... 77|
 *  F|78 ... 7F|
 *   +---------+
 */
static uint8_t matrix[MATRIX_ROWS];
#define ROW(code)      ((code>>3)&0xF)
#define COL(code)      (code&0x07)

void matrix_init(void)
{
    debug_keyboard = true;

    serial_init(); //Start USART

	// initialize matrix state: all keys off
    for (uint8_t i=0; i < MATRIX_ROWS; i++) matrix[i] = 0x00;

	print("matrix_init done.\n");
    return;
}

uint8_t matrix_scan(void)
{
    uint16_t code;
    code = serial_recv2(); //Read the scancode from the interface.
    if (code == -1) {
        return 0; //Do nothing if no code was received.
    }

    print_hex8(code); print(" "); //Debug output

    // Check to see if this is a make or break code. Since make codes are all above 0x80 and-ing them with 0x80 should return true.
    if (code & 0x80) {
        // Make scancode
        if (!matrix_is_on(ROW(code), COL(code))) {
            matrix[ROW(code)] |=  (1<<COL(code));
        }
    } else {
        // Break scancode
        if (matrix_is_on(ROW(code), COL(code))) {
            matrix[ROW(code)] &= ~(1<<COL(code));
        }
    }
	return code;
}

inline
uint8_t matrix_get_row(uint8_t row)
{
    return matrix[row];
}

//NOOP since this keyboard does not have LEDs.
void led_set(uint8_t usb_led)
{
}
