/* SCCS  %W%---%E%--%U% */
/**************************************************************/
/*                                                            */
/*                   xnsl_cmd_display_frame.c                 */
/*                                                            */
/**************************************************************/

#include "xkernel.h"
#include "nsl_kernel.h" 

xnsl_cmd_display_frame::xnsl_cmd_display_frame() : xnsl_cmd_window()
{
        set_type("display_frame");
  
//	create_data(); // create all data for all types
}

xnsl_cmd_display_frame::~xnsl_cmd_display_frame()
{
}

int xnsl_cmd_display_frame::cmd_create(nsl_interpreter& nsl)
{
        xnsl_display_frame* frame;
 	xnsl_window* pfr;
 	nsl_string str;

	strcpy(str,get_obj_name(nsl));

	if (m_parent != NULL && 
	     (pfr = (xnsl_window*) m_parent->get_ptr()) != NULL &&
	     (frame = new xnsl_display_frame(pfr,str)) != NULL)
        {
	    ((xnsl_window_interface*) pfr)->add_frame(frame);
	    nsl.add_object(frame);
            set_ptr(frame);
            create_data(frame); // nothing
            update_data(frame);
	    frame->create();
        }
        else
                cmd_error("cmd_display_frame: Unable to create new frame");

        return 1;
}
int xnsl_cmd_display_frame::cmd_init(nsl_interpreter& nsl)
{
        return cmd_type_init(nsl);
}
int xnsl_cmd_display_frame::cmd_reset(nsl_interpreter& nsl)
{
        return cmd_type_reset(nsl);
}
int xnsl_cmd_display_frame::cmd_update(nsl_interpreter& nsl)
{
        return cmd_type_update(nsl);
}
