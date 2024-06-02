/********************************************************************************
** Form generated from reading UI file 'saledialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SALEDIALOG_H
#define UI_SALEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SaleDialog
{
public:
    QGroupBox *Group4;
    QGridLayout *gridLayout;
    QLabel *label_5;
    QPushButton *btnCancel;
    QLabel *label_2;
    QLabel *label;
    QComboBox *cbCustomer;
    QDateEdit *dateEdit;
    QLabel *label_3;
    QPushButton *btnOk;
    QLineEdit *txtAmount;
    QComboBox *cbVehicle;
    QLabel *label_4;
    QComboBox *cmbDealer;

    void setupUi(QDialog *SaleDialog)
    {
        if (SaleDialog->objectName().isEmpty())
            SaleDialog->setObjectName("SaleDialog");
        SaleDialog->resize(600, 300);
        SaleDialog->setStyleSheet(QString::fromUtf8("background-color: rgb(199, 199, 199);\n"
"color: rgb(0, 0, 0);"));
        Group4 = new QGroupBox(SaleDialog);
        Group4->setObjectName("Group4");
        Group4->setGeometry(QRect(10, 10, 581, 281));
        Group4->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 220, 220);"));
        gridLayout = new QGridLayout(Group4);
        gridLayout->setObjectName("gridLayout");
        label_5 = new QLabel(Group4);
        label_5->setObjectName("label_5");

        gridLayout->addWidget(label_5, 6, 0, 1, 1);

        btnCancel = new QPushButton(Group4);
        btnCancel->setObjectName("btnCancel");
        btnCancel->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 128, 128);\n"
"color: rgb(255, 255, 255);"));

        gridLayout->addWidget(btnCancel, 8, 0, 1, 3);

        label_2 = new QLabel(Group4);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label = new QLabel(Group4);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        cbCustomer = new QComboBox(Group4);
        cbCustomer->setObjectName("cbCustomer");

        gridLayout->addWidget(cbCustomer, 4, 2, 1, 1);

        dateEdit = new QDateEdit(Group4);
        dateEdit->setObjectName("dateEdit");

        gridLayout->addWidget(dateEdit, 0, 2, 1, 1);

        label_3 = new QLabel(Group4);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 4, 0, 1, 1);

        btnOk = new QPushButton(Group4);
        btnOk->setObjectName("btnOk");
        btnOk->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 128, 128);\n"
"color: rgb(255, 255, 255);"));

        gridLayout->addWidget(btnOk, 7, 0, 1, 3);

        txtAmount = new QLineEdit(Group4);
        txtAmount->setObjectName("txtAmount");

        gridLayout->addWidget(txtAmount, 6, 2, 1, 1);

        cbVehicle = new QComboBox(Group4);
        cbVehicle->setObjectName("cbVehicle");

        gridLayout->addWidget(cbVehicle, 5, 2, 1, 1);

        label_4 = new QLabel(Group4);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 5, 0, 1, 1);

        cmbDealer = new QComboBox(Group4);
        cmbDealer->setObjectName("cmbDealer");

        gridLayout->addWidget(cmbDealer, 1, 2, 1, 1);


        retranslateUi(SaleDialog);

        QMetaObject::connectSlotsByName(SaleDialog);
    } // setupUi

    void retranslateUi(QDialog *SaleDialog)
    {
        SaleDialog->setWindowTitle(QCoreApplication::translate("SaleDialog", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\277\321\200\320\276\320\264\320\260\320\266\320\270", nullptr));
        label_5->setText(QCoreApplication::translate("SaleDialog", "\320\241\321\203\320\274\320\274\320\260 \320\277\321\200\320\276\320\264\320\260\320\266\320\270", nullptr));
        btnCancel->setText(QCoreApplication::translate("SaleDialog", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
        label_2->setText(QCoreApplication::translate("SaleDialog", "\320\237\321\200\320\276\320\264\320\260\320\262\320\265\321\206", nullptr));
        label->setText(QCoreApplication::translate("SaleDialog", "\320\224\320\260\321\202\320\260 \320\277\321\200\320\276\320\264\320\260\320\266\320\270", nullptr));
        label_3->setText(QCoreApplication::translate("SaleDialog", "\320\237\320\276\320\272\321\203\320\277\320\260\321\202\320\265\320\273\321\214", nullptr));
        btnOk->setText(QCoreApplication::translate("SaleDialog", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        label_4->setText(QCoreApplication::translate("SaleDialog", "\320\242\321\200\320\260\320\275\321\201\320\277\320\276\321\200\321\202\320\275\320\276\320\265 \321\201\321\200\320\265\320\264\321\201\321\202\320\262\320\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SaleDialog: public Ui_SaleDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SALEDIALOG_H
