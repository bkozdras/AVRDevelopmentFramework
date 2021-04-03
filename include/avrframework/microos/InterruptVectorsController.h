/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#ifndef AVRFRAMEWORK_MICROOS_INTERRUPTVECTORSCONTROLLER_H_
#define AVRFRAMEWORK_MICROOS_INTERRUPTVECTORSCONTROLLER_H_

#include <avrframework/types/TCallback.h>

void InterruptVectorsController_callOnTIMER2_COMPA_vect(const TCallback callback);
void InterruptVectorsController_resetTIMER2_COMPA_vect();

#endif // AVRFRAMEWORK_MICROOS_INTERRUPTVECTORSCONTROLLER_H_
