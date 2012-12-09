/*
 * Sphere.h
 *
 *  Created on: Dec 9, 2012
 *      Author: christiansjostedt
 */

#ifndef __VEC3_H_INCLUDED__   // if x.h hasn't been included yet...
#define __VEC3_H_INCLUDED__   //   #define this so the compiler knows it has been included
#include "../Libraries/vec3.h"


class GeoSphere
{
	GeoSphere(float radi, vec3 pos ,vec3 sca){radius = radi;position =pos,scale=sca;}
	~GeoSphere();

	float radius;
	vec3 position;
	vec3 scale;
};

#endif
