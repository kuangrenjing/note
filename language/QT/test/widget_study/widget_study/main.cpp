//#include "widget_study.h"
#include "pch.h"
#include "analogclock/analogclock.h"
#include "calculator/calculator.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

#ifdef ANALOGCLOCK
	AnalogClock wAnalogClock;
	wAnalogClock.show();
#endif

#ifdef CALCULATOR
	Calculator calc;
	calc.show();
#endif
	return a.exec();
}
