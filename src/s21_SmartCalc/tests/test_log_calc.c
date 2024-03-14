#include "tests.h"

START_TEST(test_log_calc_1) {
  double res = 0;
  double reference = log10(152.89);
  char *expression = "log(152.89)";
  evaluate_expression(expression, &res, 0);

  ck_assert_double_eq_tol(reference, res, ACCURACY);
}
END_TEST

START_TEST(test_log_calc_2) {
  double res = 0;
  double reference = log10(9) - log10(25) / (-10) - 1038;
  char *expression = "log(9)-log(25)/(-10)-1038";
  evaluate_expression(expression, &res, 0);

  ck_assert_double_eq_tol(reference, res, ACCURACY);
}
END_TEST

START_TEST(test_log_calc_3) {
  double res = 0;
  double reference = log10(9 + 78) / log10(1 / 2.0) / (10.0 + 1038);
  char *expression = "log(9+78)/log(1/2.0)/(10.0+1038)";
  evaluate_expression(expression, &res, 0);

  ck_assert_double_eq_tol(reference, res, ACCURACY);
}
END_TEST

START_TEST(test_log_calc_4) {
  double res = 0;
  double reference = log10(((1 / 3.0) - (-7 / -9.1)) + 10 + 1038);
  char *expression = "log(((1/3.0)-(-7/-9.1))+10+1038)";
  evaluate_expression(expression, &res, 0);

  ck_assert_double_eq_tol(reference, res, ACCURACY);
}
END_TEST

START_TEST(test_log_calc_5) {
  double res = 0;
  char *expression = "log(((1/3.0)-(-7/-9.1))+10-1038)";  // NaN
  evaluate_expression(expression, &res, 0);

  ck_assert_double_nan(res);
}
END_TEST

Suite *test_log_calc(void) {
  Suite *s = suite_create("\033[45m-=LOG=-\033[0m");
  TCase *tc = tcase_create("LOG");

  tcase_add_test(tc, test_log_calc_1);
  tcase_add_test(tc, test_log_calc_2);
  tcase_add_test(tc, test_log_calc_3);
  tcase_add_test(tc, test_log_calc_4);
  tcase_add_test(tc, test_log_calc_5);

  suite_add_tcase(s, tc);
  return s;
}
