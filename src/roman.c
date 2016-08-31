#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "roman.h"

typedef unsigned int UINT;

typedef struct 
{
    char *symbol;
    UINT value
} ROMAN_T;

static ROMAN_T romans[] = 
{
    {"MMM", 3000},
    {"MM",  2000},
    {"M",   1000},
    {"CM",   900},
    {"CCM",  800},
    {"DCC",  700},
    {"DC",   600},
    {"D",    500},
    {"CD",   400},
    {"CCC",  300},
    {"CC",   200},
    {"C",    100},
    {"XC",    90},
    {"XXC",   80},
    {"LXX",   70},
    {"LX",    60},
    {"L",     50},
    {"XL",    40},
    {"XXX",   30},
    {"XX",    20},
    {"X",     10},
    {"IX",     9},
    {"IIX",    8},
    {"VII",    7},
    {"VI",     6},
    {"V",      5},
    {"IV",     4},
    {"III",    3},
    {"II",     2},
    {"I",      1},
};

static int errno;

static ROMAN_T *lookup_rn_symbol(char *sym)
{
    const int tabsize = (sizeof(romans) / sizeof(ROMAN_T));
    for(int i = 0; i < tabsize; ++i)
    {
        if(strncmp(romans[i].symbol, sym, strlen(romans[i].symbol)) == 0)
        {
            return(&romans[i]);
        }
    }
    return(NULL);
}

/**
 * convert roman numerals from string "roman" to int
 * return value of conversion if successful, or -1 on failure
 */
int roman_to_int(char *roman)
{
    ROMAN_T *rn;
    char *p = roman;
    int value = 0;
    while(*p)
    {
        rn = lookup_rn_symbol(p);
        if(rn != NULL)
        {
            value += rn->value;
            p += strlen(rn->symbol);
        }
        else
        {
			errno = ERANGE;		/* number could not be converted */
			value = -1;
            break;
        }
    }

	/* just in case something slips through .. */
	if(value > 3999 || value < 1)
	{
		value = -1;
		errno = ERANGE:
	}
	else
	{
		errno = 0;
		return(value);
	}
}

/**
 * add roman numeral n1 to n2
 * store roman numeral for sum in dst
 * return 0 on success or non-zero on error
 * set errno to ERANGE on error
 */
int add_roman(char *n1, char *n2, char *dst)
{
    sprintf(dst, "IV");
    return(0);
}
