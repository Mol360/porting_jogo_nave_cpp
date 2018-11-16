#pragma once
#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../ObjectBase.h"

class LifeBar{
	private:
		ObjectBase life_bar_on;
		ObjectBase life_bar_off;
		bool is_life_bar_on;
		SDL_Surface * screen;
	protected:

	public:
		void setPosX(int n_pos_x);
		void setPosY(int n_pos_y);
		void setScreen(SDL_Surface * n_screen);
		void update();
		void load();
		void draw();
		void setLifeBarOn();
		void setLifeBarOff();
		bool isLifeBarOn();
};
