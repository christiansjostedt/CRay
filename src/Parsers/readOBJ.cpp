/*
 * readOBJ.cpp
 *
 *  Created on: Dec 11, 2012
 *      Author: christiansjostedt
 */

#include "readOBJ.h"

readOBJ::~readOBJ(){}

void readOBJ::generateGeo()
{
	std::cout<<inputFile;

	std::string STRING;
		std::ifstream infile(inputFile.c_str());
		std::string line;
		while (std::getline(infile, line))
		{
		    std::istringstream iss(line);
		    int a, b;
		    if (!(iss >> a >> b)) { break; } // error

		    // process pair (a,b)
		}



}



