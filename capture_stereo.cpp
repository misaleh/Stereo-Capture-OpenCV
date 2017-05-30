#include <iostream>
#include <sstream>
#include <time.h>
#include <stdio.h>
#include <string>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <fstream>

using namespace cv;
using namespace std;


template <typename T>
string NumberToString ( T Number )
 {
     ostringstream ss;
     ss << Number;
     return ss.str();
 }

int main()
{
	VideoCapture capL(1);
  	VideoCapture capR(0);
	//capL.set(CV_CAP_PROP_SETTINGS, 1);
	//capR.set(CV_CAP_PROP_SETTINGS, 1);
	int counter =  0; 
	char c;
	Mat imgr,imgl;
	string leftFileName, rightFileName;
	std::ofstream ofs;
	ofs.open("stereo_calib.xml", std::ofstream::out | std::ofstream::trunc);
	
	ofs<<"<?xml version=\"1.0\"?>"<<std::endl;
	ofs<<"<opencv_storage>"<<std::endl;
	ofs<<"<imagelist>"<<std::endl;
	while(1)
	{
	
	    capL >> imgl; 
		capR >> imgr;
		
		imshow("left",imgl);
		imshow("right",imgr);
		c = cvWaitKey(1);
  		if(97 == char(c))
		{
			leftFileName = "left" + NumberToString(counter) + ".png";
			rightFileName = "right" + NumberToString(counter++) + ".png";
			ofs<<"\""<<leftFileName<<"\""<<std::endl;
			ofs<<"\""<<rightFileName<<"\""<<std::endl;
			imwrite(rightFileName,imgr);
			imwrite(leftFileName,imgl);
			cerr<<"Capture = "<< counter <<endl;
		}
		else if(27 == char(c))
			break;
	}
	ofs<<"</imagelist>"<<std::endl;
	ofs<<"</opencv_storage>"<<std::endl;
	ofs.close();
	return 0 ;
}