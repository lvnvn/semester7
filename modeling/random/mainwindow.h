#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSpinBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void input();

    int** fromTable();
    int** fromAlgorythm();
    double entropy(int* sequence, int size, int span);

private:
    Ui::MainWindow *ui;
    int* fromInput = new int[10];
    QSpinBox* input_boxes = new QSpinBox[10];


};

#endif // MAINWINDOW_H
