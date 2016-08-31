#include <stdio.h>
#include <string.h>
#include "roman.h"

/* only main should be in this file, to make all other functions in
   the prograble testable by Check.  in order to test main(), use a
   whole program testing framework like Autotest.
*/

int
main (void)
{
    char roman[1000];
    memset(roman, 0, 1000);
    strcpy(roman, "MMMCMXCIX");
    int result = roman_to_int(roman);
    sprintf("%10s = %d\n", roman, result);
  return 0;
}
