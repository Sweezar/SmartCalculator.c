#include "tests.h"

START_TEST(test_cos_calc_1) {
  double res = 0;
  double reference = cos(48.5);
  char *expression = "cos(48.5)";
  res = evaluate_expression(expression);

  ck_assert_double_eq_tol(reference, res, ACCURACY);
}
END_TEST

START_TEST(test_cos_calc_2) {
  double res = 0;
  double reference = 10 - cos(48.5);
  char *expression = "10-cos(48.5)";
  res = evaluate_expression(expression);

  ck_assert_double_eq_tol(reference, res, ACCURACY);
}
END_TEST

START_TEST(test_cos_calc_3) {
  double res = 0;
  double reference = 10 - cos(48.5+35);
  char *expression = "10-cos(48.5+35)";
  res = evaluate_expression(expression);

  ck_assert_double_eq_tol(reference, res, ACCURACY);
}
END_TEST

START_TEST(test_cos_calc_4) {
  double res = 0;
  double reference = 10 - cos(48.5*35)/2;
  char *expression = "10-cos(48.5*35)/2";
  res = evaluate_expression(expression);

  ck_assert_double_eq_tol(reference, res, ACCURACY);
}
END_TEST

Suite *test_cos_calc(void) {
  Suite *s = suite_create("\033[45m-=COS=-\033[0m");
  TCase *tc = tcase_create("COS");

  tcase_add_test(tc, test_cos_calc_1);
  tcase_add_test(tc, test_cos_calc_2);
  tcase_add_test(tc, test_cos_calc_3);
  tcase_add_test(tc, test_cos_calc_4);

  suite_add_tcase(s, tc);
  return s;
}