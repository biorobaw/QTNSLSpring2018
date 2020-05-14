/* SCCS  @(#)nsl_data_comp_library.h	1.1---95/08/13--23:38:58 */
//
// nsl_data_comp_library.h
//

#include "nsl_num.h"

//extern	int		operator>(const nsl_num_0&,const num_type);
//extern	int		operator>(const nsl_num_0&,const nsl_num_0&);
//extern	int		operator>(const num_type,const nsl_num_0&);

extern	int		operator<(const nsl_num_0&,const num_type);
//extern	int		operator<(const nsl_num_0&,const nsl_num_0&);
//extern	int		operator<(const num_type,const nsl_num_0&);

extern	int		operator>=(const nsl_num_0&,const num_type);
extern	int		operator<=(const nsl_num_0&,const num_type);
extern	int		operator>=(const nsl_num_0&,const nsl_num_0&);
extern	int		operator<=(const nsl_num_0&,const nsl_num_0&);
extern	int		operator>=(const num_type,const nsl_num_0&);
extern	int		operator<=(const num_type,const nsl_num_0&);

//extern	int		operator==(const nsl_num_0&,const num_type);
extern	int		operator!=(const nsl_num_0&,const num_type);
extern	int		operator==(const nsl_num_0&,const nsl_num_0&);
extern	int		operator!=(const nsl_num_0&,const nsl_num_0&);
extern	int		operator==(const num_type,const nsl_num_0&);
extern	int		operator!=(const num_type,const nsl_num_0&);

