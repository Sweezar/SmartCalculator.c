#include "credit_calc.h"

double annuity(double creditAmount, double interestRate, int creditTerm) {
  double annuityCoefficient;
  double monthlyInterestRate = interestRate / (100 * 12);
  annuityCoefficient = (monthlyInterestRate * pow((1 + monthlyInterestRate), creditTerm)) / (pow((1 + monthlyInterestRate), creditTerm) - 1); 
  return creditAmount * annuityCoefficient;
}