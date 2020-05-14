#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtWidgets/QDesktopWidget>
#include "incl/NSLMainWindow.h"
#include "xlib_qt_interface.h"
#include "nsl_interpreter.h"

extern QApplication *MainApplication;
NSLInterface *Interface = NULL;

void QtDisplay() //this will display all widgets available
{
	Interface->Display();
}

void QtConfigureWindows()
{
	QDesktopWidget QD; //desktop visual details
	QSize avSz(QD.width()*0.4, QD.height()*0.25); //for resizing windows

	Interface->Configure(avSz.height(), avSz.width());
	Interface->SetBuffer(NSL_INTERPRETER->get_buffer());
}

void QtInitWindows()
{
	Interface = new NSLInterface;
}

void QtInit() //any qt initialization functions
{
	QtInitWindows();
	QtConfigureWindows();
	QtDisplay();
}

void QtOutput(const char *str)
{
	if (Interface != NULL)
		Interface->Output(str);
}
