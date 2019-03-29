#include <iostream>
#include <string>
#include "blokas.h"
#include "map.h"
using namespace std;

Map::Map(int x, int y)
{
	_x = x;
	_y = y;
}
Map::~Map()
{
}


void Map::draw(vector<int> &x1, vector<int> &y1, vector<int> &xm1, vector<int> &ym1)
{
	Block kblock(64, 64, "resources/kblokas.png");
	Block mblock(64, 64, "resources/mblokas.png");

	//minksti blokai
	for (int i = 0; i < xm1.size(); i++)
	{
		mblock.draw(xm1[i],ym1[i]);
	}
	//kieti blokai
	for (int i = 0; i < x1.size(); i++)
	{
		kblock.draw(x1[i], y1[i]);
	}

		
}
void Map::store(int space, int row, int col, vector<int> &x1, vector<int> &y1, vector<int> &x2, vector<int> &y2, vector<int> &xm1, vector<int> &ym1, vector<int> &xm2, vector<int> &ym2)
{
	//kieti blokai
	for (int i = 0; i < col; i++)
		for (int j = 0; j < row; j++)
		{
			x1.push_back(_x + (space*i * 2));
			y1.push_back(_y + (space*j * 2));
			x2.push_back(_x + (space*i * 2) + space);
			y2.push_back(_y + (space*j * 2) + space);
		}

	//minksti blokai
	for (int i = 0; i < col+4; i++)
		for (int j = 0; j < row+2; j++)
		{
				xm1.push_back(_x + (space*i));
				ym1.push_back(_y + (space*j));
				xm2.push_back(_x + (space*i) + space);
				ym2.push_back(_y + (space*j) + space);
		}

	for (int i = 0; i < col + 4; i++)
	{
		xm1.push_back(_x + (space*i));
		ym1.push_back(_y-64);
		xm2.push_back(_x + (space*i) + space);
		ym2.push_back(_y-64 + space);
	}
	for (int i = 0; i < col + 4; i++)
	{
		xm1.push_back(_x + (space*i));
		ym1.push_back(_y + (64*5));
		xm2.push_back(_x + (space*i) + space);
		ym2.push_back(_y +(64 * 5) + space);
	}


}
