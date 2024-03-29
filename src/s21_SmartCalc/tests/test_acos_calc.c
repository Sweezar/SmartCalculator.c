#include "tests.h"

START_TEST(test_acos_calc_1) {
  double res = 0;
  double reference = acos(0.5);
  char *expression = "acos(0.5)";
  evaluate_expression(expression, &res, 0);

  ck_assert_double_eq_tol(reference, res, ACCURACY);
}
END_TEST

START_TEST(test_acos_calc_2) {
  double res = 0;
  double reference = 10 - acos(0.5);
  char *expression = "10-acos(0.5)";
  evaluate_expression(expression, &res, 0);

  ck_assert_double_eq_tol(reference, res, ACCURACY);
}
END_TEST

START_TEST(test_acos_calc_3) {
  double res = 0;
  double reference = 10 - acos(48.5 - 48.35);
  char *expression = "10-acos(48.5-48.35)";
  evaluate_expression(expression, &res, 0);

  ck_assert_double_eq_tol(reference, res, ACCURACY);
}
END_TEST

START_TEST(test_acos_calc_4) {
  double res = 0;
  double reference = 10 - acos(48.5 * 0.0035) / 2;
  char *expression = "10-acos(48.5*0.0035)/2";
  evaluate_expression(expression, &res, 0);

  ck_assert_double_eq_tol(reference, res, ACCURACY);
}
END_TEST

Suite *test_acos_calc(void) {
  Suite *s = suite_create("\033[45m-=ACOS=-\033[0m");
  TCase *tc = tcase_create("ACOS");

  tcase_add_test(tc, test_acos_calc_1);
  tcase_add_test(tc, test_acos_calc_2);
  tcase_add_test(tc, test_acos_calc_3);
  tcase_add_test(tc, test_acos_calc_4);

  suite_add_tcase(s, tc);
  return s;
}