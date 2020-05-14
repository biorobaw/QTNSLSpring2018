/* SCCS  @(#)nsl_handlers.c	1.1---95/08/13--20:42:51 */
/**************************************************************/
/*                                                            */
/*                       nsl_handlers.c                       */
/*                                                            */
/**************************************************************/

# include <signal.h> /* file: /usr/include/signal.h */

extern int BREAKFG;

/* 
#ifdef __cplusplus
extern "C" SIG_PF signal(int, SIG_PF);
#else
extern void (*signal(int, void (*)(int)))(int);
#endif
*/
/*
int nslStop()     // stop processing
{
        BREAKFG = 1;
}
*/       //no such defined signal SIGURG -bn7

int NSLinterrupt_handler()     /* HANDLER traps interrupt '^C' */
{
        BREAKFG = 1;
#ifndef NSL_PC
      	signal(SIGINT,NSLinterrupt_handler); /* SIGINT '^C' */
#endif

	return 1;
}
int NSLurgent_handler()     /* HANDLER traps interrupt 'L1' (STOP) */
{
        BREAKFG = 1;
#ifndef NSL_PC
      	//signal(SIGURG,NSLurgent_handler); /* SIGURG 'L1' (STOP) */
#endif

	return 1;
}

int NSLinit_interrupt_handler()
{
#ifndef NSL_PC
      	signal(SIGINT,NSLinterrupt_handler);
      	//signal(SIGURG,NSLurgent_handler);
#endif

	return 1;
}
