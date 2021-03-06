#include "text.h"
#include "window.h"
#include <iostream>
#include <string>
using namespace std;




Text::Text(const string &font_path, int font_size, string message_text, const SDL_Color &color)
{
	_text_texture = loadFont(font_path, font_size, message_text, color);
	SDL_QueryTexture(_text_texture, nullptr, nullptr, &_text_rect.w, &_text_rect.h);
}

void Text::display(int x, int y) const
{
	_text_rect.x = x;
	_text_rect.y = y;
	SDL_RenderCopy(Window::renderer, _text_texture, nullptr, &_text_rect);
}

SDL_Texture* Text::loadFont(const string &font_path, int font_size, string &message_text, const SDL_Color &color)
{
	TTF_Font* font = TTF_OpenFont(font_path.c_str(), font_size);
	if (!font)
	{
		cerr << "Font nepasileido" << endl;
	}
	auto text_surface = TTF_RenderText_Solid(font, message_text.c_str(), color);
	if (!text_surface)
	{
		cerr << "Text_surface nepasileido" << endl;
	}
	//SDL_Texture text_texture =
	auto text_texture = SDL_CreateTextureFromSurface(Window::renderer, text_surface);
	if (!text_texture)
	{
		cerr << "Text_texture nepasileido" << endl;
	}
	SDL_FreeSurface(text_surface);
		return text_texture;
}