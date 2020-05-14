#include "xlib_qt_interface.h"
#include "nsl_interpreter.h"
#include "math.h"

#define QT_BUTTONCOUNT 2 //number of buttons in this version is constant since we dont need mechanism for dynamically adding buttons
#define _MOVE_OFS(x, y) move(x, menuBarHeight + y) //a macro to include a fixed offset for all positioning

extern QGuiApplication *MainApplication;
extern nsl_buffer& operator<<(nsl_buffer& buf, const char* str);

//=============================================
//Constructor initializes keyboard input filter
//and allocates memory for pointers to arrays
//and sets up basic display characteristics
//=============================================
xlib_qt_interface::xlib_qt_interface(QWidget *W) : uindex(0), stacksize(0), numButtons(0)
{
	memset(keybuf, 0, QTI_BUFFER_SIZE);
	buf = NULL;

	input = new QLabel("", this);
	outstack = NULL; //can only initialize this once we know the dimensions

	//set up keyboard input
	keyin = new xlib_qt_input();
	keyin->SetControl(this);
	installEventFilter(keyin);

	menuBarLength = 50; //size of each button
	menuBarHeight = 25; //height of all buttons

	Initialize();
}

//=============================================
//Destructor contains deletion of all
//dynamically allocated objects in this class
//=============================================
xlib_qt_interface::~xlib_qt_interface()
{
	if (stacksize != 0)
		for (unsigned int i = 0; i < stacksize; i++)
			delete outstack[stacksize];
	delete[] outstack;

	delete input;

	//delete buttons
	for (int i = 0; i > QT_BUTTONCOUNT; i++)
		delete buttons[i];

	delete[] buttons;
}


//=============================================
//Initialize() handles button set up
//buttons are held in an array and created
//with the AddButtonToPanel(...) function
//=============================================
void xlib_qt_interface::Initialize()
{
	//initialize data members
	buttons = new QPushButton*[QT_BUTTONCOUNT];

	//run button
	buttons[BUTTON_RUN] = AddButtonToPanel("Run", SLOT(execRunButton()), this);

	//exit button
	buttons[BUTTON_EXIT] = AddButtonToPanel("Exit", SLOT(quit()), MainApplication);

	//minimum size
	if (size().width() < menuBarLength*QT_BUTTONCOUNT)
	resize(menuBarLength*QT_BUTTONCOUNT, size().height());
}

//=============================================
//AddButtonToPanel(...) takes arguments that
//detail the button display and actions
//and return a button to be addded to this
//=============================================
QPushButton *xlib_qt_interface::AddButtonToPanel(const char *name, const char *action, QObject *receiver)
{
	QPushButton *Button = new QPushButton(name, this);

	Button->resize(menuBarLength, menuBarHeight);
	Button->move(menuBarLength*numButtons, 0); //anything from the cpanel does not use offset move
	QObject::connect(Button, SIGNAL(clicked()), receiver, action, Qt::AutoConnection);

	numButtons++;

	return Button;
}

//=============================================
//SetBuffer(nsl_buffer) sets the pointer
//to an nsl buffer in order to print
//console output via xlib
//=============================================
void xlib_qt_interface::SetBuffer(nsl_buffer &buffer)
{
	buf = &buffer;
}

//=============================================
//Configure(int, int) sets up the display of
//the window and the interactive functionality
//this MUST be called before the object use
//=============================================
void xlib_qt_interface::Configure(int height, int width)
{
	//theme and dimensions
	resize(width, height + menuBarHeight); //need an offset to place the control panel area
	setStyleSheet("background-color: white");

	stacksize = (ceil(height/10) > QTI_MAX_LINES) ? QTI_MAX_LINES : height/10; //about 10 pixeles "units" per line
	outstack = new QLabel*[stacksize];

	for (unsigned int i = 0; i < stacksize; i++)
	{
		outstack[i] = new QLabel("", this);
		outstack[i]->_MOVE_OFS(5, height - 12*(i + 2)); //move with an offset!
		outstack[i]->resize(QTI_BUFFER_SIZE, 12);
	}

	input->_MOVE_OFS(5, height - 12);
	input->resize(QTI_BUFFER_SIZE, 12);
}

//=============================================
//PushQueue(Qstring) text output into the queue
//=============================================
void xlib_qt_interface::PushQueue(const QString &next)
{
	if (outstack != NULL)
	{
	for (int i = stacksize - 1; i > 0; i--)
		outstack[i]->setText(outstack[i - 1]->text());

	outstack[0]->setText(next);
	}
}

//=============================================
//Output(char*) partitions strings by line
//and pushes them into queue one by one
//to output console
//=============================================
void xlib_qt_interface::Output(const char *str)
{
	if (outstack == NULL || str == 0) //cannot function without output labels
		return;

	char buf[QTI_BUFFER_SIZE];
	strncpy(buf, str, QTI_BUFFER_SIZE);

	int cpos = 0;

	for (int i = 0; str[i + 1] != '\0'; i++)
	{
		if (str[i] == '\n')
		{
			buf[i] = 0;
			PushQueue(&buf[cpos]);
			cpos = i + 1;
		}
	}

	//send the "first" chunk of the string the most recent for the queue
	PushQueue(&buf[cpos]);

	RedrawText();
}

//=============================================
//BackspaceEvent() user has pressed backspace
//this function is cross-platform
//=============================================
void xlib_qt_interface::BackspaceEvent()
{
	if (uindex > 0)
	{
		uindex--;
		keybuf[uindex] = 0;
		QString qs = input->text();
		qs.remove(qs.length() - 1, 1);


		input->clear();
		input->setText(qs);
	}
}

//=============================================
//CharacterEvent(QKeyEvent*) user has pressed
//key, this function is cross-platform
//=============================================
void xlib_qt_interface::CharacterEvent(QKeyEvent* key)
{
	if (uindex >= QTI_BUFFER_SIZE - 1 ) //input string already too long
		return;

	QChar qc = key->text().at(0);
	keybuf[uindex++] = qc.unicode();

	QString qs = input->text();
	qs.append(qc);

	input->setText(qs);

	RedrawText();
}

//=============================================
//ReturnEvent() user has pressed enter
//this function is cross-platform
//=============================================
void xlib_qt_interface::ReturnEvent()
{
	if (buf == NULL) //should never happen, if it does -> programmer's fault
		return;

	int strstart = 0;

	for (unsigned int i = 0; i <= uindex && i < QTI_BUFFER_SIZE; i++)
	{
		if (keybuf[i] == ' ' || keybuf[i] == '\0') //buffer only accepts arguments and commands, no non empty input
		{
			keybuf[i] = 0;
			cout << "sending " << &keybuf[strstart] << endl;
			(*buf) << &keybuf[strstart]; //send substring to buffer
			keybuf[i] = ' ';
			strstart = i + 1;
		}
	}

	bool bExit = false;

	if (input->text() == "exit" || input->text() == "quit") //have to simulate exit on both nsl and qt side
		bExit = true;

	//PushQueue(input->text()); //nsl buffer outputs this on the other side....
	input->setText("");
	RedrawText();

	NSL_INTERPRETER->step(); //execute command/args

	uindex = 0;
	memset(keybuf, 0, QTI_BUFFER_SIZE);

	if (bExit)
		MainApplication->quit();
}

//=============================================
//RedrawText() updates the text of the queue
//=============================================
void xlib_qt_interface::RedrawText()
{
	if (stacksize == 0)
		return;

	input->update();

	return;
	for (unsigned int i = 0; i < stacksize; i++)
	outstack[stacksize]->update();

	update();
}

//=============================================
//Display() refresh object display
//=============================================
void xlib_qt_interface::Display() //probably getparent()->Display() for child widgets?
{
	show();

	if (input != NULL)
		input->show();

	if (outstack != NULL)
	for (unsigned int i = 0; i < stacksize; i++)
	{
		if (outstack[i] != NULL)
			outstack[i]->show();
	}

	//show buttons
	for (int i = 0; i < QT_BUTTONCOUNT; i++)
		buttons[i]->show();
}

//=============================================
//eventFilter(QObject *, QEvent*)
//reads keyboard input and filters junk input
//=============================================
bool xlib_qt_input::eventFilter(QObject* obj, QEvent* event)
{
    if (event->type()==QEvent::KeyPress) //filter out non keyboard input
    {
        QKeyEvent* key = static_cast<QKeyEvent*>(event);

        if ( (key->key() >= Qt::Key_Space) && (key->key() <= Qt::Key_Underscore ) ) //user character input
        {
            //append to current string
        	control->CharacterEvent(key);
        }

        else if (key->key() == Qt::Key_Enter || key->key() == Qt::Key_Return) //then execute user input
        control->ReturnEvent();

        else if (key->key() == Qt::Key_Backspace) //delete front character
        control->BackspaceEvent();

        else return QObject::eventFilter(obj, event); //let super method deal with it

        return true;
    }

    else return QObject::eventFilter(obj, event); //let super method deal with it

    return false;
}

//=============================================
//execRunButton() functionality for Run button
//executes run command thru qtnsl method
//=============================================
bool btemp = false;
void xlib_qt_interface::execRunButton() //tell nsl interpreter to run the model
{
	if (btemp)
	{
	NSL_INTERPRETER->qt_run("run"); //TEMPORARILY COMMENTED OUT FOR TESTING STUFF
	return;
	}

	btemp = true;

	nsl_buffer &buf = NSL_INTERPRETER->get_buffer();
	buf << "set";
	buf << "system.model";
	buf << "MaxSelectorModel";

	NSL_INTERPRETER->step();

	buf << "set";
	buf << "system.simEndTime";
	buf << "200.0";

	NSL_INTERPRETER->step();

	buf << "set";
	buf << "system.diff.delta";
	buf << "0.01";

	NSL_INTERPRETER->step();

	buf << "set";
	buf << "MaxSelectorModel.maxSelector.tu";
	buf << "1.0";

	NSL_INTERPRETER->step();

	buf << "set";
	buf << "MaxSelectorModel.maxSelector.tv";
	buf << "1.0";

	NSL_INTERPRETER->step();

	buf << "set";
	buf << "MaxSelectorModel.maxSelector.k";
	buf << "0.1";

	NSL_INTERPRETER->step();

	buf << "set";
	buf << "MaxSelectorModel.maxSelector.wuu";
	buf << "1.0";

	NSL_INTERPRETER->step();

	buf << "set";
	buf << "MaxSelectorModel.maxSelector.wuv";
	buf << "1.0";

	NSL_INTERPRETER->step();

	buf << "set";
	buf << "MaxSelectorModel.maxSelector.wvu";
	buf << "1.0";

	NSL_INTERPRETER->step();

	buf << "set";
	buf << "MaxSelectorModel.maxSelector.hu";
	buf << "0.1";

	NSL_INTERPRETER->step();

	buf << "set";
	buf << "MaxSelectorModel.maxSelector.hv";
	buf << "0.5";

	NSL_INTERPRETER->step();

	buf << "set";
	buf << "MaxSelectorModel.stimulus.out";
	buf << "0"; buf << "0"; buf << "0"; buf << "0";  buf << "1.0";
	buf << "0"; buf << "0.5"; buf << "0"; buf << "0";  buf << "0";

	NSL_INTERPRETER->step();

	buf << "create";
	buf << "window_interface";

	NSL_INTERPRETER->step();

	buf << "create";
	buf << "display_frame";
	buf << ".maxSelector";

	NSL_INTERPRETER->step();

	buf << "create";
	buf << "display_window";
	buf << ".maxSelector.s";
	buf << "-width";
	buf << "600";
	buf << "-height";
	buf << "200";
	buf << "-wymin";
	buf << "-3.0";
	buf << "-wymax";
	buf << "3.0";
	buf << "-grid";
	buf << "NSL_ON";
	buf << "-layer";
	buf << "MaxSelectorModel.stimulus.out";
	buf << "-graph";
	buf << "area_level_graph";

	NSL_INTERPRETER->step();

	buf << "create";
	buf << "display_window";
	buf << ".maxSelector.up";
	buf << "-width";
	buf << "600";
	buf << "-height";
	buf << "200";
	buf << "-wymin";
	buf << "-3.0";
	buf << "-wymax";
	buf << "3.0";
	buf << "-wystep";
	buf << ".75";
	buf << "-wxstep";
	buf << "10.0";
	buf << "-t1";
	buf << "200.0";
	buf << "-layer";
	buf << "MaxSelectorModel.maxSelector.up";
	buf << "-graph";
	buf << "temporal_graph";
	buf << "-grid";
	buf << "NSL_ON";
	buf << "-x_axis";
	buf << "NSL_ON";

	NSL_INTERPRETER->step();

	buf << "create";
	buf << "display_window";
	buf << ".maxSelector.uf";
	buf << "-width";
	buf << "600";
	buf << "-height";
	buf << "200";
	buf << "-wymin";
	buf << "-3.0";
	buf << "-wymax";
	buf << "3.0";
	buf << "-wystep";
	buf << ".75";
	buf << "-wxstep";
	buf << "10.0";
	buf << "-t1";
	buf << "200.0";
	buf << "-layer";
	buf << "MaxSelectorModel.maxSelector.uf";
	buf << "-graph";
	buf << "temporal_graph";
	buf << "-grid";
	buf << "NSL_ON";
	buf << "-x_axis";
	buf << "NSL_ON";

	NSL_INTERPRETER->step();
}
