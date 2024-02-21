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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DealershipDialog
{
public:
    QLineEdit *txtName;
    QLineEdit *txtAddress;
    QLabel *label_2;
    QLabel *label;
    QPushButton *btnOk;
    QPushButton *btnCancel;

    void setupUi(QDialog *DealershipDialog)
    {
        if (DealershipDialog->objectName().isEmpty())
            DealershipDialog->setObjectName("DealershipDialog");
        DealershipDialog->resize(430, 101);
        txtName = new QLineEdit(DealershipDialog);
        txtName->setObjectName("txtName");
        txtName->setGeometry(QRect(150, 10, 271, 22));
        txtAddress = new QLineEdit(DealershipDialog);
        txtAddress->setObjectName("txtAddress");
        txtAddress->setGeometry(QRect(150, 40, 271, 22));
        label_2 = new QLabel(DealershipDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 40, 49, 16));
        label = new QLabel(DealershipDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 10, 101, 16));
        btnOk = new QPushButton(DealershipDialog);
        btnOk->setObjectName("btnOk");
        btnOk->setGeometry(QRect(200, 70, 101, 21));
        btnCancel = new QPushButton(DealershipDialog);
        btnCancel->setObjectName("btnCancel");
        btnCancel->setGeometry(QRect(320, 70, 101, 21));

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
