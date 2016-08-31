#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

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

static const int tabsize = (sizeof(romans) / sizeof(ROMAN_T));
// static int errno;


/**
 * utility function to lookup the numeric value of a roman numeral symbol
 */
static ROMAN_T *lookup_rn_symbol(char *sym)
{
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
		errno = ERANGE;
	}
	else
	{
		errno = 0;
		return(value);
	}
}

/**
 * convert value to string representing roman numeral
 */
int int_to_roman(char *dst, int val)
{
	if((val > 3999) || (val < 1))
	{
		errno = ERANGE;
		return(-1);
	}

	for(int i = 0; ((i < tabsize) && (val > 0)); ++i)
	{
		if(val >= romans[i].value)
		{
			val -= romans[i].value;
			strcat(dst, romans[i].symbol);
		}
	}

	errno = 0;
	return(0);
}

/**
 * add roman numeral n1 to n2
 * store roman numeral for sum in dst
 * return 0 on success or non-zero on error
 * set errno to ERANGE on error
 */
int add_roman(char *dst, char *rn1, char *rn2)
{
	int n1, n2;
	if((n1 = roman_to_int(rn1)) <= 0)
	{
		return(errno);
	}
	
	if((n2 = roman_to_int(rn2)) <= 0)
	{
		return(errno);
	}

	int rc = int_to_roman(dst, (n1 + n2));

	return(rc);
}


int subtract_roman(char *dst, char *rn2, char *rn1)
{
	int n2, n1;
	if((n1 = roman_to_int(rn1)) <= 0)
	{
		return(errno);
	}
	
	if((n2 = roman_to_int(rn2)) <= 0)
	{
		return(errno);
	}

	if(n1 >= n2)
	{
		return(EDOM);
	}

	int rc = int_to_roman(dst, (n2 - n1));
	return(rc);
}
