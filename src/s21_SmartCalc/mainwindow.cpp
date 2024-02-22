#include "mainwindow.h"
#include "ui_mainwindow.h"

extern "C" {
#include "./model/s21_smart_calc.h"
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->number_button_0, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->number_button_1, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->number_button_2, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->number_button_3, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->number_button_4, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->number_button_5, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->number_button_6, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->number_button_7, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->number_button_8, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->number_button_9, SIGNAL(clicked()), this, SLOT(digits_numbers()));

    connect(ui->operation_button_sum, SIGNAL(clicked()), this, SLOT(digits_numbers())); // +
    connect(ui->operation_button_sub, SIGNAL(clicked()), this, SLOT(digits_numbers())); // -
    connect(ui->operation_button_mult, SIGNAL(clicked()), this, SLOT(digits_numbers())); // *
    connect(ui->operation_button_div, SIGNAL(clicked()), this, SLOT(digits_numbers())); // /
    connect(ui->operation_button_left_bracket, SIGNAL(clicked()), this, SLOT(digits_numbers())); // (
    connect(ui->operation_button_right_bracket, SIGNAL(clicked()), this, SLOT(digits_numbers())); // )
    connect(ui->operation_button_clear, SIGNAL(clicked()), this, SLOT(clean_window())); // C
    connect(ui->operation_button_remove, SIGNAL(clicked()), this, SLOT(remove_symbol())); // <-x
    connect(ui->operation_button_dot, SIGNAL(clicked()), this, SLOT(digits_numbers())); // .

    connect(ui->operation_button_result, SIGNAL(clicked()), this, SLOT(calculate()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers()
{
    QPushButton *button = (QPushButton *)sender();
    QString allNumbers;
    allNumbers = (ui->result_show->text() + button->text());

    ui->result_show->setText(allNumbers);
}

void MainWindow::calculate()
{
    QString evaluate = ui->result_show->text();
    QByteArray currentTextUtf8 = evaluate.toUtf8();
      char* currentTextCStr = currentTextUtf8.data();

    double res = evaluate_expression(currentTextCStr);
    ui->result_show->setText(QString::number(res));
}

void MainWindow::clean_window()
{
    ui->result_show->setText("");
}

void MainWindow::remove_symbol()
{
    QString allNumbers;
    allNumbers = (ui->result_show->text());
    allNumbers.resize(allNumbers.size() - 1);

    ui->result_show->setText(allNumbers);
}

void MainWindow::keyPressEvent(QKeyEvent* pe)
{
    int key = pe->key();
        if (key >= Qt::Key_0 && key <= Qt::Key_9) {
            QString keyString = QString::number(key - Qt::Key_0);
            ui->result_show->setText(ui->result_show->text() + keyString);
        } else {
            QWidget::keyPressEvent(pe);
        }
}
