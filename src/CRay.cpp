//============================================================================
// Name        : CRay.cpp
// Author      : Christian Sjostedt
// Version     :
// Copyright   : Copyright  yatta yatta Christian Sjostedt
// Description : Raytracer In Progress
//============================================================================
#include <iostream>
#include <time.h>
#include "Libraries/vec3.h"
#include "Libraries/Ray.h"
#include "Cameras/Camera.h"
#include "Magick++.h"
#include <string>
#include <sstream>

using namespace std;
using namespace Magick;

void UVColorTest(Image &image, int x,int y)
{
	double newX = (x+0.0001)/50*MaxRGB;
	double newY = (y+0.0001)/50*MaxRGB;
	image.pixelColor(x,y,Color(newX,newY,0,1));
	//cout<<"x:"<<x<<"  y: "<<y<<"  Color:("<<newX/MaxRGB<<","<<newY/MaxRGB<<","<<0/MaxRGB<<","<<1/MaxRGB<<")"<<endl;
}

void rayThroughPixel(Camera &cam, int x, int y)
{
	/*Create a Coordinate frame
	vec3 w;
	vec3 a;
	vec3 b;
	vec3 u;
	vec3 v;

	a = eyePosition - centerPos;
	b = upVector

	w = a.normailize()
	u = (b X w).normalize()
	v = w X u


	Image Canvas will be at 1*-w or -w. 1 unit away from the camera in world-space coordniates

	alphaU = tan(fov*X / 2) * (( xPixel-(imageWidth/2)) / (imageWidth/2) )
	alphaU = horizontal pixels

	betaV = tan(fov*Y / 2) * ( ((imageHeight/2)-yPixel) / (imageHeight/2))
	betaV = Vertical pixels

	//Equation for a ray
	ray = ( eye + (alphaU + betaV-W).normalize() )
	ray = (origin + normalized direction)

	Calculating intersection is:
	ray = (origin + normalized direction)   * DistanceAlongRay
	ray = ( eye + (alphaU + betaV-W).normalize() ) * DistanceAlongRay
	*/
}

int main(int argc,char **argv)
{
  //Initialization Vars:
	int ImgResX = 80;
	int ImgResY = 50;

	//Canvas size string, Concactenating int and strings
	ostringstream oss;
	oss << ImgResX << "x"<< ImgResY;
	string imgSize = oss.str();

	//Write to this destination
	string filename = "/Users/christiansjostedt/Desktop/CRay_render.png";

	//Camera Cam;
	//Scene scene;

	//Initialize DisplayDriver
	InitializeMagick(*argv);

	//Timer Start
	clock_t initTime, finalTime; 					//Setup timer values
	initTime=clock();

	//Image Start
	Image image(imgSize, "black");		//Create canvas
	for(int x=0;x<ImgResX;x++){
		for(int y=0;y<ImgResY;y++)
		{

			//Ray ray = RayThruPixel(cam,x,y);
			//Intersection hit=Intersect(ray,scene);
			//Image[x,y] = FindColor(hit);

			UVColorTest(image, x, y);
		}
	}



	//Timer end, Print Time
	finalTime=clock()-initTime;
	cout << endl << "Rendertime: "<< (double)finalTime / ((double)CLOCKS_PER_SEC) << " Seconds"<< endl;

	//Write to disk
	image.write( filename );

	Ray ray = Ray(0,0,0);
	Ray gay = Ray(1,3,4);
	cout << gay+ray;


	return 0;
}
