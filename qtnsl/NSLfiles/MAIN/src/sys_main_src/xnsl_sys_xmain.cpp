/* SCCS  @(#)xnsl_sys_xmain.C	1.2---97/02/25--19:25:35 */

/**************************************************************/
/*                                                            */
/*                       xnsl_sys_main.C                      */
/*                                                            */
/**************************************************************/
#include <iostream>
#include "nsl.h"
#include "nsl_sys_module.h"
#include "xnsl_system.h"
#include "xnsl_window_interface.h"
#include "nsl_kernel.h"

using namespace std;

xnsl_system* XNSL_SYSTEM;
xnsl_system* xnsl_xpublic::XSYSTEM = 0;

static on_off_enum XNSL_INIT_FG = NSL_OFF;

//streams should be directed to qt UI for qt version
#ifdef NSL_QT
extern void QtOutput(const char *);
#endif

extern void xnsl_qt_init();
extern void xnsl_graph_init();	
extern void xnsl_widget_init();	
extern void xnsl_main_init();

void XNSL_SYSTEMinit()
{
	XNSL_SYSTEM = new xnsl_system;

	if (XNSL_SYSTEM != NULL)
		XNSL_SYSTEM->create();

	if (NSL_SYSTEM != NULL)
	{
		NSL_SYSTEM->set_system_interface(XNSL_SYSTEM);
		NSL_SYSTEM->set_xsystem_fg(NSL_ON);
	}
	else
		cmd_out("XNSL_SYSTEMinit: NULL NSL_SYSTEM");
}

void XNSLsysinit()
{
// The order is very important
	nsl_sys_function* xnsl_sys;

	xnsl_sys = new nsl_sys_function("xkernel",xnsl_main_init,1);
	xnsl_sys = new nsl_sys_function("widget",xnsl_widget_init,1);
	xnsl_sys = new nsl_sys_function("graph",xnsl_graph_init,1);
	xnsl_sys = new nsl_sys_function("qt",xnsl_qt_init,1);
}
void XNSLinit(int argc,char** argv)
{
  	if (XNSL_SYSTEM == NULL)
		XNSL_SYSTEMinit();

	if (XNSL_SYSTEM == NULL)
	{
		cmd_error("Cannot open XSYSTEM");
		exit(-1);
	}
	else
	{
	 	XNSL_SYSTEM->set_argc_ptr(&argc);
		XNSL_SYSTEM->set_argv_ptr(argv);
	}
}

void XNSLmain(int argc,char** argv)
{
	XNSL_INIT_FG = NSL_ON;

 	xnsl_window_interface* WI = XNSL_SYSTEM->get_interface();

	if (WI != NULL)
	{
		WI->create();
		WI->handle_events();
	}
	else
		cmd_error("XNSLmain: CANNOT open manager");
}

// integrate following

int XNSLoutput(const char* str,ostream& out)
{
#ifdef NSL_QT
	QtOutput(str);
	return 1;
#endif

	out << str;
	out.flush();

	return 1;
}

int XNSLoutput(const char* str)
{
	if (str != NULL)
	{
	   nsl_string tmp;
	   strcpy (tmp,str);

  	   if (XNSL_INIT_FG == NSL_OFF)
		cout << tmp;
	   else
		XNSL_SYSTEM->output(tmp); // str
	}
	else
		cmd_out("XNSLoutput: NULL str");

	return 1;
}


//# ifdef NSL_PC
	//int mode;
	/*
	extern Tcl_Interp* NSL_TCL_INTERP;

	if (NSL_TCL_INTERP!=NULL) {
		// char *temp = new char[strlen(str)];
		// strcpy(temp,str);

		Tcl_Channel chan = Tcl_GetChannel(NSL_TCL_INTERP,"stdout",&mode);
		Tcl_Write(chan,(char*)str,strlen(str));
		Tcl_Eval(NSL_TCL_INTERP,"update idletasks"); */

		//delete temp;
	//}
//# else
/*
	cout << str;
	cout.flush();
*/
//# endif

	/*return 1;
}
 */
