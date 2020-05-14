/* SCCS  %W%---%E%--%U% */
/**************************************************************/
/*                                                            */
/*                   xnsl_command_buffer.h                     */
/*                                                            */
/* by Alfredo Weitzenfeld 				      */
/*                                                            */
/**************************************************************/
#ifndef _XNSL_COMMAND_BUFFER_H
#define _XNSL_COMMAND_BUFFER_H
#include "nsl_cmd_buf.h"
#include "xnsl_root.h"
class xnsl_command_buffer : public nsl_cmd_buf, public xnsl_root
{
// file
	int file_type; // = 2;
	int file_index; // = 0;
	nsl_string file_type_name;
	nsl_string file_name;
 	int file_auto_name_fg; // = ON;

// window dumps
	int dump_type; // 1;
  	nsl_string dump_file; // file name
   	nsl_string dump_type_name; // printer
   	int dump_ras_index; // 0;
 	int dump_ps_index; // 0;
 	int dump_auto_name_fg; // ON;

public:
		xnsl_command_buffer(int (*)(nsl_cmd_buf&));
		xnsl_command_buffer();
		~xnsl_command_buffer();
// update
	void	update_layer_buffer(char*);
	void 	update_graph_buffer(char*);
};
#endif