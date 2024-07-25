#ifndef __LCD_H__
#define __LCD_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include "msp430.h"
#include "stdio.h"
#include "string.h"

//Change based on LCD Memory locations
#define pos1 9   /* Digit A1 begins at S18 */
#define pos2 5   /* Digit A2 begins at S10 */
#define pos3 3   /* Digit A3 begins at S6  */
#define pos4 18  /* Digit A4 begins at S36 */
#define pos5 14  /* Digit A5 begins at S28 */
#define pos6 7   /* Digit A6 begins at S14 */
#define pos7 1   /* Digit A7 begins at S2  */

extern const char digit[10][2];
extern const char alphabetBig[26][2];

void Init_LCD(void);
void showChar(char, int);
void showString(char*);
void clearLCD(void);

#ifdef __cplusplus
}
#endif

#endif /* __LCD_H__ */
