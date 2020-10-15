/********************************************************************************
** Form generated from reading UI file 'Login.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QLabel *label;
    QLineEdit *textName;
    QLabel *label_2;
    QLineEdit *textUser;
    QPushButton *btnSure;
    QLabel *LOGO;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(400, 300);
        label = new QLabel(Login);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 80, 70, 40));
        label->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"	border: 1px solid gray;\n"
"	border-right: none;\n"
"	border-top-left-radius: 20px;\n"
"	border-bottom-left-radius: 20px;\n"
"}\n"
"QLabel:hover{\n"
"	color: rgb(255, 93, 35);\n"
"	border-color: rgb(255, 93, 35);\n"
"}\n"
"QLabel:pressed{\n"
"	background-color: rgb(255, 93, 35);\n"
"	color: rgb(255, 255, 255);\n"
"}"));
        label->setAlignment(Qt::AlignCenter);
        textName = new QLineEdit(Login);
        textName->setObjectName(QString::fromUtf8("textName"));
        textName->setGeometry(QRect(130, 80, 200, 40));
        textName->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"	border: 1px solid gray;\n"
"	border-left: none;\n"
"	border-top-right-radius: 20px;\n"
"	border-bottom-right-radius: 20px;\n"
"	color: rgb(51, 51, 51);\n"
"}\n"
"QLineEdit:hover{\n"
"	color: rgb(255, 93, 35);\n"
"	border-color: rgb(255, 93, 35);\n"
"}"));
        textName->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(Login);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 160, 70, 40));
        label_2->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"	border: 1px solid gray;\n"
"	border-right: none;\n"
"	border-top-left-radius: 20px;\n"
"	border-bottom-left-radius: 20px;\n"
"}\n"
"QLabel:hover{\n"
"	color: rgb(255, 93, 35);\n"
"	border-color: rgb(255, 93, 35);\n"
"}\n"
"QLabel:pressed{\n"
"	background-color: rgb(255, 93, 35);\n"
"	color: rgb(255, 255, 255);\n"
"}"));
        label_2->setAlignment(Qt::AlignCenter);
        textUser = new QLineEdit(Login);
        textUser->setObjectName(QString::fromUtf8("textUser"));
        textUser->setGeometry(QRect(130, 160, 200, 40));
        textUser->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"	border: 1px solid gray;\n"
"	border-left: none;\n"
"	border-top-right-radius: 20px;\n"
"	border-bottom-right-radius: 20px;\n"
"	color: rgb(51, 51, 51);\n"
"}\n"
"QLineEdit:hover{\n"
"	color: rgb(255, 93, 35);\n"
"	border-color: rgb(255, 93, 35);\n"
"}"));
        textUser->setAlignment(Qt::AlignCenter);
        btnSure = new QPushButton(Login);
        btnSure->setObjectName(QString::fromUtf8("btnSure"));
        btnSure->setGeometry(QRect(60, 240, 270, 40));
        btnSure->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"	border: 1px solid gray;\n"
"	border-radius: 20px;\n"
"	font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"QPushButton:hover{\n"
"	color: rgb(255, 93, 35);\n"
"	border-color: rgb(255, 93, 35);\n"
"}\n"
"QPushButton:pressed{\n"
"	background-color: rgb(255, 93, 35);\n"
"	color: rgb(255, 255, 255);\n"
"}"));
        LOGO = new QLabel(Login);
        LOGO->setObjectName(QString::fromUtf8("LOGO"));
        LOGO->setGeometry(QRect(127, 10, 135, 54));

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QDialog *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Login", "    \345\247\223\345\220\215\357\274\232", nullptr));
        textName->setText(QString());
        label_2->setText(QCoreApplication::translate("Login", "    \345\256\242\346\210\267\345\220\215\357\274\232", nullptr));
        textUser->setText(QString());
        btnSure->setText(QCoreApplication::translate("Login", "\347\241\256\350\256\244", nullptr));
        LOGO->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
