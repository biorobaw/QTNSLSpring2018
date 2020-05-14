#ifndef _NSL_KERNEL_H
#define _NSL_KERNEL_H

#include "nsl_base.h"
#include "nsl_base_list.h"

#include "nsl_cmd_buf.h"
#include "nsl_cmd_data_layer.h"
#include "nsl_cmd_diff.h"
#include "nsl_cmd_exec_assign.h"
#include "nsl_cmd_exec_cd.h"
#include "nsl_cmd_exec_close.h"
#include "nsl_cmd_exec_connect.h"
#include "nsl_cmd_exec_cont.h"
#include "nsl_cmd_exec_create.h" //
#include "nsl_cmd_exec_csh.h"
#include "nsl_cmd_exec_delay.h" //
#include "nsl_cmd_exec_disable.h"
#include "nsl_cmd_exec_elem.h"
#include "nsl_cmd_exec_enable.h"
#include "nsl_cmd_exec_exec.h"
#include "nsl_cmd_exec_file_disable.h"
#include "nsl_cmd_exec_file_enable.h"
#include "nsl_cmd_exec_get.h" //
#include "nsl_cmd_exec_help.h"
#include "nsl_cmd_exec_init.h"
#include "nsl_cmd_exec_load.h"
#include "nsl_cmd_exec_open.h"
#include "nsl_cmd_exec_print.h"
#include "nsl_cmd_exec_quit.h"  //
#include "nsl_cmd_exec_stop.h"  //
#include "nsl_cmd_exec_reset.h" //
#include "nsl_cmd_exec_run.h"
#include "nsl_cmd_exec_set.h"
#include "nsl_cmd_exec_sh.h"     //
#include "nsl_cmd_exec_status.h" //
#include "nsl_cmd_exec_step.h"   //
#include "nsl_cmd_exec_stop.h"   //<-
#include "nsl_cmd_exec_train.h"  //
#include "nsl_cmd_exec_update.h" //
#include "nsl_cmd_exec_write.h"  //
#include "nsl_cmd_diff_manager.h"//
#include "nsl_cmd_file_manager.h"//
#include "nsl_cmd_file.h"        //
#include "nsl_cmd_function.h"    //
#include "nsl_cmd_int_data.h"    //
#include "nsl_cmd_int_matrix.h"  //
#include "nsl_cmd_int_vector.h"  //
#include "nsl_cmd_num_data.h"    //
#include "nsl_cmd_num_vector.h"  //
#include "nsl_cmd_num_matrix.h"  //
#include "nsl_cmd_matrix_layer.h"//
#include "nsl_cmd_macro.h"       //
#include "nsl_cmd_model.h"       //
#include "nsl_cmd_module.h"      //
#include "nsl_cmd_ptr_data.h"    //
#include "nsl_cmd_ptr_vector.h"  //
#include "nsl_cmd_ptr_matrix.h"  //
#include "nsl_cmd_str_data.h"    //
#include "nsl_cmd_str_vector.h"  //
#include "nsl_cmd_str_matrix.h"  //
#include "nsl_cmd_system.h"      //
#include "nsl_cmd_type.h"        //
#include "nsl_cmd_vector_layer.h"//

#include "nsl_data_layer.h"      //
#include "nsl_diff.h"            //
#include "nsl_diff_euler_data.h"
#include "nsl_diff_euler_matrix.h"
#include "nsl_diff_euler_vector.h"
#include "nsl_diff_interpolation_data.h"
#include "nsl_diff_interpolation_vector.h"
#include "nsl_diff_interpolation_matrix.h"
#include "nsl_diff_manager.h"    //
#include "nsl_dump_data.h"       //

#include "nsl_file.h"           //
#include "nsl_file_data.h"      //
#include "nsl_function.h"       //
#include "nsl_in_out_data.h"    //
#include "nsl_int_data.h"
#include "nsl_interpreter.h"
#include "nsl_layer.h"
#include "nsl_model.h"
#include "nsl_module.h"        //
#include "nsl_nsl_file.h"      //
#include "nsl_num.h"           // <-
#include "nsl_num_0.h"         //
#include "nsl_num_1.h"         //
#include "nsl_num_2.h"         //
#include "nsl_num_3.h"         //
#include "nsl_num_4.h"
#include "nsl_num_data.h"
#include "nsl_num_matrix.h"    // <-
#include "nsl_num_vector.h"    // <-
#include "nsl_on_off_data.h"   //
#include "nsl_ptr_vector.h"    //
#include "nsl_ptr_data.h"      //
#include "nsl_ptr_matrix.h"    //
#include "nsl_row_col_data.h"

#include "nsl_step_library.h"  //
#include "nsl_str_data.h"      //
#include "nsl_str_matrix.h"    //
#include "nsl_str_vector.h"    //
#include "nsl_stream.h"        //
#include "nsl_streambuf.h"     //
#include "nsl_sys_function.h"  //
#include "nsl_system.h"

extern void cmd_out(const char *);
extern void cmd_out(const char *, const char *);
extern void cmd_out(const char *, int);
extern void cmd_error(const char *, int);
extern void cmd_error(const char *);
extern void cmd_error(const char *, const char *);

extern int INTERRUPTFG;
extern int BREAKFG;
#endif
