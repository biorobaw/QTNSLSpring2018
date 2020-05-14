/* SCCS  %W%---%E%--%U% */
/*                                                            */
/*            		   xnsl_command.h          	      */
/*                                                            */
/* by Alfredo Weitzenfeld 				      */
/*                                                            */
/**************************************************************/

//static char SccsId[] = "%W%  %G%"; /* SCCS */

# include "nsl.h"
//# include "nsl_headers.h"

# include "xnsl_winds.h"
# include "xnsl_system.h"

# include "xnsl_command_buffer.h"

extern int nsl_skip_comment(istream&);
extern int nsl_get_str(istream&,char*);
extern int nsl_get_on_off(nsl_num_0*);

extern void set_global_pointers();

//extern command_buffer* CMD_BUF;

// extern istream IN_FILE;

// current object pointers
extern xnsl_system* XNSL_SYSTEM;

extern nsl_model* NSL_MODEL;
extern nsl_module* NSL_MODULE;
extern nsl_layer* NSL_LAYER;
extern nsl_layer* NSL_INPUT_LAYER;
//extern nsl_stim_obj* NSL_INPUT_STIM;
/*
extern window_interface* NSL_INTERFACE;
extern display_frame* NSL_FRAME;
extern display_window* NSL_WINDOW;
extern display_canvas* NSL_CANVAS;
extern display_panel* NSL_PANEL;

extern canvas_object* NSL_CANVAS_ITEM;
extern panel_object* NSL_PANEL_ITEM;
*/
extern nsl_num_0* NSL_WINDOW_ITEM;
