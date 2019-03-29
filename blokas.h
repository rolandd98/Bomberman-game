#pragma once

#include "window.h"
#include <string>
using namespace std;

class Block
{
private:

	int _w, _h;
	SDL_Texture * _block_texture = nullptr;
public:
	Block(int w, int h, const string &image_path);

	~Block();

	void draw(int x, int y) const;
	//void pollEvents(SDL_Event &event);
};