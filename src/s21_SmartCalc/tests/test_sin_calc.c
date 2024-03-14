#include "tests.h"

START_TEST(test_sin_calc_1) {
  double res = 0;
  double reference = sin(48.5);
  char *expression = "sin(48.5)";
  evaluate_expression(expression, &res, 0);

  ck_assert_double_eq_tol(reference, res, ACCURACY);
}
END_TEST

START_TEST(test_sin_calc_2) {
  double res = 0;
  double reference = 10 - sin(48.5);
  char *expression = "10-sin(48.5)";
  evaluate_expression(expression, &res, 0);

  ck_assert_double_eq_tol(reference, res, ACCURACY);
}
END_TEST

START_TEST(test_sin_calc_3) {
  double res = 0;
  double reference = 10 - sin(48.5 + 35);
  char *expression = "10-sin(48.5+35)";
  evaluate_expression(expression, &res, 0);

  ck_assert_double_eq_tol(reference, res, ACCURACY);
}
END_TEST

START_TEST(test_sin_calc_4) {
  double res = 0;
  double reference = 10 - sin(48.5 * 35) / 2;
  char *expression = "10-sin(48.5*35)/2";
  evaluate_expression(expression, &res, 0);

  ck_assert_double_eq_tol(reference, res, ACCURACY);
}
END_TEST

START_TEST(test_sin_calc_5) {
  double res = 0;
  double reference = 2 * -sin(5);
  char *expression = "2*-sin(5)";
  evaluate_expression(expression, &res, 0);

  ck_assert_double_eq_tol(reference, res, ACCURACY);
}
END_TEST

Suite *test_sin_calc(void) {
  Suite *s = suite_create("\033[45m-=SIN=-\033[0m");
  TCase *tc = tcase_create("SIN");

  tcase_add_test(tc, test_sin_calc_1);
  tcase_add_test(tc, test_sin_calc_2);
  tcase_add_test(tc, test_sin_calc_3);
  tcase_add_test(tc, test_sin_calc_4);
  tcase_add_test(tc, test_sin_calc_5);

  suite_add_tcase(s, tc);
  return s;
}