#pragma once

#include "window.h"
#include <string>
#include "blokas.h"
#include "bomb.h"
using namespace std;

class Rect
{
private:

	//judejimas
	int gox,goy;
	string imagepath, imagepathtemp;
	int _f, _b, _l, _r, _pb;


	//animacija
	string _fa, _ba, _la, _ra;



	int _w, _h;
	int _x, _y;
	SDL_Texture * _player_texture = nullptr;
public:
	Rect(int w, int h, int x, int y, int f, int b, int l, int r, int pb
		, const string &fa, const string &ba, const string &la, const string &ra);
	~Rect();

	void draw() const;
	void anim();
	void go(int &x, int &y, bool u, bool d, bool l, bool r);
	void pollEvents(SDL_Event &event, Bomb &bomb);
};