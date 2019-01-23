/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QLabel *label_2;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_7;
    QLabel *label_4;
    QLabel *label_8;
    QLabel *n3;
    QLabel *label_3;
    QLabel *a2;
    QLabel *label_5;
    QLabel *label_9;
    QSpinBox *w3;
    QLabel *a1;
    QLabel *n2;
    QLabel *a3;
    QSpinBox *w1;
    QLabel *label_6;
    QSpinBox *w2;
    QLabel *n1;
    QLabel *label_12;
    QSpinBox *w4;
    QLabel *n4;
    QLabel *a4;
    QSpinBox *n_req;
    QLabel *label_10;
    QPushButton *btn_model;
    QLabel *label_11;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(443, 396);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 151, 17));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 50, 301, 17));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 100, 401, 147));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(gridLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFrameShape(QFrame::StyledPanel);

        gridLayout->addWidget(label_7, 1, 0, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 0, 1, 1, 1);

        label_8 = new QLabel(gridLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFrameShape(QFrame::StyledPanel);

        gridLayout->addWidget(label_8, 2, 0, 1, 1);

        n3 = new QLabel(gridLayoutWidget);
        n3->setObjectName(QStringLiteral("n3"));
        n3->setFrameShape(QFrame::StyledPanel);

        gridLayout->addWidget(n3, 3, 2, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        a2 = new QLabel(gridLayoutWidget);
        a2->setObjectName(QStringLiteral("a2"));
        a2->setFrameShape(QFrame::StyledPanel);

        gridLayout->addWidget(a2, 2, 3, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 0, 2, 1, 1);

        label_9 = new QLabel(gridLayoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFrameShape(QFrame::StyledPanel);

        gridLayout->addWidget(label_9, 3, 0, 1, 1);

        w3 = new QSpinBox(gridLayoutWidget);
        w3->setObjectName(QStringLiteral("w3"));
        w3->setValue(1);

        gridLayout->addWidget(w3, 3, 1, 1, 1);

        a1 = new QLabel(gridLayoutWidget);
        a1->setObjectName(QStringLiteral("a1"));
        a1->setFrameShape(QFrame::StyledPanel);

        gridLayout->addWidget(a1, 1, 3, 1, 1);

        n2 = new QLabel(gridLayoutWidget);
        n2->setObjectName(QStringLiteral("n2"));
        n2->setFrameShape(QFrame::StyledPanel);

        gridLayout->addWidget(n2, 2, 2, 1, 1);

        a3 = new QLabel(gridLayoutWidget);
        a3->setObjectName(QStringLiteral("a3"));
        a3->setFrameShape(QFrame::StyledPanel);

        gridLayout->addWidget(a3, 3, 3, 1, 1);

        w1 = new QSpinBox(gridLayoutWidget);
        w1->setObjectName(QStringLiteral("w1"));
        w1->setValue(1);

        gridLayout->addWidget(w1, 1, 1, 1, 1);

        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 0, 3, 1, 1);

        w2 = new QSpinBox(gridLayoutWidget);
        w2->setObjectName(QStringLiteral("w2"));
        w2->setValue(2);

        gridLayout->addWidget(w2, 2, 1, 1, 1);

        n1 = new QLabel(gridLayoutWidget);
        n1->setObjectName(QStringLiteral("n1"));
        n1->setFrameShape(QFrame::StyledPanel);

        gridLayout->addWidget(n1, 1, 2, 1, 1);

        label_12 = new QLabel(gridLayoutWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setFrameShape(QFrame::StyledPanel);

        gridLayout->addWidget(label_12, 4, 0, 1, 1);

        w4 = new QSpinBox(gridLayoutWidget);
        w4->setObjectName(QStringLiteral("w4"));
        w4->setValue(5);

        gridLayout->addWidget(w4, 4, 1, 1, 1);

        n4 = new QLabel(gridLayoutWidget);
        n4->setObjectName(QStringLiteral("n4"));
        n4->setFrameShape(QFrame::StyledPanel);

        gridLayout->addWidget(n4, 4, 2, 1, 1);

        a4 = new QLabel(gridLayoutWidget);
        a4->setObjectName(QStringLiteral("a4"));
        a4->setFrameShape(QFrame::StyledPanel);

        gridLayout->addWidget(a4, 4, 3, 1, 1);

        n_req = new QSpinBox(centralWidget);
        n_req->setObjectName(QStringLiteral("n_req"));
        n_req->setGeometry(QRect(140, 10, 71, 26));
        n_req->setMaximum(1100);
        n_req->setValue(500);
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 70, 311, 17));
        btn_model = new QPushButton(centralWidget);
        btn_model->setObjectName(QStringLiteral("btn_model"));
        btn_model->setGeometry(QRect(300, 10, 111, 25));
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(10, 280, 391, 17));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 443, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\267\320\260\320\277\321\200\320\276\321\201\320\276\320\262", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\320\230\320\275\321\202\320\265\321\200\320\262\320\260\320\273 \320\274\320\265\320\266\320\264\321\203 \320\277\321\200\320\270\321\205\320\276\320\264\320\276\320\274 \320\267\320\260\320\277\321\200\320\276\321\201\320\276\320\262: 100 \302\261 50 \320\274\321\201", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "1", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\320\222\320\265\321\201", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "2", nullptr));
        n3->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "\342\204\226 \321\201\320\265\321\200\320\262\320\265\321\200\320\260", nullptr));
        a2->setText(QString());
        label_5->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\273-\320\262\320\276 \320\276\320\261\321\200\320\260\320\261\320\276\321\202\320\260\320\275\320\275\321\213\321\205 \320\267\320\260\320\277\321\200\320\276\321\201\320\276\320\262", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "3", nullptr));
        a1->setText(QString());
        n2->setText(QString());
        a3->setText(QString());
        label_6->setText(QApplication::translate("MainWindow", "(*)", nullptr));
        n1->setText(QString());
        label_12->setText(QApplication::translate("MainWindow", "4", nullptr));
        n4->setText(QString());
        a4->setText(QString());
        label_10->setText(QApplication::translate("MainWindow", "\320\222\321\200\320\265\320\274\321\217 \320\276\320\261\321\200\320\260\320\261\320\276\321\202\320\272\320\270 \320\267\320\260\320\277\321\200\320\276\321\201\320\260 \320\275\320\260 \321\201\320\265\321\200\320\262\320\265\321\200\320\265: 2000 \302\261 400 \320\274\321\201", nullptr));
        btn_model->setText(QApplication::translate("MainWindow", "\320\234\320\276\320\264\320\265\320\273\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "(*) - \320\241\321\200\320\265\320\264\320\275\320\265\320\265 \320\272\320\276\320\273-\320\262\320\276 \320\276\320\264\320\275\320\276\320\262\321\200\320\265\320\274\320\265\320\275\320\275\320\276 \320\276\320\261\321\200\320\260\320\261\320\260\321\202\321\213\320\262\320\260\320\265\320\274\321\213\321\205 \320\267\320\260\320\277\321\200\320\276\321\201\320\276\320\262", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
