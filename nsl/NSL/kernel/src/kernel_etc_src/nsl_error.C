/* SCCS  %W%---%E%--%U% */
//
//	nsl_error.C
//

#include <fstream>
#include <iostream>
#include "nsl_error.h"

using namespace std;

extern int NSLoutput(const int);
extern int NSLoutput(const float);
extern int NSLoutput(const char*);
//extern int NSLoutput(const char*,const char*);

void cmd_out(const char* p)
{
//	cout << p << "\n";
//	cout.flush();
	NSLoutput(p);
	NSLoutput(" ");
}
void cmd_out(const float p)
{
//	cout << p << "\n";
//	cout.flush();
	NSLoutput(p);
	NSLoutput(" ");
}
void cmd_out(const char* p1,const char* p2)
{
//	cout << p1 << p2 << "\n";
//	cout.flush();
	NSLoutput(p1);
	NSLoutput(p2);
	NSLoutput("\n");
}
void cmd_out(const char* p1,const int p2)
{
//	cout << p1 << p2 << "\n";
//	cout.flush();
	NSLoutput(p1);
	NSLoutput(p2);
	NSLoutput("\n");
}
void cmd_out(const char* p1,const float p2)
{
//	cout << p1 << p2 << "\n";
//	cout.flush();
	NSLoutput(p1);
	NSLoutput(p2);
	NSLoutput("\n");
}
void cmd_out(const char* p1,row_col_enum p2)
{
	cout << p1 << p2 << "\n";
	cout.flush();
}

void cmd_out(const char* p1,on_off_enum p2)
{
	cout << p1 << p2 << "\n";
	cout.flush();
}

void cmd_error(const char* p)
{
	std::cerr << p << "\n";
	std::cerr.flush();
}
void cmd_error(const char* p1,const char* p2)
{
	std::cerr << p1 << p2 << "\n";
	std::cerr.flush();
}
void cmd_error(const char* p1,const int p2)
{
	std::cerr << p1 << p2 << "\n";
	std::cerr.flush();
}
void cmd_error(const char* p1,const float p2)
{
	std::cerr << p1 << p2 << "\n";
	std::cerr.flush();
}
void cmd_error(const char* p1,row_col_enum p2)
{
	std::cerr << p1 << p2 << "\n";
	std::cerr.flush();
}

void cmd_error(const char* p1,on_off_enum p2)
{
	std::cerr << p1 << p2 << "\n";
	std::cerr.flush();
}

