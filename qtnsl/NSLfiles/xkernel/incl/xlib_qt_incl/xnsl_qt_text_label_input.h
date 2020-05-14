#ifndef XNSL_QT_LABEL_H
#define XNSL_QT_LABEL_H
#include "xnsl_qt_panel_item.h"
class xnsl_qt_text_label_input : public xnsl_qt_panel_item
{
private:
protected:
public:
	xnsl_qt_text_label_input  ();
      virtual  ~xnsl_qt_text_label_input ();

      virtual xnsl_widget* make_widget();

      virtual xnsl_widget *create_widget(const char* = "", xnsl_widget* = 0,
		int = 0, int = 0,int = 100, int = 100,
		int = 0, int = 0,int = 100, int = 100,
		int = 10, int = 10,const char* = "", const char* = "");

      virtual void set_env(const char * = "",
		int = 0, int = 0,int = 100, int = 100,
		int = 0, int = 0, int = 100, int = 100,int = 10, int = 10,
		const char* = "", const char* = "") { }; //TODO: def -bn7

      virtual int get_env (char *) { }; //never defined -bn7
 };
#endif
