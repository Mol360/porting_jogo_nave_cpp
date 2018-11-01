#pragma once
#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <vector>
#include "../ObjectBase.h"

class SpaceShip: public ObjectBase{

	protected:
		std::vector<SpaceShip *> enemies;
		int vel_x;
		int vel_y;
		int life;
		int shot_value;
	public:
		void setVelX(int n_vel_x);
		void setVelY(int n_vel_y);
		void setShipName(std::string n_ship_name);
		std::string getShipName();
		void setImageShip(std::string n_ship_image);
		std::string getImageShip();
		int getLife();
		void setLife(int n_tot_life);
		void setShotValue(int n_shot_value);
		int gotShot();
		void update();
		void load();
		void addEnemy(SpaceShip *n_enemy);

};
