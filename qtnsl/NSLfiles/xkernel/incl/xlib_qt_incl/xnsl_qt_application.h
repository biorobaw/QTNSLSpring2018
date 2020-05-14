#ifndef XNSL_QT_APPLICATION_H
#define XNSL_QT_APPLICATION_H
#include "xnsl_qt_widget.h"
class xnsl_qt_application : public xnsl_qt_widget
{
private:
	int	*_argc;
	char	**_argv;

protected:

public:

	xnsl_qt_application();
    virtual ~xnsl_qt_application();

	virtual xnsl_widget *make_widget();

    virtual xnsl_widget *create_widget(const char* = "", xnsl_widget* = 0,
		int = 0, int = 0,int = 100, int = 100,
		int = 0, int = 0,int = 100, int = 100,
		int = 10, int = 10,const char* = "", const char* = "");

	virtual void set_env(const char * = "",
		int = 0, int = 0, int = 100, int = 100,
		int = 0, int = 0, int = 100, int = 100,int = 10, int = 10,
		const char* = "", const char* = "") { };

      	void  handle_events();

	int output(char*);
};
#endif
