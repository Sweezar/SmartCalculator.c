#include "tests.h"

int main(void) {
  int failed = 0;

  Suite *smart_calc_test[] = {test_brackets_calc(),
                              test_sum_calc(),
                              test_sub_calc(),
                              test_mult_calc(),
                              test_div_calc(),
                              test_pow_calc(),
                              test_mod_calc(),
                              test_cos_calc(),
                              test_sin_calc(),
                              test_tan_calc(),
                              test_acos_calc(),
                              test_asin_calc(),
                              test_atan_calc(),
                              test_sqrt_calc(),
                              test_ln_calc(),
                              test_log_calc(),
                              test_deposit_calc(),
                              test_credit_calc(),
                              NULL};

  for (int i = 0; smart_calc_test[i] != NULL; i++) {
    SRunner *sr = srunner_create(smart_calc_test[i]);
    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);
    failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }

  if (failed) {
    printf("\033[101m========== TESTS FAILED: %d ==========\033[0m\n", failed);
  } else {
    printf("\033[42m========== TESTS FAILED: %d ==========\033[0m\n", failed);
  }

  return 0;
}
