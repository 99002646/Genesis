#include "leapyear.h"
/* Return values
 * 1 if given year is leap
 * 0 if not a leap year
 */
int IsLeapYear(int yy) {
  return yy%4==0;
}
