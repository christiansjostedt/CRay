#include "vec3.h"

class Ray: public vec3
{

	public:
		//Ray(int x,int y,int z);{ray = vec3(x,y,z)};
		double x, /*!< x-coordinate */ y, /*!< y-coordinate */ z; /*!< z-coordinate */

		//Calling vec3's constructors form Ray constructor to inherit everything properly
		Ray ():vec3::vec3(){};
		Ray (double xc, double yc, double zc):vec3::vec3(xc, yc, zc){};
		~Ray(){};



};



