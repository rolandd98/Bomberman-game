#include "bomb.h"
#include <vector>


Bomb::Bomb(int w, int h, const string &image_path, const string &image_paths)
{
	_w = w;
	_h = h;
	_image_path = image_path;
	_image_paths = image_paths;
}

Bomb::~Bomb()
{
}

void Bomb::load(int x, int y, int type)
{
	if (type == 1)
	{
		_x.push_back(x);
		_y.push_back(y);
		_t.push_back(160);
	}
	if (type == 2)
	{
		_xs.push_back(x);
		_ys.push_back(y);
		_ts.push_back(80);
	}
}

void Bomb::draw()
{
	Block bomba(_w, _h, _image_path);
	//Block sprogimas(_w*2, _h*2, _image_paths);
	Block sprogimas(_w, _h, _image_paths);
	Block sprogimasv(_w, _h, "resources/v.png");
	Block sprogimasa(_w, _h, "resources/a.png");
	Block sprogimask(_w, _h, "resources/k.png");
	Block sprogimasd(_w, _h, "resources/d.png");

	for (int i = 0; i < _x.size(); i++)
	{
		bomba.draw(_x[i], _y[i]);
		//time(1);
	}
	for (int i = 0; i < _xs.size(); i++)
	{
		//sprogimas.draw(_xs[i]-32, _ys[i]-32);
		sprogimas.draw(_xs[i], _ys[i]);
		sprogimasv.draw(_xs[i], _ys[i]-64);
		sprogimasa.draw(_xs[i], _ys[i]+64);
		sprogimask.draw(_xs[i]-64, _ys[i]);
		sprogimasd.draw(_xs[i]+64, _ys[i]);
		//time(2);
	}

}

void Bomb::time(int type)
{
	if (type == 1)
	{
		for (int i = 0; i < _x.size(); i++)
		{
			_t[i]--;
			if (_t[i] == 0)
			{
				load(_x[i], _y[i], 2);
				_x.erase(_x.begin());
				_y.erase(_y.begin());
				_t.erase(_t.begin());
			}
		}
	}
	else
	{
		for (int i = 0; i < _xs.size(); i++)
		{
			_ts[i]--;
			if (_ts[i] == 0)
			{
				_xs.erase(_xs.begin());
				_ys.erase(_ys.begin());
				_ts.erase(_ts.begin());
			}
		}

	}

}

void Bomb::checkb(vector<int> &xm1, vector<int> &ym1, vector<int> &xm2, vector<int> &ym2)
{

	sprog = false;

	for(int i=0; i<_xs.size(); i++)
		for (int j = 0; j < xm1.size(); j++)
		{
			if ((_xs[i] - 50 <= xm2[j] && _xs[i] >= xm1[j]) && (_ys[i] <= ym2[j]-30 && _ys[i]+64 >= ym1[j]+30))sprog = true; //kaire puse
			if ((_xs[i] + 114 >= xm1[j] && _xs[i] <= xm2[j]) && (_ys[i] <= ym2[j]-30 && _ys[i] + 64 >= ym1[j]+30))sprog = true; //desine puse
			if ((_ys[i] - 50 <= ym2[j] && _ys[i] >= ym1[j])&& (_xs[i] <= xm2[j]-30 && _xs[i]+64 >= xm1[j]+30))sprog = true; // virsus
			if ((_ys[i] + 114 >= ym1[j] && _ys[i] <= ym2[j]) && (_xs[i] <= xm2[j]-30 && _xs[i]+64 >= xm1[j]+30))sprog = true; //apacia

			if (sprog)
			{
				xm1.erase(xm1.begin() + j);
				ym1.erase(ym1.begin() + j);
				xm2.erase(xm2.begin() + j);
				ym2.erase(ym2.begin() + j);
				sprog = false;
			}
		}
}

void Bomb::checkp(int px, int py, bool &test)
{

	for (int i = 0; i < _xs.size(); i++)
	{
		/*
		if ((_xs[i] - 50 <= xm2[j] && _xs[i] >= xm1[j]) && (_ys[i] <= ym2[j] - 30 && _ys[i] + 64 >= ym1[j] + 30))sprog = true; //kaire puse
		if ((_xs[i] + 114 >= xm1[j] && _xs[i] <= xm2[j]) && (_ys[i] <= ym2[j] - 30 && _ys[i] + 64 >= ym1[j] + 30))sprog = true; //desine puse
		if ((_ys[i] - 50 <= ym2[j] && _ys[i] >= ym1[j]) && (_xs[i] <= xm2[j] - 30 && _xs[i] + 64 >= xm1[j] + 30))sprog = true; // virsus
		if ((_ys[i] + 114 >= ym1[j] && _ys[i] <= ym2[j]) && (_xs[i] <= xm2[j] - 30 && _xs[i] + 64 >= xm1[j] + 30))sprog = true; //apacia
		*/
		if ((_xs[i] - 50 <= px+64 && _xs[i] >= px) && (_ys[i] <= py+64 - 30 && _ys[i] + 64 >= py + 30))test = true; //kaire puse
		if ((_xs[i] + 114 >= px && _xs[i] <= px+64) && (_ys[i] <= py+64 - 30 && _ys[i] + 64 >= py + 30))test = true; //desine puse
		if ((_ys[i] - 50 <= py+64 && _ys[i] >= py) && (_xs[i] <= px+64 - 30 && _xs[i] + 64 >= px + 30))test = true; // virsus
		if ((_ys[i] + 114 >= py && _ys[i] <= py+64) && (_xs[i] <= px+64 - 30 && _xs[i] + 64 >= px + 30))test = true; //apacia
	}

}