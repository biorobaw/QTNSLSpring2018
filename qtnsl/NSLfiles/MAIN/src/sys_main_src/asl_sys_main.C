/* SCCS  @(#)nsl_sys_main.C	1.1---95/08/13--21:10:41 */
/**************************************************************/
/*                                                            */
/*                       asl_sys_main.C                       */
/*                                                            */
/**************************************************************/

# include "nsl_kernel.h"
# include "asl_all_rts_include.h"
#include "../incl/aslcom_seq.h"

// global data definition

AslSystem *asl;
AslSystem *ASL_SYSTEM;
// AslIPCManager *comm;
AslIPCManager *AslCom;

AslInOut aslio;
AslErr   aslerr;
AslTerminator aslend;

int    asl_debug = 0;			// If <> 0, then output debug info

// -----------------
void ASLinit(int argc, char **argv)
{
	asl = new AslSystem(argc, argv);
	ASL_SYSTEM = asl;

	if (ASL_SYSTEM != NULL && NSL_SYSTEM != NULL)
		NSL_SYSTEM->set_asl_system(ASL_SYSTEM);
	else
		cmd_out("ASLinit: Null SYSTEM");
}
int ASLsys()
{
	if (ASL_SYSTEM != NULL)
		((AslSystem*) ASL_SYSTEM)->AslDoListInitSys();
	else
		cmd_out("ASLsys: Null ASL_SYSTEM");

	return 1;
}

int ASLrun(int time_step)
{
	int fg = 1;

	if (ASL_SYSTEM != NULL)
	{
		if (time_step == 0)
			fg = ((AslSystem*) ASL_SYSTEM)->AslDoListInitRun();
		else if (time_step == -1)
			fg = ((AslSystem*) ASL_SYSTEM)->AslDoListEndRun();
		else
			fg = ((AslSystem*) ASL_SYSTEM)->AslDoListSimRun();
	}
	else
		cmd_out("ASLrun: Null ASL_SYSTEM");

	if (asl_debug)
		aslio << "ASL INIT: Asl System has finished"<<aslend;

	return fg;
}

int ASLtrain(int time_step)
{
	int fg = 1;

	if (ASL_SYSTEM != NULL)
	{
		if (time_step == 0)
			fg = ((AslSystem*) ASL_SYSTEM)->AslDoListInitTrain();
		else if (time_step == -1)
			fg = ((AslSystem*) ASL_SYSTEM)->AslDoListEndTrain();
		else
			fg = ((AslSystem*) ASL_SYSTEM)->AslDoListSimTrain();
	}
	else
		cmd_out("ASLtrain: Null ASL_SYSTEM");

	if (asl_debug)
		aslio << "ASL INIT: Asl System has finished"<<aslend;

	return fg;
}
int ASLendtrain()
{
	int fg = 1;

	if (ASL_SYSTEM != NULL)
	{
		fg = ((AslSystem*) ASL_SYSTEM)->AslDoAllEndTrain();
	}
	else
		cmd_out("ASLendtrain: Null ASL_SYSTEM");

	if (asl_debug)
		aslio << "ASL INIT: Asl System has finished"<<aslend;

	return fg;
}
int ASLconnect()
{
	int fg = 1;

	if (ASL_SYSTEM != NULL)
		fg = ((AslSystem*) ASL_SYSTEM)->AslDoListMakeConn();
	else
		cmd_out("ASLconnect: Null ASL_SYSTEM");

	return fg;
}
/*
void AslTclGraphInit(aslArgument arg)
{
	char *args, buf[20];

	Tcl_FindExecutable(arg.argv[0]);
	interp = Tcl_CreateInterp();

// Make command-line arguments available in the Tcl variables "argc" and "argv".

	args = Tcl_Merge(arg.argc-1, arg.argv+1);

	Tcl_SetVar(interp, "argv", args, TCL_GLOBAL_ONLY);
	ckfree(args);
	sprintf(buf, "%d", arg.argc-1);
	Tcl_SetVar(interp, "argc", buf, TCL_GLOBAL_ONLY);
	Tcl_SetVar(interp, "argv0", arg.argv[0], TCL_GLOBAL_ONLY);

	if (Tcl_AppInit(interp) != TCL_OK) {
		aslerr<<"ASL SYSTEM ERROR: Graphics initialization failed"<<aslend;
	}

	Tcl_SourceRCFile(interp);
	Tcl_ResetResult(interp);

//AW98	NSL_TK_FLUSH = 1;	//0- no display graphics 1- update graphics
}
void AslTclGeneralScheduler(AslSystem* aslsys)
{
	while (Tk_GetNumMainWindows() > 0) {
        	Tcl_DoOneEvent(TCL_DONT_WAIT); // TCL_DONT_WAIT
        	aslsys->AslDoListStep();
 	}
}
*/
