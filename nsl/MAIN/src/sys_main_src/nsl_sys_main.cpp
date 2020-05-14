/**************************************************************/
/*                                                            */
/*                       nsl_sys_main.C                       */
/*                                                            */
/**************************************************************/
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

#include "nsl_kernel.h"
#include "nsl_cmd_buf.h"
#include "nsl_diff.h"
#include "nsl_sys_function.h"
#include "../../../MaxSelector/maxSelector.h"

//extern void cmd_out(const char *, int);
extern void cmd_out(const char *, const char *);
/*
 * temporarily declare headers to figure out compilation errors -bn7
 *
 */

// global data definition

nsl_diff* NSL_DIFF;
nsl_interpreter* NSL_INTERPRETER;
nsl_system* NSL_SYSTEM;
nsl_model* NSL_MAIN_MODEL;
nsl_model* NSL_APPLICATION_MODEL;
fstream* NSL_FILE;

nsl_interpreter* nsl_base::INTERPRETER = 0;
nsl_system* nsl_base::SYSTEM = 0;
nsl_public* nsl_base::SYS_INTERFACE = 0;
nsl_public* nsl_base::ASL_SYS = 0;

int BREAKFG = 0;
int INTERRUPTFG = 0;	// set to 1 if BREAKFG has been serviced 
			// left to the user for reset
int TRACE_FG = 1;

// nsl_system nslSystem; // system
#define ASL_FG //REQUIRED WITH ASL -bn7

# ifdef NSL_WIN	
extern int XNSLoutput(const char*);
extern void XNSLinit(int,char**);
extern void XNSLmain(int,char**);
extern void XNSLsysinit();
# endif

# ifdef NSL_TCL 
# include "tcl.h"
//extern "C" int Tcl_Main(...);
//extern "C" int Tcl_AppInit(...);
#endif

# ifdef NSL_TK
# include "tk.h"
//extern "C" int Tk_Main(...);
//extern "C" int Tcl_AppInit(...);
# endif

# if (NSL_TCL == 1 || NSL_TK == 1)
extern Tcl_Interp* NSL_TCL_INTERP;
#endif

# ifdef ASL_FG
extern void ASLinit(int, char **);
# endif

#ifndef NSL_PC
extern "C" int NSLinit_interrupt_handler();
#endif

extern int NSLoutput(const char *);

extern void nsl_kernel_init();
extern void NSLetc();
//extern void nslMainModel(nsl_model*);

// end addition

void NSLinit(int argc = 0,char** argv = NULL)
{
	NSLoutput("NSL Version 3.0\n");
	NSLoutput("(C) Copyright 1989-1998 Brain Simulation Laboratory All Rights Reserved\n");
	NSLoutput("Center for Neural Engineering, University of Southern California\n");

	if (NSL_SYSTEM == NULL)
	{
		NSL_SYSTEM = new nsl_system;
 	}

	if (NSL_SYSTEM == NULL)
	{
		NSLoutput("Cannot create SYSTEM");
		exit(-1);
	}

	cmd_out("Initializing SYSTEM...");

	if (NSL_INTERPRETER == NULL)
	{
		NSL_INTERPRETER = new nsl_interpreter;
 	}

	if (NSL_INTERPRETER == NULL)
	{
		NSLoutput("Cannot create NSL_INTERPRETER");
		exit(-1);
	}

	NSLoutput("Initializing NSL_INTERPRETER...");

	if (NSL_DIFF == NULL)
	{
		NSL_DIFF = new nsl_diff("diff",NSL_SYSTEM->get_diff_manager(),0);
		NSL_SYSTEM->add_data(NSL_DIFF);
 	}

	cmd_out("Initializing NSL_DIFF...");

	/*	char* env = getenv("NSL_DIR");
	if (env != NULL)
		NSL_SYSTEM->set_nsl_dir(env);
	else
	{
		cmd_error("NSL_DIR not set\nUse `setenv NSL_DIR *dir*'");
		NSL_SYSTEM->set_nsl_dir(".");
	}
*/
# ifndef NSL_WIN	
	NSLoutput("Initializing NSL Simulation System...");
# else
	NSLoutput("Initializing XNSL Simulation System...");
# endif

// The order is VERY important
	nsl_sys_function* sys_mod;
	sys_mod = new nsl_sys_function("kernel",nsl_kernel_init,1);
# ifdef NSL_INPUT_FG
	sys_mod = new nsl_sys_function("input",nsl_input_init,1);
# endif
# ifdef NEURON_FG
	sys_mod = new nsl_sys_function("neuron",nsl_neuron_init,1);
# endif
	NSLetc();	// call any additional library instantiations
	
# ifdef NSL_WIN	
	XNSLsysinit();  // call graphics library instantiations
# endif
	
// AW commented out 3/96
//	NSL_SYSTEM->set_argc_ptr(&argc);
//	NSL_SYSTEM->set_argv_ptr(argv);

// init XNSL before initiating all procedures
# ifdef NSL_WIN	
	XNSLinit(argc,argv);
# endif

# ifndef __GNUG__
//	cin.sync_with_stdio(); // sync stdio with C++ streams
# endif

#ifndef NSL_PC
	NSLinit_interrupt_handler();
# endif

// initiate
        NSL.add_shell(new nsl_cmd_buf); // creating new SHELL

	NSL.init(); // init all shells and LOG

	NSL_SYSTEM->init_proc(); // initiating SHELL (nsl_sys_function)

/*	if (NSL_DIFF == NULL)
	{
		NSL_DIFF = new nsl_diff;
 	}

	if (NSL_DIFF == NULL)
	{
		cmd_error("Cannot create NSL_DIFF");
		exit(-1);
	}
*/
	
// execute nsl_system initializations
	NSL_SYSTEM->init(); 	// initiating MODELS (nsl_sys_function)
	
# ifdef ASL_FG
	ASLinit(argc,argv);
# endif

	if (argc == 1) //??? getApplicationModel is not a defined or declared method -bn7
	{
	   	//NSL_APPLICATION_MODEL = (nsl_model*) NSL_SYSTEM->getApplicationModel(NULL);
		NSL_APPLICATION_MODEL = new MaxSelector("MaxSelector", NULL, 10);
	   	if  (NSL_APPLICATION_MODEL != NULL)
		{
			cmd_out("Instantiating default model");
			//NSL_MAIN_MODEL = NSL_APPLICATION_MODEL->makeInstance();
		}
		else
			cmd_out("Null Application, NSLMain");
	}	
	/*
	else if (argc > 1)
	{ 
	   	//NSL_APPLICATION_MODEL = (nsl_model*) NSL_SYSTEM->getApplicationModel(argv[1]);
	   	if (NSL_APPLICATION_MODEL != NULL)
		{

	   		cmd_out("instantiating", argv[1]); //was cmd_out("instantiating", argv[1]), -bn7
			argc = 1;
			argv[1] = 0;
			NSL_MAIN_MODEL = NSL_APPLICATION_MODEL->get_model();
			//NSL_MAIN_MODEL = NSL_APPLICATION_MODEL->makeInstance(); //no such method defined 'makeInstance' -bn7
		}
		else
			cmd_out("Null Application, NSLMain");
	}
*/
}

extern int ASLrun(int time_step);

void NSLmain(int argc,char** argv)
{
#ifdef NSL_TCL
    Tcl_Main(argc,argv,Tcl_AppInit);
#elif NSL_TK
    Tk_MainEx(argc,argv,Tcl_AppInit,NSL_TCL_INTERP);
#elif NSL_WIN	
	XNSLmain(argc,argv);
# else
	NSL.run(); // used if no windows
	/*
	ASLrun(0);
	ASLrun(1);
	ASLrun(-1);*/
# endif

	NSLoutput("Exiting NSL Simulation System");
}

// integrate similar ones

extern int XNSLoutput(const char* str,std::ostream&);

int NSLoutput(const char* str,std::ostream& out)
{
# ifdef NSL_WIN
	XNSLoutput(str,out);
# else
	out << str;
	out.flush();
# endif

	return 1;
}

int NSLoutput(const int str1,std::ostream& out)
{
	nsl_string str;

	sprintf(str,"%d",str1);
	NSLoutput(str,out);

	return 1;
}

int NSLoutput(const float str1,std::ostream& out)
{
	nsl_string str;

	sprintf(str,"%f",str1);
	NSLoutput(str,out);

	return 1;
}

int NSLoutput(const double str1,std::ostream& out)
{
	nsl_string str;

	sprintf(str,"%f",str1);
	NSLoutput(str,out);

	return 1;
}

int NSLoutput(const char* str)
{
using namespace std; //std scope [fixed]
# ifdef NSL_WIN
	XNSLoutput(str);
# else
	cout << str;
	cout.flush();
# endif

	return 1;
}

int NSLoutput(const int str1)
{
	nsl_string str;

	sprintf(str,"%d",str1);
	NSLoutput(str);

	return 1;
}

int NSLoutput(const float str1)
{
	nsl_string str;

	sprintf(str,"%f",str1);
	NSLoutput(str);

	return 1;
}

int NSLoutput(const double str1)
{
	nsl_string str;

	sprintf(str,"%f",str1);
	NSLoutput(str);

	return 1;
}

int NSLoutput(const char* str1,const char* str2)
{
	NSLoutput(str1);
	NSLoutput(str2);

	return 1;
}


int NSLoutput(const char* str1,const int str2)
{
	NSLoutput(str1);
	NSLoutput(str2);

	return 1;
}

int NSLoutput(const char* str1,const float str2)
{
	NSLoutput(str1);
	NSLoutput(str2);

	return 1;
}

int NSLoutput(const char* str1,const double str2)
{
	NSLoutput(str1);
	NSLoutput(str2);

	return 1;
}


int nslStop()     /* stop processing */
{
        BREAKFG = 1;
        return 1;
}
