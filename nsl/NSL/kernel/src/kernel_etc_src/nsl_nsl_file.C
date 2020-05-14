/* SCCS  %W%---%E%--%U% */
/**************************************************************/
/*                                                            */
/*                       nsl_nsl_file.C 		      */
/*                                                            */
/**************************************************************/


#include "nsl_stream.h"
#include "nsl_kernel.h"
#include "nsl_nsl_file.h"

typedef nsl_base_list nsl_list;

extern void cmd_out(const char *);
extern void cmd_error(const char *, const char *);

nsl_nsl_file::nsl_nsl_file(const char* fullstr) : nsl_file(fullstr,"nsl")
{
 	init_nsl_file();
}

nsl_nsl_file::nsl_nsl_file(const int fg) : nsl_file(fg)
{
	set_type("nsl_file");
	SYSTEM->add_file_type(this);
}
nsl_nsl_file::~nsl_nsl_file()
{
}
int nsl_nsl_file::init_nsl_file()
{
 	set_type("nsl_file");

	return 1;
}
nsl_file* nsl_nsl_file::create(const char* str)
{
	return new nsl_nsl_file(str);
}
int nsl_nsl_file::read_file()
{
	status = 1;

	if (!file)
	{
		cmd_error("Cannot read file: ",fullname);
		return -1;
	}

	nsl_interpreter* nsl = SYSTEM->get_interpreter();

	int file_fg = 1;

//      while (file && file->peek() != EOF && status == 1) // read all file
        if (file && file->peek() != EOF)		// read one line
	{
	    if (nsl != NULL)
	    {
		nsl->set_input_type(NSL_FIN);
		nsl->set_input_file(this); // (istream*)
		(*nsl) << (*file);

		status = nsl->get_status();
	    }
	    else
	    {
		cmd_error("NULL NSL INTERPRETER");
		file_fg = 0;
	    }

	}

//	nsl->set_input_type(0);

	if (status == -1)
		cmd_error("Unknown Model");

	return status;
}

// print

int nsl_nsl_file::print(ostream& out) const
{
	print_nsl_file(out);

	return 1;
}
int nsl_nsl_file::print_nsl_file(ostream& out) const
{
	print_file(out);

	return 1;
}
int nsl_nsl_file::print_status(ostream& out) const
{
	print_nsl_file_status(out);

	return 1;
}
int nsl_nsl_file::print_nsl_file_status(ostream& out) const
{
	print_file_status(out);

	return 1;
}

// read, write buf

int nsl_nsl_file::write_nsl_file(nsl_buffer& buf)
{
 	if (file == NULL)
	{
		cmd_error("nsl_nsl_file: NULL fstream");
		return 1;
	}

 	buf << *file; // nsl formatted write from file into buf

	return 1;
}
int nsl_nsl_file::write(nsl_buffer& buf)
{
	write_nsl_file(buf);
	return 1;
}
int nsl_nsl_file::read_nsl_file(nsl_buffer& buf)
{
 	if (file == NULL)
	{
		cmd_error("nsl_nsl_file: NULL fstream");
		return 1;
	}

 	buf >> *file; // nsl formatted read to file from buf

	return 1;
}
int nsl_nsl_file::read(nsl_buffer& buf)
{
	read_nsl_file(buf);
	return 1;
}

// read, write model

int nsl_nsl_file::write_nsl_file(nsl_model* model)
{
    if (file != NULL)
		SYSTEM->write_model(file,model);
	else
		cmd_out("nsl_nsl_file::write_nsl_file: Null file");

	return 1;
}
int nsl_nsl_file::write(nsl_model* model)
{
	write_nsl_file(model);
	return 1;
}
int nsl_nsl_file::read_nsl_file(nsl_model* model)
{
	nsl_list* list;

	if ((list = model->get_data_list()) != NULL)
	{
            list->wind_up();
            nsl_layer* layer;
            while (layer = (nsl_layer*) list->next())
	    { 
		if (layer->get_file_able_fg() == 0)
			continue;

//		file >> layer;
	    }
	}
	else
	{
		cmd_out("Null model layer list read");
	}

	return 1;
}
int nsl_nsl_file::read(nsl_model* model)
{
	read_nsl_file(model);
	return 1;
}
