#include "graph.h"

#include "ui_graph.h"

Graph::Graph(QWidget* parent) : QFrame(parent), ui(new Ui::Graph) {
  ui->setupUi(this);
}

Graph::~Graph() { delete ui; }

void Graph::drawing_graph(char* ex) {
  ui->plot->addGraph();
  // Настройки вида
  ui->plot->graph(0)->setPen(QPen(Qt::blue));  // Цвет линии графика
  ui->plot->graph(0)->setBrush(
      QBrush(QColor(0, 0, 255, 20)));  // цвет проекции на ось Х
  ui->plot->xAxis->setLabel("x");
  ui->plot->yAxis->setLabel("y");
  // Получение значений
  int min_x = ui->min_x_box->value();
  int max_x = ui->max_x_box->value();
  int accuracy = ui->accuracy_box->value();
  double step = (max_x - min_x) / (accuracy - 1.0);
  double N = 0;
  // Генерация значений Х и вычисление значений Y
  QVector<double> x(accuracy), y(accuracy);
  for (int i = 0; i < accuracy - 1; ++i) {
    x[i] = min_x + N;
    evaluate_expression(ex, &y[i], x[i]);
    N += step;
  }
  x[accuracy - 1] = 0;
  evaluate_expression(ex, &y[accuracy - 1], x[accuracy - 1]);
  // Подстановка значений
  ui->plot->graph(0)->setData(x, y);
  // позволяет графику масштабироваться:
  ui->plot->graph(0)->rescaleAxes();
  // Разрешить пользователю масштабировать график и двигать кнопкой мыши
  ui->plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
  // Установить диапазон
  ui->plot->xAxis->setRange(min_x, max_x);
  ui->plot->yAxis->setRange(min_x, max_x);
  // Перерисовать график
  ui->plot->replot();
}
