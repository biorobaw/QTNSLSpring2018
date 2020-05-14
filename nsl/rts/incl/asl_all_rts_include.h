// asl_all_rts_include.h

//#pragma interface

#ifndef __ASL_ALL_RTS_H	
#define __ASL_ALL_RTS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef NSL_PC
//	#include <varargs.h>
#else // UNIX
	#include <unistd.h>
#endif
#include <stdarg.h>

#include "asl.h"
#include "asllist.h"        
#include "aslio.h"    
#include "aslcom_seq.h"
#include "asl_seq.h"

# include "nsl_din_num_0.h"
# include "nsl_din_num_1.h"
# include "nsl_din_num_2.h"
# include "nsl_din_num_3.h"
# include "nsl_din_num_4.h"
# include "nsl_dout_num_0.h"
# include "nsl_dout_num_1.h"
# include "nsl_dout_num_2.h"
# include "nsl_dout_num_3.h"
# include "nsl_dout_num_4.h"


#endif
