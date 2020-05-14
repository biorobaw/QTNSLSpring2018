/* SCCS  @(#)xnsl_graph_manager.C	1.1---95/08/13--20:59:14 */
//////////////////////////////////////////////////////////////////////////
//
//  xnsl_graph_main.C
//             
//////////////////////////////////////////////////////////////////////////

#include "xkernel.h"
#include "nsl_kernel.h" 
 
void   xnsl_graph_init()
{
	xnsl_manager   *pxnsl_manager;
	xnsl_widget    *pxnsl_widget;
	nsl_str_data *data;
	nsl_list *list;

	if (XNSL_SYSTEM == NULL)
		XNSL_SYSTEM = new xnsl_system;

	if ((pxnsl_manager = XNSL_SYSTEM->get_xnsl_manager()) == NULL)
	{
		cmd_error("graph_manager_init: NULL manager");
		return;
	}

	///////////////////////////////////////////////////////
	// Create and add the manager to the list.
	///////////////////////////////////////////////////////

// instantiate a copy of each type of graph that can be created
/*	xnsl_graph* graph;
	graph = new xnsl_area_level_graph_data;
	graph = new xnsl_area_level_graph_vector;
	graph = new xnsl_area_level_graph_matrix;
	graph = new xnsl_spatial_graph_2_data;
	graph = new xnsl_spatial_graph_2_vector;
	graph = new xnsl_spatial_graph_2_matrix;
	graph = new xnsl_spatial_graph_3_data;
	graph = new xnsl_spatial_graph_3_vector;
	graph = new xnsl_spatial_graph_3_matrix;
	graph = new xnsl_temporal_graph_data;
	graph = new xnsl_temporal_graph_vector;
	graph = new xnsl_temporal_graph_matrix;
*/
	XNSL_SYSTEM->add_graph("area_level_graph");

	pxnsl_widget = new xnsl_area_level_graph();

	pxnsl_manager->add_manager_widget(pxnsl_widget);

	pxnsl_widget = new xnsl_area_level_graph_data();

	pxnsl_manager->add_manager_widget(pxnsl_widget);

	pxnsl_widget = new xnsl_area_level_graph_vector();

	pxnsl_manager->add_manager_widget(pxnsl_widget);

	pxnsl_widget = new xnsl_area_level_graph_matrix();

	pxnsl_manager->add_manager_widget(pxnsl_widget);

	///////////////////////////////////////////////////////

	XNSL_SYSTEM->add_graph("spatial_graph_2");

	pxnsl_widget = new xnsl_spatial_graph_2();

	pxnsl_manager->add_manager_widget(pxnsl_widget);

	pxnsl_widget = new xnsl_spatial_graph_2_data();

	pxnsl_manager->add_manager_widget(pxnsl_widget);

	pxnsl_widget = new xnsl_spatial_graph_2_vector();

	pxnsl_manager->add_manager_widget(pxnsl_widget);

	pxnsl_widget = new xnsl_spatial_graph_2_matrix();

	pxnsl_manager->add_manager_widget(pxnsl_widget);

	////////////////////////////////////////////////////////

	XNSL_SYSTEM->add_graph("spatial_graph_3");

	pxnsl_widget = new xnsl_spatial_graph_3();

	pxnsl_manager->add_manager_widget(pxnsl_widget);

	pxnsl_widget = new xnsl_spatial_graph_3_data();

	pxnsl_manager->add_manager_widget(pxnsl_widget);

	pxnsl_widget = new xnsl_spatial_graph_3_vector();

	pxnsl_manager->add_manager_widget(pxnsl_widget);

	pxnsl_widget = new xnsl_spatial_graph_3_matrix();

	pxnsl_manager->add_manager_widget(pxnsl_widget);

	////////////////////////////////////////////////////////

	XNSL_SYSTEM->add_graph("temporal_graph");

	pxnsl_widget = new xnsl_temporal_graph();

	pxnsl_manager->add_manager_widget(pxnsl_widget);

	pxnsl_widget = new xnsl_temporal_graph_data();

	pxnsl_manager->add_manager_widget(pxnsl_widget);

	pxnsl_widget = new xnsl_temporal_graph_vector();

	pxnsl_manager->add_manager_widget(pxnsl_widget);

	pxnsl_widget = new xnsl_temporal_graph_matrix();

	pxnsl_manager->add_manager_widget(pxnsl_widget);

	////////////////////////////////////////////////////////
}
// nsl_sys_module nsl_mod_graph_init("graph",xnsl_graph_init,1);

