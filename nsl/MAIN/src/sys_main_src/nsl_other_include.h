/* SCCS  @(#)nsl_other_include.h	1.2---95/10/03--13:59:09 */
//
//	nsl_other_include.h
//

//extern "C" int fork();
//extern "C" int chdir(char*);

#include "nsl.h"

// cmd_error
extern void cmd_error(const char*);
extern void cmd_error(const char*,const char*);
extern void cmd_error(const char*,const int);
extern void cmd_error(const char*,const float);

extern void cmd_error(const char*,row_col_enum);
extern void cmd_error(const char*,on_off_enum);
extern void cmd_error(const char*,in_out_enum);
extern void cmd_error(const char*,file_enum);
extern void cmd_error(const char*,dump_enum);

// cmd_out
extern void cmd_out(const char*);
extern void cmd_out(const float);
extern void cmd_out(const char*,const char*);
extern void cmd_out(const char*,const int);
extern void cmd_out(const char*,const float);

extern void cmd_out(const char*,row_col_enum);
extern void cmd_out(const char*,on_off_enum);
extern void cmd_out(const char*,in_out_enum);
extern void cmd_out(const char*,file_enum);
extern void cmd_out(const char*,dump_enum);

// NSLoutput
extern int NSLoutput(const char*,std::ostream&);
extern int NSLoutput(const int,std::ostream&);
extern int NSLoutput(const float,std::ostream&);
extern int NSLoutput(const double,std::ostream&);
extern int NSLoutput(const char*);
extern int NSLoutput(const int);
extern int NSLoutput(const float);
extern int NSLoutput(const double);
extern int NSLoutput(const char*,const char*);

// other
extern int nsl_rint(num_type);

extern "C" int NSLinterrupt_handler();
extern "C" int NSLurgent_handler();
extern "C" int NSLinit_interrupt_handler();

// nslDiff
extern num_type& nslDiff(num_type&,num_type,
	const num_type&);
extern nsl_num_data& nslDiff(nsl_num_data&,num_type,
	const nsl_num_data&);
extern nsl_num_data& nslDiff(nsl_num_data&,nsl_num_data&,
	const nsl_num_data&);
extern nsl_num_vector& nslDiff(nsl_num_vector&,num_type,
	const nsl_num_vector&);
extern nsl_num_vector& nslDiff(nsl_num_vector&,nsl_num_data&,
	const nsl_num_vector&);
extern nsl_num_matrix& nslDiff(nsl_num_matrix&,num_type,
	const nsl_num_matrix&);
extern nsl_num_matrix& nslDiff(nsl_num_matrix&,nsl_num_data&,
	const nsl_num_matrix&);

extern nsl_num_1& nslDiff(nsl_num_1& m,nsl_num_0& k,
		const nsl_num_1& a);
extern nsl_num_0& nslDiff(nsl_num_0& m,NslNumType k,
		const nsl_num_0& a);
/*
extern num_type& nslDiff(num_type&,num_type,
	const num_type&);
extern nsl_num_0& nslDiff(nsl_num_0&,num_type,
	const nsl_num_0&);
extern nsl_num_0& nslDiff(nsl_num_0&,nsl_num_0&,
	const nsl_num_0&);
extern nsl_num_1& nslDiff(nsl_num_1&,num_type,
	const nsl_num_1&);
extern nsl_num_1& nslDiff(nsl_num_1&,nsl_num_0&,
	const nsl_num_1&);
extern nsl_num_2& nslDiff(nsl_num_2&,num_type,
	const nsl_num_2&);
extern nsl_num_2& nslDiff(nsl_num_2&,nsl_num_0&,
	const nsl_num_2&);
*/
