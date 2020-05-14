/* SCCS  %W%---%E%--%U% */
/**************************************************************/
/*                                                            */
/*                       nsl_interpreter.C                    */
/*                                                            */
/**************************************************************/

//# include "../../../../MAIN/src/sys_main_src/nsl_all_kernel_include.h"
#include <iostream>
#include <fstream>
#include <ios>
#include <stddef.h>
#include "nsl_interpreter.h"
#include "nsl_nsl_file.h"
#include "nsl_shell.h"
#include "nsl_system.h"
#include "nsl_base_list.h"
#include "nsl_num.h"

extern void cmd_error(const char *);

using namespace std;

#include "nsl_interpreter.h"
#include "nsl_base.h"
#include "nsl_file.h"


extern int NSLoutput(const char*);
extern void cmd_out(const char *, int);

extern int NSLoutput(const char*);

nsl_interpreter::nsl_interpreter()
{
	init_interpreter();
}
nsl_interpreter::~nsl_interpreter()
{
}
int nsl_interpreter::init_interpreter()
{
	shell_list = new nsl_list;
	in_type = NSL_CIN;

 	out_file = 0;
 	out_disable();

	object_total = 0;
	object_list = new nsl_list;
 
#ifndef __GNUG__
	log0.attach(1); // set cmd output log to standard output
#else
        //((filebuf *)log0.ios::_strbuf)->attach(1); //TODO: _strbuf is not a valid symbol -bn7
#endif 

	m_children_list->append(&cmd_buffer);
	cmd_buffer.set_m_parent(this);

	return 1;
}

int nsl_interpreter::add_object(nsl_base* obj)
{
	object_list->append(obj);

	return ++object_total;
}

nsl_base* nsl_interpreter::get_object(const char* bname)
{
	return object_list->get_by_name(bname);
}
nsl_base* nsl_interpreter::get_object(const int bindex)
{
	return object_list->get_by_index(bindex);
}

void nsl_interpreter::add_shell(nsl_shell* shell)
{
	shell_list->append(shell);
}
int nsl_interpreter::init()
{
 	if ((log_file = new nsl_nsl_file("LOG")) != NULL)
	{
		if (log_file->open_file(NSL_OUTPUT) == -1)
			cmd_error("Unable to open system log file: LOG.nsl");
		else
			log_enable();
	}
	else
	{
		cmd_error("Unable to create system log file");
		log_disable();
	}
	
	if (shell_list != NULL)
	{
		shell_list->wind_up();
		nsl_shell* shell;
           	while (shell = (nsl_shell*)shell_list->next())
			shell->init();
	}

	return 1;
}
int nsl_interpreter::exec(char* str)
{
	int n,fg;

	if ((n = strlen(str)) > 0)
	{
		(*this) << str;
		while ((fg = step()) == 3); // reading from file
		NSLoutput("\n"); // add new line
	}

	if (fg == 0) // exit
		exit(0);

	return 1;
}


//qt_run
/*
 * This function uses its string argument to pass to qt_step
 * in order to simulate user input commands from qt controls.
 * The command status is returned as though it were stream
 * input.
 */
//===========================================================+
int nsl_interpreter::qt_run(char *incmd)
{
	cmd_status = 1;

	if (shell_list != NULL)
	    cmd_status = qt_step(incmd);
	else
		cmd_error("NSL interpreter: NULL shell list");

	return cmd_status;
}

//qt_step
/*
 * This function uses its argument to run appropriate nsl_shell
 * types as the console version would. Instead of getting a
 * string from the buffer using nsl_interpreter, the argument
 * incmd is the command uses to run through the cmd_list
 * and execute. The return value designates the input validity.
 * Using this method will simulate user stream input.
 */
//===========================================================+

int nsl_interpreter::qt_step(char *incmd)
{
	cmd_status = 1;
	int fg = 1,error_fg = 0;
	nsl_string str;

	if (shell_list->get_total() == 0)
	{
		cmd_error("// interpreter: No Shell");
		exit(0);
	}

	//simulate sending user input to interpreter
	fg = 1; // set shell running

	shell_list->wind_up();
	nsl_shell* shell;
	shell_fg = 1; // new read in new shell
	shell_index = 0;
	cmd_mode = 1; // set rewind marker flag

	while (fg == 1 && (shell = (nsl_shell*) shell_list->next()))
	{
		// this should be called only during first nsl>>str of new shell
		if (shell_fg == 1) // running new shell
		{
		   shell_fg = 0;
		   if (cmd_mode == 1 && shell_index == 0) // set rewind marker
			cmd_buffer.reset_rewind_marker();
		}

		fg = 0; // reset next shell
		cmd_status = shell->qt_run(this, incmd);

		if (get_input_type() == NSL_FIN) // to loop outside method
			cmd_status = 3;

		switch (cmd_status)
		{
		case 0:
			fg = 0; // break
			break;
		case 1:
			fg = 0; // break
		    	break;
		case 2:
			fg = 1; // next shell
		    	break;
		default:
			fg = 0; // break
		    	break;
		}

		shell_index++;
	}
	///////////////////////////////////////////

	if (fg == 1) // unknown command, use temp buffer for output
	{
		char buf[64] = "interpreter::step: Unknown Command: ";
		strcat(buf, incmd);

		if (get_input_type() == 0 || (get_input_type() == 1 && get_str_cnt() > 0))
 	            	cmd_error(buf);

		while (get_str_cnt() > 0) //if this happens then the programmer sent a bad command
		{
			error_fg = 1;
			*this >> str;
		}
		error_fg = 0;
	}

	return cmd_status;
}


int nsl_interpreter::run()
{
	cmd_status = 1;

	if (shell_list != NULL)
	    	while (cmd_status = step());
	else
		cmd_error("NSL interpreter: NULL shell list");

	return cmd_status;
}

int nsl_interpreter::step()
{
	cmd_status = 1;
	int fg = 1,error_fg = 0;
	nsl_string str;

	if (shell_list->get_total() == 0)
	{
		cmd_error("// interpreter: No Shell");
		exit(0);
	}
	fg = 1; // set shell running
	if (get_input_type() == NSL_CIN && 
		NSL_SYSTEM->get_xsystem_fg() == NSL_OFF &&
		cmd_buffer.get_macro_str_cnt() == 0)
	{
		cout << "\nnsl> ";
		cout.flush();
	}

	shell_list->wind_up();
	nsl_shell* shell;
	shell_fg = 1; // new read in new shell
	shell_index = 0;
	cmd_mode = 1; // set rewind marker flag
        while (fg == 1 && (shell = (nsl_shell*) shell_list->next()))
	{
	// this should be called only during first nsl>>str of new shell
		if (shell_fg == 1) // running new shell
		{
		   shell_fg = 0;
		   if (cmd_mode == 1 && shell_index == 0) // set rewind marker
			cmd_buffer.reset_rewind_marker();
//		   else if (cmd_mode == 0) // reset rewind marker
//			cmd_buffer.reset_read_marker();
		}
		fg = 0; // reset next shell
		cmd_status = shell->run(this); //this method passes nsl_interpreter itself which uses >> to provide user input from cmd_buffer
		if (get_input_type() == NSL_FIN) // to loop outside method
			cmd_status = 3;
		switch (cmd_status)
		{
		case 0: 
			fg = 0; // break
			break;
		case 1: 
			fg = 0; // break
		    	break;
		case 2: 
			fg = 1; // next shell
//			shell_fg = 1;  // new read in new shell
//			cmd_buffer.reset_read_marker();
		    	break;
		default: 
			fg = 0; // break
		    	break;
		}
		shell_index++;
	}
	if (fg == 1) // unknown command, use temp buffer for output
	{   
		if (get_input_type() == 0 ||
				(get_input_type() == 1 && get_str_cnt() > 0))
 	            	cmd_error("interpreter::step: Unknown Command");
		while (get_str_cnt() > 0)
		{
			error_fg = 1;
			*this >> str;
/*		    	if (get_input_type() == 0
				&& str[0] != '\0' && str[0] != '\n' 
				&& str[0] != ' ' && str[0] != '\t') 
			{
 				cerr << " " << str;
			}
*/		}
/*		if (error_fg == 1 && get_input_type() == 0)
		{
		    	cerr << endl;
		    	cerr.flush();
		}
*/		error_fg = 0;
	}

	return cmd_status;
}
int nsl_interpreter::init_input()
{
	int itype = get_input_type();

 	// read on need basis
	if (get_str_cnt() == 0)
	{
	    if (itype == NSL_CIN) // cin
		cmd_buffer << cin;
	    else if (itype == NSL_FIN) // file
		in_file->write(cmd_buffer);
 	    else
		cmd_out("Unknown input stream type: ",itype);
	}

	return 1;
}
int nsl_interpreter::end_input()
{
	if (get_input_type() == NSL_FIN && get_eof_fg() == -1)
	{
		pop_input_file();
		set_eof_fg(0);
	}

	return 1;
}
int nsl_interpreter::putback(const char* str,int cnt)
{
//	has to be called even if (cnt == 0)
	int total = cmd_buffer.get_macro_str_cnt();
	cmd_buffer.set_macro_str_cnt(total+cnt);
	cmd_buffer.putback(str);

	return 1;
}

// input file stack

int nsl_interpreter::push_input_file(nsl_file* file)
{
	if (file != NULL)
	{
		if (in_file != NULL)
			in_file_stack.push(in_file);
		set_input_file(file);
	}
	else
		cmd_error("Empty input file stack");
 
	return 1;
}
nsl_file* nsl_interpreter::pop_input_file()
{
	nsl_file* file;

	if ((file = get_input_file()) != NULL)
		file->close_file();

	file = (nsl_file*) in_file_stack.pop();
	if (file != NULL)
		set_input_file(file);
	else
	{
		
		set_input_file(file); // NULL
		set_input_type(NSL_CIN);
//		cmd_error("Empty input file stack");
	}

	return file;
}

// out file stack

int nsl_interpreter::push_output_file(nsl_file* file)
{
	if (file != NULL)
	{
		out_file_stack.push(out_file);
		set_output_file(file);
	}
	else
		cmd_error("Empty output file stack");
 
	return 1;
}
nsl_file* nsl_interpreter::pop_output_file()
{
	nsl_file* file;

	if ((file = get_output_file()) != NULL)
		file->close_file();

	while (out_file_stack.get_total() > 0 &&
		(file = (nsl_file*) out_file_stack.pop()) == NULL);

	if (file != NULL)
		set_output_file(file);
	else
	{
		set_output_file(file); // NULL
//		cmd_error("Empty input file stack");
	}

	return file;
}

// log file stack

int nsl_interpreter::push_log_file(nsl_file* file)
{
	if (file != NULL)
	{
		if (log_file != NULL)
			log_file_stack.push(log_file);
		set_log_file(file);
	}
	else
		cmd_error("Empty log file stack");

	return 1;
}
nsl_file* nsl_interpreter::pop_log_file()
{
	nsl_file* file;

	if ((file = get_log_file()) != NULL)
		file->close_file();

	file = (nsl_file*) log_file_stack.pop();
	if (file != NULL)
		set_log_file(file);
	else
	{
		set_log_file(file); // NULL
//		set_log_type(NSL_COUT);
//		cmd_error("Empty log file stack");
	}

	return file;
}

// print

int nsl_interpreter::print_interpreter_status(ostream& out) const
{
	print_base_status(out);
   	if (get_output_able_fg() == NSL_ON)
	   out << "set interpreter out_file\tON\n";
	else // if (get_output_able_fg() == 0)
	   out << "set intepreter out_file\tOFF\n";
 	out.flush();

	return 1;
}
int nsl_interpreter::print_status(ostream& out)  const // virtual
{
	print_interpreter_status(out);
	return 1;
}
int nsl_interpreter::print_interpreter(ostream& out) const
{
	print_base(out);
	return 1;
}
int nsl_interpreter::print(ostream& out) const // virtual
{
	print_interpreter(out);
	return 1;
}



//from stream library////////////////////////-bn7

//template<class NslNumType, int NslTypeId>
nsl_interpreter& operator>>(nsl_interpreter& nsl,nsl_num_0& layer)
{
	nsl.init_input();

	nsl.get_buffer() >> layer;

	nsl.end_input();

	return nsl;
}
//template<class NslNumType, int NslTypeId>
nsl_interpreter& operator<<(nsl_interpreter& nsl,nsl_num_0& layer)
{
	nsl.init_input();

	nsl.get_buffer() << layer;

	nsl.end_input();

	return nsl;
}
//template<class NslNumType, int NslTypeId>
nsl_interpreter& operator>>(nsl_interpreter& nsl,nsl_num_1& layer)
{
	nsl.init_input();

	nsl.get_buffer() >> layer;

	nsl.end_input();

	return nsl;
}

//template<class NslNumType, int NslTypeId>
nsl_interpreter& operator<<(nsl_interpreter& nsl,nsl_num_2& layer)
{
	nsl.init_input();

	nsl.get_buffer() << layer;

	nsl.end_input();

	return nsl;
}
//template<class NslNumType, int NslTypeId>
nsl_interpreter& operator>>(nsl_interpreter& nsl,nsl_num_2& layer)
{
	nsl.init_input();

	nsl.get_buffer() >> layer;

	nsl.end_input();

	return nsl;
}
