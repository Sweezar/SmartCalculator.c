#include "tests.h"

START_TEST(test_asin_calc_1) {
  double res = 0;
  double reference = asin(0.5);
  char *expression = "asin(0.5)";
  res = evaluate_expression(expression);

  ck_assert_double_eq_tol(reference, res, ACCURACY);
}
END_TEST

START_TEST(test_asin_calc_2) {
  double res = 0;
  double reference = 10 - asin(0.5);
  char *expression = "10-asin(0.5)";
  res = evaluate_expression(expression);

  ck_assert_double_eq_tol(reference, res, ACCURACY);
}
END_TEST

START_TEST(test_asin_calc_3) {
  double res = 0;
  double reference = 10 - asin(48.5-48.35);
  char *expression = "10-asin(48.5-48.35)";
  res = evaluate_expression(expression);

  ck_assert_double_eq_tol(reference, res, ACCURACY);
}
END_TEST

START_TEST(test_asin_calc_4) {
  double res = 0;
  double reference = 10 - asin(48.5*0.0035)/2;
  char *expression = "10-asin(48.5*0.0035)/2";
  res = evaluate_expression(expression);

  ck_assert_double_eq_tol(reference, res, ACCURACY);
}
END_TEST

Suite *test_asin_calc(void) {
  Suite *s = suite_create("\033[45m-=ASIN=-\033[0m");
  TCase *tc = tcase_create("ASIN");

  tcase_add_test(tc, test_asin_calc_1);
  tcase_add_test(tc, test_asin_calc_2);
  tcase_add_test(tc, test_asin_calc_3);
  tcase_add_test(tc, test_asin_calc_4);

  suite_add_tcase(s, tc);
  return s;
}