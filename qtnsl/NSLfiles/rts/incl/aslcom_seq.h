
//  ASL COMMUNICATION LIBRARY 
//
//  ASL (Abstract Schema Language) System Comunication Kernel
//
//
//
//  FILE NAME   : aslcom_seq.h
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
//            0.5 (Oct 28, 1995 - Claudia Calderas & Salvador Marmol), 
//            Start of development for distributed execution.
//
//            1.0 (Aug 8, 1996 - Claudia Calderas & Salvador Marmol), 
//            Change of buffering mechanism.
//
//            1.1 (Nov 11, 1997 - Oscar Peguero), 
//            Addition of members in AslIPCManager class.
//
//            1.2 (Ene 29, 1998 - Oscar Peguero), 
//            Simple version for PC with double buffering (no threads).


#ifndef __ASLCOM_H	// !!!!!!! Verificar si == ASLCOM_SEQ_H !!!
#define __ASLCOM_H

// Classes for the session layer

class AslIPCManager
{
	// Private member functions

	int systemType;

	int msgCount;			// Message counter
	int bidCount;			// Buffer id counter

	char consoleName[ASL_MAXENV];	// Console host name
	char aslPath[ASL_MAXENV];	// ASL binaries path
	
	AslList<AslPort> PortList;

	void  AslGetEnvironment(void);
	
	static void AslScheduler(void);
	
	void AslIPCInitialize(int);
public:
	
	
	AslIPCManager(void);
	~AslIPCManager(void);
	
	// Communication methods

//	int AslMkBuf(int,short int);
	int AslIncPortID(void);		// incrementa BidCount
	AslPort* AslGetIOPort(int);
	int AslSend(int);
//	int AslRecv(int);
//	int AslDelBuf(int);
	
	int AslConnect(AslPort*, AslPort*);
	int AslDisconnect(AslPort*, AslPort*);
	
	int AslRelabel(AslPort*, AslPort*);
	int AslDelabel(AslPort*, AslPort*);
	
	AslList<AslPort>& getPortList(void) { return PortList; };	
	
	// Filtering methods

//	int AslFilterBuf(int, char*);
//	int AslFilterBuf(int, char*, int);
	
	int AslGetPort(void);
	char *AslGetHost(void);
	char *AslGetAslPath(void);
};

#endif
