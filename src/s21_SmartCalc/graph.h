#ifndef GRAPH_H
#define GRAPH_H

#include <QFrame>
extern "C" {
#include "./model/s21_smart_calc.h"
}

namespace Ui {
class Graph;
}

class Graph : public QFrame
{
    Q_OBJECT

public:
    explicit Graph(QWidget *parent = nullptr);
    ~Graph();

private:
    Ui::Graph *ui;

public slots:
    void drawing_graph(char* ex);
};



#endif // GRAPH_H
