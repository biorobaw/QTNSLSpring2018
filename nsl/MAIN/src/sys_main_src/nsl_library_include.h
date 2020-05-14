/* SCCS  @(#)nsl_library_include.h	1.1---95/08/13--22:29:21 */
/****************************************************************/
/*                                                           	*/
/*                       nsl_library_include.h                  */
/*                                                            	*/
/****************************************************************/

//# include "lib_main_incl/nsl_library.h"
# include "lib_main_incl/nsl_num_max_library.h"
# include "lib_main_incl/nsl_num_min_library.h"
# include "lib_main_incl/nsl_data_add_library.h"
# include "lib_main_incl/nsl_data_sub_library.h"
# include "lib_main_incl/nsl_data_mult_library.h"
# include "lib_main_incl/nsl_data_div_library.h"
# include "lib_main_incl/nsl_data_conv_library.h"
# include "lib_main_incl/nsl_data_comp_library.h"
# include "lib_main_incl/nsl_data_max_library.h"
# include "lib_main_incl/nsl_data_min_library.h"
# include "lib_main_incl/nsl_vector_add_library.h"
# include "lib_main_incl/nsl_vector_sub_library.h"
# include "lib_main_incl/nsl_vector_mult_library.h"
# include "lib_main_incl/nsl_vector_div_library.h"
# include "lib_main_incl/nsl_vector_conv_library.h"
# include "lib_main_incl/nsl_vector_comp_library.h"
# include "lib_main_incl/nsl_vector_max_library.h"
# include "lib_main_incl/nsl_vector_min_library.h"
# include "lib_main_incl/nsl_matrix_add_library.h"
# include "lib_main_incl/nsl_matrix_sub_library.h"
# include "lib_main_incl/nsl_matrix_mult_library.h"
# include "lib_main_incl/nsl_matrix_div_library.h"
# include "lib_main_incl/nsl_matrix_conv_library.h"
# include "lib_main_incl/nsl_matrix_comp_library.h"
# include "lib_main_incl/nsl_matrix_max_library.h"
# include "lib_main_incl/nsl_matrix_min_library.h"
# include "lib_main_incl/nsl_mat_vec_prod_library.h"
# include "lib_main_incl/nsl_mat_to_vec_library.h"
# include "lib_main_incl/nsl_vec_to_mat_library.h"
/*
# include "lib_main_incl/nsl_num_library.h"

# include "lib_thresh_incl/nsl_thresh_library.h"
# include "lib_thresh_incl/nsl_step_library.h"
# include "lib_thresh_incl/nsl_ramp_library.h"
# include "lib_thresh_incl/nsl_sat_library.h"
# include "lib_thresh_incl/nsl_sigma_library.h"
*/
# include "lib_thresh_incl/nsl_num_step_library.h"
# include "lib_thresh_incl/nsl_num_ramp_library.h"
# include "lib_thresh_incl/nsl_num_sat_library.h"
# include "lib_thresh_incl/nsl_num_sigma_library.h"
# include "lib_thresh_incl/nsl_data_step_library.h"
# include "lib_thresh_incl/nsl_data_ramp_library.h"
# include "lib_thresh_incl/nsl_data_sat_library.h"
# include "lib_thresh_incl/nsl_data_sigma_library.h"
# include "lib_thresh_incl/nsl_vector_step_library.h"
# include "lib_thresh_incl/nsl_vector_ramp_library.h"
# include "lib_thresh_incl/nsl_vector_sat_library.h"
# include "lib_thresh_incl/nsl_vector_sigma_library.h"
# include "lib_thresh_incl/nsl_vector_gauss_library.h"
# include "lib_thresh_incl/nsl_matrix_step_library.h"
# include "lib_thresh_incl/nsl_matrix_ramp_library.h"
# include "lib_thresh_incl/nsl_matrix_sat_library.h"
# include "lib_thresh_incl/nsl_matrix_sigma_library.h"
# include "lib_thresh_incl/nsl_matrix_expdecay_library.h"
# include "lib_thresh_incl/nsl_matrix_kernel_library.h"

# include "lib_etc_incl/nsl_interpreter_stream_library.h"
# include "lib_etc_incl/nsl_buffer_stream_library.h"
# include "lib_etc_incl/nsl_streambuf_stream_library.h"
# include "lib_etc_incl/nsl_nsl_file_stream_library.h"
/*
# include "lib_diff_incl/nsl_diff_euler.h"
# include "lib_diff_incl/nsl_diff_euler_data.h"
# include "lib_diff_incl/nsl_diff_euler_vector.h"
# include "lib_diff_incl/nsl_diff_euler_matrix.h"
# include "lib_diff_incl/nsl_diff_interpolation.h"
# include "lib_diff_incl/nsl_diff_interpolation_data.h"
# include "lib_diff_incl/nsl_diff_interpolation_vector.h"
# include "lib_diff_incl/nsl_diff_interpolation_matrix.h"
*/
// old compatibility

# undef NSLsigmoid
# define NSLsigmoid NSLsigma
# undef NSLsaturation
# define NSLsaturation NSLsat

