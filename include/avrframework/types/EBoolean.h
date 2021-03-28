/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Purpose: Defined EBoolean type.                                                */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#ifndef AVRFRAMEWORK_TYPES_EBOOLEAN_H_
#define AVRFRAMEWORK_TYPES_EBOOLEAN_H_

typedef enum __attribute__((__packed__)) _EBoolean
{
    EBoolean_False = 0,
    EBoolean_True  = 1
} EBoolean;

_Static_assert(sizeof(EBoolean) == sizeof(uint8_t), L"EBoolean size");

#endif // AVRFRAMEWORK_TYPES_EBOOLEAN_H_
