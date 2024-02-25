#include "tests.h"

START_TEST(test_pow_calc_1) {
  double res = 0;
  double reference = pow(1, 2.0);
  char *expression = "1^2.0";
  evaluate_expression(expression, &res, 0);

  ck_assert_double_eq_tol(reference, res, ACCURACY);
}
END_TEST

START_TEST(test_pow_calc_2) {
  double res = 0;
  double reference = pow(1, 3.0) - pow(pow(7, 9.0), (-10)) - 1038;
  char *expression = "1^3.0-7^9.0^(-10)-1038";
  evaluate_expression(expression, &res, 0);

  ck_assert_double_eq_tol(reference, res, ACCURACY);
}
END_TEST

START_TEST(test_pow_calc_3) {
  double res = 0;
  double reference = pow(pow((1 + 3), (7 - 9.0)), (30.0 - 27));
  char *expression = "(1+3)^(7-9.0)^(30.0-27)";
  evaluate_expression(expression, &res, 0);

  ck_assert_double_eq_tol(reference, res, ACCURACY);
}
END_TEST

START_TEST(test_pow_calc_4) {
  double res = 0;
  double reference = (pow(1, 3.0) - pow(7, 2.0)) + 10 - 1038;
  char *expression = "(1^3.0-(7^2.0))+10-1038";
  evaluate_expression(expression, &res, 0);

  ck_assert_double_eq_tol(reference, res, ACCURACY);
}
END_TEST

Suite *test_pow_calc(void) {
  Suite *s = suite_create("\033[45m-=POW=-\033[0m");
  TCase *tc = tcase_create("POW");

  tcase_add_test(tc, test_pow_calc_1);
  tcase_add_test(tc, test_pow_calc_2);
  tcase_add_test(tc, test_pow_calc_3);
  tcase_add_test(tc, test_pow_calc_4);

  suite_add_tcase(s, tc);
  return s;
}
