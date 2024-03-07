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
    int pos_x = 200;
    int pos_y = 200;
    move_main(pos_x, pos_y);

    connect(ui->number_button_0, SIGNAL(clicked()), this, SLOT(add_button_text()));
    connect(ui->number_button_1, SIGNAL(clicked()), this, SLOT(add_button_text()));
    connect(ui->number_button_2, SIGNAL(clicked()), this, SLOT(add_button_text()));
    connect(ui->number_button_3, SIGNAL(clicked()), this, SLOT(add_button_text()));
    connect(ui->number_button_4, SIGNAL(clicked()), this, SLOT(add_button_text()));
    connect(ui->number_button_5, SIGNAL(clicked()), this, SLOT(add_button_text()));
    connect(ui->number_button_6, SIGNAL(clicked()), this, SLOT(add_button_text()));
    connect(ui->number_button_7, SIGNAL(clicked()), this, SLOT(add_button_text()));
    connect(ui->number_button_8, SIGNAL(clicked()), this, SLOT(add_button_text()));
    connect(ui->number_button_9, SIGNAL(clicked()), this, SLOT(add_button_text()));

    connect(ui->operation_button_sum, SIGNAL(clicked()), this, SLOT(add_button_text())); // +
    connect(ui->operation_button_sub, SIGNAL(clicked()), this, SLOT(add_button_text())); // -
    connect(ui->operation_button_mult, SIGNAL(clicked()), this, SLOT(add_button_text())); // *
    connect(ui->operation_button_div, SIGNAL(clicked()), this, SLOT(add_button_text())); // /
    connect(ui->operation_button_pow, SIGNAL(clicked()), this, SLOT(add_button_text())); // ^
    connect(ui->operation_button_mod, SIGNAL(clicked()), this, SLOT(add_button_text())); // mod
    connect(ui->operation_button_left_bracket, SIGNAL(clicked()), this, SLOT(add_button_text())); // (
    connect(ui->operation_button_right_bracket, SIGNAL(clicked()), this, SLOT(add_button_text())); // )
    connect(ui->operation_button_clear, SIGNAL(clicked()), this, SLOT(clean_window())); // C
    connect(ui->operation_button_remove, SIGNAL(clicked()), this, SLOT(remove_symbol())); // <-x
    connect(ui->operation_button_dot, SIGNAL(clicked()), this, SLOT(add_button_text())); // .

    connect(ui->operation_button_acos, SIGNAL(clicked()), this, SLOT(add_math_function())); // acos
    connect(ui->operation_button_asin, SIGNAL(clicked()), this, SLOT(add_math_function())); // asin
    connect(ui->operation_button_atan, SIGNAL(clicked()), this, SLOT(add_math_function())); // atan
    connect(ui->operation_button_cos, SIGNAL(clicked()), this, SLOT(add_math_function())); // cos
    connect(ui->operation_button_sin, SIGNAL(clicked()), this, SLOT(add_math_function())); // sin
    connect(ui->operation_button_tan, SIGNAL(clicked()), this, SLOT(add_math_function())); // tan
    connect(ui->operation_button_ln, SIGNAL(clicked()), this, SLOT(add_math_function())); // ln
    connect(ui->operation_button_log, SIGNAL(clicked()), this, SLOT(add_math_function())); // log

    connect(ui->operation_button_x, SIGNAL(clicked()), this, SLOT(x_button_clicked())); // X

    connect(ui->operation_button_result, SIGNAL(clicked()), this, SLOT(calculate())); // =


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::move_main(int pos_x, int pos_y) {
  this->move(pos_x, pos_y);
}

void MainWindow::add_button_text()
{
    if(ui->result_show->text() == "ERROR") {
        ui->result_show->setText("");
    }
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

    double res;
    double x = ui->x_show->value();
    if(0 == evaluate_expression(currentTextCStr, &res, x)) {
        ui->result_show->setText(QString::number(res));
    } else {
        ui->result_show->setText("ERROR");
    }
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

void MainWindow::add_math_function()
{
    add_button_text();
    QString allNumbers;
    allNumbers = (ui->result_show->text() + "(");

    ui->result_show->setText(allNumbers);
}

void MainWindow::x_button_clicked()
{
    add_button_text();
//    QString x_number;

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


void MainWindow::on_radioButton_graph_toggled(bool checked)
{
    if(checked) {
        graph.move(200 + this.width(), 200);
        graph.show();
    } else {
        graph.close();
    }
}

