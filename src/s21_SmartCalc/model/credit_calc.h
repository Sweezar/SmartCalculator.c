#ifndef CREDIT_CALC_H
#define CREDIT_CALC_H

#include <math.h>

double annuity(double creditAmount, double interestRate, int creditTerm);
void differentiated(double creditAmount, double interestRate, int creditTerm,
                    double result[]);

#endif