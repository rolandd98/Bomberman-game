#pragma once

#include "window.h"
#include <string>
#include <vector>
using namespace std;

class Map
{
private:

	int _x, _y;

public:
	Map(int x, int y);
	~Map();
	void draw(vector<int> &x1, vector<int> &y1, vector<int> &xm1, vector<int> &ym1);
	void store(int space, int row, int col, vector<int> &x1, vector<int> &y1, vector<int> &x2, vector<int> &y2, vector<int> &xm1, vector<int> &ym1, vector<int> &xm2, vector<int> &ym2);
};