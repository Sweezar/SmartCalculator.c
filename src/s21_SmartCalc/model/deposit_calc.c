#include "deposit_calc.h"

double deposit_calc(double *deposit_amount, int posting_period, double interest_rate, int interest_capitalization, int capitalisation_period, Replenishments_s replenishments[], Withdrawals_s withdrawals[]) {
	double result = 0;
	for(int i = 0; i < posting_period; i++) {
		result += (*deposit_amount * (interest_rate / 100.0)) / 12.0;
		if(interest_capitalization) {
			if(capitalisation_period == MONTH_C) {
				*deposit_amount += (*deposit_amount * (interest_rate / 100.0)) / 12.0;
			}
			if(capitalisation_period == QUARTER_C && ((i + 1) % 3) == 0) {
				*deposit_amount += (*deposit_amount * (interest_rate / 100.0)) / 4.0;
			}
			if(capitalisation_period == HALF_YEARLY_C && ((i + 1) % 6) == 0) {
				*deposit_amount += (*deposit_amount * (interest_rate / 100.0)) / 2.0;
			}
			if(capitalisation_period == YEAR_C && ((i + 1) % 12) == 0) {
				*deposit_amount += (*deposit_amount * (interest_rate / 100.0));
			}
		}
		for(int ii = 0; ii < 20; ii++) {
			if(replenishments[ii].sum != 0 && *deposit_amount + replenishments[ii].sum > 0) {
				if(replenishments[ii].period == 0 && replenishments[ii].month == i) {
					*deposit_amount += replenishments[ii].sum;
				} else if(replenishments[ii].period == 1 && i > 0){
					*deposit_amount += replenishments[ii].sum;
				} else if(replenishments[ii].period == 2 && (i + 1) % 3){
					*deposit_amount += replenishments[ii].sum;
				} else if(replenishments[ii].period == 3 && (i + 1) % 6){
					*deposit_amount += replenishments[ii].sum;
				} else if(replenishments[ii].period == 3 && (i + 1) % 12){
					*deposit_amount += replenishments[ii].sum;
				}
			}
		}
		for(int ii = 0; ii < 20; ii++) {
			if(withdrawals[ii].sum != 0 && *deposit_amount + withdrawals[ii].sum > 0) {
				if(withdrawals[ii].period == 0 && withdrawals[ii].month == i) {
					*deposit_amount -= withdrawals[ii].sum;
				} else if(withdrawals[ii].period == 1){
					*deposit_amount -= withdrawals[ii].sum;
				} else if(withdrawals[ii].period == 2 && (i + 1) % 3){
					*deposit_amount -= withdrawals[ii].sum;
				} else if(withdrawals[ii].period == 3 && (i + 1) % 6){
					*deposit_amount -= withdrawals[ii].sum;
				} else if(withdrawals[ii].period == 3 && (i + 1) % 12){
					*deposit_amount -= withdrawals[ii].sum;
				}
			}
		}
	}

	return result;
}
