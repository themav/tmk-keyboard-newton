/*
Copyright 2018 Jun Wako <wakojun@gmail.com>
Modified by TheMK 2022

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
#ifndef _TRANS_H
#define _TRANS_H

#include <stdint.h>
#include <avr/pgmspace.h>
#include "unimap.h"


// Mapping Newton scan codes to UNIMAP layout codes

/* Apple Newton ANSI Keyboard
 *,-----------------------------------------------------------.
 *| B2| 92| 93| 94| 95| 97| 96| 9A| 9C| 99| 9D| 9B| 98|  B3   |
 *|-----------------------------------------------------------|
 *|  B0 | 8C| 8D| 8E| 8F| 91| 90| A0| A2| 9F| A3| A1| 9E| AA  |
 *|-----------------------------------------------------------|
 *|  B9  | 80| 81| 82| 83| 85| 84| A6| A8| A5| A9| A7|   A4   |
 *|-----------------------------------------------------------|
 *|   B8   | 86| 87| 88| 89| 8B| AD| AE| AB| AF| AC|    BC    |
 *|-----------------------------------------------------------|
 *|  BB |  BA  |  B7  |       B1          |  FB|  FC| FD| FE  |
 *`-----------------------------------------------------------'
 */

const uint8_t PROGMEM unimap_trans[MATRIX_ROWS][MATRIX_COLS] = {
    { UNIMAP_A,  UNIMAP_S,    UNIMAP_D,    UNIMAP_F,    UNIMAP_H,    UNIMAP_G,    UNIMAP_Z,    UNIMAP_X     }, /* 80-87 */
    { UNIMAP_C,    UNIMAP_V,    UNIMAP_NO,    UNIMAP_B, UNIMAP_Q,  UNIMAP_W, UNIMAP_E, UNIMAP_R   }, /* 88-8F */
    { UNIMAP_Y,    UNIMAP_T,    UNIMAP_1,    UNIMAP_2,    UNIMAP_3,    UNIMAP_4,    UNIMAP_6,    UNIMAP_5     }, /* 90-97 */
    { UNIMAP_EQL,    UNIMAP_9,    UNIMAP_7, UNIMAP_MINS, UNIMAP_8,  UNIMAP_0,    UNIMAP_RBRC,    UNIMAP_O     }, /* 98-9F */
    { UNIMAP_U,    UNIMAP_LBRC,    UNIMAP_I,    UNIMAP_P,    UNIMAP_ENT,    UNIMAP_L,   UNIMAP_J, UNIMAP_QUOT  }, /* A0-A7 */
    { UNIMAP_K, UNIMAP_SCLN,    UNIMAP_BSLS,    UNIMAP_COMM,    UNIMAP_SLSH,    UNIMAP_N,    UNIMAP_M,    UNIMAP_DOT     }, /* A8-AF */
    { UNIMAP_TAB, UNIMAP_SPC,  UNIMAP_GRV, UNIMAP_BSPC,   UNIMAP_NO,  UNIMAP_ESC, UNIMAP_NO, UNIMAP_LGUI  }, /* B0-B7 */
    { UNIMAP_LSFT,  UNIMAP_CAPS,  UNIMAP_LALT,   UNIMAP_LCTL, UNIMAP_RSFT, UNIMAP_RALT, UNIMAP_RCTL, UNIMAP_NO   }, /* B8-BF */
    { UNIMAP_NO, UNIMAP_NO, UNIMAP_NO,   UNIMAP_NO,   UNIMAP_NO,   UNIMAP_NO, UNIMAP_NO,   UNIMAP_NO    }, /* C0-C7 */
    { UNIMAP_NO,   UNIMAP_NO, UNIMAP_NO,   UNIMAP_NO,   UNIMAP_NO,   UNIMAP_NO, UNIMAP_NO,   UNIMAP_NO  }, /* C8-CF */
    { UNIMAP_NO, UNIMAP_NO, UNIMAP_NO,  UNIMAP_NO,  UNIMAP_NO,  UNIMAP_NO,  UNIMAP_NO,  UNIMAP_NO    }, /* D0-D7 */
    { UNIMAP_NO,  UNIMAP_NO,  UNIMAP_NO,  UNIMAP_NO,  UNIMAP_NO,   UNIMAP_NO,   UNIMAP_NO,  UNIMAP_NO    }, /* D8-DF */
    { UNIMAP_NO, UNIMAP_NO, UNIMAP_NO,   UNIMAP_NO,   UNIMAP_NO,   UNIMAP_NO,   UNIMAP_NO,   UNIMAP_NO    }, /* E0-E7 */
    { UNIMAP_NO,   UNIMAP_NO,   UNIMAP_NO,   UNIMAP_NO,  UNIMAP_NO,   UNIMAP_NO,   UNIMAP_NO,   UNIMAP_NO    }, /* E8-EF */
    { UNIMAP_NO, UNIMAP_NO, UNIMAP_NO, UNIMAP_NO, UNIMAP_NO, UNIMAP_NO,   UNIMAP_NO,   UNIMAP_NO    }, /* F0-F7 */
    { UNIMAP_NO, UNIMAP_NO, UNIMAP_NO, UNIMAP_LEFT,  UNIMAP_RGHT,   UNIMAP_DOWN,   UNIMAP_UP,   UNIMAP_NO    }  /* F8-FF */
};

#endif
