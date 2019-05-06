/********************************************************************************
** Form generated from reading UI file 'widget_study.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_STUDY_H
#define UI_WIDGET_STUDY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_widget_studyClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *widget_studyClass)
    {
        if (widget_studyClass->objectName().isEmpty())
            widget_studyClass->setObjectName(QString::fromUtf8("widget_studyClass"));
        widget_studyClass->resize(600, 400);
        menuBar = new QMenuBar(widget_studyClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        widget_studyClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(widget_studyClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        widget_studyClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(widget_studyClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        widget_studyClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(widget_studyClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        widget_studyClass->setStatusBar(statusBar);

        retranslateUi(widget_studyClass);

        QMetaObject::connectSlotsByName(widget_studyClass);
    } // setupUi

    void retranslateUi(QMainWindow *widget_studyClass)
    {
        widget_studyClass->setWindowTitle(QApplication::translate("widget_studyClass", "widget_study", nullptr));
    } // retranslateUi

};

namespace Ui {
    class widget_studyClass: public Ui_widget_studyClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_STUDY_H
