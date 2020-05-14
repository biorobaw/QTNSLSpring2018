#include <QtWidgets/QApplication>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <stddef.h>
#include "NSLControls/incl/NSLMainWindow.h"

extern void NSLmain(int argc,char** argv);
extern void NSLinit(int argc,char** argv);

QApplication *MainApplication = NULL;

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	MainApplication = &app;

	QQmlApplicationEngine engine;
	engine.load(QUrl(QStringLiteral("qrc:/qtnsl.qml")));

	NSLinit(argc, argv);
	NSLmain(argc, argv);

	return app.exec();
}
