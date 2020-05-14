//
//	nsl_neural_network.C
//
#include "nsl_neuron.h"
#include "nsl_neural_network.h"
#include "nsl_layer.h"
#include "nsl_model.h"
#include "nsl_base_list.h"

nsl_neural_network::nsl_neural_network(const char* str,int fg) : 
	nsl_model(str,NULL,fg) //todo: changed, no such constructor -bn7
{
	set_type("neural_network");
}
nsl_neural_network::~nsl_neural_network()
{
}

int nsl_neural_network::run()
{
	nsl_model::run(); 	// run modules

	nsl_layer* layer;

/*	if (layer_list != NULL)
	{
	   layer_list->wind_up(); 
	   while ((layer = (nsl_layer*)layer_list->next()) != NULL)
	   {
		//if (CURRENT_TIME == 0) //not defined -bn7
	//		layer->init();
	//	else
	//		layer->run();
	   }
	}
	else */
	   cmd_out("NULL layer_list");

	return 1;
}
