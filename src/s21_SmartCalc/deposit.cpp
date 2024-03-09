#include "deposit.h"
#include "ui_deposit.h"

Deposit::Deposit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Deposit)
{
    ui->setupUi(this);
}

Deposit::~Deposit()
{
    delete ui;
}

void Deposit::on_replenishments_push_button_clicked()
{
    int periodicity = ui->replenishments_combobox->currentIndex();
    double replenishment = ui->replenishments_box->value();
    ui->replenishments_list->insertItem(0, ui->replenishments_combobox->currentText() + " , " + QString::number(replenishment) + " ₽");
}

