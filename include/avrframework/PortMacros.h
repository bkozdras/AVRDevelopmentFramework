/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Purpose: Macros for accessing MCU ports data.                                  */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#ifndef AVRFRAMEWORK_PORTMACROS_H_
#define AVRFRAMEWORK_PORTMACROS_H_

#define PORT(x) SPORT(x)
#define SPORT(x) (PORT##x)

#define PIN(x) SPIN(x)
#define SPIN(x) (PIN##x)

#define DDR(x) SDDR(x)
#define SDDR(x) (DDR##x)

#define PA(x) SPA(x)
#define SPA(x) (PA##x)

#define PB(x) SPB(x)
#define SPB(x) (PB##x)

#define PC(x) SPC(x)
#define SPC(x) (PC##x)

#define PD(x) SPD(x)
#define SPD(x) (PD##x)

#endif // AVRFRAMEWORK_PORTMACROS_H_
