/********************************************************************************
** Form generated from reading UI file 'manufacturerdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANUFACTURERDIALOG_H
#define UI_MANUFACTURERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ManufacturerDialog
{
public:
    QGroupBox *Group3;
    QGridLayout *gridLayout;
    QLineEdit *txtCountry;
    QLineEdit *txtName;
    QLabel *label_2;
    QLabel *label;
    QPushButton *btnOk;
    QPushButton *btnCancel;

    void setupUi(QDialog *ManufacturerDialog)
    {
        if (ManufacturerDialog->objectName().isEmpty())
            ManufacturerDialog->setObjectName("ManufacturerDialog");
        ManufacturerDialog->resize(431, 134);
        ManufacturerDialog->setStyleSheet(QString::fromUtf8("background-color: rgb(199, 199, 199);\n"
"color: rgb(0, 0, 0);"));
        Group3 = new QGroupBox(ManufacturerDialog);
        Group3->setObjectName("Group3");
        Group3->setGeometry(QRect(10, 10, 411, 111));
        Group3->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 220, 220);"));
        gridLayout = new QGridLayout(Group3);
        gridLayout->setObjectName("gridLayout");
        txtCountry = new QLineEdit(Group3);
        txtCountry->setObjectName("txtCountry");

        gridLayout->addWidget(txtCountry, 1, 1, 1, 1);

        txtName = new QLineEdit(Group3);
        txtName->setObjectName("txtName");

        gridLayout->addWidget(txtName, 0, 1, 1, 1);

        label_2 = new QLabel(Group3);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label = new QLabel(Group3);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        btnOk = new QPushButton(Group3);
        btnOk->setObjectName("btnOk");
        btnOk->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 128, 128);\n"
"color: rgb(255, 255, 255);"));

        gridLayout->addWidget(btnOk, 2, 0, 1, 2);

        btnCancel = new QPushButton(Group3);
        btnCancel->setObjectName("btnCancel");
        btnCancel->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 128, 128);\n"
"color: rgb(255, 255, 255);"));

        gridLayout->addWidget(btnCancel, 3, 0, 1, 2);


        retranslateUi(ManufacturerDialog);

        QMetaObject::connectSlotsByName(ManufacturerDialog);
    } // setupUi

    void retranslateUi(QDialog *ManufacturerDialog)
    {
        ManufacturerDialog->setWindowTitle(QCoreApplication::translate("ManufacturerDialog", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\277\321\200\320\276\320\270\320\267\320\262\320\276\320\264\320\270\321\202\320\265\320\273\321\217", nullptr));
        label_2->setText(QCoreApplication::translate("ManufacturerDialog", "\320\241\321\202\321\200\320\260\320\275\320\260 \320\277\321\200\320\276\320\270\321\201\321\205\320\276\320\266\320\264\320\265\320\275\320\270\321\217", nullptr));
        label->setText(QCoreApplication::translate("ManufacturerDialog", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        btnOk->setText(QCoreApplication::translate("ManufacturerDialog", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        btnCancel->setText(QCoreApplication::translate("ManufacturerDialog", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ManufacturerDialog: public Ui_ManufacturerDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANUFACTURERDIALOG_H
