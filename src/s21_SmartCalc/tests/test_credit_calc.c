#include <check.h>

#include "tests.h"

START_TEST(annuity_01) {
  double creditAmount = 2000000;
  double interestRate = 15;
  int creditTerm = 60;
  double reference = 47579.9;
  double result = annuity(creditAmount, interestRate, creditTerm);
  ck_assert_double_eq_tol(reference, result, 1e-01);
}

START_TEST(differentiated_01) {
  double creditAmount = 300000;
  double interestRate = 20;
  int creditTerm = 6;
  double result[creditTerm];
  double resultSum = 0;
  double reference = 317500;
  differentiated(creditAmount, interestRate, creditTerm, result);
  for (int i = 0; i < creditTerm; i++) {
    resultSum += result[i];
  }
  ck_assert_double_eq_tol(reference, resultSum, 1e-01);
}

Suite *test_credit_calc(void) {
  Suite *suite = suite_create("\033[45m-=CREDITS_CALC=-\033[0m");
  TCase *test_case = tcase_create("credit_calc");

  tcase_add_test(test_case, annuity_01);
  tcase_add_test(test_case, differentiated_01);

  suite_add_tcase(suite, test_case);
  return suite;
}