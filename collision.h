#pragma once
#include <vector>
using namespace std;

class Liecia
{
private:
	//langas
	int _x1, _y1, _x2, _y2;

	//blokai



public:
	Liecia(int x1, int y1, int x2, int y2);
	~Liecia();

	void store();
	
	void check(int x, int y, bool &u, bool &d, bool &l, bool &r, vector<int> &x1, vector<int> &y1, vector<int> &x2, vector<int> &y2,
		vector<int> &xm1, vector<int> &ym1, vector<int> &xm2, vector<int> &ym2);

};