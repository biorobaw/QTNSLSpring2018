/* 
 * tcltkAppInit.c --
 *
 *	Provides a default version of the Tcl_AppInit procedure.
 *
 * Copyright (c) 1993 The Regents of the University of California.
 * All rights reserved.
 *
 * Permission is hereby granted, without written agreement and without
 * license or royalty fees, to use, copy, modify, and distribute this
 * software and its documentation for any purpose, provided that the
 * above copyright notice and the following two paragraphs appear in
 * all copies of this software.
 * 
 * IN NO EVENT SHALL THE UNIVERSITY OF CALIFORNIA BE LIABLE TO ANY PARTY FOR
 * DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES ARISING OUT
 * OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN IF THE UNIVERSITY OF
 * CALIFORNIA HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * THE UNIVERSITY OF CALIFORNIA SPECIFICALLY DISCLAIMS ANY WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS FOR A PARTICULAR PURPOSE.  THE SOFTWARE PROVIDED HEREUNDER IS
 * ON AN "AS IS" BASIS, AND THE UNIVERSITY OF CALIFORNIA HAS NO OBLIGATION TO
 * PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.
 */

#ifndef lint
static char rcsid[] = "$Header: /user6/ouster/tcl/RCS/tclAppInit.c,v 1.6 93/08/26 14:34:55 ouster Exp $ SPRITE (Berkeley)";
#endif /* not lint */

#ifdef NSL_TK
	#include "tk.h"
#else
	//#include "tcl.h" //TODO: uncomment when tcl is available -bn7
#endif

#include "../../../MAIN/src/sys_main_src/nsl_all_kernel_include.h"
#ifndef __ASL_PVM_H
	//#include "/opt/local/pvm3/include/pvm3.h" here- bn7
#endif

//#include "/home/asl/NSL3.0/ASL/rts/incl/asl.h" //here -bn7

extern int PROC_N;
extern int *children_tid;
//extern int CTRL;

//Tcl_Interp* NSL_TCL_INTERP;

/*
 *----------------------------------------------------------------------
 *
 * tcltkAppInit --
 *
 *	This procedure performs application-specific initialization.
 *	Most applications, especially those that incorporate additional
 *	packages, will have their own version of this procedure.
 *
 * Results:
 *	Returns a standard Tcl completion code, and leaves an error
 *	message in interp->result if an error occurs.
 *
 * Side effects:
 *	Depends on the startup script.
 *
 *----------------------------------------------------------------------
 */


int NslLoad(char* str)
{
	int code = 0;

/*	if (NSL_TCL_INTERP != NULL)
		code = Tcl_EvalFile(NSL_TCL_INTERP,str);
	else
		cmd_out("NSL_TCL_INTERP is NULL");*/

	return code;
}

/*int NslProc(ClientData clientData, Tcl_Interp* interp,
	int argc, char* argv[])
{
#ifdef CONSOLE
	char msg[256];
	strcpy(msg,""); // para limpiar de basura
	
	Tcl_Eval(interp, "update");	
#endif
	for (int i = 1; i < argc; i++)
	{
		NSL << argv[i];
#ifdef CONSOLE
		strcat(msg, argv[i]);
		strcat(msg, " ");
#endif
	}

#ifdef CONSOLE
	cout << "$$$$$$ MANDARE LOS COMANDOS A CLIENTES:" << msg << endl;
	pvm_initsend(PvmDataDefault);
	pvm_pkstr(msg);
	pvm_mcast(children_tid, PROC_N, CTRL);
	
	for (i=0; i<PROC_N; i++) {
		pvm_recv(children_tid[i], ACK);
		cout << " ##### YA RECIBIO COMANDO ####" << endl;
		cout.flush();
	}
	
	Tcl_Eval(interp, "update");		
	
	NSL.step();
	
	Tcl_Eval(interp, "update");	
#endif

//	return TCL_OK; */
//}
/*
int Tcl_AppInit(Tcl_Interp *interp)	/* Interpreter for application. */
//{
#ifdef NSL_TK
	Tk_Window tk_main = Tk_MainWindow(interp);
#endif
    /*
     * Call the init procedures for included packages.  Each call should
     * look like this:
     *
     * if (Mod_Init(interp) == TCL_ERROR) {
     *     return TCL_ERROR;
     * }
     *
     * where "Mod" is the name of the module.
     */
     
  //  if (Tcl_Init(interp) == TCL_ERROR) {
	//return TCL_ERROR;
   // }

#ifdef NSL_TK
    if (Tk_Init(interp) == TCL_ERROR) {
	return TCL_ERROR;
    }
#endif

// global variable assignment


    /*
     * Call Tcl_CreateCommand for application-specific commands, if
     * they weren't already created by the init procedures called above.
     */

	//Tcl_CreateCommand(interp, "nsl", NslProc, (ClientData) NULL,
	//	(Tcl_CmdDeleteProc *) NULL);

    /*
     * Specify a user-specific startup file to invoke if the application
     * is run interactively.  Typically the startup file is "~/.apprc"
     * where "app" is the name of the application.  If this line is deleted
     * then no user-specific startup file will be run under any conditions.
     */
	//NSL_TCL_INTERP = interp;

  // 	Tcl_Eval(interp,"set tcl_precision 3");
   
#ifdef NSL_TK
// read in Tk functions
	nsl_string str;
	
	strcpy(str,"source $env(NSL_DIR)/TK/grid.tk");
	printf("// Reading: %s\n",str);
	Tcl_Eval(interp,str);

#endif   

//	 tcl_RcFileName = "~/.tclshrc";
//return 0; //TCL_OK is undefined -bn7
   // return TCL_OK;
//}

void ASLrefresh(void)
{
#ifdef CONSOLE	//NSL_TK
//	cout << "!!!-!-!-!-!&&&&&.@.@.@>@>>@>@>@>@.@.@> GRAFICANDO (SOY CONSOLA)" << endl;
	Tcl_Eval(NSL_TCL_INTERP, "update");	
#endif
}

