//
//	nsl_connect_library.C
//

//# include "../../../../MAIN/src/sys_main_src/nsl_all_kernel_include.h"
//# include "../../incl/nsl_all_neuron_include.h"
#include "nsl_neuron.h"
#include "nsl_neuron_vector.h"

extern void cmd_out(const char *);


// neuron<-weight<-neuron

void NSLconnect(nsl_neuron_vector& to,nsl_neuron_vector& from,
	nsl_num_vector& weight,int sign)
{
	nsl_link_layer* link = new nsl_link_vector_vector_vector(from,to,
					weight,sign);
	nsl_site_layer* site_in;

	if ((site_in = to.get_site_in()) != NULL)
		site_in->add_link(link);
	else
		cmd_out("NSLconnect: NULL layer");
}
void NSLconnect(nsl_neuron_vector& to,nsl_neuron_vector& from,
	nsl_num_data& weight,int sign)
{
	nsl_link_layer* link = new nsl_link_vector_data_vector(from,to,
					weight,sign);
	nsl_site_layer* site_in;

	if ((site_in = to.get_site_in()) != NULL)
		site_in->add_link(link);
	else
		cmd_out("NSLconnect: NULL layer");
}

void NSLconnect(nsl_neuron_vector& to,nsl_neuron_data& from,
	nsl_num_vector& weight,int sign)
{
	nsl_link_layer* link = new nsl_link_data_vector_vector(from,to,
					weight,sign);
	nsl_site_layer* site_in;

	if ((site_in = to.get_site_in()) != NULL)
		site_in->add_link(link);
	else
		cmd_out("NSLconnect: NULL layer");
}

void NSLconnect(nsl_neuron_vector& to,nsl_neuron_data& from,
	nsl_num_data& weight,int sign)
{
	nsl_link_layer* link = new nsl_link_data_data_vector(from,to,
					weight,sign);
	nsl_site_layer* site_in;

	if ((site_in = to.get_site_in()) != NULL)
		site_in->add_link(link);
	else
		cmd_out("NSLconnect: NULL layer");
}

void NSLconnect(nsl_neuron_data& to,nsl_neuron_data& from,
	nsl_num_data& weight,int sign)
{
	nsl_link_layer* link = new nsl_link_data_data_data(from,to,weight,sign);
	nsl_site_layer* site_in;

	if ((site_in = to.get_site_in()) != NULL)
		site_in->add_link(link);
	else
		cmd_out("NSLconnect: NULL layer");
}

void NSLconnect(nsl_neuron_data& to,nsl_neuron_vector& from,
	nsl_num_vector& weight,int sign)
{
	nsl_link_layer* link = new nsl_link_vector_vector_data(from,to,
					weight,sign);
	nsl_site_layer* site_in;

	if ((site_in = to.get_site_in()) != NULL)
		site_in->add_link(link);
	else
		cmd_out("NSLconnect: NULL layer");
}

void NSLconnect(nsl_neuron_data& to,nsl_neuron_vector& from,
	nsl_num_data& weight,int sign)
{
	nsl_link_layer* link = new nsl_link_vector_data_data(from,to,
					weight,sign);
	nsl_site_layer* site_in;

	if ((site_in = to.get_site_in()) != NULL)
		site_in->add_link(link);
	else
		cmd_out("NSLconnect: NULL layer");
}

// neuron<-weight<-layer

void NSLconnect(nsl_neuron_vector& to,nsl_num_vector& from,
	nsl_num_vector& weight,int sign)
{
	nsl_link_layer* link = new 
		nsl_link_vector_data_vector(from,to,weight,sign);
	nsl_site_layer* site_in;

	if ((site_in = to.get_site_in()) != NULL)
		site_in->add_link(link);
	else
		cmd_out("NSLconnect: NULL layer");
}
void NSLconnect(nsl_neuron_vector& to,nsl_num_vector& from,
	nsl_num_data& weight,int sign)
{
	nsl_link_layer* link = new 
		nsl_link_vector_data_vector(from,to,weight,sign);
	nsl_site_layer* site_in;

	if ((site_in = to.get_site_in()) != NULL)
		site_in->add_link(link);
	else
		cmd_out("NSLconnect: NULL layer");
}

void NSLconnect(nsl_neuron_vector& to,nsl_num_data& from,
	nsl_num_vector& weight,int sign)
{
	nsl_link_layer* link = new 
		nsl_link_data_vector_vector(from,to,weight,sign);
	nsl_site_layer* site_in;

	if ((site_in = to.get_site_in()) != NULL)
		site_in->add_link(link);
	else
		cmd_out("NSLconnect: NULL layer");
}

void NSLconnect(nsl_neuron_vector& to,nsl_num_data& from,
	nsl_num_data& weight,int sign)
{
	nsl_link_layer* link = new 
		nsl_link_data_data_vector(from,to,weight,sign);
	nsl_site_layer* site_in;

	if ((site_in = to.get_site_in()) != NULL)
		site_in->add_link(link);
	else
		cmd_out("NSLconnect: NULL layer");
}

void NSLconnect(nsl_neuron_data& to,nsl_num_data& from,
	nsl_num_data& weight,int sign)
{
	nsl_link_layer* link = new nsl_link_data_data_data(from,to,weight,sign);
	nsl_site_layer* site_in;

	if ((site_in = to.get_site_in()) != NULL)
		site_in->add_link(link);
	else
		cmd_out("NSLconnect: NULL layer");
}

void NSLconnect(nsl_neuron_data& to,nsl_num_vector& from,
	nsl_num_vector& weight,int sign)
{
	nsl_link_layer* link = new 
		nsl_link_vector_vector_data(from,to,weight,sign);
	nsl_site_layer* site_in;

	if ((site_in = to.get_site_in()) != NULL)
		site_in->add_link(link);
	else
		cmd_out("NSLconnect: NULL layer");
}

void NSLconnect(nsl_neuron_data& to,nsl_num_vector& from,
	nsl_num_data& weight,int sign)
{
	nsl_link_layer* link = new 
		nsl_link_data_vector_data(from,to,weight,sign);
	nsl_site_layer* site_in;

	if ((site_in = to.get_site_in()) != NULL)
		site_in->add_link(link);
	else
		cmd_out("NSLconnect: NULL layer");
}

// neuron<-neuron

void NSLconnect(nsl_neuron_vector& to,nsl_neuron_vector& from,int sign)
{
	nsl_link_layer* link = new nsl_link_vector_vector(from,to,sign);
	nsl_site_layer* site_in;

	if ((site_in = to.get_site_in()) != NULL)
		site_in->add_link(link);
	else
		cmd_out("NSLconnect: NULL layer");
}
void NSLconnect(nsl_neuron_vector& to,nsl_neuron_data& from,int sign)
{
	nsl_link_layer* link = new nsl_link_data_vector(from,to,sign);
	nsl_site_layer* site_in;

	if ((site_in = to.get_site_in()) != NULL)
		site_in->add_link(link);
	else
		cmd_out("NSLconnect: NULL layer");
}

void NSLconnect(nsl_neuron_data& to,nsl_neuron_data& from,int sign)
{
	nsl_link_layer* link = new nsl_link_data_data(from,to,sign);
	nsl_site_layer* site_in;

	if ((site_in = to.get_site_in()) != NULL)
		site_in->add_link(link);
	else
		cmd_out("NSLconnect: NULL layer");
}

void NSLconnect(nsl_neuron_data& to,nsl_neuron_vector& from,int sign)
{
	nsl_link_layer* link = new nsl_link_vector_data(from,to,sign);
	nsl_site_layer* site_in;

	if ((site_in = to.get_site_in()) != NULL)
		site_in->add_link(link);
	else
		cmd_out("NSLconnect: NULL layer");
}

// neuron<-layer

void NSLconnect(nsl_neuron_vector& to,nsl_num_vector& from,int sign)
{
	nsl_link_layer* link = new nsl_link_vector_vector(from,to,sign);
	nsl_site_layer* site_in;

	if ((site_in = to.get_site_in()) != NULL)
		site_in->add_link(link);
	else
		cmd_out("NSLconnect: NULL layer");
}
void NSLconnect(nsl_neuron_vector& to,nsl_num_data& from,int sign)
{
	nsl_link_layer* link = new nsl_link_data_vector(from,to,sign);
	nsl_site_layer* site_in;

	if ((site_in = to.get_site_in()) != NULL)
		site_in->add_link(link);
	else
		cmd_out("NSLconnect: NULL layer");
}

void NSLconnect(nsl_neuron_data& to,nsl_num_data& from,int sign)
{
	nsl_link_layer* link = new nsl_link_data_data(from,to,sign);
	nsl_site_layer* site_in;

	if ((site_in = to.get_site_in()) != NULL)
		site_in->add_link(link);
	else
		cmd_out("NSLconnect: NULL layer");
}

void NSLconnect(nsl_neuron_data& to,nsl_num_vector& from,int sign)
{
	nsl_link_layer* link = new nsl_link_vector_data(from,to,sign);
	nsl_site_layer* site_in;

	if ((site_in = to.get_site_in()) != NULL)
		site_in->add_link(link);
	else
		cmd_out("NSLconnect: NULL layer");
}



