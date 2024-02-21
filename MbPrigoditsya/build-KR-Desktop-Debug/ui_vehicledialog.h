/********************************************************************************
** Form generated from reading UI file 'vehicledialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VEHICLEDIALOG_H
#define UI_VEHICLEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_VehicleDialog
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *txtMark;
    QLineEdit *txtModel;
    QLineEdit *txtYear;
    QLineEdit *txtPrice;
    QLineEdit *txtDescription;
    QPushButton *btnOk;
    QPushButton *btnCancel;
    QLineEdit *txtStatus;

    void setupUi(QDialog *VehicleDialog)
    {
        if (VehicleDialog->objectName().isEmpty())
            VehicleDialog->setObjectName("VehicleDialog");
        VehicleDialog->setWindowModality(Qt::ApplicationModal);
        VehicleDialog->resize(433, 242);
        label = new QLabel(VehicleDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 20, 49, 16));
        label_2 = new QLabel(VehicleDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 50, 49, 16));
        label_3 = new QLabel(VehicleDialog);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 80, 81, 16));
        label_4 = new QLabel(VehicleDialog);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 110, 71, 16));
        label_5 = new QLabel(VehicleDialog);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 140, 81, 16));
        label_6 = new QLabel(VehicleDialog);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(10, 170, 49, 16));
        txtMark = new QLineEdit(VehicleDialog);
        txtMark->setObjectName("txtMark");
        txtMark->setGeometry(QRect(150, 20, 271, 22));
        txtModel = new QLineEdit(VehicleDialog);
        txtModel->setObjectName("txtModel");
        txtModel->setGeometry(QRect(150, 50, 271, 22));
        txtYear = new QLineEdit(VehicleDialog);
        txtYear->setObjectName("txtYear");
        txtYear->setGeometry(QRect(150, 80, 271, 22));
        txtPrice = new QLineEdit(VehicleDialog);
        txtPrice->setObjectName("txtPrice");
        txtPrice->setGeometry(QRect(150, 110, 271, 22));
        txtDescription = new QLineEdit(VehicleDialog);
        txtDescription->setObjectName("txtDescription");
        txtDescription->setGeometry(QRect(150, 140, 271, 22));
        btnOk = new QPushButton(VehicleDialog);
        btnOk->setObjectName("btnOk");
        btnOk->setGeometry(QRect(200, 210, 101, 21));
        btnCancel = new QPushButton(VehicleDialog);
        btnCancel->setObjectName("btnCancel");
        btnCancel->setGeometry(QRect(320, 210, 101, 21));
        txtStatus = new QLineEdit(VehicleDialog);
        txtStatus->setObjectName("txtStatus");
        txtStatus->setGeometry(QRect(150, 170, 271, 22));

        retranslateUi(VehicleDialog);

        QMetaObject::connectSlotsByName(VehicleDialog);
    } // setupUi

    void retranslateUi(QDialog *VehicleDialog)
    {
        VehicleDialog->setWindowTitle(QCoreApplication::translate("VehicleDialog", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \321\202\321\200\320\260\320\275\321\201\320\277\320\276\321\200\321\202\320\275\320\276\320\263\320\276 \321\201\321\200\320\265\320\264\321\201\321\202\320\262\320\260", nullptr));
        label->setText(QCoreApplication::translate("VehicleDialog", "\320\234\320\260\321\200\320\272\320\260", nullptr));
        label_2->setText(QCoreApplication::translate("VehicleDialog", "\320\234\320\276\320\264\320\265\320\273\321\214", nullptr));
        label_3->setText(QCoreApplication::translate("VehicleDialog", "\320\223\320\276\320\264 \320\262\321\213\320\277\321\203\321\201\320\272\320\260", nullptr));
        label_4->setText(QCoreApplication::translate("VehicleDialog", "\320\241\321\202\320\276\320\270\320\274\320\276\321\201\321\202\321\214", nullptr));
        label_5->setText(QCoreApplication::translate("VehicleDialog", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265", nullptr));
        label_6->setText(QCoreApplication::translate("VehicleDialog", "\320\241\321\202\320\260\321\202\321\203\321\201", nullptr));
        btnOk->setText(QCoreApplication::translate("VehicleDialog", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        btnCancel->setText(QCoreApplication::translate("VehicleDialog", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VehicleDialog: public Ui_VehicleDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VEHICLEDIALOG_H
