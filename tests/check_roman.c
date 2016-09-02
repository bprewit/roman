#include <stdio.h>
#include <stdlib.h>
#include <check.h>
#include "../src/roman.h"

#define BUFSIZE 4096

char *result;

/**
 * test setup - allocate space for result
 */
void setup(void)
{
    result = calloc(BUFSIZE, sizeof(char));
}

/**
 * test cleanup - free previously allocated space
 */
void teardown(void)
{
    free(result);
}

START_TEST(test_convert_int_to_roman)
{
	char roman[1000];

	int rc;

	memset(roman, 0, sizeof(roman));
	rc = int_to_roman(roman, 1);
	ck_assert_int_eq(rc, 0);
	ck_assert_str_eq(roman, "I");

	memset(roman, 0, sizeof(roman));
	rc = int_to_roman(roman, 2);
	ck_assert_int_eq(rc, 0);
	ck_assert_str_eq(roman, "II");

	memset(roman, 0, sizeof(roman));
	rc = int_to_roman(roman, 10);
	ck_assert_int_eq(rc, 0);
	ck_assert_str_eq(roman, "X");

	memset(roman, 0, sizeof(roman));
	rc = int_to_roman(roman, 3999);
	ck_assert_int_eq(rc, 0);
	ck_assert_str_eq(roman, "MMMCMXCIX");
}
END_TEST

START_TEST(test_convert_roman_to_int)
{
    int num;
    
    num = roman_to_int("I");
    ck_assert_int_eq(num, 1);
    
	num = roman_to_int("II");
	ck_assert_int_eq(num, 2);

    num = roman_to_int("V");
    ck_assert_int_eq(num, 5);
    
    num = roman_to_int("MMMCMXCIX");
    ck_assert_int_eq(num, 3999);
}
END_TEST

START_TEST(test_add_roman)
{
    int rc = add_roman(result, "II", "II");
    ck_assert_int_eq(rc, 0);
    ck_assert_str_eq(result, "IV");
}
END_TEST

START_TEST(test_subtract_roman)
{
	int rc = subtract_roman(result, "X", "III");
	ck_assert_int_eq(rc, 0);
	ck_assert_str_eq(result, "VII");
}
END_TEST

START_TEST(test_long_roman)
{
	int num = roman_to_int("MMMDCCCLXXXVIII");
	ck_assert_int_eq(num, 3888);
}
END_TEST

START_TEST(test_empty_string)
{
	int num = roman_to_int("");
	ck_assert_int_eq(num, -1);
}
END_TEST

START_TEST(test_invalid_input)
{
	int num = roman_to_int("XYZZY");
	ck_assert_int_eq(num, -1);
}
END_TEST

START_TEST(test_null_input)
{
	char *sym = NULL;
	int num = roman_to_int(sym);
	ck_assert_int_eq(num, -1);
}
END_TEST

Suite *test_suite(void)
{
  Suite *s = suite_create("Roman");

  TCase *core = tcase_create("Core");
  tcase_add_checked_fixture(core, setup, teardown);
  
  tcase_add_test(core, test_add_roman);
  tcase_add_test(core, test_convert_roman_to_int);
  tcase_add_test(core, test_convert_int_to_roman);
  tcase_add_test(core, test_long_roman);  
  tcase_add_test(core, test_empty_string);
  tcase_add_test(core, test_invalid_input);

  suite_add_tcase(s, core);

  return(s);
}

int main(void)
{
  int n_failed;
  Suite *s = test_suite();
  SRunner *sr = srunner_create(s);
  srunner_run_all(sr, CK_VERBOSE);
  n_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return((n_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE);
}

