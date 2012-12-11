//============================================================================
// Name        : CRay.cpp
// Author      : Christian Sjostedt
// Version     :
// Copyright   : Copyright  yatta yatta Christian Sjostedt
// Description : Raytracer In Progress
//============================================================================

//DefGuards
#ifndef RAY_H_
#define RAY_H_
#endif

#ifndef VEC3_H_
#define VEC3_H_
#endif
//______________

#include <iostream>
#include <time.h>
#include <math.h>
#include <string>
#include <sstream>
#include "Magick++.h"


#include "Geometry/CRayGeo.h"
//#include "Libraries/CRayLibs.h"
#include "Cameras/Camera.h"
#include "Parsers/readOBJ.h"

using namespace std;
using namespace Magick;

Ray ComputeCameraRay(Ray &ray, Camera &cam, int x, int y) {
  const float width = cam.getImgResX();  // pixels across
  const float height = cam.getImgResY();  // pixels high

	vec3 rightVector = cam.getRightVector();
	vec3 up = cam.getUp();
	vec3 view_direction = cam.getViewDirection();
	vec3 camera_position = cam.getPosition();
	float aspectRatio = cam.getAspect();
	vec3 r;

	vec3 xPixelOffset = vec3(-0.5*(1/width),0,0);
	vec3 yPixelOffset = vec3(0,0.5*(1/height),0);

  double normalized_i = (x / width) - 0.5;
  double normalized_j = (1-y / height)- 0.5;
  vec3 image_point = rightVector*normalized_i * aspectRatio + xPixelOffset*aspectRatio +
		  	  	  	  	  up*normalized_j+ yPixelOffset
		  	  	  	  	  + camera_position +view_direction;
  r = image_point + camera_position;


  	//cout << endl<<"_______________________________"<<endl<<"_______________________________"<<endl;
  	/*
  	//cout<<cam.setFov(30);
  	cout<<"X:"<<x<<" Y:"<<y<<endl;
  	cout<<"Camera position:"<<camera_position;
  	cout<<"Camera focusPoint:"<<cam.getCenter();
  	cout<<"rightVector:"<< rightVector;
  	cout<<"upVector:"<< up;
  	cout<<"view_direction:"<<view_direction;

 	cout << "image_Point:" << image_point<<endl;
  	r = r + cam.getPosition();
  	cout <<"RayThroughPixel " << r<<endl;
  	//------------------------------------------------------------------------------------------

  	//cout <<"RayThroughPixel " << r<<endl;
  	 */

  	return Ray(cam.getPosition(), r);

}


void Intersect(Ray &ray, Tri tri)
{
	vec3 hitPoint = tri.Intersection(ray);
	if (hitPoint.x != 0.0 && hitPoint.y!= 0.0 && hitPoint.z != 0.0){
		ray.setHit(1);
	}

}

//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------

int main(int argc,char **argv)
{

  //Initialization Vars:
	int ImgResX = 256;
	int ImgResY = 128;

	//Canvas size string, Concactenating int and strings
	ostringstream oss;
	oss << ImgResX << "x"<< ImgResY;
	string imgSize = oss.str();

	//Write to this destination
	string filename = "/Users/christiansjostedt/Desktop/CRay_render.png";

	//SceneDescription
	Camera cam = Camera(vec3(0,0,0), vec3(0,0,10),vec3(0,1,0),ImgResX,ImgResY,90);
	//Tri tri = Tri( vec3(4,4,10), vec3(-5,5,10), vec3(0,-10,10) );
	//tri.calculateNormal();
	//std::string path = "/Users/christiansjostedt/Desktop/Cube.obj";
	readOBJ Cube = readOBJ("/Users/christiansjostedt/Desktop/Cube.obj");
	Cube.generateGeo();

	//Initialize DisplayDriver
	InitializeMagick(*argv);

	//Timer Start
	clock_t initTime, finalTime; 					//Setup timer values
	initTime=clock();

	//Image Start
	Image image(imgSize, "black");		//Create canvas


/*
	for(int xPixel=0;xPixel<ImgResX;xPixel++){
		for(int yPixel=0;yPixel<ImgResY;yPixel++)
		{
			//cout << "X:"<<xPixel<<" Y:"<<yPixel<<endl;
			Ray ray = ComputeCameraRay(ray, cam, xPixel, yPixel);

			//Intersect
			Intersect(ray, tri);

			if (ray.getHit()==1)
			{image.pixelColor(xPixel,yPixel,Color(MaxRGB,MaxRGB,MaxRGB,1));}

			else
			{image.pixelColor(xPixel,yPixel,Color(0,0,0,1));}

			ray.setHit(0);
			//Image[x,y] = FindColor(hit);

		}
	}

*/
	//Timer end, Print Time
	finalTime=clock()-initTime;
	cout << endl << "Rendertime: "<< (double)finalTime / ((double)CLOCKS_PER_SEC) << " Seconds"<< endl;


	//Write to disk
	image.write( filename );

	return 0;
}


