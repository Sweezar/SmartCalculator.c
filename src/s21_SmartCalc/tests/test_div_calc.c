#include "tests.h"

START_TEST(test_div_calc_1) {
  double res = 0;
  double reference = 1 / -2.0;
  char *expression = "1/-2.0";
  evaluate_expression(expression, &res, 0);

  ck_assert_double_eq_tol(reference, res, ACCURACY);
}
END_TEST

START_TEST(test_div_calc_2) {
  double res = 0;
  double reference = 1 / 3.0 - 7 * 9.0 / (-10) - 1038;
  char *expression = "1/3.0-7*9.0/(-10)-1038";
  evaluate_expression(expression, &res, 0);

  ck_assert_double_eq_tol(reference, res, ACCURACY);
}
END_TEST

START_TEST(test_div_calc_3) {
  double res = 0;
  double reference = (1 + 3) / (7 + 9.0) / (10.0 + 1038);
  char *expression = "(1+3)/(7+9.0)/(10.0+1038)";
  evaluate_expression(expression, &res, 0);

  ck_assert_double_eq_tol(reference, res, ACCURACY);
}
END_TEST

START_TEST(test_div_calc_4) {
  double res = 0;
  double reference = ((1 / 3.0) - (-7 / -9.1)) + 10 - 1038;
  char *expression = "((1/3.0)-(-7/-9.1))+10-1038";
  evaluate_expression(expression, &res, 0);

  ck_assert_double_eq_tol(reference, res, ACCURACY);
}
END_TEST

START_TEST(test_div_calc_5) {
  double res = 0;
  char *expression = "2/0";
  int return_code = evaluate_expression(expression, &res, 0);

  ck_assert_int_eq(return_code, 1);
}
END_TEST

Suite *test_div_calc(void) {
  Suite *s = suite_create("\033[45m-=DIV=-\033[0m");
  TCase *tc = tcase_create("DIV");

  tcase_add_test(tc, test_div_calc_1);
  tcase_add_test(tc, test_div_calc_2);
  tcase_add_test(tc, test_div_calc_3);
  tcase_add_test(tc, test_div_calc_4);
  tcase_add_test(tc, test_div_calc_5);

  suite_add_tcase(s, tc);
  return s;
}
