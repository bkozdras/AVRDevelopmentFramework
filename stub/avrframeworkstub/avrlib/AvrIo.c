/**********************************************************************************/
/* Copyright by @bkozdras <b.kozdras@gmail.com>                                   */
/* Version: 1.0                                                                   */
/* Licence: MIT                                                                   */
/**********************************************************************************/

#include <avrframeworkstub/avrlib/AvrIo.h>

void clearMcuRegisters()
{
    DDRA = 0x00;
    DDRB = 0x00;
    DDRC = 0x00;
    DDRD = 0x00;
    PINA = 0x00;
    PINB = 0x00;
    PINC = 0x00;
    PIND = 0x00;
    PORTA = 0x00;
    PORTB = 0x00;
    PORTC = 0x00;
    PORTD = 0x00;
    TIMSK2 = 0x00;
    TCCR2A = 0x00;
    TCCR2B = 0x00;
    TCNT2 = 0x00;
    OCR2A = 0x00;
    OCR2B = 0x00;
}

TMcuRegister DDRA = 0x00;
TMcuRegister DDRB = 0x00;
TMcuRegister DDRC = 0x00;
TMcuRegister DDRD = 0x00;

TMcuRegister PINA = 0x00;
TMcuRegister PINB = 0x00;
TMcuRegister PINC = 0x00;
TMcuRegister PIND = 0x00;

TMcuRegister PORTA = 0x00;
TMcuRegister PORTB = 0x00;
TMcuRegister PORTC = 0x00;
TMcuRegister PORTD = 0x00;

TMcuRegister TIMSK2 = 0x00;
TMcuRegister TCCR2A = 0x00;
TMcuRegister TCCR2B = 0x00;
TMcuRegister TCNT2 = 0x00;
TMcuRegister OCR2A = 0x00;
TMcuRegister OCR2B = 0x00;
