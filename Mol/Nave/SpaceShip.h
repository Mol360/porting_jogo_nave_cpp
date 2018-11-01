#pragma once
#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <vector>

class SpaceShip{

	protected:
		SDL_Surface * ship_obj;
		SDL_Surface * screen; // A janela principal
		std::string ship_name;
		std::string ship_image;
		std::vector<SpaceShip *> enemies;
		int pos_x;
		int pos_y;
		int vel_x;
		int vel_y;
		SDL_Rect dest;
		int life;
		int shot_value;
	public:
		int getPosX();
		int getPosY();
		int getWidth();
		int getHeight();
		void setPosX(int n_pos_x);
		void setPosY(int n_pos_y);
		void setVelX(int n_vel_x);
		void setVelY(int n_vel_y);
		void setScreen(SDL_Surface * n_screen);
		void setShipName(std::string n_ship_name);
		std::string getShipName();
		void setImageShip(std::string n_ship_image);
		std::string getImageShip();
		int getLife();
		void setLife(int n_tot_life);
		void setShotValue(int n_shot_value);
		int gotShot();
		void moveX(int n_vel_x);
		void moveY(int n_vel_y);
		void update();
		void draw();
		void load();
		void addEnemy(SpaceShip *n_enemy);

};
