#include "tests.h"

START_TEST(test_deposit_calc_1) {
  double res = 0;
  double deposit_amount = 100000;
  int posting_period = 12;
  double interest_rate = 8.0;
  int interest_capitalization = 0;
  int capitalisation_period = 0;
  Replenishments_s replenishments[20];
  Withdrawals_s withdrawals[20];

  res = deposit_calc(&deposit_amount, posting_period, interest_rate,
                     interest_capitalization, capitalisation_period,
                     replenishments, withdrawals);
  double reference = 8000.0;
  ck_assert_ldouble_eq_tol(reference, res, 1e-1);
}
END_TEST

START_TEST(test_deposit_calc_2) {
  double res = 0;
  double deposit_amount = 100000;
  int posting_period = 12;
  double interest_rate = 8.0;
  int interest_capitalization = 1;
  int capitalisation_period = 1;
  Replenishments_s replenishments[20];
  Withdrawals_s withdrawals[20];

  res = deposit_calc(&deposit_amount, posting_period, interest_rate,
                     interest_capitalization, capitalisation_period,
                     replenishments, withdrawals);
  double reference = 8243.22;
  ck_assert_ldouble_eq_tol(reference, res, 1e-1);
}
END_TEST

START_TEST(test_deposit_calc_3) {
  double res = 0;
  double deposit_amount = 100000;
  int posting_period = 24;
  double interest_rate = 8.0;
  int interest_capitalization = 1;
  int capitalisation_period = 2;
  Replenishments_s replenishments[20];
  replenishments[0].sum = 1000;
  replenishments[0].period = 1;
  replenishments[1].sum = 1000;
  replenishments[1].period = 3;
  Withdrawals_s withdrawals[20];

  res = deposit_calc(&deposit_amount, posting_period, interest_rate,
                     interest_capitalization, capitalisation_period,
                     replenishments, withdrawals);
  double reference = 18997.2;
  ck_assert_ldouble_eq_tol(reference, res, 1e-1);
}
END_TEST

START_TEST(test_deposit_calc_4) {
  double res = 0;
  double deposit_amount = 100000;
  int posting_period = 24;
  double interest_rate = 8.0;
  int interest_capitalization = 1;
  int capitalisation_period = 2;
  Replenishments_s replenishments[20];
  Withdrawals_s withdrawals[20];
  withdrawals[0].sum = 1000;
  withdrawals[0].period = 2;
  withdrawals[1].month = 3;
  withdrawals[1].sum = 1000;
  withdrawals[1].period = 0;

  res = deposit_calc(&deposit_amount, posting_period, interest_rate,
                     interest_capitalization, capitalisation_period,
                     replenishments, withdrawals);
  double reference = 16259.9;
  ck_assert_ldouble_eq_tol(reference, res, 1e-1);
}
END_TEST

Suite *test_deposit_calc(void) {
  Suite *s = suite_create("\033[45m-=DEPOSIT_CALC=-\033[0m");
  TCase *tc = tcase_create("DEPOSIT_CALC");

  tcase_add_test(tc, test_deposit_calc_1);
  tcase_add_test(tc, test_deposit_calc_2);
  tcase_add_test(tc, test_deposit_calc_3);
  tcase_add_test(tc, test_deposit_calc_4);

  suite_add_tcase(s, tc);
  return s;
}