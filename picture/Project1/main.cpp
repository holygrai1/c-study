#include<opencv2\opencv.hpp>
#include<iostream>
#include "StreamImageManager.h"
using namespace cv;
using namespace std;

int main(int argc, char** argv) {
	StreamImageManager photes("D:/cstudy/picture");
	//photes.showpicture(2);
	photes.applyForImage(0, 300, 300, []{
		cout << "ok" << endl; });
	return 0;
}