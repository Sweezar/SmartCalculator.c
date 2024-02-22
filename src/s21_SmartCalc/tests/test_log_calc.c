#include "tests.h"

START_TEST(test_lg_calc_1) {
  double res = 0;
  double reference = log10(152.89);
  char *expression = "lg(152.89)";
  res = evaluate_expression(expression);

  ck_assert_double_eq_tol(reference, res, ACCURACY);
}
END_TEST

START_TEST(test_log_calc_2) {
  double res = 0;
  double reference = log10(9) - log10(25) / (-10) - 1038;
  char *expression = "lg(9)-lg(25)/(-10)-1038";
  res = evaluate_expression(expression);

  ck_assert_double_eq_tol(reference, res, ACCURACY);
}
END_TEST

START_TEST(test_log_calc_3) {
  double res = 0;
  double reference = log10(9+78) / log10(1/2.0) / (10.0 + 1038);
  char *expression = "lg(9+78)/lg(1/2.0)/(10.0+1038)";
  res = evaluate_expression(expression);

  ck_assert_double_eq_tol(reference, res, ACCURACY);
}
END_TEST

START_TEST(test_log_calc_4) {
  double res = 0;
  double reference = log10(((1 / 3.0) - (-7 / -9.1)) + 10 + 1038);
  char *expression = "lg(((1/3.0)-(-7/-9.1))+10+1038)";
  res = evaluate_expression(expression);

  ck_assert_double_eq_tol(reference, res, ACCURACY);
}
END_TEST

START_TEST(test_log_calc_5) { 
  double res = 0;
  char *expression = "lg(((1/3.0)-(-7/-9.1))+10-1038)"; // NaN
  res = evaluate_expression(expression);

  ck_assert_double_nan(res);
}
END_TEST

Suite *test_log_calc(void) {
  Suite *s = suite_create("\033[45m-=LG=-\033[0m");
  TCase *tc = tcase_create("LG");

  tcase_add_test(tc, test_lg_calc_1);
  tcase_add_test(tc, test_log_calc_2);
  tcase_add_test(tc, test_log_calc_3);
  tcase_add_test(tc, test_log_calc_4);
  tcase_add_test(tc, test_log_calc_5);

  suite_add_tcase(s, tc);
  return s;
}
