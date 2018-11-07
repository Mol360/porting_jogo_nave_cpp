#pragma once
#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "InputManager.h"
#include "BackgroundController.h"
#include "Nave/PlayerShip.h"
#include "Nave/EnemyShipRed.h"
#include "Nave/EnemyShipBlue.h"
#include "Nave/SpaceShip.h"
#include "ObjectBase.h"
#include <iostream>
#include <stdio.h>

using namespace std;

class GameController{
	private:
		static int window_width;
		static int window_height;
		std::vector<std::vector<SpaceShip>> enemies;
		int enemy_qtt_col;
		int enemy_qtt_row;
		int enemy_shoot_proximity;
		int enemy_speed_x;
		int enemy_speed_y;
		bool enemy_moves_y;
		Uint64 enemy_movement_timer;
		int enemy_movement_delay;
		string game_name;
		BackgroundController background_controller;
		SDL_Surface * screen;
		PlayerShip player;
		EnemyShipRed enemy;
		ObjectBase tiro_t;
		InputManager input;
		void enemiesUpdate();
		void controlEnemiesMovement();
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
