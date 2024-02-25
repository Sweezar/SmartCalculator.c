#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void add_button_text();
    void calculate();
    void clean_window();
    void remove_symbol();
    void add_math_function();
    void x_button_clicked();

protected:
    void keyPressEvent(QKeyEvent *pe) override;

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
