#include <math.h>
#include <string>
#include "../Libraries/vec3.h"

//#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067982148086513282306647093844609550582231725359408128481117450284102701938521105559644622948954930381964428810975665933446128475648233786783165271201909145648566923460348610454326648213393607260249141273724587006606315588174881520920962829254091715364367892590360011330530548820466521384146951941511609
#define PI 3.1415926535897932384626433832795028841971

//----------------------------------------------------------------------------------------------------------
//Prototype
//----------------------------------------------------------------------------------------------------------
class Camera
{
	public:
		Camera(vec3,vec3,vec3, int, int, float);
		~Camera();

		vec3 getPosition();
		void setPosition(vec3 position);

		vec3 getUp();
		void setUp(vec3 upVector);

		vec3 getCenter();
		void setCenter(vec3 center);

		vec3 getRightVector();
		vec3 getViewDirection();

		void setImgResX(int);
		void setImgResY(int);
		int getImgResX();
		int getImgResY();

		void recalc();

		void setFov(double);
		float getFov(){return fov;}

		void setAspect(double aspect){Aspect = aspect;}
		void setAspect(int x, int y){Aspect = (double)x / y;}
		float getAspect(){return Aspect;}

		float get_tan_fovY();
		float get_tan_fovX();


	private:
		vec3 up, pos, cent;
		vec3 view_direction, right_vector;
		float fov, tan_fovY, tan_fovX, Aspect;
		int imgResX,imgResY;


};
