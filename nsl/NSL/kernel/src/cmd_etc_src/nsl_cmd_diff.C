/* SCCS  %W%---%E%--%U% */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_diff.C                           */
/*                                                            */
/**************************************************************/

#include "nsl_kernel.h"
#include "nsl_stream.h"
#include "nsl_diff_manager.h"
#include "nsl_cmd_system.h"
#include "nsl_diff.h"
extern nsl_diff* NSL_DIFF;

using namespace std;

extern void cmd_error(const char *);

nsl_cmd_diff::nsl_cmd_diff(const char* dtype) : nsl_cmd_type(dtype)
{
	set_base_type(dtype);
	init_cmd_diff();
}

nsl_cmd_diff::~nsl_cmd_diff()
{
}

int nsl_cmd_diff::init_cmd_diff()
{
	return set_cmd_diff();
}
int nsl_cmd_diff::set_cmd_diff()
{
	OBJ = NSL_DIFF;

	return 1;
}

// data

int nsl_cmd_diff::init_data(nsl_base*)
{
	return 1;
}
int nsl_cmd_diff::update_data(nsl_base*,
	int,int,int,int,int,int,int,int,int,int)
{
	// check for data and update model object

        nsl_layer* data;
        nsl_base* pbase;
        nsl_list* list = 0;
	num_type t;
	nsl_string s;
	nsl_model* model;
	nsl_diff_manager* mdiff;

	if ((model = SYSTEM->get_model()) == NULL || 
		(mdiff = model->get_diff_manager()) == NULL)
	{
		cmd_error("cmd_diff: NULL LOBJ");
		return 0;
	}

        pbase = SYSTEM->get_cmd_system()->
             get_m_children_list()->get_mi_by_type(get_base_type());
        if (pbase != NULL)
                list = ((nsl_cmd_type*) pbase)->get_data_list();
        else
                cmd_error("cmd_diff: NULL parent type");

        if (list != NULL)
        {
          if ((data = (nsl_layer*) list->get_by_name("delta")) != NULL)
	  {
                t = ((nsl_num_data*) data)->get_value();
		mdiff->set_delta(t);
		if (NSL_DIFF != NULL)
			NSL_DIFF->set_delta(t);
		else
			cmd_error("cmd_diff: NULL NSL_DIFF");	
	  }
          else
                cmd_error("cmd_diff: NULL 'delta' obj");
        
          if ((data = (nsl_layer*) list->get_by_name("integration")) != NULL)
	  {
                strcpy(s,((nsl_str_data*) data)->get_value());
		mdiff->set_method(s);
	  }
          else
                cmd_error("cmd_diff: NULL 'integration' obj");
        }

	return 1;
}

int nsl_cmd_diff::cmd_create(nsl_interpreter& nsl)
{
	return 1;
}
int nsl_cmd_diff::cmd_disable(nsl_interpreter& nsl)
{
	cmd_type_disable(nsl);

	return 1;
}
int nsl_cmd_diff::cmd_enable(nsl_interpreter& nsl)
{
	cmd_type_enable(nsl);

	return 1;
}
int nsl_cmd_diff::cmd_print(nsl_interpreter& nsl)
{
// diff command actually refers to diff_manager
//	cmd_type_print(nsl);

 	if (m_parent == NULL)
	{
		cmd_error("CMD DIFF: Null Parent");
		return 1;
	}

	fstream& log = nsl.get_log0();

 	if (nsl.get_str_cnt() > 0)
		cmd_error("cmd_diff: No arguments used");

	nsl_model* model;
	nsl_diff_manager* dm;

	if ((model = SYSTEM->get_model()) != NULL && 
	   (dm = model->get_diff_manager()) != NULL)
  		dm->print(log);
	else
 		cmd_error("cmd_diff: NULL obj");
 
	return 1;
}
int nsl_cmd_diff::cmd_set(nsl_interpreter& nsl)
{
	int fg = cmd_type_set(nsl);

	if (fg == 1)
		update_data(0);

	return fg;
}
int nsl_cmd_diff::cmd_status(nsl_interpreter& nsl)
{
// diff command actually refers to diff_manager
//	cmd_type_status(nsl);

        nsl_layer* dobj;

	if (m_parent == NULL)
	{
		cmd_error("CMD DIFF: Null Parent");
		return 1;
	}

	fstream& log = nsl.get_log0();

	log << "\nBuffer Status:\n";

	data_list->wind_up();
        while ((dobj = (nsl_layer*) data_list->next()) != NULL)
 	 	dobj->print(log);
  
 	log << "\nType Status:\n";
	log.flush();

	if (nsl.get_str_cnt() > 0)
		cmd_error("cmd_diff: No arguments used");

	nsl_model* model;
	nsl_diff_manager* dm;

	if ((model = SYSTEM->get_model()) != NULL && 
	   (dm = model->get_diff_manager()) != NULL)
  		dm->print_status(log);
	else
 		cmd_error("cmd_diff: NULL obj");
 
	return 1;
}
int nsl_cmd_diff::cmd_update(nsl_interpreter& nsl)
{
	int fg = 2;

	return fg;
}

// local print

int nsl_cmd_diff::print_cmd_diff(std::ostream& out) const
{
	print_cmd_type(out);
	i_children_list->print(out);
	return 1;
}
int nsl_cmd_diff::print(std::ostream& out) const // virtual
{
	print_cmd_diff(out);
	return 1;
}
