#ifndef _NSL_NEURON_H
#define _NSL_NEURON_H
#include "nsl_link_matrix_matrix_data.h"
#include "nsl_cmd_link_data_data_vector.h"
#include "nsl_link_data_data_vector.h"
# include "nsl_cmd_link_vector_data_matrix.h"
#include "nsl_link_vector_data_matrix.h"
#include "nsl_cmd_link_matrix_matrix_vector.h"
#include "nsl_link_matrix_matrix_vector.h"
#include "nsl_cmd_link_vector_matrix_data.h"
#include "nsl_link_vector_matrix_data.h"
#include "nsl_link_vector_data_data.h"
#include "nsl_cmd_link_vector_matrix_matrix.h"
#include "nsl_cmd_link_vector_data_data.h"
#include "nsl_link_vector_matrix_matrix.h"
#include "nsl_link_data_data.h"
#include "nsl_link_vector_vector_vector.h"
#include "nsl_neuron_data.h"
#include "nsl_neuron_vector.h"
#include "nsl_neuron_layer.h"
#include "nsl_site_layer.h"
#include "nsl_link_layer.h"
#include "nsl_site_layer.h"
#include "nsl_layer.h"

#include "nsl_cmd_link_data_data_data.h" // does not name a type	nsl_neuron_main_short.C	/CppApplication_NSL/NSL/neuron/src/main_src	line 168	C/C++ Problem
#include "nsl_cmd_link_data_data_matrix.h" // does not name a type	nsl_neuron_main_short.C	/CppApplication_NSL/NSL/neuron/src/main_src	line 198	C/C++ Problem
#include "nsl_cmd_link_data_data.h" // does not name a type	nsl_neuron_main_short.C	/CppApplication_NSL/NSL/neuron/src/main_src	line 123	C/C++ Problem
#include "nsl_cmd_link_data_matrix_data.h" // does not name a type	nsl_neuron_main_short.C	/CppApplication_NSL/NSL/neuron/src/main_src	line 178	C/C++ Problem
#include "nsl_cmd_link_data_matrix_vector.h" // does not name a type	nsl_neuron_main_short.C	/CppApplication_NSL/NSL/neuron/src/main_src	line 193	C/C++ Problem
#include "nsl_cmd_link_data_matrix_vector.h" // does not name a type	nsl_neuron_main_short.C	/CppApplication_NSL/NSL/neuron/src/main_src	line 208	C/C++ Problem
#include "nsl_cmd_link_data_matrix.h" // does not name a type	nsl_neuron_main_short.C	/CppApplication_NSL/NSL/neuron/src/main_src	line 153	C/C++ Problem
#include "nsl_cmd_link_data_vector_data.h" // does not name a type	nsl_neuron_main_short.C	/CppApplication_NSL/NSL/neuron/src/main_src	line 173	C/C++ Problem
#include "nsl_cmd_link_data_vector_matrix.h" // does not name a type	nsl_neuron_main_short.C	/CppApplication_NSL/NSL/neuron/src/main_src	line 203	C/C++ Problem
#include "nsl_cmd_link_data_vector_vector.h" // does not name a type	nsl_neuron_main_short.C	/CppApplication_NSL/NSL/neuron/src/main_src	line 188	C/C++ Problem
#include "nsl_cmd_link_matrix_data_data.h" // does not name a type	nsl_neuron_main_short.C	/CppApplication_NSL/NSL/neuron/src/main_src	line 258	C/C++ Problem
#include "nsl_cmd_link_matrix_data_matrix.h" // does not name a type	nsl_neuron_main_short.C	/CppApplication_NSL/NSL/neuron/src/main_src	line 288	C/C++ Problem
#include "nsl_cmd_link_matrix_data_vector.h" // does not name a type	nsl_neuron_main_short.C	/CppApplication_NSL/NSL/neuron/src/main_src	line 273	C/C++ Problem
#include "nsl_cmd_link_matrix_data.h" // does not name a type	nsl_neuron_main_short.C	/CppApplication_NSL/NSL/neuron/src/main_src	line 133	C/C++ Problem
#include "nsl_cmd_link_matrix_matrix_data.h" // does not name a type	nsl_neuron_main_short.C	/CppApplication_NSL/NSL/neuron/src/main_src	line 268	C/C++ Problem
#include "nsl_cmd_link_matrix_matrix_matrix.h" // does not name a type	nsl_neuron_main_short.C	/CppApplication_NSL/NSL/neuron/src/main_src	line 298	C/C++ Problem
#include "nsl_cmd_link_matrix_matrix.h" // does not name a type	nsl_neuron_main_short.C	/CppApplication_NSL/NSL/neuron/src/main_src	line 163	C/C++ Problem
#include "nsl_cmd_link_matrix_vector_data.h" // does not name a type	nsl_neuron_main_short.C	/CppApplication_NSL/NSL/neuron/src/main_src	line 263	C/C++ Problem
#include "nsl_cmd_link_matrix_vector_matrix.h" // does not name a type	nsl_neuron_main_short.C	/CppApplication_NSL/NSL/neuron/src/main_src	line 293	C/C++ Problem
#include "nsl_cmd_link_matrix_vector_vector.h" // does not name a type	nsl_neuron_main_short.C	/CppApplication_NSL/NSL/neuron/src/main_src	line 278	C/C++ Problem
#include "nsl_cmd_link_vector_data_vector.h" // does not name a type	nsl_neuron_main_short.C	/CppApplication_NSL/NSL/neuron/src/main_src	line 228	C/C++ Problem
#include "nsl_cmd_link_vector_matrix_vector.h" // does not name a type	nsl_neuron_main_short.C	/CppApplication_NSL/NSL/neuron/src/main_src	line 238	C/C++ Problem
#include "nsl_cmd_link_vector_vector_data.h" // does not name a type	nsl_neuron_main_short.C	/CppApplication_NSL/NSL/neuron/src/main_src	line 218	C/C++ Problem
#include "nsl_cmd_link_vector_vector_matrix.h" // does not name a type	nsl_neuron_main_short.C	/CppApplication_NSL/NSL/neuron/src/main_src	line 248	C/C++ Problem
#include "nsl_cmd_link_vector_vector_vector.h" // does not name a type	nsl_neuron_main_short.C	/CppApplication_NSL/NSL/neuron/src/main_src	line 233	C/C++ Problem
#include "nsl_cmd_link_vector_vector.h" // does not name a type	nsl_neuron_main_short.C	/CppApplication_NSL/NSL/neuron/src/main_src	line 143	C/C++ Problem

#include "nsl_num_matrix.h"
#include "nsl_num_data.h"
#include "nsl_num_vector.h"

#include "nsl_site_matrix.h"
#include "nsl_link_matrix.h"


#include "nsl_interpreter.h"

#include "nsl_cmd_system.h"
#include "nsl_cmd_neuron_matrix.h"
#include "nsl_cmd_neuron_vector.h"
#include "nsl_cmd_site_data.h"
#include "nsl_cmd_site_layer.h"
#include "nsl_cmd_site_vector.h"
#include "nsl_site_matrix.h"
#include "nsl_cmd_neuron_layer.h"
#include "nsl_cmd_neural_network.h"
#include "nsl_cmd_buf.h"
#include "nsl_ramp_library.h"
#include "nsl_int_data.h"

#include "nsl_thresh_library.h"
#include "nsl_sat_library.h"
#include "nsl_sigma_library.h"

#include "nsl_step_library.h"

#include "nsl_cmd_buf.h"
#include "nsl_cmd_neuron_data.h"
#include "nsl_cmd_site_matrix.h"
#include "nsl_str_data.h"

#include "nsl_diff_method.h"
#include "nsl_model.h"
#include "nsl_ptr_vector.h"
#include "nsl_system.h"
#include "nsl_diff.h"


#include "nsl_base_list.h"


#include "nsl_link_vector_data_vector.h"
#include "nsl_link_data_data_data.h"
#include "nsl_link_data_vector_data.h"
#include "nsl_link_data_vector_vector.h"
#include "nsl_link_vector_vector_data.h"

#endif
