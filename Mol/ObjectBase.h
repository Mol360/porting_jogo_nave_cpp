#pragma once
#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <vector>

class ObjectBase{

	protected:
		SDL_Surface * base_obj;
		SDL_Surface * screen; // A janela principal
		std::string object_name;
		std::string object_image;
		int pos_x;
		int pos_y;
		SDL_Rect dest;
		bool is_visible;
	public:
		int getPosX();
		int getPosY();
		int getWidth();
		int getHeight();
		void setPosX(int n_pos_x);
		void setPosY(int n_pos_y);
		void setScreen(SDL_Surface * n_screen);
		void setObjName(std::string n_obj_name);
		std::string getObjName();
		void setImageObj(std::string n_obj_image);
		std::string getImageObj();
		void moveX(int n_vel_x);
		void moveY(int n_vel_y);
		void hide();
		void show();
		bool isVisible();
		void update();
		void draw();
		void load();

};
