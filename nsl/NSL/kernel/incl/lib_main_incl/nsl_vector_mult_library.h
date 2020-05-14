/* SCCS  @(#)nsl_vector_mult_library.h	1.1---95/08/13--23:38:58 */
//
// nsl_vector_mult_library.h
//

class nsl_num_0;
class nsl_num_1;
class nsl_num_2;
//typedef nsl_num_0 nsl_num_0;
//typedef nsl_num_1 nsl_num_1;
//typedef nsl_num_2 nsl_num_2;
typedef float num_type;

extern 	nsl_num_1 	operator^(const nsl_num_1&,const nsl_num_1&);
extern	nsl_num_1 	operator^(const nsl_num_1&,const num_type);
extern	nsl_num_1 	operator^(const num_type,const nsl_num_1&);
extern	nsl_num_1 	operator^(const nsl_num_0&,const nsl_num_1&);
extern	nsl_num_1 	operator^(const nsl_num_1&,const nsl_num_0&);

