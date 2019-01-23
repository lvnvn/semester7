
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#define NumberOfServers 4

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

class LoadBalancer {
public:
    LoadBalancer(int _count, int* weights): count(_count)
    {
        for(int i = 0; i < NumberOfServers; i++)
            servers[i] = Server(weights[i]);
    }
    void model();
    void recieve(double time);
    double getStats(bool flag, int i);

private:
    Server servers[NumberOfServers];
    Generator requestGenerator = Generator(100,50);
    int count;
    int last_used_server = 0;
    int used_times = 0;
};

void LoadBalancer::recieve(double time) // time - время прихода очередного запроса (заявки)
{
    for(int i = 0; i < NumberOfServers; i++)
        servers[i].update(time); // удаляем отработанные запросы для статистики

    std::cout << "\nserver[" << last_used_server << "] weight = " << servers[last_used_server].weight << " used " << used_times;
    if(servers[last_used_server].weight <= used_times)
    {
        if(last_used_server < NumberOfServers-1)
            last_used_server++;
        else
            last_used_server = 0;
        used_times = 0;
    }

    servers[last_used_server].recieve(time);
    used_times++;
    std::cout << "\nserver [" << last_used_server << "] recieved request at " << time ;

    /*int index = 0;
    for(int i = 0; i < NumberOfServers; i++)
        for(int j = i+1; j < NumberOfServers; j++)
            if(servers[i].numberOfConnections() * servers[j].weight > servers[j].numberOfConnections() * servers[i].weight)
                index = j;
    servers[index].recieve(time);
    std::cout << "\nrequest time = " << time << " assigned to server " << index;*/
}

double LoadBalancer::getStats(bool flag, int i)
{
    if(flag)
        return servers[i].number_of_processed;
    else
        return (servers[i].currently_connected_sum / servers[i].number_of_measurements);
}

void LoadBalancer::model()
{
    double gen_next = requestGenerator.generate();

    for(int i = 0; i < count; i++)
    {
        gen_next += requestGenerator.generate();
        recieve(gen_next);
    }
}


void MainWindow::on_btn_model_clicked()
{
    int count = ui->n_req->value();
    int weights[4] = {ui->w1->value(), ui->w2->value(), ui->w3->value(), ui->w4->value()};
    LoadBalancer balancer = LoadBalancer(count, weights);
    balancer.model();

    ui->a1->setText(QString::number(balancer.getStats(0,0)));
    ui->a2->setText(QString::number(balancer.getStats(0,1)));
    ui->a3->setText(QString::number(balancer.getStats(0,2)));
    ui->a4->setText(QString::number(balancer.getStats(0,3)));
    ui->n1->setText(QString::number(balancer.getStats(1,0)));
    ui->n2->setText(QString::number(balancer.getStats(1,1)));
    ui->n3->setText(QString::number(balancer.getStats(1,2)));
    ui->n4->setText(QString::number(balancer.getStats(1,3)));
}
