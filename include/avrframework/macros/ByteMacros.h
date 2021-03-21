/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Purpose: Macros for operations on bytes.                                       */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#ifndef AVRFRAMEWORK_MACROS_BYTEMACROS_H_
#define AVRFRAMEWORK_MACROS_BYTEMACROS_H_

#define BYTE_SET_BIT(_BYTE, _BIT) (_BYTE |= (1 << _BIT))
#define BYTE_CLEAR_BIT(_BYTE, _BIT) (_BYTE &= ~(1 << _BIT))

#define BYTE_IS_BIT_SET(_BYTE, _BIT) (_BYTE & (1 << _BIT))
#define BYTE_IS_BIT_CLEARED(_BYTE, _BIT) (!(_BYTE & (1 << _BIT)))

#endif // AVRFRAMEWORK_MACROS_BYTEMACROS_H_
