/********************************************************************************
** Form generated from reading UI file 'example.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXAMPLE_H
#define UI_EXAMPLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_exampleClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *exampleClass)
    {
        if (exampleClass->objectName().isEmpty())
            exampleClass->setObjectName(QString::fromUtf8("exampleClass"));
        exampleClass->resize(600, 400);
        menuBar = new QMenuBar(exampleClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        exampleClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(exampleClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        exampleClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(exampleClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        exampleClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(exampleClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        exampleClass->setStatusBar(statusBar);

        retranslateUi(exampleClass);

        QMetaObject::connectSlotsByName(exampleClass);
    } // setupUi

    void retranslateUi(QMainWindow *exampleClass)
    {
        exampleClass->setWindowTitle(QApplication::translate("exampleClass", "example", nullptr));
    } // retranslateUi

};

namespace Ui {
    class exampleClass: public Ui_exampleClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXAMPLE_H
