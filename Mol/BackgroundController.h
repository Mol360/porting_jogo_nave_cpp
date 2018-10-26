#pragma once
#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

class BackgroundController{

	protected:
		SDL_Surface * background_01;
		SDL_Surface * background_02;
		SDL_Surface * screen;
		std::string background_image;
		SDL_Rect bg_dest_01;
		SDL_Rect bg_dest_02;
		int speed;
	public:
		void setScreen(SDL_Surface * n_screen);
		void update();
		void draw();
		void load();
};
