/* SCCS  @(#)nsl_kernel_main.C	1.1---95/08/13--20:50:06 */
/**************************************************************/
/*                                                            */
/*                       nsl_kernel_main.C                    */
/*                                                            */
/**************************************************************/

#include "nsl_kernel.h"
#include "nsl.h"

extern void cmd_error(const char *);
//extern void cmd_error(const char *, const char *);

void nsl_kernel_init()
{
// AW98 move to separate testing method
// start template test

/*	nsl_num_0<float> x0;
	nsl_num_1<float> x1(1);
	nsl_num_2<float> x2(1,1);
	nsl_num_3<float> x3(1,1,1);
	nsl_num_3<float> y3(1,1,1);
	nsl_num_3<float> z3(1,1,1);
	nsl_num_4<float> x4(1,1,1,1);
	nsl_num_4<float> y4(1,1,1,1);
	nsl_num_4<float> z4(1,1,1,1);
*/
/*
	float  z;
	nsl_din_num_0 d0 = 5 ;
	nsl_num_0 x0 = d0;
	nsl_num_1 x1(1);
	nsl_num_2 x2(1,1);
	nsl_num_3 x3(1,1,1);
	nsl_num_3 y3(1,1,1);
	nsl_num_3 z3(1,1,1);
	z3 = y3; // + x3;
	z3.get_v();
	x2 = z3.get_matrix(0);
	x2 = z3[0];
	z = z3.elem(0,0,0);
	nsl_num_4 x4(1,1,1,1);
	nsl_num_4 y4(1,1,1,1);
	nsl_num_4 z4(1,1,1,1);
	z4 = y4; // + x4;
	z4.get_v();
	x2 = z4.get_matrix(0,0);
	x3 = z4[0];
	z = z4.elem(0,0,0,0);
*/

// end template test

 	nsl_cmd_buf* CMD_SHELL;
	if ((CMD_SHELL = (nsl_cmd_buf*) 
		NSL.get_shell_list()->get_top()) == NULL)
	{
		cmd_error("kernel_init: NULL CMD_SHELL");
		return;
	}
	const char* tstr = "kernel";
	const char* dstr = "NSL/kernel/doc";
	nsl_cmd_exec* exec;
	exec = new nsl_cmd_exec_assign;
 	CMD_SHELL->add_cmd(exec);
	exec->add_help_file(tstr,dstr);
	exec = new nsl_cmd_exec_cd;
	CMD_SHELL->add_cmd(exec);
	exec->add_help_file(tstr,dstr);
	exec = new nsl_cmd_exec_close;
	CMD_SHELL->add_cmd(exec);
	exec->add_help_file(tstr,dstr);
	exec = new nsl_cmd_exec_cont;
	CMD_SHELL->add_cmd(exec);
	exec->add_help_file(tstr,dstr);
	exec = new nsl_cmd_exec_connect;
	CMD_SHELL->add_cmd(exec);
	exec->add_help_file(tstr,dstr);
	exec = new nsl_cmd_exec_create;
	CMD_SHELL->add_cmd(exec);
	exec->add_help_file(tstr,dstr);
	exec = new nsl_cmd_exec_csh;
	CMD_SHELL->add_cmd(exec);
	exec->add_help_file(tstr,dstr);
	exec = new nsl_cmd_exec_delay;
	CMD_SHELL->add_cmd(exec);
	exec->add_help_file(tstr,dstr);
	exec = new nsl_cmd_exec_disable;
	CMD_SHELL->add_cmd(exec);
	exec->add_help_file(tstr,dstr);
	exec = new nsl_cmd_exec_elem;
	CMD_SHELL->add_cmd(exec);
	exec->add_help_file(tstr,dstr);
	exec = new nsl_cmd_exec_enable;
	CMD_SHELL->add_cmd(exec);
	exec->add_help_file(tstr,dstr);
	exec = new nsl_cmd_exec_exec;
	CMD_SHELL->add_cmd(exec);
	exec->add_help_file(tstr,dstr);
	exec = new nsl_cmd_exec_file_disable;
	CMD_SHELL->add_cmd(exec);
	exec->add_help_file(tstr,dstr);
	exec = new nsl_cmd_exec_file_enable;
	CMD_SHELL->add_cmd(exec);
	exec->add_help_file(tstr,dstr);
	exec = new nsl_cmd_exec_get;
	CMD_SHELL->add_cmd(exec);
	exec->add_help_file(tstr,dstr);
	exec = new nsl_cmd_exec_help;
	CMD_SHELL->add_cmd(exec);
	exec->add_help_file(tstr,dstr);
	exec = new nsl_cmd_exec_init;
	CMD_SHELL->add_cmd(exec);
	exec->add_help_file(tstr,dstr);
	exec = new nsl_cmd_exec_load;
	CMD_SHELL->add_cmd(exec);
	exec->add_help_file(tstr,dstr);
	exec = new nsl_cmd_exec_open;
	CMD_SHELL->add_cmd(exec);
	exec->add_help_file(tstr,dstr);
	exec = new nsl_cmd_exec_print;
	CMD_SHELL->add_cmd(exec);
	exec->add_help_file(tstr,dstr);
	exec = new nsl_cmd_exec_quit;
	CMD_SHELL->add_cmd(exec);
	exec->add_help_file(tstr,dstr);
	exec = new nsl_cmd_exec_reset;
	CMD_SHELL->add_cmd(exec);
	exec->add_help_file(tstr,dstr);
	exec = new nsl_cmd_exec_run;
	CMD_SHELL->add_cmd(exec);
	exec->add_help_file(tstr,dstr);
	exec = new nsl_cmd_exec_set;
	CMD_SHELL->add_cmd(exec);
	exec->add_help_file(tstr,dstr);
	exec = new nsl_cmd_exec_sh;
	CMD_SHELL->add_cmd(exec);
	exec->add_help_file(tstr,dstr);
	exec = new nsl_cmd_exec_status;
	CMD_SHELL->add_cmd(exec);
	exec->add_help_file(tstr,dstr);
	exec = new nsl_cmd_exec_step;
	CMD_SHELL->add_cmd(exec);
	exec->add_help_file(tstr,dstr);
	exec = new nsl_cmd_exec_stop;
	CMD_SHELL->add_cmd(exec);
	exec->add_help_file(tstr,dstr);
	exec = new nsl_cmd_exec_train;
	CMD_SHELL->add_cmd(exec);
	exec->add_help_file(tstr,dstr);
	exec = new nsl_cmd_exec_update;
	CMD_SHELL->add_cmd(exec);
	exec->add_help_file(tstr,dstr);
	exec = new nsl_cmd_exec_write;
	CMD_SHELL->add_cmd(exec);
	exec->add_help_file(tstr,dstr);

// add global macros
	nsl_cmd_macro* cmd_macro;
	cmd_macro = new nsl_cmd_macro("exit","quit");
	CMD_SHELL->add_macro(cmd_macro);
	cmd_macro = new nsl_cmd_macro("!","csh");
	CMD_SHELL->add_macro(cmd_macro);
	cmd_macro = new nsl_cmd_macro("network","model");
	CMD_SHELL->add_macro(cmd_macro);
// add macros to set cmd
	nsl_cmd_exec* cmd_exec = CMD_SHELL->get_cmd("set");
	cmd_macro = new nsl_cmd_macro("data_value","set layer",2); // value
	((nsl_cmd_exec_set*) cmd_exec)->add_macro(cmd_macro);
	cmd_macro = new nsl_cmd_macro("elem_data_value","elem layer",2);
	((nsl_cmd_exec_set*) cmd_exec)->add_macro(cmd_macro);
	cmd_macro = new nsl_cmd_macro("all_data_value","reset layer",2);
	((nsl_cmd_exec_set*) cmd_exec)->add_macro(cmd_macro);
	cmd_macro = new nsl_cmd_macro("network","set model name",3);
	((nsl_cmd_exec_set*) cmd_exec)->add_macro(cmd_macro);
	cmd_macro = new nsl_cmd_macro("delta","set model delta",3);
	((nsl_cmd_exec_set*) cmd_exec)->add_macro(cmd_macro);
	cmd_macro = new nsl_cmd_macro("integration","set diff integration",3);
	((nsl_cmd_exec_set*) cmd_exec)->add_macro(cmd_macro);
	cmd_macro = new nsl_cmd_macro("end_time","set model end_time",3);
	((nsl_cmd_exec_set*) cmd_exec)->add_macro(cmd_macro);
	cmd_macro = new nsl_cmd_macro("current_time","set model current_time",3);
	((nsl_cmd_exec_set*) cmd_exec)->add_macro(cmd_macro);

// init numerical methods (1 copy per numerical class/layer)
// AW98 added diff_euler and diff_interpolation (only need those two!)
	nsl_diff_method* mdiff;
	mdiff = new nsl_diff_interpolation_data;
	mdiff = new nsl_diff_interpolation_vector;
	mdiff = new nsl_diff_interpolation_matrix;
	mdiff = new nsl_diff_interpolation;
	mdiff = new nsl_diff_euler_data;
	mdiff = new nsl_diff_euler_vector;
	mdiff = new nsl_diff_euler_matrix;
	mdiff = new nsl_diff_euler;

	if (NSL_DIFF != NULL)
		NSL_DIFF->set_diff_obj(0); // instead of doing it during NSL_DIFF init
	else
		cmd_error("diff_method: NULL NSL_DIFF");

// AW98: do we need next line?
//	nsl_diff* diff = new nsl_diff("diff",0,2); // 2 - add to SYSTEM diff_model list

	nsl_file* file;
	file = new nsl_nsl_file(1);
 
// check variable args here

	nsl_cmd_type* cmd_type;
	nsl_layer* cmd_set;

// system
	cmd_type = new nsl_cmd_system;
	CMD_SHELL->add_type(cmd_type);

	cmd_set = new nsl_str_data("model","");
 	cmd_type->add_data(cmd_set);

	cmd_set = new nsl_num_data("delta",0.1);
 	cmd_type->add_data(cmd_set);

	cmd_set = new nsl_num_data("current_time");
 	cmd_type->add_data(cmd_set);

	cmd_set = new nsl_num_data("end_time",1.0);
 	cmd_type->add_data(cmd_set);

	cmd_set = new nsl_on_off_data("print_time",NSL_ON);
 	cmd_type->add_data(cmd_set);

	cmd_set = new nsl_on_off_data("verbose",NSL_ON);
 	cmd_type->add_data(cmd_set);

	cmd_set = new nsl_on_off_data("log",NSL_ON);
	cmd_type->add_data(cmd_set);

	cmd_set = new nsl_on_off_data("output",NSL_ON);
	cmd_type->add_data(cmd_set);

// model
	cmd_type = new nsl_cmd_model;
	CMD_SHELL->add_type_m_parent(cmd_type,"system");

	cmd_set = new nsl_str_data("name","");
 	cmd_type->add_data(cmd_set);

	cmd_set = new nsl_int_data("index");
 	cmd_type->add_data(cmd_set);

	cmd_set = new nsl_str_data("integration","EULER");
 	cmd_type->add_data(cmd_set);

	cmd_set = new nsl_num_data("delta",0.1);
 	cmd_type->add_data(cmd_set);

	cmd_set = new nsl_num_data("current_time");
 	cmd_type->add_data(cmd_set);

	cmd_set = new nsl_num_data("end_time",1.0);
 	cmd_type->add_data(cmd_set);

// layer
	cmd_type = new nsl_cmd_layer;
	CMD_SHELL->add_type_m_parent(cmd_type,"model");

	cmd_set = new nsl_str_data("name","");
 	cmd_type->add_data(cmd_set);

	cmd_set = new nsl_int_data("index");
 	cmd_type->add_data(cmd_set);

	cmd_set = new nsl_int_data("elem_i");
 	cmd_type->add_data(cmd_set);
	cmd_set = new nsl_int_data("elem_j");
 	cmd_type->add_data(cmd_set);

// data layer
	cmd_type = new nsl_cmd_data_layer;
	CMD_SHELL->add_type_i_children(cmd_type,"layer");
	CMD_SHELL->add_type_m_parent(cmd_type,"model");

// int data
	cmd_type = new nsl_cmd_int_data;
	CMD_SHELL->add_type_i_children(cmd_type,"data_layer");
	CMD_SHELL->add_type_m_parent(cmd_type,"model");
// num data
	cmd_type = new nsl_cmd_num_data;
	CMD_SHELL->add_type_i_children(cmd_type,"data_layer");
	CMD_SHELL->add_type_m_parent(cmd_type,"model");
// str data
	cmd_type = new nsl_cmd_str_data;
	CMD_SHELL->add_type_i_children(cmd_type,"data_layer");
	CMD_SHELL->add_type_m_parent(cmd_type,"model");
// ptr data
	cmd_type = new nsl_cmd_ptr_data;
	CMD_SHELL->add_type_i_children(cmd_type,"data_layer");
	CMD_SHELL->add_type_m_parent(cmd_type,"model");

// vector layer
	cmd_type = new nsl_cmd_vector_layer;
	CMD_SHELL->add_type_i_children(cmd_type,"layer");
	CMD_SHELL->add_type_m_parent(cmd_type,"model");
   
// int vector
	cmd_type = new nsl_cmd_int_vector;
	CMD_SHELL->add_type_i_children(cmd_type,"vector_layer");
 	CMD_SHELL->add_type_m_parent(cmd_type,"model");
// num vector
	cmd_type = new nsl_cmd_num_vector;
	CMD_SHELL->add_type_i_children(cmd_type,"vector_layer");
	CMD_SHELL->add_type_m_parent(cmd_type,"model");
// str vector
	cmd_type = new nsl_cmd_str_vector;
	CMD_SHELL->add_type_i_children(cmd_type,"vector_layer");
	CMD_SHELL->add_type_m_parent(cmd_type,"model");
// ptr vector
	cmd_type = new nsl_cmd_ptr_vector;
	CMD_SHELL->add_type_i_children(cmd_type,"vector_layer");
	CMD_SHELL->add_type_m_parent(cmd_type,"model");

// matrix layer
	cmd_type = new nsl_cmd_matrix_layer;
	CMD_SHELL->add_type_i_children(cmd_type,"layer");
	CMD_SHELL->add_type_m_parent(cmd_type,"model");

// int matrix
	cmd_type = new nsl_cmd_int_matrix;
	CMD_SHELL->add_type_i_children(cmd_type,"matrix_layer");
	CMD_SHELL->add_type_m_parent(cmd_type,"model");
// num matrix
	cmd_type = new nsl_cmd_num_matrix;
	CMD_SHELL->add_type_i_children(cmd_type,"matrix_layer");
	CMD_SHELL->add_type_m_parent(cmd_type,"model");
// str matrix
	cmd_type = new nsl_cmd_str_matrix;
	CMD_SHELL->add_type_i_children(cmd_type,"matrix_layer");
	CMD_SHELL->add_type_m_parent(cmd_type,"model");
// ptr matrix
	cmd_type = new nsl_cmd_ptr_matrix;
	CMD_SHELL->add_type_i_children(cmd_type,"matrix_layer");
	CMD_SHELL->add_type_m_parent(cmd_type,"model");

// function
	cmd_type = new nsl_cmd_function;
 	CMD_SHELL->add_type_m_parent(cmd_type,"model");

	cmd_set = new nsl_str_data("name","");
 	cmd_type->add_data(cmd_set);

	cmd_set = new nsl_int_data("index");
 	cmd_type->add_data(cmd_set);

// diff_manager
	cmd_type = new nsl_cmd_diff_manager;
 	CMD_SHELL->add_type_m_parent(cmd_type,"model");

// diff
	cmd_type = new nsl_cmd_diff;
 	CMD_SHELL->add_type_m_parent(cmd_type,"diff_manager");

	cmd_set = new nsl_str_data("integration","EULER");
 	cmd_type->add_data(cmd_set);

	cmd_set = new nsl_num_data("delta",0.1);
 	cmd_type->add_data(cmd_set);

// file_manager
	cmd_type = new nsl_cmd_file_manager;
 	CMD_SHELL->add_type_m_parent(cmd_type,"system");

// file
	cmd_type = new nsl_cmd_file;
 	CMD_SHELL->add_type_m_parent(cmd_type,"file_manager");

 	cmd_set = new nsl_str_data("name","");
 	cmd_type->add_data(cmd_set);

	cmd_set = new nsl_int_data("index");
 	cmd_type->add_data(cmd_set);

	cmd_set = new nsl_str_data("dname",".");
 	cmd_type->add_data(cmd_set);

	cmd_set = new nsl_str_data("ftype","nsl_file");
 	cmd_type->add_data(cmd_set);

 	cmd_set = new nsl_on_off_data("auto",NSL_ON);
	cmd_type->add_data(cmd_set);

	cmd_set = new nsl_file_data("io_type",(file_enum) NSL_OUTPUT);
	cmd_type->add_data(cmd_set);

	cmd_set = new nsl_dump_data("dump_type",NSL_LP);
	cmd_type->add_data(cmd_set);
}
