
//  ASL IPC MANAGER LIBRARY 
//
//  ASL (Abstract Schema Language) System Comunication Kernel
//
//
//
//  FILE NAME   : aslcom_seq.c
//  MODULE TYPE : ASL Comunication System File
//  STATUS      : In development 
//  PURPOSE     : Comunication between processes
//  
//
//  Instituto Tecnologico Autonomo de Mexico 
//  (c) Copyright 1995  
//
//
//
//  HISTORY : Version (Date-Name) Modification, description.  
//
//            1.0 (Oct 28, 1995 - Claudia Calderas & Salvador Marmol), 
//            Start of development for distributed execution.
//
//            1.1 (Nov 11, 1997 - Oscar Peguero), 
//            Addition of members in AslIPCManager class.
//
//            1.2 (Feb 4, 1998 - Oscar Peguero), 
//            Simple version for PC with double buffering (no threads).

   
#include "asl_all_rts_include.h"  

//temp, not declared anywhere else -bn7
/*
char *tempbuf[] = {"temporary" , "buffer"};
AslTerminator aslend = AslTerminator();
int asl_debug;
AslErr aslerr = AslErr();
AslInOut aslio = AslInOut();
AslIPCManager *AslCom = new AslIPCManager();
AslSystem *asl = new AslSystem(1,tempbuf); //this is here because nowhere else was it instantiated, what to do with args? -bn7
*/
extern AslTerminator aslend;
extern int asl_debug;
extern AslErr aslerr;
extern AslInOut aslio;
extern AslIPCManager *AslCom;
extern AslSystem *asl;


// AslBuffer methods
// AslIPCManager methods

AslIPCManager::AslIPCManager(void)
{
	AslIPCInitialize(0);
}

AslIPCManager::~AslIPCManager(void)
{	

}

void AslIPCManager::AslIPCInitialize(int port)
{	
	if (asl_debug)
		aslio<<"ASL IPC MANAGER: Creating session layer at "<<0
		     <<" port"<<aslend;

	AslCom	  = this;
	msgCount  = 1;
	bidCount  = 1;
	
	AslGetEnvironment();    
	 
	systemType = ASL_SIGNAL;
}


int AslIPCManager::AslGetPort(void)
{
	return 0;
}

char *AslIPCManager::AslGetHost(void)
{
	return "local host";
}


void AslIPCManager::AslScheduler(void)
{
//	int res, timeout = 0;

	if(asl_debug)
		aslio<<"ASL IPC MANAGER: In the receiver thread"<<aslend;

//	while(una vuelta a todos los puertos) 
//	{
//		AslCom->recvThread(NULL);
//	}
}

char* AslIPCManager::AslGetAslPath(void)
{
	return aslPath;
}

AslPort *AslIPCManager::AslGetIOPort(int bid)
{
	AslPort *tempNode;

	if (asl_debug)
		aslio<<"ASL IPC MANAGER: Getting Port "<<bid<<" as actual"<<aslend;
	
	PortList.startOnTop();
	while ((tempNode=PortList.getActual())!=NULL && (tempNode->AslGetBid()!=bid))
		PortList.goNext();

	if (tempNode==NULL)
	{
		aslerr<<"ASL IPC MANAGER ERROR: Can't get Port "<<bid<<aslend;
		return NULL;
	}

	return tempNode;
}
/*
int AslIPCManager::AslFilterBuf(int id, char *msg)		//char *
{	
	AslBuffer *buf = AslGetBuffer(id);
	
	if (buf==NULL)
	{
		aslerr<<"ASL IPC MANAGER ERROR: Can't find the buffer with id "<<id<<aslend;
		return FALSE;
	}
	
	short int type     = buf->AslGetBufType();
	
	if (asl_debug)
		aslio<<"ASL IPC MANAGER: The buffer type is ["<<type<<"]"<<aslend;
	
	if (buf->AslIsAnInputBuffer())
	{
		if (buf->AslGetNumberOfElements()==0)
		{
			aslerr<<"ASL IPC MANAGER ERROR: Can't get in an empty buffer"<<aslend;
			return FALSE;
		}

		AslBufData *bd=buf->AslGetBufData();
		memcpy(msg, bd->data, bd->len);
	}
	else
		buf->AslSetBufData(msg, strlen(msg));

	return 1;
}

int AslIPCManager::AslFilterBuf(int id, char *msg, int len)
{	
	AslBuffer *buf	 = AslGetBuffer(id);
	
	if (buf==NULL)
	{
		aslerr<<"ASL IPC MANAGER ERROR: Can't find the buffer with id "<<id<<aslend;
		return FALSE;
	}
	
	short int type     = buf->AslGetBufType();

	if (asl_debug)
		aslio<<"ASL IPC MANAGER: The buffer type is ["<<type<<"]"<<aslend;

	if (buf->AslIsAnInputBuffer())
	{
		if (buf->AslGetNumberOfElements()==0)
		{
			aslerr<<"ASL IPC MANAGER ERROR: Can't get in an empty buffer"<<aslend;
			return FALSE;
		}

		AslBufData *bd=buf->AslGetBufData();
		memcpy(msg, bd->data, bd->len);
		aslio << "@@@@@@@@@@@@@@@@@@@@@@@@ " << msg[5] << aslend;
	}
	else
		buf->AslSetBufData(msg, len);
	
	return 1;
}
*/
void AslIPCManager::AslGetEnvironment(void)
{
	aslPath[0]='\0';
	consoleName[0]='\0';
	if (getenv("ASL_HOME")!=NULL)
		strcpy(aslPath, getenv("ASL_HOME"));

	if (getenv("ASL_CONSOLE")!=NULL)
		strcpy(consoleName, getenv("ASL_CONSOLE"));

	if (aslPath[0]=='\0')
		if (getenv("HOME")!=NULL)
			strcpy(aslPath, getenv("HOME"));
	
	if (consoleName[0]=='\0')
		strcpy(consoleName, AslGetHost()); 

	if (asl_debug)
		aslio<<"ASL IPC MANAGER: Binary path ["<<aslPath
		     <<"] Console ["<<consoleName<<"]"<<aslend;
}

/* int AslIPCManager::AslMkBuf(int op, short int type)
{
	if (asl_debug)
		aslio<<"ASL IPC MANAGER: Making buffer with bid ["<<bidCount<<"]"<<aslend;
	
	AslBuffer *tempNode = new AslBuffer(bidCount, op, type);	
	
	bufList.insert(tempNode);
	bidCount++;

	return tempNode->AslGetBufId();
}	*/
// ------------------------------------
int AslIPCManager::AslIncPortID(void)
{
	if (asl_debug)
		aslio<<"ASL IPC MANAGER: Making Port ID with ["<<bidCount<<"]"<<aslend;
	
	int temp=bidCount;
	bidCount++;
	
	return temp;	
}
// ------------------------------------
/* int AslIPCManager::AslDelBuf(int bid)
{
	int res=1;
	
	if (asl_debug)
		aslio<<"ASL IPC MANAGER: Deleting buffer "<<bid<<aslend;
	
	AslBuffer *tempNode;
	bufList.startOnTop();
	while ((tempNode=bufList.getActual())!=NULL && (tempNode->AslGetBufId()!=bid))
		bufList.goNext();
			
	if (tempNode!=NULL)
	{
		tempNode=bufList.removeThis();
		delete tempNode;
	}
	else
	{
		aslerr<<"ASL IPC MANAGER ERROR: Can't delete buf "<<bid<<aslend;
		res=0;
	}	

	return res;
}	*/

/* int AslIPCManager::AslRecv(int bid)
{
	AslPort  *port     = AslGetIOPort(bid);

	if (port==NULL)
	{
		aslerr<<"ASL IPC MANAGER ERROR: Can't find the port with id "<<bid<<aslend;
		return -1;
	}

//	if (!port->AslIsAnInputBuffer())
	{
		aslerr<<"ASL IPC MANAGER ERROR: This port is not an input port"<<aslend;
		return -1;
	}
	
	if (asl_debug)
		aslio<<"ASL IPC MANAGER: Receiving Data"<<aslend;

	return 1;
}
*/
// ------------------------------------ 
int AslIPCManager::AslSend(int sourceBid)
{
	int res=1;
	
	AslPort  *port = AslGetIOPort(sourceBid);

	if (port==NULL)
	{
		aslerr<<"ASL IPC MANAGER ERROR: Can't find the Port with id "<<sourceBid<<aslend;
		return -1;
	}

/*AW98	if (port->AslGetNumberOfElements()==0)
	{
		aslerr<<"ASL IPC MANAGER ERROR: There is nothing in the port to send"<<aslend;
		return -1;
	}
*/	
//	AslBufData *temp = buf->AslGetBufData();
	
	AslPort *bufSend;
	
	AslPortRelations *connTemp;	
	
	if (port->AslIsAnOutputBuffer())
	{	
	    port->AslPutConnectionListAtBegining();
	    while ((connTemp=port->AslGetConnection())!=NULL)
	    {
		if (asl_debug)
			aslio<<"ASL IPC MANAGER: Sending local Data"<<aslend;
			
		bufSend = AslGetIOPort(connTemp->bid);
		
		if (bufSend!=NULL)
			bufSend->AslCopyData(port);	// !!!!!!!
		
		port->AslGoToNextConnection();
	    }

	    port->AslPutRelabelListAtBegining();
	    while ((connTemp=port->AslGetRelabel())!=NULL)
	    {
		if (asl_debug)
			aslio<<"ASL IPC MANAGER: Sending local Data"<<aslend;
			
		bufSend = AslGetIOPort(connTemp->bid);
		
		if (bufSend!=NULL)
			bufSend->AslCopyData(port);	// !!!!!!!
		
		port->AslGoToNextRelabel();
	    }
	}
	else {	
	    port->AslPutRelabelListAtBegining();
	    while ((connTemp=port->AslGetRelabel())!=NULL)
	    {
		if (asl_debug)
			aslio<<"ASL IPC MANAGER: Sending local Data"<<aslend;
			
		bufSend = AslGetIOPort(connTemp->bid);
		
		if (bufSend!=NULL)
			bufSend->AslCopyData(port);	// !!!!!!!
		
		port->AslGoToNextRelabel();
	    }
	}

	return 1;
}
// ------------------------------------
int AslIPCManager::AslConnect(AslPort *src, AslPort *dst)
{
	if (src==NULL)
	{
		aslerr<<"ASL IPC MANAGER ERROR: Can't find the Port with id [~] "<<aslend;
		return -1;
	}
	
	if (!src->AslIsAnOutputBuffer() || !dst->AslIsAnInputBuffer())
	{
		aslerr<<"ASL IPC MANAGER ERROR: This port is not an output port"<<aslend;
		return -1;
	}

	return src->AslAddConnection(dst->AslGetBid());
}

int AslIPCManager::AslDisconnect(AslPort* src, AslPort* dst)
{
	if (src==NULL)
	{
		aslerr<<"ASL IPC MANAGER ERROR: Can't find the Port with id [~]"<<aslend;
		return -1;
	}

/*	if (!src->AslIsAnOutputBuffer())
	{
		aslerr<<"ASL IPC MANAGER ERROR: This port is not an output port"<<aslend;
		return -1;
	}
*/	
	return src->AslDeleteConnection(dst->AslGetBid());
}

int AslIPCManager::AslRelabel(AslPort *src, AslPort *dst)
{
	if (src==NULL)
	{
		aslerr<<"ASL IPC MANAGER ERROR: Can't find the Port with id [~] "<<aslend;
		return -1;
	}
	
	if (src->AslGetType() != src->AslGetType())
	{
		aslerr<<"ASL IPC MANAGER ERROR: ports are of different type"<<aslend;
		return -1;
	}

	return src->AslAddRelabel(dst->AslGetBid());
}

int AslIPCManager::AslDelabel(AslPort *src, AslPort *dst)
{
	if (src==NULL)
	{
		aslerr<<"ASL IPC MANAGER ERROR: Can't find the Port with id [~]"<<aslend;
		return -1;
	}

/*	if (!src->AslIsAnOutputBuffer())
	{
		aslerr<<"ASL IPC MANAGER ERROR: This port is not an output port"<<aslend;
		return -1;
	}
*/	
	return src->AslDeleteRelabel(dst->AslGetBid());
}
