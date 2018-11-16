#pragma once
#include <string>
#include "LifeBar.h"
#include <iostream>
#include <stdio.h>

using namespace std;

class HudController{
	private:
		SDL_Surface * screen;
		std::vector<LifeBar> arr_life_bar;
		int total_life;
	protected:

	public:
		void load();
		void draw();
		void update();
		void setScreen(SDL_Surface * n_screen);
		void setTotalPlayerLife(int n_total_life);
		void lessOneLife();
};
