#pragma once
#include <vector>
#include <string>
#include "blokas.h"
using namespace std;

class Bomb
{
private:

	bool sprog;
	//bomba
	vector<int> _x,_y,_t;
	//sprogimas
	vector<int> _xs, _ys, _ts;
	int _w, _h;
	string _image_path;
	string _image_paths;

public:

	Bomb(int w, int h, const string &image_path, const string &image_paths);

	~Bomb();
	//type 1=bomba 2=sprogimas
	void load(int x, int y, int type);
	void draw();
	void time(int type);
	void checkb(vector<int> &xm1, vector<int> &ym1, vector<int> &xm2, vector<int> &ym2);
	void checkp(int px, int py, bool &test);

};