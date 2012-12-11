#include "Camera.h"
//#include <iostream>
//using namespace std;
//----------------------------------------------------------------------------------------------------------
//Implementation
//----------------------------------------------------------------------------------------------------------
Camera::~Camera(){}



Camera::Camera(vec3 position,vec3 center,vec3 upVector,int ImgSizeX, int ImgSizeY, float FOV)
{
	//setFov(ImgSizeX, ImgSizeY);
	up = upVector;
	cent = center;
	pos = position;
	imgResX = ImgSizeX;
	imgResY = ImgSizeY;
	fov = FOV;

	setAspect(ImgSizeX,ImgSizeY);
	setFov(fov);
	recalc();

}


vec3 Camera::getPosition(){return pos;}
void Camera::setPosition(vec3 position){pos = position;}

vec3  Camera::getUp(){return up;}
void Camera::setUp(vec3 upVector){up = upVector;}

vec3  Camera::getCenter(){return cent;}
void Camera::setCenter(vec3 center){cent = center;}

void Camera::setImgResX(int x){imgResX = x;}
int Camera::getImgResX(){return imgResX;}

void Camera::setImgResY(int y){imgResY = y;}
int Camera::getImgResY(){return imgResY;}


vec3 Camera::getRightVector(){return right_vector;}
vec3 Camera::getViewDirection(){return view_direction;}

void Camera::recalc()
{
    // renormalise the up vector
    up.Normalize();

    // calculate unit view direction vector
    view_direction = cent-pos;
    view_direction.Normalize();


    // and the right hand view vector
    right_vector=vec3().crossprod(view_direction,up);
    right_vector.Normalize();

    // and re-base the up vector (may not be normalised)
    up=vec3().crossprod(right_vector, view_direction);
}

void Camera::setFov(double fovy)
{
	//cout<<"Setting tan_fovX and Y.."<<endl;
	//cout<<fovy<<endl;

    tan_fovY = tan(PI/180 * (fovy) / 2.0);
    tan_fovX = tan(PI/180 * (fovy)*Aspect / 2.0);

	//cout<<PI/180 * (fovy)<<endl;
	//cout<<tan(PI/180 * (fovy) / 2.0)<<endl;
}


float Camera::get_tan_fovY(){return tan_fovY;}
float Camera::get_tan_fovX(){return tan_fovX;}













/*
________________


void Camera::setFov(int width, int height)
{
	//   Tan(Q/2) = (H/2)/d = H/2d --> FOV =
	//   Angle = 2 * arctan(heightt/DistanceToImagePlane) --> 2 * arctan(height)
	fovX = 2*atan(width)*PI/180;
	fovY = 2*atan(height)*PI/180;
}


 */
