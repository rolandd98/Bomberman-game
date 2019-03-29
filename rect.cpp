#include "rect.h"
#include <SDL_image.h>
#include <iostream>
#include <string>
using namespace std;


Rect::Rect(int w, int h, int x, int y, int f, int b, int l, int r, int pb
	, const string &fa, const string &ba, const string &la, const string &ra)
{
	_w = w;
	_h = h;

	//judejimas
	_x = x;
	_y = y;
	gox = 0;
	goy = 0;

	_f = f;
	_b = b;
	_l = l;
	_r = r;
	_pb = pb;


	//animacija
	_fa = fa;
	_ba = ba;
	_la = la;
	_ra = ra;

	imagepath = fa;


	//SDL_Surface* surface = IMG_Load(image_path.c_str());
	auto surface = IMG_Load(imagepath.c_str());
	if (!surface)
	{
		cerr << "Surface nesusikure" << endl;
	}
	_player_texture = SDL_CreateTextureFromSurface(Window::renderer, surface);

	if (!_player_texture)
	{
		cerr << "Nesukure texturos" << endl;
	}
	SDL_FreeSurface(surface);
}

Rect::~Rect()
{
	SDL_DestroyTexture(_player_texture);

}

void Rect::draw() const
{
	SDL_Rect rect = { _x, _y, _w, _h };
		SDL_RenderCopy(Window::renderer, _player_texture, nullptr, &rect);

}


void Rect::anim()
{
	auto surface = IMG_Load(imagepath.c_str());
	if (!surface)
	{
		cerr << "Surface nesusikure" << endl;
	}
	_player_texture = SDL_CreateTextureFromSurface(Window::renderer, surface);

	if (!_player_texture)
	{
		cerr << "Nesukure texturos" << endl;
	}
	SDL_FreeSurface(surface);
}


void Rect::go(int &x, int &y, bool u, bool d, bool l, bool r)
{
	//cout << u << d << l << r << endl;
	//cout << gox << " " << goy << endl;

	//AMIMATION
	imagepathtemp = imagepath;
	if(gox==1)imagepath = _ra;
	if(gox==-1)imagepath = _la;
	if(goy==1)imagepath = _fa;
	if(goy==-1)imagepath = _ba;
	if (gox == 0 && goy == 0)imagepath = _fa;

	if (imagepathtemp != imagepath)
	{
		anim();
		imagepathtemp = imagepath;
	}

	//MOVEMENT
	if (gox == 1) { if (r)_x += 5; }
	else if (gox == -1) { if (l)_x -= 5; }

	 if (goy == 1){if (d)_y += 5; }
	else if (goy == -1) { if (u)_y -= 5; }
	/*
	if (gox == 1)_x += 10;
	else if (gox == -1)_x -= 10;

	if (goy == 1)_y += 10;
	else if (goy == -1) { if (d)_y -= 10;
	*/

	x = _x;
	y = _y;
	//cout << x <<" "<< y << endl;

}


void Rect::pollEvents(SDL_Event &event, Bomb &bomb)
{
	

	if (event.type == SDL_KEYDOWN)
	{
		if (event.key.keysym.sym == _l)
		{
		//cout << "TU SPAUDI \"A\"" << endl;
		//imagepath = "resources/player1l.png";
		gox = -1;
		}
		if (event.key.keysym.sym == _r)
		{
			//cout << "TU SPAUDI \"D\"" << endl;
			//imagepath = "resources/player1r.png";
			gox = 1;
		}
		if (event.key.keysym.sym == _f)
		{
			//cout << "TU SPAUDI \"W\"" << endl;
			//imagepath = "resources/player1b.png";
			goy = -1;
		}
		if (event.key.keysym.sym == _b)
		{
			//cout << "TU SPAUDI \"S\"" << endl;
			//imagepath = "resources/player1f.png";
			goy = 1;
		}
		if (event.key.keysym.sym == _pb)
		{
			cout << "TU SPAUDI \"SPACE\"" << endl;
			bomb.load(_x, _y, 1);
		}

	
	}

	if (event.type == SDL_KEYUP)
	{
		if (event.key.keysym.sym == _l)
		{
			//cout << "TU SPAUDI \"A\"" << endl;
			//imagepath = "resources/player1l.png";
			gox = 0;
		}
		if (event.key.keysym.sym == _r)
		{
			//cout << "TU SPAUDI \"D\"" << endl;
			//imagepath = "resources/player1r.png";
			gox = 0;
		}
		if (event.key.keysym.sym == _f)
		{
			//cout << "TU SPAUDI \"W\"" << endl;
			//imagepath = "resources/player1b.png";
			goy = 0;
		}
		if (event.key.keysym.sym == _b)
		{
			//cout << "TU SPAUDI \"S\"" << endl;
			//imagepath = "resources/player1f.png";
			goy = 0;
		}

	}
}