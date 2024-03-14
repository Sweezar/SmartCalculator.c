#include "deposit.h"

#include "ui_deposit.h"

Deposit::Deposit(QWidget *parent) : QWidget(parent), ui(new Ui::Deposit) {
  ui->setupUi(this);
  ui->replenishments_month_box->setValidator(new QIntValidator(0, 100, this));
}

Deposit::~Deposit() { delete ui; }

void Deposit::on_replenishments_push_button_clicked() {
  static int i = 0;
  if (ui->replenishments_list->item(0) == NULL) {
    clear_replenishments();
    i = 0;
  }
  int periodicity = ui->replenishments_combobox->currentIndex();
  double replenishment = ui->replenishments_box->value();
  int month = ui->replenishments_month_box->text().toInt();
  if (periodicity == 0) {
    ui->replenishments_list->insertItem(
        0, ui->replenishments_combobox->currentText() + " , " +
               QString::number(month) + " месяц, " +
               QString::number(replenishment) + " ₽");
  } else {
    ui->replenishments_list->insertItem(
        0, ui->replenishments_combobox->currentText() + " , " +
               QString::number(replenishment) + " ₽");
  }
  replenishments[i].period = periodicity;
  replenishments[i].sum = replenishment;
  replenishments[i].month = month;
  i++;
}

void Deposit::on_withdrawals_push_button_clicked() {
  static int i = 0;
  if (ui->withdrawals_list->item(0) == 0) {
    i = 0;
    clear_withdrawals();
  }
  int periodicity = ui->withdrawals_combobox->currentIndex();
  double withdrawal = ui->withdrawals_box->value();
  int month = ui->withdrawals_month_box->text().toInt();
  if (periodicity == 0) {
    ui->withdrawals_list->insertItem(
        0, ui->withdrawals_combobox->currentText() + " , " +
               QString::number(month) + " месяц, " +
               QString::number(withdrawal) + " ₽");
  } else {
    ui->withdrawals_list->insertItem(
        0, ui->withdrawals_combobox->currentText() + " , " +
               QString::number(withdrawal) + " ₽");
  }
  withdrawals[i].period = periodicity;
  withdrawals[i].sum = withdrawal;
  withdrawals[i].month = month;
  i++;
}

void Deposit::on_calculate_push_button_clicked() {
  double deposit_amount = ui->total_deposit_box->value();
  int posting_period = ui->posting_period_box->value();
  double intererst_rate = ui->interest_rate_box->value();
  int interest_capitalisation =
      ui->interest_capitalization_checkbox->isChecked();
  double tax_rate = ui->tax_rate_box->value() / 100.0;  // налоговая ставка
  int capitalisation_period = ui->frequency_payments_combobox->currentIndex();

  if (ui->posting_period_combobox->currentIndex() == 0) {
    posting_period *= 12;  // года в месяцы
  }

  double interest_charges = deposit_calc(
      &deposit_amount, posting_period, intererst_rate, interest_capitalisation,
      capitalisation_period, replenishments, withdrawals);
  double tax_amount = interest_charges * tax_rate;  // налог от прибыли
  interest_charges -= tax_amount;  // отнимаем процент налога от прибыли

  ui->interes_charges_box->setText(QString::number(interest_charges));
  ui->total_amount_box->setText(QString::number(deposit_amount));
  ui->tax_amount_box->setText(QString::number(tax_amount));
}

void Deposit::on_interest_capitalization_checkbox_stateChanged(int arg1) {
  if (arg1) {
    ui->frequency_payments_label->setText("Периодичность капитализации");
    ui->frequency_payments_combobox->setItemText(0, "Раз в месяц");
    ui->frequency_payments_combobox->setItemText(1, "Раз в квартал");
    ui->frequency_payments_combobox->setItemText(2, "Раз в полгода");
    ui->frequency_payments_combobox->setItemText(3, "Раз в год");
    ui->frequency_payments_combobox->removeItem(4);
  } else {
    ui->frequency_payments_label->setText("Периодичность выплат");
    ui->frequency_payments_combobox->setItemText(0, "В конце срока");
    ui->frequency_payments_combobox->setItemText(1, "Раз в месяц");
    ui->frequency_payments_combobox->setItemText(2, "Раз в квартал");
    ui->frequency_payments_combobox->setItemText(3, "Раз в полгода");
    ui->frequency_payments_combobox->addItem("Раз в год", 4);
  }
}

void Deposit::on_replenishments_combobox_currentIndexChanged(int index) {
  if (index == 0) {
    ui->replenishments_month_box->show();
  } else {
    ui->replenishments_month_box->hide();
  }
}

void Deposit::on_withdrawals_combobox_currentIndexChanged(int index) {
  if (index == 0) {
    ui->withdrawals_month_box->show();
  } else {
    ui->withdrawals_month_box->hide();
  }
}

void Deposit::on_replenishments_push_button_2_clicked() {
  ui->replenishments_list->clear();
  clear_replenishments();
}

void Deposit::on_withdrawals_push_button_2_clicked() {
  ui->withdrawals_list->clear();
  clear_withdrawals();
}

void Deposit::clear_replenishments() {
  for (int i = 0; i < REPLENISHMENTS_MAX; i++) {
    replenishments[i].month = 0;
    replenishments[i].sum = 0;
    replenishments[i].period = 0;
  }
}

void Deposit::clear_withdrawals() {
  for (int i = 0; i < WITHDRAWALS_MAX; i++) {
    withdrawals[i].month = 0;
    withdrawals[i].sum = 0;
    withdrawals[i].period = 0;
  }
}
