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
#include "Cameras/Camera.h"
#include "Magick++.h"
#include <string>
#include <sstream>

using namespace std;
using namespace Magick;


int main(int argc,char **argv)
{
  //Initialization Vars:
	int ImgResX = 50;
	int ImgResY = 50;

	//Canvas size string, concactenate int and strings
	ostringstream oss;
	oss << ImgResX << "x"<< ImgResY;
	string imgSize = oss.str();

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

			double newX = (x+0.0001)/50*MaxRGB;
			double newY = (y+0.0001)/50*MaxRGB;
			image.pixelColor(x,y,Color(newX,newY,0,1));
			//cout<<"x:"<<x<<"  y: "<<y<<"  Color:("<<newX/MaxRGB<<","<<newY/MaxRGB<<","<<0/MaxRGB<<","<<1/MaxRGB<<")"<<endl;
			//image.pixelColor(50,50,Color("red")); // set the pixel at position (50,50) to red
		}
	}



	//Timer end, Print Time
	finalTime=clock()-initTime;
	cout << endl << "Rendertime: "<< (double)finalTime / ((double)CLOCKS_PER_SEC) << " Seconds"<< endl;

	//Write to disk
	image.write( filename );


	return 0;
}
