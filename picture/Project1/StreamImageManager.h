#pragma once
#include<opencv2\opencv.hpp>
#include<iostream>
#include"LRUCache.h"
#include<string>
#include<vector>
#include <functional>
using namespace std;
using namespace cv;
//typedef map<int, string> id_map;
class StreamImageManager
{
public:
	StreamImageManager(const string& adress);
	void applyForImage(int id, int x, int y, function<void()> callback);
    void showpicture(int i);
private:
	//id_map src_name;
	LRUCache photo_cache;
};

StreamImageManager::StreamImageManager(const string& adress)
{
	vector<string> temp_src;
	glob(adress, temp_src, false);
	if (temp_src.size() == 0)
	{
		cerr << "That's no file in " << adress << endl;
		exit(1);
	};
	for (int i = 0; i < temp_src.size(); ++i) {
		Mat image = imread(temp_src[i]);
		photo_cache.Set(i, image);
		//src_name[i] = temp_src[i];
	};
}

static void read_image(int i, LRUCache*  cache) {
	string new_adr = "D:/cstudy/picture/" + to_string(i) + ".jpeg";
	cout << new_adr << endl;
	Mat image = imread(new_adr);
	cache->Set(i, image);
}
void StreamImageManager::showpicture(int i) {
		if (!photo_cache.Exist(i)) {
			thread t_read(&read_image, i, &photo_cache);
			t_read.join();
		}
		namedWindow(to_string(i), WINDOW_AUTOSIZE);
		imshow(to_string(i), photo_cache.Get(i));
		waitKey(0);
		destroyAllWindows();
}

void StreamImageManager::applyForImage(int id, int x, int y,function<void()> callback) {
	if (!photo_cache.Exist(id)) {
		thread t_read(&read_image, id, &photo_cache);
		t_read.join();
	}
	Mat image = photo_cache.Get(id).clone();
	Mat Roi = image(Rect(x, y, 128, 128));
	callback();
	namedWindow(to_string(id), WINDOW_AUTOSIZE);
	imshow(to_string(id), Roi);
	waitKey(0);
	destroyAllWindows();
}




