#include "SpaceShip.h"

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

void SpaceShip::update(){
	
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
