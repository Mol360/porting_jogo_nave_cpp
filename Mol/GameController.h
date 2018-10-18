#pragma once
#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "Mol/InputManager.h"
#include "Mol/Nave/PlayerShip.h"
#include <iostream>
#include <stdio.h>

using namespace std;

class GameController{
	private:
		int window_width;
		int window_height;
		string game_name;
		SDL_Surface * screen;
		PlayerShip player;
		InputManager * input;
	protected:

	public:
		int getWindowWidth();
		int getWindowHeight();
		string getGameName();
		SDL_Surface getScreen();
		InputManager getInputManager();
		PlayerShip getPlayer();
		void load();
		void draw();
		void update();
		bool isPressClose();
		void quit();
};
