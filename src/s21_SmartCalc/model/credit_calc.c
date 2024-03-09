#include "credit_calc.h"

double annuity(double creditAmount, double interestRate, int creditTerm) {
  double annuityCoefficient;
  double monthlyInterestRate = interestRate / (100 * 12);
  annuityCoefficient = (monthlyInterestRate * pow((1 + monthlyInterestRate), creditTerm)) / (pow((1 + monthlyInterestRate), creditTerm) - 1); 
  return creditAmount * annuityCoefficient;
}

void differentiated(double creditAmount, double interestRate, int creditTerm,
                    double result[]) {
  double currentDebtBalance = creditAmount;
  double amoundWithdrawToPayoffInterest;
  interestRate = interestRate / 100.0;

  double loanRepaymentAmount = creditAmount / creditTerm;

  for (int numberOfPaidFees = 0; numberOfPaidFees < creditTerm;
       numberOfPaidFees++) {
    amoundWithdrawToPayoffInterest =
        currentDebtBalance * interestRate / 12.0;
    currentDebtBalance -= loanRepaymentAmount;
    result[numberOfPaidFees] =
        loanRepaymentAmount + amoundWithdrawToPayoffInterest;
  }
}