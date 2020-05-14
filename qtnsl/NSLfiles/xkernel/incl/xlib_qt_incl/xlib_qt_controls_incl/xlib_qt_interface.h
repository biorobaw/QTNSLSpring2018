#ifndef _XLIB_INTERFACE_CONTROL_H
#define _XLIB_INTERFACE_CONTROL_H
#include <QGuiApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QKeyEvent>
#include "nsl_buffer.h"
#define QTI_BUFFER_SIZE 256
#define QTI_MAX_LINES 10

class xlib_qt_interface;
class xlib_qt_input : public QObject //keyboard event detector and filter
{
private:
	Q_OBJECT

	xlib_qt_interface *control;
protected:
bool eventFilter(QObject* obj, QEvent* event); //captures keyboard input

public:
inline void SetControl(xlib_qt_interface *c) { control = c; };
};

class xlib_qt_interface : public QWidget //the qt console and control panel
{
private:
	Q_OBJECT

	void Initialize();
	QPushButton *AddButtonToPanel(const char *, const char *, QObject *);

	enum QT_BUTTON_ID { BUTTON_RUN, BUTTON_EXIT };

	QPushButton **buttons;
	QGuiApplication *refApp;

	int menuBarLength;
	int menuBarHeight;
	int numButtons;

	bool disableRun;

	char keybuf[QTI_BUFFER_SIZE]; //the char buffer for current line
	nsl_buffer *buf; //interface cannot function without buffer
	unsigned int uindex, stacksize, panelHeight;

	QLabel *input;
	QLabel **outstack;
	xlib_qt_input *keyin;

private slots:
		void execRunButton();

protected:
	void RedrawText();
	void PushQueue(const QString &next);

public:
	explicit xlib_qt_interface(QWidget *W = 0);
	~xlib_qt_interface();

	void BackspaceEvent();
	void CharacterEvent(QKeyEvent*);
	void ReturnEvent();

	void Configure(int height, int width);
	void Display();
	void SetBuffer(nsl_buffer &);
	void Output(const char *);

};
typedef xlib_qt_interface NSLInterface;
#endif
