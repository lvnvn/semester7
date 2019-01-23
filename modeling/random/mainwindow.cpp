#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QScrollArea"
#include <fstream>
#include <iostream>
#include <sys/stat.h>
#include <string>
#include <tgmath.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(input()));

    for(int i = 0; i< 10; i++)
    {
        ui->horizontalLayout->addWidget(&(input_boxes[i]));
    }
    int** table = fromTable();
    int** algo = fromAlgorythm();
    for(int i = 4; i < 14; i++)
        for(int j = 0; j < 6; j++)
        {
            QString text;
            if(j<3)
                text = QString::number(table[j][i-4]);
            else
                text = QString::number(algo[j-3][i-4]);
            QLabel* label = new QLabel(text);
            ui->gridLayout->addWidget(label,i,j);
        }
    QString text = "Энтропия";
    QLabel* label = new QLabel(text);
    ui->gridLayout->addWidget(label,14,0,1,6);

    double entropies[6];
    for(int i = 0; i < 3; i++)
        entropies[i] = entropy(table[i], 1000, pow(10,i+1));
    for(int i = 0; i < 3; i++)
        entropies[i+3] = entropy(algo[i], 1000, pow(10,i+1));

    for(int i = 0; i < 6; i++)
    {
          QString text = QString::number(entropies[i]);
          QLabel* label = new QLabel(text);
          ui->gridLayout->addWidget(label,15,i);
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

int** MainWindow::fromTable()
{
    int** result = new int* [3];
    for(int i = 0; i < 3; i++)
        result[i] = new int[1000];

    char* path = "../digits.txt";
    struct stat fileinfo;
    stat(path, &fileinfo);
    long size = fileinfo.st_size;
    char* file_contents = new char[size]();
    std::ifstream file (path, std::ios::in);
    file.read(file_contents, size);

    int array[3000], k = 0;

    for(int i = 0; i< 300; i++)
    {
        std::string line = "";
        line.append(file_contents,i*66, 65);
        for(int j = 0; j < 10; j++)
           array[k++] = std::stoi(line.substr(6+6*j, 5));
    }
    delete[] file_contents;

    for(int i = 0; i < 1000; i++)
        result[0][i] = array[i]/10000;
    for(int i = 0; i < 1000; i++)
        result[1][i] = array[1000+i]/1000;
    for(int i = 0; i < 1000; i++)
        result[2][i] = array[2000+i]/100;

    return result;
}

int** MainWindow::fromAlgorythm() //линейный конгруэнтный метод
{
    int** result = new int* [3];
    for(int i = 0; i < 3; i++)
        result[i] = new int[1000];

    int a = 1103515245, c = 12345; // ,  m = 32767;
    unsigned long next=time(NULL);

    int res;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 1000; j++)
        {
            next=next*a+c;
            //res = ((unsigned int)(next)%m);
            //result[i][j] = res%((int)pow(10,i+1));
            result[i][j] = ((unsigned int)(next)%((int)pow(10,i+1)));
        }
    return result;
}

double MainWindow::entropy(int* sequence, int size, int span)
{
    int* counts = new int[span];
    for(int i = 0; i < span; i++)
        counts[i] = 0;

    for(int i = 0; i < size; i++)
    {
        counts[sequence[i]]++;
    }

    double en = 0.0, logsize = log(size);
    for(int i = 0; i < span; i++)
        if(counts[i] != 0)
        {
            double pi = (double) counts[i] / size;
            en -= pi * log(pi) / logsize;
        }

        return en;
}

void MainWindow::input()
{
    for(int i = 0; i < 10; i++)
        fromInput[i] = input_boxes[i].value();
   for(int i = 0; i < 10; i++)
       std::cout << fromInput[i] << " ";
   ui->label_12->setText(QString::number( entropy(fromInput, 10, ui->spinBox->value()*10)));
}

