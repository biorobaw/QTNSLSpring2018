/* SCCS  @(#)nsl_data_add_library.h	1.1---95/08/13--23:38:58 */
//
// nsl_data_add_library.h
//
/*AW98
extern	nsl_num_0 	operator+(const nsl_num_0&);
extern	nsl_num_0 	operator+(const nsl_num_0&,const nsl_num_0&);
extern 	nsl_num_0 	operator+(const nsl_num_0&,const num_type);
*/
class nsl_num_data;
extern 	nsl_num_0 	operator+(const num_type,const nsl_num_0&);

nsl_num_data operator+(nsl_num_data &a, nsl_num_data &b);
nsl_num_data operator+(nsl_num_data &a, num_type &b);
