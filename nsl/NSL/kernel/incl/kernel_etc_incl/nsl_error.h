/* SCCS  %W%---%E%--%U% */
//
//	nsl_error.C
//

#ifndef _NSL_ERROR_H_
#define _NSL_ERROR_H_


#include "nsl.h"

void cmd_out(const char* p);
void cmd_out(const float p);
void cmd_out(const char* p1,const char* p2);
void cmd_out(const char* p1,const int p2);
void cmd_out(const char* p1,const float p2);
void cmd_out(const char* p1,row_col_enum p2);
void cmd_out(const char* p1,on_off_enum p2);
void cmd_error(const char* p);
void cmd_error(const char* p1,const char* p2);
void cmd_error(const char* p1,const int p2);
void cmd_error(const char* p1,const float p2);
void cmd_error(const char* p1,row_col_enum p2);

void cmd_error(const char* p1,on_off_enum p2);

#endif
