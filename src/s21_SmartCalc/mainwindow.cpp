#include "mainwindow.h"
#include "ui_mainwindow.h"

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
