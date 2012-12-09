/*
 * Polygons.h
 *
 *  Created on: Dec 9, 2012
 *      Author: christiansjostedt
 */

#ifndef POLYGONS_H_
#define POLYGONS_H_

#include "../Libraries/Ray.h"
#include "../Libraries/vec3.h"
#include <iostream>

//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------



class Tri
{
	public:
		//Tri();
		Tri(vec3 p1, vec3 p2, vec3 p3){vtx1=p1; vtx2=p2; vtx3=p3; color=vec3(1,1,1);}
		//Tri(vec3 camera);
		~Tri(){};

		void calculateNormal();
		vec3 Intersection(Ray);
		vec3 getNormal();

	private:

		vec3 vtx1;
		vec3 vtx2;
		vec3 vtx3;
		vec3 color;
		vec3 normal;



};


inline void Tri::calculateNormal()
{
	vec3 CA = (vtx3-vtx1);
	vec3 BA = (vtx2-vtx1);
	normal = vec3().crossprod( BA,CA );
	normal.Normalize();
}

inline vec3 Tri::Intersection(Ray ray)
{
	//Check to see if the ray hits the plane that the triangle makes up
	float div = ray.getRayDirection()*normal;   //Make sure the ray is not paralell to the plane since we cant divide by 0



	if (div!=0)
	{
		float hit = (vtx1*normal) - (ray.getRayOrigin()*normal);
		hit = hit/div; 								//This is where it intersects the triangle plane (T variable in the Ray Equation)
		vec3 hitPoint = ray.getRayOrigin() + ray.getRayDirection() * hit;  //This is the actual hitpoint

		//Q = HitPoint
		vec3 BA = vtx2-vtx1;
		vec3 QA =hitPoint-vtx1;
		vec3 crossBAQA = vec3().crossprod(BA,QA);
		crossBAQA.Normalize();

		vec3 CB = vtx3-vtx2;
		vec3 QB =hitPoint-vtx2;
		vec3 crossCBQB = vec3().crossprod(CB,QB);
		crossCBQB.Normalize();

		vec3 AC = vtx1-vtx3;
		vec3 QC =hitPoint-vtx3;
		vec3 crossACQC = vec3().crossprod(AC,QC);
		crossACQC.Normalize();

		/*
		std::cout<< "div:"<<div<<std::endl;
		std::cout<< "Plane-hitPoint:"<<hitPoint;
		std::cout<< "normal:"<<normal;
		std::cout<< "crossBAQA: "<<crossBAQA;
		std::cout<< "crossCBQB: "<<crossCBQB<<std::endl;
		std::cout<< "crossACQC: "<<crossCBQB<<std::endl;
		*/

		//Now to solve if the intersection happends inside the actual triangle
		if ( crossBAQA * normal >=0 )
		{
			//std::cout<<"Made it through test1"<<std::endl;
			if ( crossCBQB * normal >=0 )
			{
				//std::cout<<"Made it through test2"<<std::endl;
				if ( crossACQC * normal >=0 )
				{
					//std::cout<<"Made it through test3"<<std::endl;
					//std::cout<< "Actual-hitPoint:"<<hitPoint<<std::endl;
					return hitPoint; // The hit is inside the triangle since all the above condition are above 0;

				}
			}
		}
	}


	else
	{
		return ray.getRayOrigin(); // no hit on object. return the camera position.
	}

	//return ray.getRayOrigin();
}


//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
/*
class Sphere
{
	Sphere(float radi, vec3 pos ,vec3 sca){radius = radi;position =pos,scale=sca;color = vec3(1,1,1);}
	~Sphere();

	float radius;
	vec3 position;
	vec3 scale;
	vec3 color;
};
*/
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------


#endif /* POLYGONS_H_ */
