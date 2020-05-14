/**************************************************************/
/*                                                            */
/*               nsl_cmd_neuron_layer.C                       */
/*                                                            */
/**************************************************************/

#include "nsl_cmd_neuron_layer.h"
#include "nsl_neuron.h"
#include "nsl_base.h"

nsl_cmd_neuron_layer::nsl_cmd_neuron_layer(int fg) : nsl_cmd_layer()
{
	set_type("neuron");
	set_base_type("layer"); // this used for look up in "assign" command
	set_abstract_type("layer");

	if (fg == 0) // constructor called from subclass
		return;

	// if this class is the actual class instantiated, then init data

	nsl_layer* cmd_set;

	cmd_set = new nsl_str_data("name");
 	add_data(cmd_set);

	cmd_set = new nsl_int_data("index");
 	add_data(cmd_set);

	cmd_set = new nsl_str_data("diff_model");
 	add_data(cmd_set);

	cmd_set = new nsl_str_data("diff_method");
 	add_data(cmd_set);

	cmd_set = new nsl_num_data("diff_delta");
 	add_data(cmd_set);

	cmd_set = new nsl_str_data("thresh");
 	add_data(cmd_set);

	cmd_set = new nsl_num_data("tm");
 	add_data(cmd_set);

	cmd_set = new nsl_num_data("end_time");
 	add_data(cmd_set);

	cmd_set = new nsl_num_data("h");
 	add_data(cmd_set);

	cmd_set = new nsl_num_data("inp");
 	add_data(cmd_set);

	cmd_set = new nsl_num_data("inf");
 	add_data(cmd_set);
}

nsl_cmd_neuron_layer::~nsl_cmd_neuron_layer()
{
}

int nsl_cmd_neuron_layer::init_cmd_neuron_layer()
{
	return set_cmd_neuron_layer();
}
int nsl_cmd_neuron_layer::set_cmd_neuron_layer()
{
	nsl_layer* l;

	set_base_type("layer");

	nsl_model* model = SYSTEM->get_model();
	if (model == NULL)
	{
		cmd_error("CMD NEURON LAYER: Null Model");
		return 1;
	}
	/*
	if ((l = model->get_layer(1)) != NULL) //NO SUCH METHOD get_layer in nsl_model -bn7
		OBJ = l;
	else*/
		cmd_error("CMD NEURON LAYER: Null Layer");

 	return 1;
}

// commands

int nsl_cmd_neuron_layer::cmd_clear(nsl_interpreter& nsl)
{
	cmd_type_clear(nsl);

	return 1;
}
int nsl_cmd_neuron_layer::cmd_cont(nsl_interpreter& nsl)
{
	cmd_type_cont(nsl);

	return 1;
}
int nsl_cmd_neuron_layer::cmd_connect(nsl_interpreter& nsl)
{
	return 1;
}
int nsl_cmd_neuron_layer::cmd_create(nsl_interpreter& nsl)
{
	cmd_type_create(nsl);

	return 1;
}
int nsl_cmd_neuron_layer::cmd_disable(nsl_interpreter& nsl)
{
	cmd_type_disable(nsl);

	return 1;
}
int nsl_cmd_neuron_layer::cmd_enable(nsl_interpreter& nsl)
{
	cmd_type_enable(nsl);

	return 1;
}
int nsl_cmd_neuron_layer::cmd_init(nsl_interpreter& nsl)
{
	cmd_type_init(nsl);

	return 1;
}
int nsl_cmd_neuron_layer::cmd_print(nsl_interpreter& nsl)
{
	cmd_type_print(nsl);

	return 1;
}
int nsl_cmd_neuron_layer::cmd_reset(nsl_interpreter& nsl)
{
	cmd_type_reset(nsl);

	return 1;
}
int nsl_cmd_neuron_layer::cmd_run(nsl_interpreter& nsl)
{
	cmd_type_run(nsl);

	return 1;
}
int nsl_cmd_neuron_layer::cmd_set(nsl_interpreter& nsl)
{
 	return cmd_type_set(nsl);
}

int nsl_cmd_neuron_layer::cmd_status(nsl_interpreter& nsl)
{
	cmd_type_status(nsl);

	return 1;
}
int nsl_cmd_neuron_layer::cmd_step(nsl_interpreter& nsl)
{
	cmd_type_step(nsl);

	return 1;
}
int nsl_cmd_neuron_layer::cmd_update(nsl_interpreter& nsl)
{
	nsl_list* list; // data_list
	nsl_cmd_type* cmd_obj; 
	nsl_layer* data;
	const char* sval;
	const char* stype;
	nsl_string lib_type;
	num_type fval;
	nsl_library *lib,*obj_lib; // thresh
	nsl_diff *diff,*obj_diff; // diff_model
	nsl_diff_method *mdiff,*obj_mdiff; // diff_model

//	strcpy(str,get_obj_name(nsl));

        if (OBJ != NULL && (cmd_obj = (nsl_cmd_type*) 
	   SYSTEM->get_cmd_system()->get_m_children_list()
		->get_mi_by_type("neuron")) != NULL	
	   && (list = cmd_obj->get_data_list()) != NULL)
        {
           if ((data = (nsl_layer*) list->get_by_name("thresh")) != NULL &&
		data->get_flag() == 1)
	   {
		data->set_flag(0);
                sval = ((nsl_str_data*) data)->get_value();
                stype = OBJ->get_abstract_type();
		sprintf(lib_type,"%s_%s",sval,stype);
		nsl_list* tlist = SYSTEM->get_thresh_lib_list();
		if (tlist != NULL)
		{
		  lib = (nsl_library*) tlist->get_by_type(lib_type); 
		  if (lib != NULL)
		  {
		// instantiates new lib copy, new pars according to layer size
			obj_lib = lib->make_copy((nsl_layer*) OBJ); // get copy
			((nsl_neuron_layer*) OBJ)->set_thresh_library(
				(nsl_thresh_library*) obj_lib);
			nsl_ptr_vector* ptr = obj_lib->get_par_vector();
			if (ptr != NULL)
				ptr->read(nsl.get_buffer());
			else
				cmd_error("cmd_neuron_layer: NULL lib par");
		  }
		  else
			cmd_error("cmd_neuron_layer: BAD thresh lib: ",sval);
		}
		else
			cmd_error("cmd_neuron_layer: NULL thresh lib list");
	   }
//         else
//                cmd_error("cmd_neuron_layer: NULL 'thresh' obj");

           if ((data = (nsl_layer*) list->get_by_name("diff_model")) != NULL &&
		data->get_flag() == 1)
	   {
		data->set_flag(0);
                sval = ((nsl_str_data*) data)->get_value();
//                stype = OBJ->get_abstract_type();
//		sprintf(lib_type,"%s_%s",sval,stype);
		nsl_list* tlist = SYSTEM->get_diff_model_list();
		if (tlist != NULL)
		{
		  diff = (nsl_diff*) tlist->get_by_type(sval); // lib_type
		  if (diff != NULL)
		  {
			// instantiates new diff model copy
			obj_diff = diff->make_copy(); 
			((nsl_neuron_layer*) OBJ)->set_diff_model(
				(nsl_diff*) obj_diff);
		  }
		  else
			cmd_error("cmd_neuron_layer: BAD diff_model: ",sval);
		}
		else
			cmd_error("cmd_neuron_layer: NULL diff_model list");
	   }

           if ((data = (nsl_layer*) list->get_by_name("diff_method")) != NULL &&
		data->get_flag() == 1)
	   {
		data->set_flag(0);
                sval = ((nsl_str_data*) data)->get_value();
                stype = OBJ->get_abstract_type();
		sprintf(lib_type,"%s_%s",sval,stype);
		nsl_list* tlist = SYSTEM->get_diff_method_list();
		if (tlist != NULL)
		{
		  mdiff = (nsl_diff_method*) tlist->get_by_type(lib_type); 
		  if (mdiff != NULL)
		  {
			// instantiates new diff method copy
			obj_mdiff = mdiff->make_copy();
			((nsl_neuron_layer*) OBJ)->set_diff_method(
				(nsl_diff_method*) obj_mdiff);
		  }
		  else
			cmd_error("cmd_neuron_layer: BAD diff_method: ",sval);
		}
		else
			cmd_error("cmd_neuron_layer: NULL diff_method list");
	   }

           if ((data = (nsl_layer*) list->get_by_name("diff_delta")) != NULL &&
		data->get_flag() == 1)
	   {
		data->set_flag(0);
                fval = ((nsl_num_data*) data)->get_value();
		((nsl_neuron_layer*) OBJ)->set_delta(fval);
 	   }
//           else
//                cmd_error("cmd_neuron_layer: NULL 'diff_delta' obj");
        
           if ((data = (nsl_layer*) list->get_by_name("end_time")) != NULL &&
		data->get_flag() == 1)
	   {
		data->set_flag(0);
                fval = ((nsl_num_data*) data)->get_value();
		((nsl_neuron_layer*) OBJ)->set_end_time(fval);
 	   }
//           else
//                cmd_error("cmd_neuron_layer: NULL 'end_time' obj");

           if ((data = (nsl_layer*) list->get_by_name("tm")) != NULL &&
		data->get_flag() == 1)
	   {
		data->set_flag(0);
                fval = ((nsl_num_data*) data)->get_value();
		((nsl_neuron_layer*) OBJ)->set_tm(fval);
 	   }
//           else
//                cmd_error("cmd_neuron_layer: NULL 'tm' obj");

           if ((data = (nsl_layer*) list->get_by_name("h")) != NULL &&
		data->get_flag() == 1)
	   {
		data->set_flag(0);
                fval = ((nsl_num_data*) data)->get_value();
		((nsl_neuron_layer*) OBJ)->set_h(fval);
 	   }
//           else
//                cmd_error("cmd_neuron_layer: NULL 'h' obj");

           if ((data = (nsl_layer*) list->get_by_name("inp")) != NULL &&
		data->get_flag() == 1)
	   {
		data->set_flag(0);
                fval = ((nsl_num_data*) data)->get_value();
		((nsl_neuron_layer*) OBJ)->set_inp(fval);
 	   }
//           else
//                cmd_error("cmd_neuron_layer: NULL 'inp' obj");

           if ((data = (nsl_layer*) list->get_by_name("inf")) != NULL &&
		data->get_flag() == 1)
	   {
		data->set_flag(0);
                fval = ((nsl_num_data*) data)->get_value();
		((nsl_neuron_layer*) OBJ)->set_inf(fval);
 	   }
//           else
//                cmd_error("cmd_neuron_layer: NULL 'inf' obj");
        }
        else
                cmd_error("cmd_neuron_layer: NULL OBJ");

	return 1;
}

// local print

int nsl_cmd_neuron_layer::print_cmd_neuron_layer(ostream& out) const
{
	print_cmd_type(out);
	i_children_list->print(out);
	return 1;
}
int nsl_cmd_neuron_layer::print(ostream& out) const // virtual
{
	print_cmd_neuron_layer(out);
	return 1;
}

