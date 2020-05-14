#ifndef _NSLMAINWINDOW_H
#define _NSLMAINWINDOW_H
#include <QGuiApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include "NSLVectorGraph.h"
#define QT_BUTTONCOUNT 2
class NSLMainWindow : public QMainWindow
{
private:
	void Initialize();

	//NSLVectorGraph *tgraph;

private slots:
public:
	explicit NSLMainWindow(QWidget *W = 0);
	~NSLMainWindow();

	void Display();
};

#endif
