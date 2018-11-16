#include "HudController.h"
#include "../GameController.h"

using namespace std;

void HudController::load(){
	if(this->total_life > 0){
		for(int i = 0; i < this->total_life/20; i++){
			LifeBar n_lifebar = LifeBar();
			n_lifebar.setScreen(this->screen);
			n_lifebar.load();
			n_lifebar.setPosX(10+(i*25));
			//n_lifebar.setPosY(GameController::getWindowHeight()-30);
			n_lifebar.setPosY(10);
			this->arr_life_bar.push_back(n_lifebar);
		}
	}
}

void HudController::update(){
	if(this->arr_life_bar.size() > 0){
		for(int i = 0; i < this->arr_life_bar.size(); i++){
			this->arr_life_bar[i].update();
		}
	}
}

void HudController::draw(){
	if(this->arr_life_bar.size() > 0){
		for(int i = 0; i < this->arr_life_bar.size(); i++){
			this->arr_life_bar[i].draw();
		}
	}
}

void HudController::setScreen(SDL_Surface * n_screen){
	this->screen = n_screen;
}

void HudController::setTotalPlayerLife(int n_total_life){
	this->total_life = n_total_life;
}

void HudController::lessOneLife(){
	if(this->arr_life_bar.size() > 0){
		for(int i = this->arr_life_bar.size(); i >= 0; --i){
			if(this->arr_life_bar[i].isLifeBarOn() == true){
				this->arr_life_bar[i].setLifeBarOff();
				break;
			}
		}
	}
}