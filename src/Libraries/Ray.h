#include "vec3.h"

class Ray: public vec3
{
	public:
		Ray (vec3 camera, vec3 direction){rayOrigin = camera; rayDirection = direction;}
		~Ray(){};

		void setIntersectionPosition(vec3 pos){IntersectionPosition=pos;hit=1;}
		vec3 getIntersectionPosition(){return IntersectionPosition;}

		void setIntersectionNormal(vec3 n){IntersectionNormal=n; hit=1;}
		vec3 getIntersectionNormal(){return IntersectionNormal;}

		vec3 getRayOrigin(){return rayOrigin;}
		vec3 getRayDirection(){return rayDirection;}

		void setHit(int x){hit = x ;}
		int getHit(){return hit;}


	private:
		vec3 rayOrigin;
		vec3 rayDirection;

		vec3 IntersectionPosition;
		vec3 IntersectionNormal;

		int hit;



};





