#ifndef GRAPH_H
#define GRAPH_H

#include <QFrame>

namespace Ui {
class Graph;
}

class Graph : public QFrame
{
    Q_OBJECT

public:
    explicit Graph(QWidget *parent = nullptr);
    ~Graph();
    void move_graph(int pos_x, int pos_y);

private:
    Ui::Graph *ui;
};

#endif // GRAPH_H
