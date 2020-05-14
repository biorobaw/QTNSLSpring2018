
//  ASL INPUT/OUTPUT LIBRARY 
//
//  ASL (Abstract Schema Language) Input/Output Library
//
//
//
//  FILE NAME   : aslio.h
//  MODULE TYPE : ASL Input/Output Library
//  STATUS      : Ready for use 
//  PURPOSE     : Reliable Input/Output Library
//  
//
//  Instituto Tecnologico Autonomo de Mexico 
//  (c) Copyrigth 1995  
//
//
//
//  HISTORY : Version (Date-Name) Modification, description. 
//
//            1.0 (Agu 15, 1995 - Claudia Calderas & Salvador Marmol), 
//            Start of development for distributed execution.

#ifndef __ASLIO_H
#define __ASLIO_H

class AslReliableIO
{
//	AslMutex *m;

protected:
//	int  threadID;
//	char hostName[64];
	int  first;

public:
	AslReliableIO(void);
	~AslReliableIO(void);
	
	void start(void);
	void stop(void);
};

class AslErr: public AslReliableIO
{
	char buf[256];
public:
	void printHeader(void);

	AslErr& operator << (const char*);
	AslErr& operator << (char*);
	AslErr& operator << (AslTerminator&);
	AslErr& operator << (char);
	AslErr& operator << (int);
	AslErr& operator << (long int);
	AslErr& operator << (unsigned int);
	AslErr& operator << (unsigned long int);
	AslErr& operator << (float);
};

class AslInOut: public AslReliableIO
{
	char buf[256];
public:
	void printHeader(void);

	AslInOut& operator >> (char*);
	AslInOut& operator >> (char&);
	AslInOut& operator >> (int&);
	AslInOut& operator >> (unsigned int&);
	AslInOut& operator >> (unsigned long int&);
	AslInOut& operator >> (long int&);
	AslInOut& operator >> (float&);

	AslInOut& operator << (AslTerminator&);
	AslInOut& operator << (const char*);
	AslInOut& operator << (char*);
	AslInOut& operator << (char);
	AslInOut& operator << (int);
	AslInOut& operator << (unsigned int);
	AslInOut& operator << (unsigned long int);
	AslInOut& operator << (long int);
	AslInOut& operator << (float);
};

class AslTerminator
{
	char dummy;
};

#endif
