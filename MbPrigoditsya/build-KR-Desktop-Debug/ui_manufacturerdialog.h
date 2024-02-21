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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ManufacturerDialog
{
public:
    QLineEdit *txtName;
    QLineEdit *txtCountry;
    QLabel *label_2;
    QLabel *label;
    QPushButton *btnCancel;
    QPushButton *btnOk;

    void setupUi(QDialog *ManufacturerDialog)
    {
        if (ManufacturerDialog->objectName().isEmpty())
            ManufacturerDialog->setObjectName("ManufacturerDialog");
        ManufacturerDialog->resize(433, 109);
        txtName = new QLineEdit(ManufacturerDialog);
        txtName->setObjectName("txtName");
        txtName->setGeometry(QRect(150, 10, 271, 22));
        txtCountry = new QLineEdit(ManufacturerDialog);
        txtCountry->setObjectName("txtCountry");
        txtCountry->setGeometry(QRect(150, 40, 271, 22));
        label_2 = new QLabel(ManufacturerDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 40, 131, 16));
        label = new QLabel(ManufacturerDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 10, 101, 16));
        btnCancel = new QPushButton(ManufacturerDialog);
        btnCancel->setObjectName("btnCancel");
        btnCancel->setGeometry(QRect(320, 80, 101, 21));
        btnOk = new QPushButton(ManufacturerDialog);
        btnOk->setObjectName("btnOk");
        btnOk->setGeometry(QRect(200, 80, 101, 21));

        retranslateUi(ManufacturerDialog);

        QMetaObject::connectSlotsByName(ManufacturerDialog);
    } // setupUi

    void retranslateUi(QDialog *ManufacturerDialog)
    {
        ManufacturerDialog->setWindowTitle(QCoreApplication::translate("ManufacturerDialog", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\277\321\200\320\276\320\270\320\267\320\262\320\276\320\264\320\270\321\202\320\265\320\273\321\217", nullptr));
        label_2->setText(QCoreApplication::translate("ManufacturerDialog", "\320\241\321\202\321\200\320\260\320\275\320\260 \320\277\321\200\320\276\320\270\321\201\321\205\320\276\320\266\320\264\320\265\320\275\320\270\321\217", nullptr));
        label->setText(QCoreApplication::translate("ManufacturerDialog", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        btnCancel->setText(QCoreApplication::translate("ManufacturerDialog", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
        btnOk->setText(QCoreApplication::translate("ManufacturerDialog", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ManufacturerDialog: public Ui_ManufacturerDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANUFACTURERDIALOG_H
