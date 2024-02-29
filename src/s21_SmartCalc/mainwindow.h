#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <graph.h>>

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
    void move_main(int pos_x, int pos_y);
    void add_button_text();
    void calculate();
    void clean_window();
    void remove_symbol();
    void add_math_function();
    void x_button_clicked();

    void on_radioButton_graph_toggled(bool checked);

protected:
    void keyPressEvent(QKeyEvent *pe) override;

private:
    Ui::MainWindow *ui;
    Graph graph;
};
#endif // MAINWINDOW_H
