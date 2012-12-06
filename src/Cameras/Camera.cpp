#include "Camera.h"

//----------------------------------------------------------------------------------------------------------
//Implementation
//----------------------------------------------------------------------------------------------------------
Camera::Camera(){}
Camera::~Camera(){}

Camera::Camera(vec3 position,vec3 center,vec3 upVector, float FOV)
{
	up = upVector;
	cent = center;
	pos = position;
	fov = FOV;
}

Camera::Camera(vec3 position,vec3 center,vec3 upVector, std::string name)
{
	up = upVector;
	cent = center;
	pos = position;
	cameraName = name;
}

Camera::Camera(vec3 position,vec3 center,vec3 upVector, float FOV, std::string name)
{
	up = upVector;
	cent = center;
	pos = position;
	fov = FOV;
	cameraName = name;
}


Camera::Camera(vec3 position,vec3 center,vec3 upVector)
{
	up = upVector;
	cent = center;
	pos = position;
}

Camera::Camera(float FOV)
{
	fov = FOV;
}

Camera::Camera(std::string name)
{
	cameraName = name;
}

vec3 Camera::getPosition(){return pos;}
void Camera::setPosition(vec3 position){pos = position;}

vec3  Camera::getUp(){return cent;}
void Camera::setUp(vec3 upVector){up = upVector;}

vec3  Camera::getCenter(){return cent;}
void Camera::setCenter(vec3 center){cent = center;}

float Camera::getFov(){return fov;}
void Camera::setFov(float FOV){fov = FOV;}
