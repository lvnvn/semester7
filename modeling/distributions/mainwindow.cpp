#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <cmath>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(plot()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::plot()
{
    if(ui->radioButton->isChecked()) //равномерное
    {
        float a = ui->doubleSpinBox_1->value();
        float b = ui->doubleSpinBox_2->value();


        QVector<double> x(200), y(200);
        float ylength = (b-a)*1.2;
        float step = ylength/200;
        x[0] = a - (b-a)/10;
        for (int i=1; i<200; ++i)
            x[i] = x[i-1] + step;

        // функция распределения

        ui->customPlot->addGraph();
        ui->customPlot->graph(0)->setPen(QPen(Qt::blue)); // line color blue for graph
        ui->customPlot->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20))); // first graph will be filled with translucent blue

        for (int i=0; i<200; ++i)
        {
          if(x[i] < a)
              y[i] = 0;
          else if(x[i] > b)
              y[i] = 1;
          else
              y[i] = (x[i] - a)/(b - a);
        }

        ui->customPlot->graph(0)->setData(x, y);
        ui->customPlot->graph(0)->rescaleAxes();
        ui->customPlot->replot();

        // плотность вероятности

        ui->customPlot_2->addGraph();
        ui->customPlot_2->graph(0)->setPen(QPen(Qt::blue)); // line color blue for graph
        ui->customPlot_2->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20))); // first graph will be filled with translucent blue

        for (int i=0; i<200; ++i)
        {
          if((x[i] < a) || (x[i] > b))
              y[i] = 0;
          else
              y[i] = 1/(b-a);
        }

        ui->customPlot_2->graph(0)->setData(x, y);
        ui->customPlot_2->graph(0)->rescaleAxes();
        ui->customPlot_2->replot();

    }
    if(ui->radioButton_2->isChecked()) //нормальное
    {
        float m = ui->doubleSpinBox_3->value();
        float s = ui->doubleSpinBox_4->value();

        QVector<double> x(200), y(200);
        float ylength = s*10;
        float step = ylength/200;
        x[0] = m - (ylength)/2;
        for (int i=1; i<200; ++i)
            x[i] = x[i-1] + step;

        // функция распределения

        ui->customPlot->addGraph();
        ui->customPlot->graph(0)->setPen(QPen(Qt::blue)); // line color blue for first graph
        ui->customPlot->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20))); // first graph will be filled with translucent blue

        double temp = 1/(s*sqrt(2*M_PI));

        double f_prev = exp(-pow(x[0]-step-m, 2)/(2*s*s));
        double f_curr = exp(-pow(x[0]-m, 2)/(2*s*s));
        y[0] = temp * step * (f_curr + f_prev)/2;

        for (int i=1; i<200; ++i)
        {
            f_curr = exp(-pow(x[i]-m, 2)/(2*s*s));
            y[i] = y[i-1] + temp * step * (f_prev + f_curr)/2;
            f_prev = f_curr;
        }

        ui->customPlot->graph(0)->setData(x, y);
        ui->customPlot->graph(0)->rescaleAxes();
        ui->customPlot->replot();

        // плотность вероятности

        ui->customPlot_2->addGraph();
        ui->customPlot_2->graph(0)->setPen(QPen(Qt::blue)); // line color blue for first graph
        ui->customPlot_2->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20))); // first graph will be filled with translucent blue

        for (int i=0; i<200; ++i)
        {
          y[i] = temp * exp(- (x[i]-m)*(x[i]-m) / (2*s*s) );
        }

        ui->customPlot_2->graph(0)->setData(x, y);
        ui->customPlot_2->graph(0)->rescaleAxes();
        ui->customPlot_2->replot();
    }

}

