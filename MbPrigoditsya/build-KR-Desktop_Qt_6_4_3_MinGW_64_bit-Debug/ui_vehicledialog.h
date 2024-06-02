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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_VehicleDialog
{
public:
    QGroupBox *Group5;
    QGridLayout *gridLayout;
    QPushButton *btnCancel;
    QLabel *label_3;
    QLineEdit *txtPrice;
    QLabel *label_4;
    QLineEdit *txtYear;
    QPushButton *btnOk;
    QLabel *label_5;
    QLabel *label_2;
    QLabel *label;
    QLineEdit *txtModel;
    QLineEdit *txtDescription;
    QLineEdit *txtStatus;
    QLabel *label_6;
    QComboBox *cmbMark;

    void setupUi(QDialog *VehicleDialog)
    {
        if (VehicleDialog->objectName().isEmpty())
            VehicleDialog->setObjectName("VehicleDialog");
        VehicleDialog->setWindowModality(Qt::ApplicationModal);
        VehicleDialog->resize(600, 300);
        VehicleDialog->setStyleSheet(QString::fromUtf8("background-color: rgb(199, 199, 199);\n"
"color: rgb(0, 0, 0);"));
        Group5 = new QGroupBox(VehicleDialog);
        Group5->setObjectName("Group5");
        Group5->setGeometry(QRect(10, 5, 581, 281));
        Group5->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 220, 220);"));
        gridLayout = new QGridLayout(Group5);
        gridLayout->setObjectName("gridLayout");
        btnCancel = new QPushButton(Group5);
        btnCancel->setObjectName("btnCancel");
        btnCancel->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 128, 128);\n"
"color: rgb(255, 255, 255);"));

        gridLayout->addWidget(btnCancel, 8, 0, 1, 3);

        label_3 = new QLabel(Group5);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        txtPrice = new QLineEdit(Group5);
        txtPrice->setObjectName("txtPrice");

        gridLayout->addWidget(txtPrice, 4, 2, 1, 1);

        label_4 = new QLabel(Group5);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        txtYear = new QLineEdit(Group5);
        txtYear->setObjectName("txtYear");

        gridLayout->addWidget(txtYear, 3, 2, 1, 1);

        btnOk = new QPushButton(Group5);
        btnOk->setObjectName("btnOk");
        btnOk->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 128, 128);\n"
"color: rgb(255, 255, 255);"));

        gridLayout->addWidget(btnOk, 7, 0, 1, 3);

        label_5 = new QLabel(Group5);
        label_5->setObjectName("label_5");

        gridLayout->addWidget(label_5, 5, 0, 1, 1);

        label_2 = new QLabel(Group5);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        label = new QLabel(Group5);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        txtModel = new QLineEdit(Group5);
        txtModel->setObjectName("txtModel");

        gridLayout->addWidget(txtModel, 2, 2, 1, 1);

        txtDescription = new QLineEdit(Group5);
        txtDescription->setObjectName("txtDescription");

        gridLayout->addWidget(txtDescription, 5, 2, 1, 1);

        txtStatus = new QLineEdit(Group5);
        txtStatus->setObjectName("txtStatus");

        gridLayout->addWidget(txtStatus, 6, 2, 1, 1);

        label_6 = new QLabel(Group5);
        label_6->setObjectName("label_6");

        gridLayout->addWidget(label_6, 6, 0, 1, 1);

        cmbMark = new QComboBox(Group5);
        cmbMark->setObjectName("cmbMark");

        gridLayout->addWidget(cmbMark, 0, 2, 1, 1);


        retranslateUi(VehicleDialog);

        QMetaObject::connectSlotsByName(VehicleDialog);
    } // setupUi

    void retranslateUi(QDialog *VehicleDialog)
    {
        VehicleDialog->setWindowTitle(QCoreApplication::translate("VehicleDialog", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \321\202\321\200\320\260\320\275\321\201\320\277\320\276\321\200\321\202\320\275\320\276\320\263\320\276 \321\201\321\200\320\265\320\264\321\201\321\202\320\262\320\260", nullptr));
        btnCancel->setText(QCoreApplication::translate("VehicleDialog", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
        label_3->setText(QCoreApplication::translate("VehicleDialog", "\320\223\320\276\320\264 \320\262\321\213\320\277\321\203\321\201\320\272\320\260", nullptr));
        label_4->setText(QCoreApplication::translate("VehicleDialog", "\320\241\321\202\320\276\320\270\320\274\320\276\321\201\321\202\321\214", nullptr));
        btnOk->setText(QCoreApplication::translate("VehicleDialog", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        label_5->setText(QCoreApplication::translate("VehicleDialog", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265", nullptr));
        label_2->setText(QCoreApplication::translate("VehicleDialog", "\320\234\320\276\320\264\320\265\320\273\321\214", nullptr));
        label->setText(QCoreApplication::translate("VehicleDialog", "\320\234\320\260\321\200\320\272\320\260", nullptr));
        label_6->setText(QCoreApplication::translate("VehicleDialog", "\320\241\321\202\320\260\321\202\321\203\321\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VehicleDialog: public Ui_VehicleDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VEHICLEDIALOG_H
