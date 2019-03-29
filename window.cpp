#include "window.h"
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>
using namespace std;

SDL_Renderer* Window::renderer = nullptr;

Window::Window(const string &title, int width, int height, const string &image_path)
{
	_title = title;
	_width = width;
	_height = height;
	_closed = !init();


	//BACKGROUND
	//SDL_Surface* surface = IMG_Load(image_path.c_str());
	auto surface = IMG_Load(image_path.c_str());
	if (!surface)
	{
		cerr << "Surface nesusikure" << endl;
	}
	_background_texture = SDL_CreateTextureFromSurface(renderer, surface);

	if (!_background_texture)
	{
		cerr << "Nesukure texturos" << endl;
	}
	SDL_FreeSurface(surface);
}

Window::~Window()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(_window);
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}

bool Window::init()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		cerr << "SDL nepasileido" << endl;
		return false;
	}

	if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG)
	{
		cerr << "SDL_IMAGE nepasileido" << endl;
		return false;
	}

	if (TTF_Init() == -1)
	{
		cerr << "SDL_ttf nepasileido" << endl;
		return false;
	}

	_window = SDL_CreateWindow(_title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _width, _height, 0);

	if (_window == nullptr)
	{
		cerr << "LANGAS NESUSIKURE" << endl;
		return 0;
	}

	//_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
	renderer = SDL_CreateRenderer(_window, -1, 0);

	if (renderer == nullptr)
	{
			cerr << "RENDERERIS NESUSIKURE" << endl;
			return false;
	}

	return true;
}

void Window::pollEvents(SDL_Event &event)
{
	switch (event.type)
	{
	case SDL_QUIT:
		_closed = true;
		break;
	case  SDL_KEYDOWN:
		switch (event.key.keysym.sym)
		{
		case SDLK_ESCAPE:
			_closed = true;
			break;
		}
		break;
	case SDL_MOUSEMOTION:
		cout << "X= " << event.motion.x << " Y= " << event.motion.y << endl;
		break;
	case SDL_MOUSEBUTTONDOWN:
		cout << "SPAUDI PELE " << endl;
		break;

	default:
		break;
	}
}
void Window::clear()const
{
	SDL_RenderPresent(renderer);
	SDL_SetRenderDrawColor(renderer, 157, 143, 143, 255);
	SDL_RenderClear(renderer);
}
void Window::drawbackground()const
{
	SDL_Rect rect = { 0, 0, _width,_height };
	SDL_RenderCopy(Window::renderer, _background_texture, nullptr, &rect);
}