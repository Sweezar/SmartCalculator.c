#include "tests.h"

START_TEST(test_brackets_calc_1) {
  double res = 0;
  double reference = (1 + 2) * pow(pow(3, 2), 2) - 6 / (7 + 8 / 9.0);
  char *expression = "(1+2)*3^2^2-6/(7+8/9)";
  evaluate_expression(expression, &res);

  ck_assert_double_eq_tol(reference, res, ACCURACY);
}
END_TEST

START_TEST(test_brackets_calc_2) {
  double res = 0;
  double reference = (1 + (2 - 3 * (5 - 3) + 4));
  char *expression = "(1+(2-3*(5-3)+4))";
  evaluate_expression(expression, &res);

  ck_assert_double_eq_tol(reference, res, ACCURACY);
}
END_TEST

START_TEST(test_brackets_calc_3) {
  double res = 0;
  int return_code;
  char *expression = "(1+(2-3*(5-3)+4)))"; // лишняя скобка
  return_code = evaluate_expression(expression, &res);

  ck_assert_int_eq(return_code, 1);
}
END_TEST

Suite *test_brackets_calc(void) {
  Suite *s = suite_create("\033[45m-=BRACKETS=-\033[0m");
  TCase *tc = tcase_create("BRACKETS");

  tcase_add_test(tc, test_brackets_calc_1);
  tcase_add_test(tc, test_brackets_calc_2);
  tcase_add_test(tc, test_brackets_calc_3);

  suite_add_tcase(s, tc);
  return s;
}
