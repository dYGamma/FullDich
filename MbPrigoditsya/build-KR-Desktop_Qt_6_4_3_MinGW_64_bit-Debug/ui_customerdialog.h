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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_CustomerDialog
{
public:
    QGroupBox *Group1;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *txtLName;
    QLineEdit *txtFName;
    QLineEdit *txtContacts;
    QLabel *label;
    QLabel *label_3;
    QPushButton *btnOk;
    QPushButton *btnCancel;

    void setupUi(QDialog *CustomerDialog)
    {
        if (CustomerDialog->objectName().isEmpty())
            CustomerDialog->setObjectName("CustomerDialog");
        CustomerDialog->resize(431, 163);
        CustomerDialog->setStyleSheet(QString::fromUtf8("background-color: rgb(199, 199, 199);\n"
"color: rgb(0, 0, 0);"));
        Group1 = new QGroupBox(CustomerDialog);
        Group1->setObjectName("Group1");
        Group1->setGeometry(QRect(10, 10, 411, 141));
        Group1->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 220, 220);"));
        gridLayout = new QGridLayout(Group1);
        gridLayout->setObjectName("gridLayout");
        label_2 = new QLabel(Group1);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        txtLName = new QLineEdit(Group1);
        txtLName->setObjectName("txtLName");

        gridLayout->addWidget(txtLName, 1, 1, 1, 1);

        txtFName = new QLineEdit(Group1);
        txtFName->setObjectName("txtFName");

        gridLayout->addWidget(txtFName, 0, 1, 1, 1);

        txtContacts = new QLineEdit(Group1);
        txtContacts->setObjectName("txtContacts");

        gridLayout->addWidget(txtContacts, 2, 1, 1, 1);

        label = new QLabel(Group1);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_3 = new QLabel(Group1);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        btnOk = new QPushButton(Group1);
        btnOk->setObjectName("btnOk");
        btnOk->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 128, 128);\n"
"color: rgb(255, 255, 255);"));

        gridLayout->addWidget(btnOk, 3, 0, 1, 2);

        btnCancel = new QPushButton(Group1);
        btnCancel->setObjectName("btnCancel");
        btnCancel->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 128, 128);\n"
"color: rgb(255, 255, 255);"));

        gridLayout->addWidget(btnCancel, 4, 0, 1, 2);


        retranslateUi(CustomerDialog);

        QMetaObject::connectSlotsByName(CustomerDialog);
    } // setupUi

    void retranslateUi(QDialog *CustomerDialog)
    {
        CustomerDialog->setWindowTitle(QCoreApplication::translate("CustomerDialog", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\277\320\276\320\272\321\203\320\277\320\260\321\202\320\265\320\273\321\217", nullptr));
        label_2->setText(QCoreApplication::translate("CustomerDialog", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", nullptr));
        label->setText(QCoreApplication::translate("CustomerDialog", "\320\230\320\274\321\217", nullptr));
        label_3->setText(QCoreApplication::translate("CustomerDialog", "\320\232\320\276\320\275\321\202\320\260\320\272\321\202\320\275\320\260\321\217 \320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217", nullptr));
        btnOk->setText(QCoreApplication::translate("CustomerDialog", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        btnCancel->setText(QCoreApplication::translate("CustomerDialog", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CustomerDialog: public Ui_CustomerDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMERDIALOG_H
