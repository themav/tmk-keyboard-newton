/* 
 * Copyright 2012,2013 Jun Wako <wakojun@gmail.com>
 * This file is based on:
 *     LUFA-120219/Demos/Device/Lowlevel/KeyboardMouse
 *     LUFA-120219/Demos/Device/Lowlevel/GenericHID
 */

/*
             LUFA Library
     Copyright (C) Dean Camera, 2012.

  dean [at] fourwalledcubicle [dot] com
           www.lufa-lib.org
*/

/*
  Copyright 2012  Dean Camera (dean [at] fourwalledcubicle [dot] com)
  Copyright 2010  Denver Gingerich (denver [at] ossguy [dot] com)

  Permission to use, copy, modify, distribute, and sell this
  software and its documentation for any purpose is hereby granted
  without fee, provided that the above copyright notice appear in
  all copies and that both that the copyright notice and this
  permission notice and warranty disclaimer appear in supporting
  documentation, and that the name of the author not be used in
  advertising or publicity pertaining to distribution of the
  software without specific, written prior permission.

  The author disclaim all warranties with regard to this
  software, including all implied warranties of merchantability
  and fitness.  In no event shall the author be liable for any
  special, indirect or consequential damages or any damages
  whatsoever resulting from loss of use, data or profits, whether
  in an action of contract, negligence or other tortious action,
  arising out of or in connection with the use or performance of
  this software.
*/

/** \file
 *
 *  Header file for Descriptors.c.
 */

#ifndef _DESCRIPTORS_H_
#define _DESCRIPTORS_H_

#include <LUFA/Drivers/USB/USB.h>
#include <avr/pgmspace.h>


typedef struct
{
    USB_Descriptor_Configuration_Header_t Config;

#ifndef NO_KEYBOARD
    // Keyboard HID Interface
    USB_Descriptor_Interface_t            Keyboard_Interface;
    USB_HID_Descriptor_HID_t              Keyboard_HID;
    USB_Descriptor_Endpoint_t             Keyboard_INEndpoint;
#endif

#if defined(MOUSE_ENABLE) || defined(EXTRAKEY_ENABLE)
    // Mouse HID Interface
    USB_Descriptor_Interface_t            Mouse_Interface;
    USB_HID_Descriptor_HID_t              Mouse_HID;
    USB_Descriptor_Endpoint_t             Mouse_INEndpoint;
#endif

#ifdef CONSOLE_ENABLE
    // Console HID Interface
    USB_Descriptor_Interface_t            Console_Interface;
    USB_HID_Descriptor_HID_t              Console_HID;
    USB_Descriptor_Endpoint_t             Console_INEndpoint;
//    USB_Descriptor_Endpoint_t             Console_OUTEndpoint;
#endif

#if !defined(NO_KEYBOARD) && defined(NKRO_6KRO_ENABLE)
    // NKRO HID Interface
    USB_Descriptor_Interface_t            NKRO_Interface;
    USB_HID_Descriptor_HID_t              NKRO_HID;
    USB_Descriptor_Endpoint_t             NKRO_INEndpoint;
#endif
} USB_Descriptor_Configuration_t;


/* index of interface */
#ifndef NO_KEYBOARD
#   define KEYBOARD_INTERFACE          0
#else
#   define KEYBOARD_INTERFACE          -1
#endif

#if defined(MOUSE_ENABLE) || defined(EXTRAKEY_ENABLE)
#   define MOUSE_INTERFACE          (KEYBOARD_INTERFACE + 1)
#else
#   define MOUSE_INTERFACE          KEYBOARD_INTERFACE
#endif 

#ifdef CONSOLE_ENABLE
#   define CONSOLE_INTERFACE        (MOUSE_INTERFACE + 1)
#else
#   define CONSOLE_INTERFACE        MOUSE_INTERFACE
#endif

#if !defined(NO_KEYBOARD) && defined(NKRO_6KRO_ENABLE)
#   define NKRO_INTERFACE           (CONSOLE_INTERFACE + 1)
#else
#   define NKRO_INTERFACE           CONSOLE_INTERFACE
#endif


/* nubmer of interfaces */
#define TOTAL_INTERFACES            (NKRO_INTERFACE + 1)


// Endopoint number and size
#ifndef NO_KEYBOARD
#   define KEYBOARD_IN_EPNUM           1
#else
#   define KEYBOARD_IN_EPNUM           0
#endif

#if defined(MOUSE_ENABLE) || defined(EXTRAKEY_ENABLE)
#   define MOUSE_IN_EPNUM           (KEYBOARD_IN_EPNUM + 1) 
#else
#   define MOUSE_IN_EPNUM           KEYBOARD_IN_EPNUM
#endif

#ifdef CONSOLE_ENABLE
    // ATMega32U2 doesn't support double bank on endpoint 1 and 2, use 3 or 4
#   if MOUSE_IN_EPNUM < 2
#       define CONSOLE_IN_EPNUM     3
#       define CONSOLE_OUT_EPNUM    3
#   else
#       define CONSOLE_IN_EPNUM     (MOUSE_IN_EPNUM + 1)
#       define CONSOLE_OUT_EPNUM    (MOUSE_IN_EPNUM + 1)
#   endif
#else
#   define CONSOLE_OUT_EPNUM        MOUSE_IN_EPNUM
#endif

#if !defined(NO_KEYBOARD) && defined(NKRO_6KRO_ENABLE)
#   define NKRO_IN_EPNUM            (CONSOLE_OUT_EPNUM + 1)
#else
#   define NKRO_IN_EPNUM            CONSOLE_OUT_EPNUM
#endif

/* Check number of endpoints. ATmega32u2 has only four except for control endpoint. */
#if defined(__AVR_ATmega32U2__) && NKRO_IN_EPNUM > 4
#   error "Endpoints are not available enough to support all functions. Disable some of build options in Makefile.(MOUSEKEY, CONSOLE, NKRO)"
#endif


#define KEYBOARD_EPSIZE             8

#if defined(MOUSE_EXT_REPORT)
#define MOUSE_EPSIZE                10
#else
#define MOUSE_EPSIZE                8
#endif

#define CONSOLE_EPSIZE              32
#define NKRO_EPSIZE                 32


uint16_t CALLBACK_USB_GetDescriptor(const uint16_t wValue,
                                    const uint16_t wIndex,
                                    const void** const DescriptorAddress)
                                    ATTR_WARN_UNUSED_RESULT ATTR_NON_NULL_PTR_ARG(3);

#endif
