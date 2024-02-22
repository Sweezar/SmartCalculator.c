#ifndef TESTS_H
#define TESTS_H

#include <check.h>
#include <stdio.h>

#include "../model/s21_smart_calc.h"

#define ACCURACY 1e-07

Suite *test_brackets_calc(void);
Suite *test_sum_calc(void);
Suite *test_sub_calc(void);
Suite *test_mult_calc(void);
Suite *test_div_calc(void);
Suite *test_pow_calc(void);
Suite *test_mod_calc(void);

Suite *test_cos_calc(void);
Suite *test_sin_calc(void);
Suite *test_tan_calc(void);
Suite *test_acos_calc(void);
Suite *test_asin_calc(void);
Suite *test_atan_calc(void);
Suite *test_sqrt_calc(void);
Suite *test_ln_calc(void);
Suite *test_log_calc(void);

#endif
