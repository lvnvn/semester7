#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "operator.h"
#include "generator.h"
#include "computer.h"
#include <iostream>

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

class InfoCenter {
public:
    InfoCenter(int _count): count(_count) {}
    void model();
    void recieve(double time);
    int accept_count = 0;
    int refuse_count = 0;

private:
    Generator generator = Generator(10,2);
    Operator operators[3] = {Operator(20,5,0), Operator(40,10,0), Operator(40,20,1)};
    Computer computers[2] = {Computer(15), Computer(30)};
    int count;
};

void InfoCenter::recieve(double time) // time - время прихода очередного клиента (заявки)
{
    for(int i = 0; i < 3; i++)
        if(operators[i].time_of_release < time) // если во время прихода клиента оператор уже освободился
        {
            operators[i].recieve(time);  // i-тый оператор принял заявку
            double ready_time = operators[i].time_of_release; // обработка этой заявки оператором завершена
            computers[operators[i].comp].recieve(ready_time); // заявка поставлена в очередь к компьютеру
            accept_count++;
            //std::cout << "\naccept time = " << time << " op = " << i << " release time = " << ready_time << " time in work = " << ready_time-time;
            return;
        }
    refuse_count++; // отказ
    //std::cout << "\ndenial time = " << time;
}


void InfoCenter::model()
{
    double gen_next = generator.generateRequest();

    //for(int i = 0; i < count; i++)
    while(accept_count<count)
    {
        gen_next += generator.generateRequest();
        recieve(gen_next);
    }
}


void MainWindow::on_btn_model_clicked()
{
    int count = ui->spinBox->value();
    InfoCenter center = InfoCenter(count);
    center.model();

    ui->statusBar->showMessage("Заявок сгенерировано: " + QString::number(center.accept_count+center.refuse_count) + "   Число отказов: " + QString::number(center.refuse_count) + "   Вероятность отказа: " + QString::number((double)center.refuse_count / (center.refuse_count+center.accept_count)));
}
