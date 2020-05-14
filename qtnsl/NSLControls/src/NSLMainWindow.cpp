#include <QtWidgets/QApplication>
#include "../incl/NSLMainWindow.h"
#include "nsl_interpreter.h"

extern QGuiApplication *MainApplication;
extern nsl_interpreter* NSL_INTERPRETER;

NSLMainWindow::NSLMainWindow(QWidget *iparent)
{
Initialize();
}

NSLMainWindow::~NSLMainWindow()
{
}

void NSLMainWindow::Initialize()
{
	//initialize data members
	setStyleSheet("background-color: white");
}

void NSLMainWindow::Display()
{
}
