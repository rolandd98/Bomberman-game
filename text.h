#pragma once

#include <SDL_ttf.h>
#include <SDL.h>
#include <string>
#include "window.h"
using namespace std;


class Text
{
	SDL_Texture* _text_texture = nullptr;
	mutable SDL_Rect _text_rect;

public:
	Text(const string &font_path, int font_size, string message_text, const SDL_Color &color);

	void display(int x, int y) const;

	static SDL_Texture* loadFont(const string &font_path, int font_size, string &message_text, const SDL_Color &color);

private:

};