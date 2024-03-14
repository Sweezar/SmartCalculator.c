#ifndef DEPOSIT_CALC_H
#define DEPOSIT_CALC_H

enum Capitalisation_periods { MONTH_C, QUARTER_C, HALF_YEARLY_C, YEAR_C };

enum Pay_periods { END_P, MONTH_P, QUARTER_P, HALF_YEARLY_P, YEAR_P };

typedef struct {
  double sum;
  int period;
  int month;
} Replenishments_s;

typedef struct {
  double sum;
  int period;
  int month;
} Withdrawals_s;

double deposit_calc(double *deposit_amount, int posting_period,
                    double interest_rate, int interest_capitalization,
                    int capitalisation_period,
                    Replenishments_s replenishments[],
                    Withdrawals_s withdrawals[]);

void interest_capitalization_handler(double *deposit_amount,
                                     double interest_rate,
                                     int capitalisation_period, int month);
void replenishments_handler(double *deposit_amount,
                            Replenishments_s replenishments[], int month);
void withdrawals_handler(double *deposit_amount, Withdrawals_s withdrawals[],
                         int month);
#endif
