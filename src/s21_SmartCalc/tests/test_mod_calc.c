#include "tests.h"

START_TEST(test_mod_calc_1) {
  double res = 0;
  double reference = 1 % 2;
  char *expression = "1mod2";
  evaluate_expression(expression, &res);

  ck_assert_double_eq_tol(reference, res, ACCURACY);
}
END_TEST

START_TEST(test_mod_calc_2) {
  double res = 0;
  double reference = 1 % 3 - 7 * 9 % (-10) - 1038;
  char *expression = "1mod3-7*9mod(-10)-1038";
  evaluate_expression(expression, &res);

  ck_assert_double_eq_tol(reference, res, ACCURACY);
}
END_TEST

START_TEST(test_mod_calc_3) {
  double res = 0;
  double reference = (1+3)%(7+9)%(10+1038);
  char *expression = "(1+3)mod(7+9)mod(10+1038)";
  evaluate_expression(expression, &res);

  ck_assert_double_eq_tol(reference, res, ACCURACY);
}
END_TEST

START_TEST(test_mod_calc_4) {
  double res = 0;
  double reference = ((1%3)-(-7%-9))+10-1038;
  char *expression = "((1mod3)-(-7mod-9))+10-1038";
  evaluate_expression(expression, &res);

  ck_assert_double_eq_tol(reference, res, ACCURACY);
}
END_TEST

Suite *test_mod_calc(void) {
  Suite *s = suite_create("\033[45m-=MOD=-\033[0m");
  TCase *tc = tcase_create("MOD");

  tcase_add_test(tc, test_mod_calc_1);
  tcase_add_test(tc, test_mod_calc_2);
	tcase_add_test(tc, test_mod_calc_3);
    tcase_add_test(tc, test_mod_calc_4);

  suite_add_tcase(s, tc);
  return s;
}
