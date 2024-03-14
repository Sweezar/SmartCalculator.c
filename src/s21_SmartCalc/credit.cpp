#include "credit.h"

#include "ui_credit.h"

Credit::Credit(QWidget *parent) : QWidget(parent), ui(new Ui::Credit) {
  ui->setupUi(this);

  connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(calculate()));
}

Credit::~Credit() { delete ui; }

void Credit::calculate() {
  double credit_sum = ui->credit_sum_box->value();
  double interest_rate = ui->interest_rate_box->value();
  int months = ui->credit_term_box->value();

  if (ui->term_combo_box->currentIndex() == 0) {
    months *= 12;
  }
  if (months > 0 && credit_sum > 0 && interest_rate > 0) {
    if (ui->type_combo_box->currentIndex() == 0) {
      double monthly_payment = annuity(credit_sum, interest_rate, months);
      ui->montly_payment_box->setText(QString::number(monthly_payment));
      ui->overpayment_box->setText(
          QString::number(monthly_payment * months - credit_sum));
      ui->total_payout_box->setText(
          QString::number(monthly_payment * 1.0 * months));
    } else {
      double monthly_payments[months];
      differentiated(credit_sum, interest_rate, months, monthly_payments);
      double total_payout = 0;
      for (int i = 0; i < months; i++) {
        total_payout += monthly_payments[i];
      }
      ui->montly_payment_box->setText(
          QString::number(monthly_payments[0]) + " ... " +
          QString::number(monthly_payments[months - 1]));

      ui->overpayment_box->setText(QString::number(total_payout - credit_sum));
      ui->total_payout_box->setText(QString::number(total_payout));
    }
  }
}
