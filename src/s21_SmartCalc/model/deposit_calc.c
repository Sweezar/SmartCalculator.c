#include "deposit_calc.h"
#define MID_YEAR 365.25
#define MID_MONTH (MID_YEAR / 12.0)
#define MID_QUARTER (MID_YEAR / 4.0)
#define MID_HALF_YEAR (MID_YEAR / 2.0)

double deposit_calc(double *deposit_amount, int posting_period,
                    double interest_rate, int interest_capitalization,
                    int capitalisation_period,
                    Replenishments_s replenishments[],
                    Withdrawals_s withdrawals[]) {
  double result = 0;
  for (int i = 0; i < posting_period; i++) {
    result +=
        (*deposit_amount * (interest_rate / 100.0)) * MID_MONTH / MID_YEAR;

    if (interest_capitalization) {
      interest_capitalization_handler(deposit_amount, interest_rate,
                                      capitalisation_period, i);
    }
    replenishments_handler(deposit_amount, replenishments, i);
    withdrawals_handler(deposit_amount, withdrawals, i);
  }

  return result;
}

void interest_capitalization_handler(double *deposit_amount,
                                     double interest_rate,
                                     int capitalisation_period, int month) {
  if (capitalisation_period == MONTH_C) {
    *deposit_amount +=
        (*deposit_amount * (interest_rate / 100.0)) * MID_MONTH / MID_YEAR;
  }
  if (capitalisation_period == QUARTER_C && ((month + 1) % 3) == 0) {
    *deposit_amount +=
        (*deposit_amount * (interest_rate / 100.0)) * MID_QUARTER / MID_YEAR;
  }
  if (capitalisation_period == HALF_YEARLY_C && ((month + 1) % 6) == 0) {
    *deposit_amount +=
        (*deposit_amount * (interest_rate / 100.0)) * MID_HALF_YEAR / MID_YEAR;
  }
  if (capitalisation_period == YEAR_C && ((month + 1) % 12) == 0) {
    *deposit_amount += (*deposit_amount * (interest_rate / 100.0));
  }
}

void replenishments_handler(double *deposit_amount,
                            Replenishments_s replenishments[], int month) {
  for (int i = 0; i < 20; i++) {
    if (replenishments[i].sum != 0) {
      if (replenishments[i].period == 0 && replenishments[i].month == month) {
        *deposit_amount += replenishments[i].sum;
      } else if (replenishments[i].period == 1 && month > 0) {
        *deposit_amount += replenishments[i].sum;
      } else if (replenishments[i].period == 2 && (month + 1) % 3 == 0) {
        *deposit_amount += replenishments[i].sum;
      } else if (replenishments[i].period == 3 && (month + 1) % 6 == 0) {
        *deposit_amount += replenishments[i].sum;
      } else if (replenishments[i].period == 4 && (month + 1) % 12 == 0) {
        *deposit_amount += replenishments[i].sum;
      }
    }
  }
}

void withdrawals_handler(double *deposit_amount, Withdrawals_s withdrawals[],
                         int month) {
  for (int i = 0; i < 20; i++) {
    if (withdrawals[i].sum != 0 && *deposit_amount + withdrawals[i].sum > 0) {
      if (withdrawals[i].period == 0 && withdrawals[i].month == month) {
        *deposit_amount -= withdrawals[i].sum;
      } else if (withdrawals[i].period == 1 && month > 0) {
        *deposit_amount -= withdrawals[i].sum;
      } else if (withdrawals[i].period == 2 && (month + 1) % 3 == 0) {
        *deposit_amount -= withdrawals[i].sum;
      } else if (withdrawals[i].period == 3 && (month + 1) % 6 == 0) {
        *deposit_amount -= withdrawals[i].sum;
      } else if (withdrawals[i].period == 4 && (month + 1) % 12 == 0) {
        *deposit_amount -= withdrawals[i].sum;
      }
    }
  }
}
