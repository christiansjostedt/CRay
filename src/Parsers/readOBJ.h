/*
 * readOBJ.h
 *
 *  Created on: Dec 11, 2012
 *      Author: christiansjostedt
 */

#ifndef READOBJ_H_
#define READOBJ_H_

#include <string>
#include <iostream>
#include <fstream>
#include "../Geometry/CRayGeo.h"

class readOBJ
{
	public:
		readOBJ(std::string Input){inputFile=Input;}
		~readOBJ();

		void generateGeo();

	private:
		std::string inputFile;
		//BBox bbox;
};




#endif /* READOBJ_H_ */
