#include "LifeBar.h"

void LifeBar::load(){
	this->is_life_bar_on = true;

	life_bar_on = ObjectBase();
	life_bar_on.setImageObj("life_bar_on.png");
	life_bar_on.setScreen(this->screen);
	life_bar_on.load();

	life_bar_off = ObjectBase();
	life_bar_off.setImageObj("life_bar_off.png");
	life_bar_off.setScreen(this->screen);
	life_bar_off.load();
}

void LifeBar::update(){
	if(this->is_life_bar_on == true){
		this->life_bar_on.update();
	}else{
		this->life_bar_off.update();
	}
}

void LifeBar::draw(){
	if(this->is_life_bar_on == true){
		this->life_bar_on.draw();
	}else{
		this->life_bar_off.draw();
	}
}

void LifeBar::setPosX(int n_pos_x){
	this->life_bar_on.setPosX(n_pos_x);
	this->life_bar_off.setPosX(n_pos_x);
}

void LifeBar::setPosY(int n_pos_y){
	this->life_bar_on.setPosY(n_pos_y);
	this->life_bar_off.setPosY(n_pos_y);
}

void LifeBar::setLifeBarOn(){
	this->is_life_bar_on = true;
}

void LifeBar::setLifeBarOff(){
	this->is_life_bar_on = false;
}

void LifeBar::setScreen(SDL_Surface * n_screen){
	this->screen = n_screen;
}

bool LifeBar::isLifeBarOn(){
	return this->is_life_bar_on;
}