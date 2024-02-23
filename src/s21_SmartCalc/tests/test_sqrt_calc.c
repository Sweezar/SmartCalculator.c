#include "tests.h"

START_TEST(test_sqrt_calc_1) {
  double res = 0;
  double reference = sqrt(9);
  char *expression = "sqrt(9)";
  evaluate_expression(expression, &res);

  ck_assert_double_eq_tol(reference, res, ACCURACY);
}
END_TEST

START_TEST(test_sqrt_calc_2) {
  double res = 0;
  double reference = sqrt(9) - sqrt(25) / (-10) - 1038;
  char *expression = "sqrt(9)-sqrt(25)/(-10)-1038";
  evaluate_expression(expression, &res);

  ck_assert_double_eq_tol(reference, res, ACCURACY);
}
END_TEST

START_TEST(test_sqrt_calc_3) {
  double res = 0;
  double reference = sqrt(9+78) / sqrt(1/2.0) / (10.0 + 1038);
  char *expression = "sqrt(9+78)/sqrt(1/2.0)/(10.0+1038)";
  evaluate_expression(expression, &res);

  ck_assert_double_eq_tol(reference, res, ACCURACY);
}
END_TEST

START_TEST(test_sqrt_calc_4) {
  double res = 0;
  double reference = sqrt(((1 / 3.0) - (-7 / -9.1)) + 10 + 1038);
  char *expression = "sqrt(((1/3.0)-(-7/-9.1))+10+1038)";
  evaluate_expression(expression, &res);

  ck_assert_double_eq_tol(reference, res, ACCURACY);
}
END_TEST

START_TEST(test_sqrt_calc_5) { 
  double res = 0;
  char *expression = "sqrt(((1/3.0)-(-7/-9.1))+10-1038)"; // NaN
  evaluate_expression(expression, &res);

  ck_assert_double_nan(res);
}
END_TEST

Suite *test_sqrt_calc(void) {
  Suite *s = suite_create("\033[45m-=SQRT=-\033[0m");
  TCase *tc = tcase_create("SQRT");

  tcase_add_test(tc, test_sqrt_calc_1);
  tcase_add_test(tc, test_sqrt_calc_2);
  tcase_add_test(tc, test_sqrt_calc_3);
  tcase_add_test(tc, test_sqrt_calc_4);
  tcase_add_test(tc, test_sqrt_calc_5);

  suite_add_tcase(s, tc);
  return s;
}
