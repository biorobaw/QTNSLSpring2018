/* SCCS  %W%---%E%--%U% */
/****************************************************************/
/*                                                              */
/*                       xnsl_commands.h                        */
/*                                                              */
/****************************************************************/
#ifndef _XNSL_COMMANDS_H
#define _XNSL_COMMANDS_H
class xnsl_commands 
{
protected:
	xnsl_command_buffer* xbuf;
public:
	xnsl_commands();
	~xnsl_commands();

 	void xnsl_help_enable();
 	void xnsl_help_create();
 	void xnsl_help_disable();
 	void xnsl_help_dump();
 	void xnsl_help_print();
 	void xnsl_help_reset();
 	void xnsl_help_set();
 	void xnsl_help_set_frame();
 	void xnsl_help_set_window();
 	void xnsl_help_set_dump();
 	void xnsl_help_status();
 	void xnsl_help_update();

 	int xnsl_help_command(nsl_interpreter&);
 	int xnsl_enable_command(nsl_interpreter&);
 	int xnsl_disable_command(nsl_interpreter&);
 	int xnsl_status_command(nsl_interpreter&);
 	int xnsl_update_command(nsl_interpreter&);
 	int xnsl_create_command(nsl_interpreter&);
 	int xnsl_set_command(nsl_interpreter&);
 	int xnsl_reset_command(nsl_interpreter&);
 	int xnsl_win_dump_command(nsl_interpreter&);
	int xnsl_print_dump_command(nsl_interpreter&);
};
#endif