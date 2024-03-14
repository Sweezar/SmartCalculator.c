#ifndef DEPOSIT_H
#define DEPOSIT_H

#include <QWidget>
extern "C" {
#include "model/deposit_calc.h"
}

#define REPLENISHMENTS_MAX 20
#define WITHDRAWALS_MAX 20

namespace Ui {
class Deposit;
}

class Deposit : public QWidget {
  Q_OBJECT

 public:
  explicit Deposit(QWidget *parent = nullptr);
  ~Deposit();

 private slots:
  void on_replenishments_push_button_clicked();

  void on_calculate_push_button_clicked();

  void on_interest_capitalization_checkbox_stateChanged(int arg1);

  void on_replenishments_combobox_currentIndexChanged(int index);

  void on_withdrawals_push_button_clicked();

  void on_withdrawals_combobox_currentIndexChanged(int index);

  void on_replenishments_push_button_2_clicked();
  void clear_replenishments();
  void clear_withdrawals();

  void on_withdrawals_push_button_2_clicked();

 private:
  Ui::Deposit *ui;
  Replenishments_s replenishments[REPLENISHMENTS_MAX];
  Withdrawals_s withdrawals[WITHDRAWALS_MAX];
};

#endif  // DEPOSIT_H
