/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *mainLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *tab1layout;
    QTableView *tableVehicle;
    QHBoxLayout *buttonsLayout;
    QPushButton *btnAddVehicle;
    QPushButton *btnRemoveVehicle;
    QWidget *tab_2;
    QVBoxLayout *tab1layout1;
    QTableView *tableManufacturers;
    QHBoxLayout *buttonsLayout1;
    QPushButton *btnAddManufacturer;
    QPushButton *btnRemoveManufacturer;
    QWidget *tab_3;
    QVBoxLayout *tab1layout2;
    QTableView *tableDealerships;
    QHBoxLayout *buttonsLayout2;
    QPushButton *btnAddDealership;
    QPushButton *btnRemoveDealership;
    QWidget *tab_4;
    QVBoxLayout *tab1layout3;
    QTableView *tableCustomers;
    QHBoxLayout *buttonsLayout3;
    QPushButton *btnAddCustomer;
    QPushButton *btnRemoveCustomer;
    QWidget *tab_5;
    QVBoxLayout *tab1layout4;
    QTableView *tableSales;
    QHBoxLayout *buttonsLayout4;
    QPushButton *btnAddSale;
    QPushButton *btnRemoveSale;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(758, 459);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        mainLayout = new QHBoxLayout(centralwidget);
        mainLayout->setObjectName("mainLayout");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tab = new QWidget();
        tab->setObjectName("tab");
        tab1layout = new QVBoxLayout(tab);
        tab1layout->setObjectName("tab1layout");
        tableVehicle = new QTableView(tab);
        tableVehicle->setObjectName("tableVehicle");

        tab1layout->addWidget(tableVehicle);

        buttonsLayout = new QHBoxLayout();
        buttonsLayout->setObjectName("buttonsLayout");
        btnAddVehicle = new QPushButton(tab);
        btnAddVehicle->setObjectName("btnAddVehicle");

        buttonsLayout->addWidget(btnAddVehicle);

        btnRemoveVehicle = new QPushButton(tab);
        btnRemoveVehicle->setObjectName("btnRemoveVehicle");

        buttonsLayout->addWidget(btnRemoveVehicle);


        tab1layout->addLayout(buttonsLayout);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        tab1layout1 = new QVBoxLayout(tab_2);
        tab1layout1->setObjectName("tab1layout1");
        tableManufacturers = new QTableView(tab_2);
        tableManufacturers->setObjectName("tableManufacturers");

        tab1layout1->addWidget(tableManufacturers);

        buttonsLayout1 = new QHBoxLayout();
        buttonsLayout1->setObjectName("buttonsLayout1");
        btnAddManufacturer = new QPushButton(tab_2);
        btnAddManufacturer->setObjectName("btnAddManufacturer");

        buttonsLayout1->addWidget(btnAddManufacturer);

        btnRemoveManufacturer = new QPushButton(tab_2);
        btnRemoveManufacturer->setObjectName("btnRemoveManufacturer");

        buttonsLayout1->addWidget(btnRemoveManufacturer);


        tab1layout1->addLayout(buttonsLayout1);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        tab1layout2 = new QVBoxLayout(tab_3);
        tab1layout2->setObjectName("tab1layout2");
        tableDealerships = new QTableView(tab_3);
        tableDealerships->setObjectName("tableDealerships");

        tab1layout2->addWidget(tableDealerships);

        buttonsLayout2 = new QHBoxLayout();
        buttonsLayout2->setObjectName("buttonsLayout2");
        btnAddDealership = new QPushButton(tab_3);
        btnAddDealership->setObjectName("btnAddDealership");

        buttonsLayout2->addWidget(btnAddDealership);

        btnRemoveDealership = new QPushButton(tab_3);
        btnRemoveDealership->setObjectName("btnRemoveDealership");

        buttonsLayout2->addWidget(btnRemoveDealership);


        tab1layout2->addLayout(buttonsLayout2);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        tab1layout3 = new QVBoxLayout(tab_4);
        tab1layout3->setObjectName("tab1layout3");
        tableCustomers = new QTableView(tab_4);
        tableCustomers->setObjectName("tableCustomers");

        tab1layout3->addWidget(tableCustomers);

        buttonsLayout3 = new QHBoxLayout();
        buttonsLayout3->setObjectName("buttonsLayout3");
        btnAddCustomer = new QPushButton(tab_4);
        btnAddCustomer->setObjectName("btnAddCustomer");

        buttonsLayout3->addWidget(btnAddCustomer);

        btnRemoveCustomer = new QPushButton(tab_4);
        btnRemoveCustomer->setObjectName("btnRemoveCustomer");

        buttonsLayout3->addWidget(btnRemoveCustomer);


        tab1layout3->addLayout(buttonsLayout3);

        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName("tab_5");
        tab1layout4 = new QVBoxLayout(tab_5);
        tab1layout4->setObjectName("tab1layout4");
        tableSales = new QTableView(tab_5);
        tableSales->setObjectName("tableSales");

        tab1layout4->addWidget(tableSales);

        buttonsLayout4 = new QHBoxLayout();
        buttonsLayout4->setObjectName("buttonsLayout4");
        btnAddSale = new QPushButton(tab_5);
        btnAddSale->setObjectName("btnAddSale");

        buttonsLayout4->addWidget(btnAddSale);

        btnRemoveSale = new QPushButton(tab_5);
        btnRemoveSale->setObjectName("btnRemoveSale");

        buttonsLayout4->addWidget(btnRemoveSale);


        tab1layout4->addLayout(buttonsLayout4);

        tabWidget->addTab(tab_5, QString());

        mainLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 758, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btnAddVehicle->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        btnRemoveVehicle->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "\320\242\321\200\320\260\320\275\321\201\320\277\320\276\321\200\321\202\320\275\321\213\320\265 \321\201\321\200\320\265\320\264\321\201\321\202\320\262\320\260", nullptr));
        btnAddManufacturer->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        btnRemoveManufacturer->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\320\270\320\267\320\262\320\276\320\264\320\270\321\202\320\265\320\273\320\270", nullptr));
        btnAddDealership->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        btnRemoveDealership->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "\320\224\320\270\320\273\320\265\321\200\321\201\320\272\320\270\320\265 \321\206\320\265\320\275\321\202\321\200\321\213", nullptr));
        btnAddCustomer->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        btnRemoveCustomer->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("MainWindow", "\320\237\320\276\320\272\321\203\320\277\320\260\321\202\320\265\320\273\320\270", nullptr));
        btnAddSale->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        btnRemoveSale->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\320\264\320\260\320\266\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
