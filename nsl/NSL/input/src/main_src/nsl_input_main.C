/* SCCS  @(#)nsl_input_main.C	1.1---95/08/13--20:56:28 */
/**************************************************************/
/*                                                            */
/*                       nsl_input_main.C                     */
/*                                                            */
/**************************************************************/

//# include "../../../../MAIN/src/sys_main_src/nsl_all_kernel_include.h"
//# include "../../incl/nsl_all_input_include.h"

#include "nsl_input.h"
#include "nsl_cmd_macro.h"

extern void cmd_error(const char *);
 
void nsl_input_init()
{
 	nsl_cmd_buf* CMD_SHELL;	//no such method: get_shell_list() -bn7
/*	if ((CMD_SHELL = (nsl_cmd_buf*)
		NSL.get_shell_list()->get_top()) == NULL)
	{
		cmd_error("kernel_init: NULL CMD_SHELL");
		return;
	}
*/
// add macros to set cmd
	nsl_cmd_macro* cmd_macro;
	cmd_macro = new nsl_cmd_macro("time_stim","time_interval");
	CMD_SHELL->add_macro(cmd_macro);
	cmd_macro = new nsl_cmd_macro("stim_list","input_layer");
	CMD_SHELL->add_macro(cmd_macro);
	cmd_macro = new nsl_cmd_macro("input_stim","stim");
	CMD_SHELL->add_macro(cmd_macro);

	const char* tstr = "input";
	const char* dstr = "NSL/input/doc";
	nsl_cmd_exec* cmd_exec;
	if ((cmd_exec = CMD_SHELL->get_cmd("create")) != NULL)
		cmd_exec->add_help_file(tstr,dstr);
	if ((cmd_exec = CMD_SHELL->get_cmd("enable")) != NULL)
		cmd_exec->add_help_file(tstr,dstr);
	if ((cmd_exec = CMD_SHELL->get_cmd("disable")) != NULL)
		cmd_exec->add_help_file(tstr,dstr);
	if ((cmd_exec = CMD_SHELL->get_cmd("help")) != NULL) 
		cmd_exec->add_help_file(tstr,dstr);
	if ((cmd_exec = CMD_SHELL->get_cmd("print")) != NULL)
		cmd_exec->add_help_file(tstr,dstr);
	if ((cmd_exec = CMD_SHELL->get_cmd("reset")) != NULL)
		cmd_exec->add_help_file(tstr,dstr);
	if ((cmd_exec = CMD_SHELL->get_cmd("set")) != NULL)
	{
		cmd_exec->add_help_file(tstr,dstr);
		cmd_macro = new nsl_cmd_macro("input_xz","set input_layer xz");
		((nsl_cmd_exec_set*) cmd_exec)->add_macro(cmd_macro);
		cmd_macro = new nsl_cmd_macro("input_yz","set input_layer yz");
		((nsl_cmd_exec_set*) cmd_exec)->add_macro(cmd_macro);
		cmd_macro = new nsl_cmd_macro("input_dx","set input_layer dx");
		((nsl_cmd_exec_set*) cmd_exec)->add_macro(cmd_macro);
		cmd_macro = new nsl_cmd_macro("input_dy","set input_layer dy");
		((nsl_cmd_exec_set*) cmd_exec)->add_macro(cmd_macro);
		cmd_macro = new nsl_cmd_macro("stim_val","set stim val");
		((nsl_cmd_exec_set*) cmd_exec)->add_macro(cmd_macro);
		cmd_macro = new nsl_cmd_macro("stim_vx","set stim vx");
		((nsl_cmd_exec_set*) cmd_exec)->add_macro(cmd_macro);
		cmd_macro = new nsl_cmd_macro("stim_vy","set stim vy");
		((nsl_cmd_exec_set*) cmd_exec)->add_macro(cmd_macro);
		cmd_macro = new nsl_cmd_macro("stim_x0","set stim x0");
		((nsl_cmd_exec_set*) cmd_exec)->add_macro(cmd_macro);
		cmd_macro = new nsl_cmd_macro("stim_y0","set stim y0");
		((nsl_cmd_exec_set*) cmd_exec)->add_macro(cmd_macro);
		cmd_macro = new nsl_cmd_macro("stim_xc","set stim xc");
		((nsl_cmd_exec_set*) cmd_exec)->add_macro(cmd_macro);
		cmd_macro = new nsl_cmd_macro("stim_yc","set stim yc");
		((nsl_cmd_exec_set*) cmd_exec)->add_macro(cmd_macro);
		cmd_macro = new nsl_cmd_macro("stim_dx","set stim dx");
		((nsl_cmd_exec_set*) cmd_exec)->add_macro(cmd_macro);
		cmd_macro = new nsl_cmd_macro("stim_dy","set stim dy");
		((nsl_cmd_exec_set*) cmd_exec)->add_macro(cmd_macro);
		cmd_macro = new nsl_cmd_macro("stim_spec","set stim stim_spec");
		((nsl_cmd_exec_set*) cmd_exec)->add_macro(cmd_macro);
		cmd_macro = new nsl_cmd_macro("stim_type","set stim stim_type");
		((nsl_cmd_exec_set*) cmd_exec)->add_macro(cmd_macro);
		cmd_macro = new nsl_cmd_macro("stim_t0","set time_interval t0");
		((nsl_cmd_exec_set*) cmd_exec)->add_macro(cmd_macro);
		cmd_macro = new nsl_cmd_macro("stim_t1","set time_interval t1");
		((nsl_cmd_exec_set*) cmd_exec)->add_macro(cmd_macro);
	}
	else
		cmd_error("input_init: NULL SHELL CMD");
	if ((cmd_exec = CMD_SHELL->get_cmd("status")) != NULL)
		cmd_exec->add_help_file(tstr,dstr);
	if ((cmd_exec = CMD_SHELL->get_cmd("update")) != NULL)
		cmd_exec->add_help_file(tstr,dstr);
	if ((cmd_exec = CMD_SHELL->get_cmd("write")) != NULL)
		cmd_exec->add_help_file(tstr,dstr);

// vars
	nsl_cmd_type* cmd_type;
	nsl_cmd_type* cmd_set_type;
	nsl_layer* cmd_set;
	
// input layer
	cmd_type = new nsl_cmd_input_layer; 
	CMD_SHELL->add_type_i_children(cmd_type,"layer");
	CMD_SHELL->add_type_m_parent(cmd_type,"model");

	cmd_set = new nsl_int_data("xz",0,0);
 	cmd_type->add_data(cmd_set);
 	cmd_set = new nsl_int_data("yz",0,0);
 	cmd_type->add_data(cmd_set);
	cmd_set = new nsl_num_data("dx",1.0,0);	//changed nsl_num_data to nsl_num_0
 	cmd_type->add_data(cmd_set);
	cmd_set = new nsl_num_data("dy",1.0,0);
 	cmd_type->add_data(cmd_set);
	cmd_set = new nsl_on_off_data("overlap",NSL_ON);
 	cmd_type->add_data(cmd_set);

	cmd_type = new nsl_cmd_input_data;
	CMD_SHELL->add_type_i_children(cmd_type,"input_layer");
	CMD_SHELL->add_type_i_children(cmd_type,"num_data");
	CMD_SHELL->add_type_m_parent(cmd_type,"model");

	cmd_type = new nsl_cmd_input_vector;
	CMD_SHELL->add_type_i_children(cmd_type,"input_layer");
	CMD_SHELL->add_type_i_children(cmd_type,"num_vector");
	CMD_SHELL->add_type_m_parent(cmd_type,"model");

 	cmd_type = new nsl_cmd_input_matrix;
	CMD_SHELL->add_type_i_children(cmd_type,"input_layer");
	CMD_SHELL->add_type_i_children(cmd_type,"num_matrix");
	CMD_SHELL->add_type_m_parent(cmd_type,"model");

// input stim
	cmd_type = new nsl_cmd_stim;
	CMD_SHELL->add_type_m_parent(cmd_type,"input_layer");

	cmd_set = new nsl_str_data("name");
 	cmd_type->add_data(cmd_set);

	cmd_set = new nsl_int_data("index",0,0);
 	cmd_type->add_data(cmd_set);

	cmd_set = new nsl_num_data("val",1.0,0);
 	cmd_type->add_data(cmd_set);
	cmd_set = new nsl_int_data("step",1,0);
 	cmd_type->add_data(cmd_set);
	cmd_set = new nsl_on_off_data("interval",NSL_ON);
 	cmd_type->add_data(cmd_set);
	cmd_set = new nsl_num_data("vx",0.0,0);
 	cmd_type->add_data(cmd_set);
 	cmd_set = new nsl_num_data("vy",0.0,0);
 	cmd_type->add_data(cmd_set);
	cmd_set = new nsl_num_data("x0",0.0,0);
 	cmd_type->add_data(cmd_set);
 	cmd_set = new nsl_num_data("y0",0.0,0);
 	cmd_type->add_data(cmd_set);
	cmd_set = new nsl_num_data("xc",0.0,0);
 	cmd_type->add_data(cmd_set);
 	cmd_set = new nsl_num_data("yc",0.0,0);
 	cmd_type->add_data(cmd_set);
	cmd_set = new nsl_num_data("dx",1.0,0);
 	cmd_type->add_data(cmd_set);
	cmd_set = new nsl_num_data("dy",1.0,0);
 	cmd_type->add_data(cmd_set);

	cmd_set_type = new nsl_cmd_stim_type("stim_type",NSL_BLOCK);
 	cmd_type->add_data(cmd_set_type);
	cmd_set_type = new nsl_cmd_spec_type("spec_type",NSL_CORNER);
 	cmd_type->add_data(cmd_set_type);
 
 	cmd_type = new nsl_cmd_block_stim;
	CMD_SHELL->add_type_i_children(cmd_type,"stim");
	CMD_SHELL->add_type_m_parent(cmd_type,"input_layer");

 	cmd_type = new nsl_cmd_icon_stim;
	CMD_SHELL->add_type_i_children(cmd_type,"stim");
	CMD_SHELL->add_type_m_parent(cmd_type,"input_layer");

 	cmd_type = new nsl_cmd_stim_data;
	CMD_SHELL->add_type_i_children(cmd_type,"stim");
	CMD_SHELL->add_type_m_parent(cmd_type,"input_data");

	cmd_type = new nsl_cmd_stim_vector;
	CMD_SHELL->add_type_i_children(cmd_type,"stim");
	CMD_SHELL->add_type_m_parent(cmd_type,"input_vector");

	cmd_type = new nsl_cmd_stim_matrix;
	CMD_SHELL->add_type_i_children(cmd_type,"stim");
	CMD_SHELL->add_type_m_parent(cmd_type,"input_matrix");

 	cmd_type = new nsl_cmd_block_stim_data;
	CMD_SHELL->add_type_i_children(cmd_type,"stim_data");
	CMD_SHELL->add_type_i_children(cmd_type,"block_stim");
	CMD_SHELL->add_type_m_parent(cmd_type,"input_data");

	cmd_type = new nsl_cmd_block_stim_vector;
	CMD_SHELL->add_type_i_children(cmd_type,"stim_vector");
	CMD_SHELL->add_type_i_children(cmd_type,"block_stim");
	CMD_SHELL->add_type_m_parent(cmd_type,"input_vector");

	cmd_type = new nsl_cmd_block_stim_matrix;
	CMD_SHELL->add_type_i_children(cmd_type,"stim_matrix");
	CMD_SHELL->add_type_i_children(cmd_type,"block_stim");
	CMD_SHELL->add_type_m_parent(cmd_type,"input_matrix");

 	cmd_type = new nsl_cmd_icon_stim_data;
	CMD_SHELL->add_type_i_children(cmd_type,"stim_data");
	CMD_SHELL->add_type_i_children(cmd_type,"icon_stim");
	CMD_SHELL->add_type_m_parent(cmd_type,"input_data");

	cmd_type = new nsl_cmd_icon_stim_vector;
	CMD_SHELL->add_type_i_children(cmd_type,"stim_vector");
	CMD_SHELL->add_type_i_children(cmd_type,"icon_stim");
	CMD_SHELL->add_type_m_parent(cmd_type,"input_vector");

	cmd_type = new nsl_cmd_icon_stim_matrix;
	CMD_SHELL->add_type_i_children(cmd_type,"stim_matrix");
	CMD_SHELL->add_type_i_children(cmd_type,"icon_stim");
	CMD_SHELL->add_type_m_parent(cmd_type,"input_matrix");

	cmd_type = new nsl_cmd_time_interval;
	CMD_SHELL->add_type_m_parent(cmd_type,"stim");

	cmd_set = new nsl_str_data("name");
 	cmd_type->add_data(cmd_set);


	cmd_set = new nsl_int_data("index",0,0);
 	cmd_type->add_data(cmd_set);

	cmd_set = new nsl_num_data("t0",0.0,0);
 	cmd_type->add_data(cmd_set);
	cmd_set = new nsl_num_data("t1",1.0,0);
 	cmd_type->add_data(cmd_set);
}
// nsl_sys_module nsl_mod_input_init("input",nsl_input_init,1);
