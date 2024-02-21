/********************************************************************************
** Form generated from reading UI file 'customerdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMERDIALOG_H
#define UI_CUSTOMERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_CustomerDialog
{
public:
    QLabel *label_3;
    QLineEdit *txtFName;
    QLabel *label;
    QLineEdit *txtContacts;
    QLabel *label_2;
    QLineEdit *txtLName;
    QPushButton *btnOk;
    QPushButton *btnCancel;

    void setupUi(QDialog *CustomerDialog)
    {
        if (CustomerDialog->objectName().isEmpty())
            CustomerDialog->setObjectName("CustomerDialog");
        CustomerDialog->resize(431, 140);
        label_3 = new QLabel(CustomerDialog);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 70, 141, 16));
        txtFName = new QLineEdit(CustomerDialog);
        txtFName->setObjectName("txtFName");
        txtFName->setGeometry(QRect(150, 10, 271, 22));
        label = new QLabel(CustomerDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 10, 49, 16));
        txtContacts = new QLineEdit(CustomerDialog);
        txtContacts->setObjectName("txtContacts");
        txtContacts->setGeometry(QRect(150, 70, 271, 22));
        label_2 = new QLabel(CustomerDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 40, 81, 16));
        txtLName = new QLineEdit(CustomerDialog);
        txtLName->setObjectName("txtLName");
        txtLName->setGeometry(QRect(150, 40, 271, 22));
        btnOk = new QPushButton(CustomerDialog);
        btnOk->setObjectName("btnOk");
        btnOk->setGeometry(QRect(200, 110, 101, 21));
        btnCancel = new QPushButton(CustomerDialog);
        btnCancel->setObjectName("btnCancel");
        btnCancel->setGeometry(QRect(320, 110, 101, 21));

        retranslateUi(CustomerDialog);

        QMetaObject::connectSlotsByName(CustomerDialog);
    } // setupUi

    void retranslateUi(QDialog *CustomerDialog)
    {
        CustomerDialog->setWindowTitle(QCoreApplication::translate("CustomerDialog", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\277\320\276\320\272\321\203\320\277\320\260\321\202\320\265\320\273\321\217", nullptr));
        label_3->setText(QCoreApplication::translate("CustomerDialog", "\320\232\320\276\320\275\321\202\320\260\320\272\321\202\320\275\320\260\321\217 \320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217", nullptr));
        label->setText(QCoreApplication::translate("CustomerDialog", "\320\230\320\274\321\217", nullptr));
        label_2->setText(QCoreApplication::translate("CustomerDialog", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", nullptr));
        btnOk->setText(QCoreApplication::translate("CustomerDialog", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        btnCancel->setText(QCoreApplication::translate("CustomerDialog", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CustomerDialog: public Ui_CustomerDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMERDIALOG_H
