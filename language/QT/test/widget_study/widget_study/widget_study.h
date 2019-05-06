#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_widget_study.h"

class widget_study : public QMainWindow
{
	Q_OBJECT

public:
	widget_study(QWidget *parent = Q_NULLPTR);

private:
	Ui::widget_studyClass ui;
};
