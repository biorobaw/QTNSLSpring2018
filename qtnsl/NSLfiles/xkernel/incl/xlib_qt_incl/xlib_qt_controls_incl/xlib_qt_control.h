#ifndef _XLIB_QT_CONTROL_H
#define _XLIB_QT_CONTROL_H
#include <QGuiApplication>
#include <QtWidgets/QMainWindow>
//this is the master class for all qt controls
class xlib_qt_control : public QWidget
{
private:
	Q_OBJECT

private slots:

protected:
QGuiApplication *refApp;
void Initialize();

public:
	explicit xlib_qt_control(QWidget *W = 0);
	~xlib_qt_control();

	virtual void Configure(int height, int width);
	virtual void Display();
};
#endif
