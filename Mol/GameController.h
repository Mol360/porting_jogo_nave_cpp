#pragma once
#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "InputManager.h"
#include "BackgroundController.h"
#include "Nave/PlayerShip.h"
#include "Nave/EnemyShipRed.h"
#include "ObjectBase.h"
#include <iostream>
#include <stdio.h>

using namespace std;

class GameController{
	private:
		static int window_width;
		static int window_height;
		string game_name;
		BackgroundController background_controller;
		SDL_Surface * screen;
		PlayerShip player;
		EnemyShipRed enemy;
		ObjectBase tiro_t;
		InputManager input;
	protected:

	public:
		static int getWindowWidth();
		static int getWindowHeight();
		string getGameName();
		SDL_Surface getScreen();
		InputManager getInputManager();
		PlayerShip getPlayer();
		void load();
		void draw();
		void update();
		bool isPressClose();
		void quit();
		void controlaFps(int tempo_inicial);
};
