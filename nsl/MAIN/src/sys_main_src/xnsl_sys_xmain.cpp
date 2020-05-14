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

#define NULL 0

using namespace std;

xnsl_system* XNSL_SYSTEM;
xnsl_system* xnsl_xpublic::XSYSTEM = 0;

static on_off_enum XNSL_INIT_FG = NSL_OFF;

extern void xnsl_tcltk_init();	
extern void xnsl_graph_init();	
extern void xnsl_widget_init();	
extern void xnsl_main_init();

void XNSL_SYSTEMinit()
{
	/*
	XNSL_SYSTEM = new xnsl_system;

	if (XNSL_SYSTEM != NULL)
		XNSL_SYSTEM->create();

	if (NSL_SYSTEM != NULL)
	{
		NSL_SYSTEM->set_system_interface(XNSL_SYSTEM);
		NSL_SYSTEM->set_xsystem_fg(NSL_ON);
	}
	else
		cmd_out("XNSL_SYSTEMinit: NULL NSL_SYSTEM"); */
}

void XNSLsysinit()
{
// The order is very important
/*	nsl_sys_module* xnsl_sys;
	
	xnsl_sys = new nsl_sys_function("xkernel",xnsl_main_init,1);
	xnsl_sys = new nsl_sys_function("widget",xnsl_widget_init,1);
	xnsl_sys = new nsl_sys_function("graph",xnsl_graph_init,1);
	xnsl_sys = new nsl_sys_function("tcltk",xnsl_tcltk_init,1); */
}
void XNSLinit(int argc,char** argv)
{
/*  	if (XNSL_SYSTEM == NULL)
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
	}*/
}

void XNSLmain(int argc,char** argv)
{
/*	XNSL_INIT_FG = NSL_ON;

 	xnsl_window_interface* WI = XNSL_SYSTEM->get_interface();

	if (WI != NULL)
	{
		WI->create();
		WI->handle_events();
	}
	else
		cmd_error("XNSLmain: CANNOT open manager"); */
}

// integrate following

int XNSLoutput(const char* str,std::ostream& out)
{
	out << str;
	out.flush();

	return 1;
}

int XNSLoutput(const char* str)
{
/* 
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
*/
	cout << str;
	cout.flush();

	return 1;
}
 
