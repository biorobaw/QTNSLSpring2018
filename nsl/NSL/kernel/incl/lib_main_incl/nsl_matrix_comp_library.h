/* SCCS  @(#)nsl_matrix_comp_library.h	1.1---95/08/13--23:38:58 */
//
// nsl_matrix_comp_library.h
//

#ifndef _NSL_SET
class nsl_num_0;
class nsl_num_1;
class nsl_num_2;
//typedef nsl_num_2 nsl_num_2;
//typedef nsl_num_0 nsl_num_0;
//typedef nsl_num_1 nsl_num_1;

#endif

extern	int 		operator>(const nsl_num_2&,const num_type);
extern	int 		operator<(const nsl_num_2&,const num_type);
extern	int 		operator>(const num_type,const nsl_num_2&);
extern	int 		operator<(const num_type,const nsl_num_2&);
extern	int 		operator>(const nsl_num_2&,const nsl_num_0&);
extern	int 		operator<(const nsl_num_2&,const nsl_num_0&);
extern	int 		operator>(const nsl_num_0&,const nsl_num_2&);
extern	int 		operator<(const nsl_num_0&,const nsl_num_2&);

extern	int 		operator>=(const nsl_num_2&,const num_type);
extern	int 		operator<=(const nsl_num_2&,const num_type);
extern	int 		operator>=(const num_type,const nsl_num_2&);
extern	int 		operator<=(const num_type,const nsl_num_2&);
extern	int 		operator>=(const nsl_num_2&,const nsl_num_0&);
extern	int 		operator<=(const nsl_num_2&,const nsl_num_0&);
extern	int 		operator>=(const nsl_num_0&,const nsl_num_2&);
extern	int 		operator<=(const nsl_num_0&,const nsl_num_2&);

extern	int 		operator==(const nsl_num_2&,const num_type);
extern	int 		operator!=(const nsl_num_2&,const num_type);
extern	int 		operator==(const num_type,const nsl_num_2&);
extern	int 		operator!=(const num_type,const nsl_num_2&);
extern	int 		operator==(const nsl_num_2&,const nsl_num_0&);
extern	int 		operator!=(const nsl_num_2&,const nsl_num_0&);
extern	int 		operator==(const nsl_num_0&,const nsl_num_2&);
extern	int 		operator!=(const nsl_num_0&,const nsl_num_2&);


