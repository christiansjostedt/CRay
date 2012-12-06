#include <math.h>
#include <vector>
#include <string>
#include "../Libraries/vec3.h"
//----------------------------------------------------------------------------------------------------------
//Prototype
//----------------------------------------------------------------------------------------------------------
class Camera
{
	public:
		Camera();
		Camera(vec3,vec3,vec3);
		Camera(vec3,vec3,vec3, float);
		Camera(vec3,vec3,vec3, std::string);
		Camera(vec3,vec3,vec3, float,std::string);
		Camera(float);
		Camera(std::string);
		~Camera();

		vec3 getPosition();
		void setPosition(vec3 position);

		vec3 getUp();
		void setUp(vec3 upVector);

		vec3 getCenter();
		void setCenter(vec3 center);

		float getFov();
		void setFov(float FOV);

	private:
		vec3 up;
		vec3 pos;
		vec3 cent;
		float fov;
		std::string cameraName;
};
