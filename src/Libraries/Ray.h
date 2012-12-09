
#include "vec3.h"

class Ray: public vec3
{

	public:
		vec3 rayOrigin;
		vec3 rayDirection;

		//Calling vec3's constructors form Ray constructor to inherit everything properly
		Ray (vec3 camera, vec3 direction){rayOrigin = camera; rayDirection = direction;}
		~Ray(){};



};



