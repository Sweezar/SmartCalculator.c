#include "tests.h"

START_TEST(test_atan_calc_1) {
  double res = 0;
  double reference = atan(0.5);
  char *expression = "atan(0.5)";
  res = evaluate_expression(expression);

  ck_assert_double_eq_tol(reference, res, ACCURACY);
}
END_TEST

START_TEST(test_atan_calc_2) {
  double res = 0;
  double reference = 10 - atan(0.5);
  char *expression = "10-atan(0.5)";
  res = evaluate_expression(expression);

  ck_assert_double_eq_tol(reference, res, ACCURACY);
}
END_TEST

START_TEST(test_atan_calc_3) {
  double res = 0;
  double reference = 10 - atan(48.5-48.35);
  char *expression = "10-atan(48.5-48.35)";
  res = evaluate_expression(expression);

  ck_assert_double_eq_tol(reference, res, ACCURACY);
}
END_TEST

START_TEST(test_atan_calc_4) {
  double res = 0;
  double reference = 10 - atan(48.5*0.0035)/2;
  char *expression = "10-atan(48.5*0.0035)/2";
  res = evaluate_expression(expression);

  ck_assert_double_eq_tol(reference, res, ACCURACY);
}
END_TEST

Suite *test_atan_calc(void) {
  Suite *s = suite_create("\033[45m-=ATAN=-\033[0m");
  TCase *tc = tcase_create("ATAN");

  tcase_add_test(tc, test_atan_calc_1);
  tcase_add_test(tc, test_atan_calc_2);
  tcase_add_test(tc, test_atan_calc_3);
  tcase_add_test(tc, test_atan_calc_4);

  suite_add_tcase(s, tc);
  return s;
}