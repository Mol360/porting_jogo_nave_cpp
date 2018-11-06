#pragma once
#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <vector>
#include "../ObjectBase.h"
#include <time.h>

class SpaceShip: public ObjectBase{
	private:
		void validateShootDelay();
	protected:
		std::vector<SpaceShip *> enemies;
		int max_num_of_shots;
		int bullet_vel;
		std::vector<ObjectBase> arr_bullets;
		int vel_x;
		int vel_y;
		int life;
		int shot_value;
		Uint64 shoot_delay_timer;
		bool can_shoot;
		int delay_shoot_miliseconds;
		void updateShotEnemies(ObjectBase& tmp_bullet, unsigned int bullet_index);
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
		void shoot();
		void update();
		void load();
		void draw();
		void addEnemy(SpaceShip *n_enemy);

};
