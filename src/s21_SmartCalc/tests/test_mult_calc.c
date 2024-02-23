#include "tests.h"

START_TEST(test_mult_calc_1) {
  double res = 0;
  double reference = 1 * 2;
  char *expression = "1*2";
  evaluate_expression(expression, &res);

  ck_assert_double_eq_tol(reference, res, ACCURACY);
}
END_TEST

START_TEST(test_mult_calc_2) {
  double res = 0;
  double reference = 1 * 3 - 7 * 9 * (-10) - 1038;
  char *expression = "1*3-7*9*(-10)-1038";
  evaluate_expression(expression, &res);

  ck_assert_double_eq_tol(reference, res, ACCURACY);
}
END_TEST

START_TEST(test_mult_calc_3) {
  double res = 0;
  double reference = (1 + 3) * (7 + 9) * (10 + 1038);
  char *expression = "(1+3)*(7+9)*(10+1038)";
  evaluate_expression(expression, &res);

  ck_assert_double_eq_tol(reference, res, ACCURACY);
}
END_TEST

START_TEST(test_mult_calc_4) {
  double res = 0;
  double reference = ((1 * 3) - (-7 * -9)) + 10 - 1038;
  char *expression = "((1*3)-(-7*-9))+10-1038";
  evaluate_expression(expression, &res);

  ck_assert_double_eq_tol(reference, res, ACCURACY);
}
END_TEST

Suite *test_mult_calc(void) {
  Suite *s = suite_create("\033[45m-=MULT=-\033[0m");
  TCase *tc = tcase_create("MULT");

  tcase_add_test(tc, test_mult_calc_1);
  tcase_add_test(tc, test_mult_calc_2);
  tcase_add_test(tc, test_mult_calc_3);
  tcase_add_test(tc, test_mult_calc_4);

  suite_add_tcase(s, tc);
  return s;
}
