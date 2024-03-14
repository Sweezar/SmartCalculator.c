#ifndef CREDIT_H
#define CREDIT_H

#include <QWidget>

extern "C" {
#include "model/credit_calc.h"
}

namespace Ui {
class Credit;
}

class Credit : public QWidget {
  Q_OBJECT

 public:
  explicit Credit(QWidget *parent = nullptr);
  ~Credit();

 private:
  Ui::Credit *ui;

 private slots:
  void calculate();
};

#endif  // CREDIT_H
