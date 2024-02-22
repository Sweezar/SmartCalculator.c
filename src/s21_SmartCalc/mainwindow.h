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
    void digits_numbers();
    void calculate();
    void clean_window();
    void remove_symbol();

protected:
    void keyPressEvent(QKeyEvent *pe) override;

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
