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

using namespace std;
using namespace Magick;


void UVColorTest(Image &image, int x,int y)
{
	double newX = (x+0.0001)/50*MaxRGB;
	double newY = (y+0.0001)/50*MaxRGB;
	image.pixelColor(x,y,Color(newX,newY,0,1));
	//cout<<"x:"<<x<<"  y: "<<y<<"  Color:("<<newX/MaxRGB<<","<<newY/MaxRGB<<","<<0/MaxRGB<<","<<1/MaxRGB<<")"<<endl;
}


Ray ComputeCameraRay(Ray &ray, Camera &cam, int x, int y) {
  const float width = cam.getImgResX();  // pixels across
  const float height = cam.getImgResY();  // pixels high

	vec3 rightVector = cam.getRightVector();
	vec3 up = cam.getUp();
	vec3 view_direction = cam.getViewDirection();
	vec3 camera_position = cam.getPosition();
	vec3 r;

  double normalized_i = (1-x / width) - 0.5;
  double normalized_j = (1-y / height)- 0.5;
  vec3 image_point = rightVector*normalized_i +
		  	  	  	  	  up*normalized_j + camera_position +view_direction;
  r = image_point + camera_position;

  	/*
  	cout << endl<<"_______________________________"<<endl<<"_______________________________"<<endl;
  	//cout<<cam.setFov(30);
  	cout<<"X:"<<x<<" Y:"<<y<<endl;
  	//cout<<"alpha:"<<alpha<<" beta:"<<beta<<endl;
  	cout<<"rightVector:"<< rightVector;
  	cout<<"upVector:"<< up;
  	cout<<"view_direction:"<<view_direction;
  	cout<<"Camera position:"<<camera_position;
 	cout << "image_Point:" << image_point<<endl;
  	r = r + cam.getPosition();
  	cout <<"RayThroughPixel " << r<<endl;
  	//------------------------------------------------------------------------------------------
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


int main(int argc,char **argv)
{


  //Initialization Vars:
	int ImgResX = 512;
	int ImgResY = 512;

	//Canvas size string, Concactenating int and strings
	ostringstream oss;
	oss << ImgResX << "x"<< ImgResY;
	string imgSize = oss.str();

	//Write to this destination
	string filename = "/Users/christiansjostedt/Desktop/CRay_render.png";

	Camera cam = Camera(vec3(0,0,0), vec3(0,0,10),vec3(0,1,0),ImgResX,ImgResY,90);
	//Scene scene;
	Tri tri = Tri( vec3(1,-0.5,10), vec3(-0.8,-0.4,10), vec3(0,0.8,10) );
	tri.calculateNormal();

	//Initialize DisplayDriver
	InitializeMagick(*argv);

	//Timer Start
	clock_t initTime, finalTime; 					//Setup timer values
	initTime=clock();

	//Image Start
	Image image(imgSize, "black");		//Create canvas



	for(int xPixel=0;xPixel<ImgResX;xPixel++){
		for(int yPixel=0;yPixel<ImgResY;yPixel++)
		{

			Ray ray = ComputeCameraRay(ray, cam, xPixel, yPixel);
			//RayThroughPixel( ray, cam, ImgResX, ImgResY, xPixel, yPixel );

			Intersect(ray, tri);
			//=Intersect(ray,scene);

			if (ray.getHit()==1)
			{image.pixelColor(xPixel,yPixel,Color(MaxRGB,MaxRGB,MaxRGB,1));}

			else
			{image.pixelColor(xPixel,yPixel,Color(0,0,0,1));}

			//Image[x,y] = FindColor(hit);

			//UVColorTest(image, x, y);
		}
	}


	//Timer end, Print Time
	finalTime=clock()-initTime;
	cout << endl << "Rendertime: "<< (double)finalTime / ((double)CLOCKS_PER_SEC) << " Seconds"<< endl;


	//Write to disk
	image.write( filename );

	return 0;
}


