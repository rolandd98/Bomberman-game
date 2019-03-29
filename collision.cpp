#include "collision.h"
using namespace std;

Liecia::Liecia(int x1, int y1, int x2, int y2)
{
	_x1 = x1;
	_y1 = y1;
	_x2 = x2;
	_y2 = y2;
}

Liecia::~Liecia()
{
}

void Liecia::check(int x, int y, bool &u, bool &d, bool &l, bool &r, vector<int> &x1, vector<int> &y1, vector<int> &x2, vector<int> &y2,
	vector<int> &xm1, vector<int> &ym1, vector<int> &xm2, vector<int> &ym2)
{
	//langas
	u = true;
	d = true;
	l = true;
	r = true;
	if (x == _x1)l = false;
	if (y == _y1)u = false;
	if (x+64 == _x2)r = false;
	if (y+64 == _y2)d = false;

	//blokai
	for (int i = 0; i<x1.size(); i++)
	{


		//if ((y + 64) == y1[i] && ((x + 64) > (x1[i] + 5) && x < (x2[i]) - 5))d = false;
		//if (y == y2[i] && ((x + 64) > (x1[i] + 5) && x < (x2[i]) - 5))u = false;

		if (abs((y + 54) - y1[i]) <= 10 && ((x + 60) > (x1[i] + 5) && x < (x2[i]) - 5))d = false;
		if (abs(y - y2[i]+10) <= 10 && ((x + 60) > (x1[i] + 5) && x < (x2[i]) - 5))u = false;
		if (abs((x + 54) - x1[i]) <= 5 && ((y + 60) > (y1[i] + 5) && y < (y2[i]) - 5))r = false;
		if (abs(x - x2[i]+10) <= 5 && ((y + 60) > (y1[i] + 5) && y < (y2[i]) - 5))l = false;
	}
	
	for (int i = 0; i < xm1.size(); i++)
	{

		if (abs((y + 54) - ym1[i]) <= 10 && ((x + 60) > (xm1[i] + 5) && x < (xm2[i]) - 5))d = false;
		if (abs(y - ym2[i] + 10) <= 10 && ((x + 60) > (xm1[i] + 5) && x < (xm2[i]) - 5))u = false;
		if (abs((x + 54) - xm1[i]) <= 5 && ((y + 60) > (ym1[i] + 5) && y < (ym2[i]) - 5))r = false;
		if (abs(x - xm2[i] + 10) <= 5 && ((y + 60) > (ym1[i] + 5) && y < (ym2[i]) - 5))l = false;
	}

}