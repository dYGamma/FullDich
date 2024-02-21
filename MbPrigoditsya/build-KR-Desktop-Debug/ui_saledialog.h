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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SaleDialog
{
public:
    QLabel *label_3;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *txtDealer;
    QLabel *label_4;
    QLineEdit *txtAmount;
    QLabel *label_5;
    QDateEdit *dateEdit;
    QPushButton *btnOk;
    QPushButton *btnCancel;
    QComboBox *cbCustomer;
    QComboBox *cbVehicle;

    void setupUi(QDialog *SaleDialog)
    {
        if (SaleDialog->objectName().isEmpty())
            SaleDialog->setObjectName("SaleDialog");
        SaleDialog->resize(431, 202);
        label_3 = new QLabel(SaleDialog);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 70, 81, 16));
        label = new QLabel(SaleDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 10, 121, 16));
        label_2 = new QLabel(SaleDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 40, 101, 16));
        txtDealer = new QLineEdit(SaleDialog);
        txtDealer->setObjectName("txtDealer");
        txtDealer->setGeometry(QRect(150, 40, 271, 22));
        label_4 = new QLabel(SaleDialog);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 100, 141, 16));
        txtAmount = new QLineEdit(SaleDialog);
        txtAmount->setObjectName("txtAmount");
        txtAmount->setGeometry(QRect(150, 130, 271, 22));
        label_5 = new QLabel(SaleDialog);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 130, 101, 16));
        dateEdit = new QDateEdit(SaleDialog);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setGeometry(QRect(150, 10, 271, 22));
        btnOk = new QPushButton(SaleDialog);
        btnOk->setObjectName("btnOk");
        btnOk->setGeometry(QRect(200, 170, 101, 21));
        btnCancel = new QPushButton(SaleDialog);
        btnCancel->setObjectName("btnCancel");
        btnCancel->setGeometry(QRect(320, 170, 101, 21));
        cbCustomer = new QComboBox(SaleDialog);
        cbCustomer->setObjectName("cbCustomer");
        cbCustomer->setGeometry(QRect(150, 70, 271, 22));
        cbVehicle = new QComboBox(SaleDialog);
        cbVehicle->setObjectName("cbVehicle");
        cbVehicle->setGeometry(QRect(150, 100, 271, 22));

        retranslateUi(SaleDialog);

        QMetaObject::connectSlotsByName(SaleDialog);
    } // setupUi

    void retranslateUi(QDialog *SaleDialog)
    {
        SaleDialog->setWindowTitle(QCoreApplication::translate("SaleDialog", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\277\321\200\320\276\320\264\320\260\320\266\320\270", nullptr));
        label_3->setText(QCoreApplication::translate("SaleDialog", "\320\237\320\276\320\272\321\203\320\277\320\260\321\202\320\265\320\273\321\214", nullptr));
        label->setText(QCoreApplication::translate("SaleDialog", "\320\224\320\260\321\202\320\260 \320\277\321\200\320\276\320\264\320\260\320\266\320\270", nullptr));
        label_2->setText(QCoreApplication::translate("SaleDialog", "\320\237\321\200\320\276\320\264\320\260\320\262\320\265\321\206", nullptr));
        label_4->setText(QCoreApplication::translate("SaleDialog", "\320\242\321\200\320\260\320\275\321\201\320\277\320\276\321\200\321\202\320\275\320\276\320\265 \321\201\321\200\320\265\320\264\321\201\321\202\320\262\320\276", nullptr));
        label_5->setText(QCoreApplication::translate("SaleDialog", "\320\241\321\203\320\274\320\274\320\260 \320\277\321\200\320\276\320\264\320\260\320\266\320\270", nullptr));
        btnOk->setText(QCoreApplication::translate("SaleDialog", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        btnCancel->setText(QCoreApplication::translate("SaleDialog", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SaleDialog: public Ui_SaleDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SALEDIALOG_H
