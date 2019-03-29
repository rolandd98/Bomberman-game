#include <SDL.h>
#include <iostream>
#include <string>
#include <vector>
#include "window.h"
#include "rect.h"
#include "text.h"
#include "blokas.h"
#include "map.h"
#include "collision.h"
#include "bomb.h"
using namespace std;


void pollEvents(Window &window, Rect &rect1, Rect &rect2, Bomb &bomb)
{
	SDL_Event event;

	if (SDL_PollEvent(&event))
	{
		rect1.pollEvents(event, bomb);
		rect2.pollEvents(event, bomb);
		window.pollEvents(event);
	}

}



int main(int argc, char** argv)
{
	

	//fps
	const int FPS = 80;
	const int frameDelay = 1000 / FPS;
	Uint32 frameStart;
	int frameTime;
	//collision

	int p1x = 30, p1y = 103;
	int p2x = 700, p2y = 493;

	bool test1 = false;
	bool test2 = false;

	bool p1u = true;
	bool p1d = true;
	bool p1l = true;
	bool p1r = true;
	bool p2u = true;
	bool p2d = true;
	bool p2l = true;
	bool p2r = true;


	//blokai
	//kieti
	vector<int> x1, x2, y1, y2;
	//minksti
	vector<int> xm1, xm2, ym1, ym2;

	SDLK_DOWN;
	SDLK_UP;
	SDLK_LEFT;
	SDLK_RIGHT;

	Window window("LANGAS", 800, 600, "resources/background.png");
	Rect rect1(64, 64, p1x, p1y, 119, 115, 97, 100, 32, "resources/player1f.png", "resources/player1b.png", "resources/player1l.png", "resources/player1r.png");
	Rect rect2(64, 64, p2x, p2y, 1073741906, 1073741905, 1073741904, 1073741903, 92, "resources/player2f.png", "resources/player2b.png", "resources/player2l.png", "resources/player2r.png");
	//Rect rect(64, 64, 100, 100, "resources/drift.png");
	Text text("resources/arial.TTF", 40, "BOMBMAN", { 62, 56, 56, 255 });
	Text text1("resources/arial.TTF", 40, "1 PLAYER WON", { 62, 56, 56, 255 });
	Text text2("resources/arial.TTF", 40, "2 PLAYER WON", { 62, 56, 56, 255 });
	Map map(115, 187);
	Liecia liecia(30,103,764,577);
	//Block bomb(40, 40, "resources/bomb.png");
	Bomb bomb(64, 64, "resources/bomb.png", "resources/sujungimas.png");
	//Bomb bomb(64,64,"resources/bomb.png", "resources/explosion.png");
	
	map.store(64, 3, 5, x1, y1, x2, y2, xm1, ym1, xm2, ym2);
	
	//cout << x1.size() << endl;
	
	for (int i = 0; i < x1.size(); i++)
	{
		cout << x1[i] << " " << y1[i] << endl;
	}

	for (int i = 0; i < xm1.size(); i++)
	{
		cout << xm1[i] << " " << ym1[i] << endl;
	}


		//PAGRINDINIS ZAIDIMO CIKLAS
		while (!window.isClosed())
		{
			frameStart = SDL_GetTicks();


			pollEvents(window, rect1, rect2 , bomb);
			window.drawbackground();
			liecia.check(p1x, p1y, p1u, p1d, p1l, p1r, x1, y1, x2, y2, xm1, ym1, xm2, ym2);
			liecia.check(p2x, p2y, p2u, p2d, p2l, p2r, x1, y1, x2, y2, xm1, ym1, xm2, ym2);
			rect1.go(p1x, p1y, p1u, p1d, p1l, p1r);
			rect2.go(p2x, p2y, p2u, p2d, p2l, p2r);
			//block.draw();
			rect1.draw();
			rect2.draw();
			map.draw(x1,y1,xm1,ym1);
			bomb.draw();
			bomb.time(1);
			bomb.time(2);
			bomb.checkb(xm1, ym1, xm2, ym2);
			bomb.checkp(p1x, p1y, test1);
			bomb.checkp(p2x, p2y, test2);


			text.display(500, 20);
			window.clear();



			if (test1 || test2)break;


			frameTime = SDL_GetTicks() - frameStart;

			if (frameDelay > frameTime)
			{
				SDL_Delay(frameDelay - frameTime);
			}

		}
		//PABAIGOS CIKLAS
		while (!window.isClosed())
		{
			frameStart = SDL_GetTicks();


			pollEvents(window, rect1, rect2, bomb);

			if(test2)text1.display(250, 300);
			else text2.display(250, 300);
			window.clear();

			frameTime = SDL_GetTicks() - frameStart;

			if (frameDelay > frameTime)
			{
				SDL_Delay(frameDelay - frameTime);
			}

		}




	return 0;
}