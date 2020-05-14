/* SCCS  @(#)nsl_cmd_exec.C	1.1---95/10/13--16:35:06 */
/**************************************************************/
/*                                                            */
/*                   nsl_cmd_exec.C                           */
/*                                                            */
/**************************************************************/

#include "nsl_kernel.h"
#include "nsl_file.h"

nsl_cmd_exec::nsl_cmd_exec(const char* str) : nsl_public(str)
{
	dir_list = new nsl_list("help");
}
nsl_cmd_exec::nsl_cmd_exec()
{
}

nsl_cmd_exec::~nsl_cmd_exec()
{
}
int nsl_cmd_exec::exec(nsl_interpreter&)
{
	return 2;
}
int nsl_cmd_exec::help(const char*)
{
	return 2;
}
int nsl_cmd_exec::help_file(const char* str)
{
	nsl_string fname;
  	nsl_file* file;
	nsl_str_data* data;
	nsl_string nsl_dir;
	char* stmp;

	if (dir_list != NULL)
	{
	    if ((stmp = SYSTEM->get_nsl_dir()) != NULL)
		strcpy(nsl_dir,stmp);
	    else
		strcpy(nsl_dir,".");
	    dir_list->wind_up();
	    while ((data = (nsl_str_data*) dir_list->next()) != NULL)
	    {
 		const char* nsl_doc_dir = data->get_value();
 		sprintf(fname,"%s/%s/nsl_%s",nsl_dir,nsl_doc_dir,str);

		if ((file = new nsl_file(fname,"doc")) != 0)
		{
		    	file->load_file(NSL_TEXT,NSL_OFF);
//			delete file;
		}
 		else 
 			cmd_error("nsl_cmd_exec_help: Cannot open help file");
 	    }
	}
	else
		cmd_error("NULL list");

	return 1;
}
int nsl_cmd_exec::add_help_file(const char* str,const char* dir)
{
   	nsl_str_data* data;

 	if (str != NULL && dir != NULL && dir_list != NULL &&
		(data = new nsl_str_data(str,dir)) != NULL)
	{
 		dir_list->wind_down();
		dir_list->append(data);
	}
	else
		cmd_error("NULL list");

	return 1;
}
int nsl_cmd_exec::print_cmd_exec(ostream& out) const
{
	print_base(out);
	i_children_list->print(out);
	return 1;
}
int nsl_cmd_exec::print(ostream& out) const // virtual
{
	print_cmd_exec(out);
	return 1;
}

