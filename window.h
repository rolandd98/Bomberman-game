#pragma once

#include <string>
#include <SDL.h>
using namespace std;

class Window
{
private:
	bool init();


private:
	string _title;
	int _width, _height;

	bool _closed = false;

	SDL_Window* _window = nullptr;
	SDL_Texture * _background_texture = nullptr;

public:
	static SDL_Renderer* renderer;

public:
	Window(const string &title, int width, int height, const string &image_path);
	~Window();
	void pollEvents(SDL_Event &event);
	void clear()const;
	void drawbackground()const;
	inline bool isClosed() const { return _closed;  }

};