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

#ifndef CONFIG_H
#define CONFIG_H

#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x8801
#define DEVICE_VER      0x0101
#define MANUFACTURER    t.m.k.
#define PRODUCT         Newton Keyboard Converter
#define DESCRIPTION     Converts Newton keyboard protocol into USB


/* matrix size */
#define MATRIX_ROWS     16
#define MATRIX_COLS     8

/* key combination for command */
#define IS_COMMAND()    ( \
    keyboard_report->keys[0] == KC_STOP || \
    keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
)


/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE


/*
 * Newton Serial(USART) configuration
 *     asynchronous, positive logic, 9600baud, bit order: LSB first
 *     1-start bit, 8-data bit, non parity, 1-stop bit
 */

/*
 * Hardware Serial(UART)
 *   Add protocol/serial_uart.c to SRC in Makefile
 */
#if defined(__AVR_ATmega32U4__) || defined(__AVR_ATmega32U2__)
    #define SERIAL_UART_BAUD       9600
    #define SERIAL_UART_DATA       UDR1
    #define SERIAL_UART_UBRR       ((F_CPU/(16UL*SERIAL_UART_BAUD))-1)
    #define SERIAL_UART_RXD_VECT   USART1_RX_vect
    #define SERIAL_UART_TXD_READY  (UCSR1A&(1<<UDRE1))
    #define SERIAL_UART_INIT()     do { \
        UBRR1L = (uint8_t) SERIAL_UART_UBRR;       /* baud rate */ \
        UBRR1H = (uint8_t) (SERIAL_UART_UBRR>>8);  /* baud rate */ \
        UCSR1B |= (1<<RXCIE1) | (1<<RXEN1); /* RX interrupt, RX: enable */ \
        UCSR1B |= (0<<TXCIE1) | (1<<TXEN1); /* TX interrupt, TX: enable */ \
        UCSR1C |= (0<<UPM11) | (0<<UPM10);  /* parity: none(00), even(01), odd(11) */ \
        DDRD  &= ~(1<<2); PORTD |=  (1<<2); /* Pull-up RXD pin */ \
        sei(); \
    } while(0)
#else
    #error "USART configuration is needed."
#endif


#endif
