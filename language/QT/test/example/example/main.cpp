//#include "example.h"
#include "pch.h"
//#include <QtWidgets/QApplication>

#include <QApplication>
#include <QCommandLineParser>
#include <QCommandLineOption>

#include "application/application_example/application_example_mainwindow.h"

//https://doc.qt.io/qt-5/qtexamplesandtutorials.html
int main(int argc, char *argv[])
{
#ifdef __APPLICATIONS__
#ifdef __APPLICATION_EXAMPLE__
	Q_INIT_RESOURCE(application_example_application);

	QApplication app(argc, argv);
	//QCoreApplication::setOrganizationName("QtProject");
	//QCoreApplication::setApplicationName("Application Example");
	//QCoreApplication::setApplicationVersion(QT_VERSION_STR);
	//QCommandLineParser parser;
	//parser.setApplicationDescription(QCoreApplication::applicationName());
	//parser.addHelpOption();
	//parser.addVersionOption();
	//parser.addPositionalArgument("file", "The file to open.");
	//parser.process(app);

	MainWindow mainWin;
	//if(!parser.positionalArguments().isEmpty())
	//	mainWin.loadFile(parser.positionalArguments().first());
	mainWin.show();
	return app.exec();


#endif //__APPLICATION_EXAMPLE__
#endif //__APPLICATIONS__
}
