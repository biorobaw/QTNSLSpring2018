/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: aaronboshers
 *
 * Created on August 17, 2016, 5:27 PM
 */

#include <cstdlib>

using namespace std;

extern void NSLmain(int argc,char** argv);
extern void NSLinit(int argc,char** argv);

/*
 * 
 */
int main(int argc, char** argv)
{
   NSLinit(argc, argv);
   NSLmain(argc, argv);
   return 0;
}

