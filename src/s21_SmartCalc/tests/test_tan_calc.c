#include "tests.h"

START_TEST(test_tan_calc_1) {
  double res = 0;
  double reference = tan(48.5);
  char *expression = "tan(48.5)";
  evaluate_expression(expression, &res);

  ck_assert_double_eq_tol(reference, res, ACCURACY);
}
END_TEST

START_TEST(test_tan_calc_2) {
  double res = 0;
  double reference = 10 - tan(48.5);
  char *expression = "10-tan(48.5)";
  evaluate_expression(expression, &res);

  ck_assert_double_eq_tol(reference, res, ACCURACY);
}
END_TEST

START_TEST(test_tan_calc_3) {
  double res = 0;
  double reference = 10 - tan(48.5+35);
  char *expression = "10-tan(48.5+35)";
  evaluate_expression(expression, &res);

  ck_assert_double_eq_tol(reference, res, ACCURACY);
}
END_TEST

START_TEST(test_tan_calc_4) {
  double res = 0;
  double reference = 10 - tan(48.5*35)/2;
  char *expression = "10-tan(48.5*35)/2";
  evaluate_expression(expression, &res);

  ck_assert_double_eq_tol(reference, res, ACCURACY);
}
END_TEST

Suite *test_tan_calc(void) {
  Suite *s = suite_create("\033[45m-=TAN=-\033[0m");
  TCase *tc = tcase_create("TAN");

  tcase_add_test(tc, test_tan_calc_1);
  tcase_add_test(tc, test_tan_calc_2);
  tcase_add_test(tc, test_tan_calc_3);
  tcase_add_test(tc, test_tan_calc_4);

  suite_add_tcase(s, tc);
  return s;
}