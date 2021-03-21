/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Purpose: Macros for getting IO registers by defined hardware settings.         */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#ifndef AVRFRAMEWORK_MACROS_IOMACROS_H_
#define AVRFRAMEWORK_MACROS_IOMACROS_H_

#define IO_GET_DDR(_PORT) DDR##_PORT
#define IO_GET_PIN(_PORT) PIN##_PORT
#define IO_GET_PORT(_PORT) PORT##_PORT

#endif // AVRFRAMEWORK_MACROS_IOMACROS_H_
