#include "graph.h"
#include "ui_graph.h"

Graph::Graph(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::Graph)
{
    ui->setupUi(this);
}

Graph::~Graph()
{
    delete ui;
}

void Graph::move_graph(int pos_x, int pos_y) {
    this->move(pos_x, pos_y);
}
