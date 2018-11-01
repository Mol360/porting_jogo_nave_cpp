#include "SpaceShip.h"
#include "../GameController.h"

void SpaceShip::setShipName(std::string n_ship_name){
	this->object_name = n_ship_name;
}

std::string SpaceShip::getShipName(){
	return this->object_name;    
}

int SpaceShip::getLife(){
	return this->life;
}

void SpaceShip::setLife(int n_tot_life){
	this->life = n_tot_life;
}

void SpaceShip::setShotValue(int n_shot_value){
	this->shot_value = n_shot_value;
}

int SpaceShip::gotShot(){
	this->life = this->life - this->shot_value;
}

void SpaceShip::load(){
	//SDL_Surface * ship_obj;
	if(this->object_image == ""){
		this->object_image = "nave_player.png";
	}
	ObjectBase::load();
	this->max_num_of_shots = 5;
	this->bullet_vel = 10;
	this->life = 100;
	this->shot_value = 20;
	this->object_name = "Nave";
	this->vel_x = 0;
	this->vel_y = 0;
	this->dest = {0,0,0,0}; // Destino da imagem no screen
}

std::string SpaceShip::getImageShip(){
    return this->object_image;
}

void SpaceShip::setImageShip(std::string n_ship_image){
	this->object_image = n_ship_image;
}

void SpaceShip::shoot(){
	if(this->arr_bullets.size() < this->max_num_of_shots){
		ObjectBase tiro_t = ObjectBase();
		tiro_t.setScreen(this->screen);
		tiro_t.load();

		int n_pos_x = this->getPosX()+(this->getWidth()/2);
		int n_pos_y = this->getPosY();

		tiro_t.setPosX(n_pos_x);
		if(this->bullet_vel > 0){
			n_pos_y = this->getPosY()+this->getHeight();
		}
		tiro_t.setPosY(n_pos_y);

		this->arr_bullets.push_back(tiro_t);
	}
}

void SpaceShip::update(){
	if(this->arr_bullets.size() > 0){
		for (unsigned i=0; i<this->arr_bullets.size(); ++i){
			ObjectBase& tmp_bullet = arr_bullets[i];
			if(tmp_bullet.getPosY() > GameController::getWindowHeight() || tmp_bullet.getPosY() <= 0){
				arr_bullets.erase(arr_bullets.begin()+i);
			}else{
				tmp_bullet.moveY(this->bullet_vel);
				tmp_bullet.update();
			}
		}
	}
}

void SpaceShip::draw(){
	ObjectBase::draw();

	if(this->arr_bullets.size() > 0){
		for (unsigned i=0; i < this->arr_bullets.size(); ++i){
			ObjectBase& tmp_bullet = arr_bullets[i];
			tmp_bullet.draw();
		}
	}
}

void SpaceShip::setVelY(int n_vel_y){
	this->vel_y = n_vel_y;
}

void SpaceShip::setVelX(int n_vel_x){
	this->vel_x = n_vel_x;
}

void SpaceShip::addEnemy(SpaceShip *n_enemy){
	this->enemies.push_back(n_enemy);
}
