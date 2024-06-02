/********************************************************************************
** Form generated from reading UI file 'dealershipdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEALERSHIPDIALOG_H
#define UI_DEALERSHIPDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DealershipDialog
{
public:
    QGroupBox *Group2;
    QGridLayout *gridLayout;
    QLineEdit *txtName;
    QLabel *label_2;
    QLabel *label;
    QLineEdit *txtAddress;
    QPushButton *btnOk;
    QPushButton *btnCancel;

    void setupUi(QDialog *DealershipDialog)
    {
        if (DealershipDialog->objectName().isEmpty())
            DealershipDialog->setObjectName("DealershipDialog");
        DealershipDialog->resize(432, 142);
        DealershipDialog->setStyleSheet(QString::fromUtf8("background-color: rgb(199, 199, 199);\n"
"color: rgb(0, 0, 0);"));
        Group2 = new QGroupBox(DealershipDialog);
        Group2->setObjectName("Group2");
        Group2->setGeometry(QRect(10, 10, 411, 121));
        Group2->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 220, 220);"));
        gridLayout = new QGridLayout(Group2);
        gridLayout->setObjectName("gridLayout");
        txtName = new QLineEdit(Group2);
        txtName->setObjectName("txtName");

        gridLayout->addWidget(txtName, 0, 1, 1, 1);

        label_2 = new QLabel(Group2);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label = new QLabel(Group2);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        txtAddress = new QLineEdit(Group2);
        txtAddress->setObjectName("txtAddress");

        gridLayout->addWidget(txtAddress, 1, 1, 1, 1);

        btnOk = new QPushButton(Group2);
        btnOk->setObjectName("btnOk");
        btnOk->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 128, 128);\n"
"color: rgb(255, 255, 255);"));

        gridLayout->addWidget(btnOk, 2, 0, 1, 2);

        btnCancel = new QPushButton(Group2);
        btnCancel->setObjectName("btnCancel");
        btnCancel->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 128, 128);\n"
"color: rgb(255, 255, 255);"));

        gridLayout->addWidget(btnCancel, 3, 0, 1, 2);


        retranslateUi(DealershipDialog);

        QMetaObject::connectSlotsByName(DealershipDialog);
    } // setupUi

    void retranslateUi(QDialog *DealershipDialog)
    {
        DealershipDialog->setWindowTitle(QCoreApplication::translate("DealershipDialog", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\264\320\270\320\273\320\265\321\200\321\201\320\272\320\276\320\263\320\276 \321\206\320\265\320\275\321\202\321\200\320\260", nullptr));
        label_2->setText(QCoreApplication::translate("DealershipDialog", "\320\220\320\264\321\200\320\265\321\201", nullptr));
        label->setText(QCoreApplication::translate("DealershipDialog", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        btnOk->setText(QCoreApplication::translate("DealershipDialog", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        btnCancel->setText(QCoreApplication::translate("DealershipDialog", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DealershipDialog: public Ui_DealershipDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEALERSHIPDIALOG_H
