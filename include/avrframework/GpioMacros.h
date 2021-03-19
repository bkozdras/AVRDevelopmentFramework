/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Purpose: Macros for operations on MCU General Purpose Input / Output.          */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#ifndef AVRFRAMEWORK_GPIOMACROS_H_
#define AVRFRAMEWORK_GPIOMACROS_H_

#define GPIO_SET_INPUT_LINE(_PORTIDENT, _PINNUMBER) _GPIO_SET_INPUT_LINE(_PORTIDENT, _PINNUMBER)
#define _GPIO_SET_INPUT_LINE(_PORTIDENT, _PINNUMBER) (DDR##_PORTIDENT &= ~(1 << _PINNUMBER))

#define GPIO_SET_OUTPUT_LINE(_PORTIDENT, _PINNUMBER) _GPIO_SET_OUTPUT_LINE(_PORTIDENT, _PINNUMBER)
#define _GPIO_SET_OUTPUT_LINE(_PORTIDENT, _PINNUMBER) (DDR##_PORTIDENT |= (1 << _PINNUMBER))

#define GPIO_SET_HIGH_LEVEL_ON_LINE(_PORTIDENT, _PINNUMBER) _GPIO_SET_HIGH_LEVEL_ON_LINE(_PORTIDENT, _PINNUMBER)
#define _GPIO_SET_HIGH_LEVEL_ON_LINE(_PORTIDENT, _PINNUMBER) (PORT##_PORTIDENT |= (1 << _PINNUMBER))

#define GPIO_SET_LOW_LEVEL_ON_LINE(_PORTIDENT, _PINNUMBER) _GPIO_SET_LOW_LEVEL_ON_LINE(_PORTIDENT, _PINNUMBER)
#define _GPIO_SET_LOW_LEVEL_ON_LINE(_PORTIDENT, _PINNUMBER) (PORT##_PORTIDENT &= ~(1 << _PINNUMBER))

#define GPIO_IS_HIGH_LEVEL_ON_LINE(_PORTIDENT, _PINNUMBER) _GPIO_IS_HIGH_LEVEL_ON_LINE(_PORTIDENT, _PINNUMBER)
#define _GPIO_IS_HIGH_LEVEL_ON_LINE(_PORTIDENT, _PINNUMBER) (PIN##_PORTIDENT & (1 << _PINNUMBER))

#define GPIO_IS_LOW_LEVEL_ON_LINE(_PORTIDENT, _PINNUMBER) _GPIO_IS_LOW_LEVEL_ON_LINE(_PORTIDENT, _PINNUMBER)
#define _GPIO_IS_LOW_LEVEL_ON_LINE(_PORTIDENT, _PINNUMBER) (!(PIN##_PORTIDENT & (1 << _PINNUMBER)))

#endif // AVRFRAMEWORK_GPIOMACROS_H_
