//
//	nsl_thresh_library.C
//

#include "nsl_thresh_library.h"
#include "nsl_system.h"

nsl_thresh_library::nsl_thresh_library(const char* lname,int size,int fg) : 
	nsl_library(lname,size,fg)
{
	if (fg == 1) // initial copy of thresh library to be added to nsl_system
	{
		m_parent = SYSTEM;
		((nsl_system*) m_parent)->add_thresh_lib(this);
	}
}

nsl_thresh_library::~nsl_thresh_library()
{
}

