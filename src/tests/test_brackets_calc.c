#include "tests.h"

START_TEST(test_brackets_calc_1) {
  
}
END_TEST

Suite *test_calc_complements(void) {
  Suite *s = suite_create("\033[45m-=S21_CALC_COMPLEMENTS=-\033[0m");
  TCase *tc = tcase_create("CALC_COMPLEMENTS");

  tcase_add_test(tc, test_brackets_calc_1);

  suite_add_tcase(s, tc);
  return s;
}
