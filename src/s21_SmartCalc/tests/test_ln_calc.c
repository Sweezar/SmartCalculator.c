#include "tests.h"

START_TEST(test_ln_calc_1) {
  double res = 0;
  double reference = log(9);
  char *expression = "ln(9)";
  evaluate_expression(expression, &res);

  ck_assert_double_eq_tol(reference, res, ACCURACY);
}
END_TEST

START_TEST(test_ln_calc_2) {
  double res = 0;
  double reference = log(9) - log(25) / (-10) - 1038;
  char *expression = "ln(9)-ln(25)/(-10)-1038";
  evaluate_expression(expression, &res);

  ck_assert_double_eq_tol(reference, res, ACCURACY);
}
END_TEST

START_TEST(test_ln_calc_3) {
  double res = 0;
  double reference = log(9+78) / log(1/2.0) / (10.0 + 1038);
  char *expression = "ln(9+78)/ln(1/2.0)/(10.0+1038)";
  evaluate_expression(expression, &res);

  ck_assert_double_eq_tol(reference, res, ACCURACY);
}
END_TEST

START_TEST(test_ln_calc_4) {
  double res = 0;
  double reference = log(((1 / 3.0) - (-7 / -9.1)) + 10 + 1038);
  char *expression = "ln(((1/3.0)-(-7/-9.1))+10+1038)";
  evaluate_expression(expression, &res);

  ck_assert_double_eq_tol(reference, res, ACCURACY);
}
END_TEST

START_TEST(test_ln_calc_5) { 
  double res = 0;
  char *expression = "ln(((1/3.0)-(-7/-9.1))+10-1038)"; // NaN
  evaluate_expression(expression, &res);

  ck_assert_double_nan(res);
}
END_TEST

Suite *test_ln_calc(void) {
  Suite *s = suite_create("\033[45m-=LN=-\033[0m");
  TCase *tc = tcase_create("LN");

  tcase_add_test(tc, test_ln_calc_1);
  tcase_add_test(tc, test_ln_calc_2);
  tcase_add_test(tc, test_ln_calc_3);
  tcase_add_test(tc, test_ln_calc_4);
  tcase_add_test(tc, test_ln_calc_5);

  suite_add_tcase(s, tc);
  return s;
}
