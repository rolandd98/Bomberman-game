#include <SDL_image.h>
#include <iostream>
#include <string>
#include "blokas.h"
using namespace std;



Block::Block(int w, int h, const string &image_path)
{
	_w = w;
	_h = h;

	//SDL_Surface* surface = IMG_Load(image_path.c_str());
	auto surface = IMG_Load(image_path.c_str());
	if (!surface)
	{
		cerr << "Surface nesusikure" << endl;
	}
	_block_texture = SDL_CreateTextureFromSurface(Window::renderer, surface);

	if (!_block_texture)
	{
		cerr << "Nesukure texturos" << endl;
	}
	SDL_FreeSurface(surface);
}

Block::~Block()
{
	SDL_DestroyTexture(_block_texture);

}

void Block::draw(int x, int y) const
{
	SDL_Rect rect = { x, y, _w, _h };
	SDL_RenderCopy(Window::renderer, _block_texture, nullptr, &rect);
}
