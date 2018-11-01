#include "SpaceShip.h"

void SpaceShip::setShipName(std::string n_ship_name){
	this->ship_name = n_ship_name;
}

std::string SpaceShip::getShipName(){
	return this->ship_name;    
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
	if(this->ship_image == ""){
		this->ship_image = "nave_player.png";
	}
	std::string tmp_image = "imgs/"+this->ship_image;
	this->ship_obj = IMG_Load(tmp_image.c_str()); // Carrega a imagem
	this->life = 100;
	this->shot_value = 20;
	this->ship_name = "Nave";
	this->vel_x = 0;
	this->vel_y = 0;
	this->dest = {0,0,0,0}; // Destino da imagem no screen
}

std::string SpaceShip::getImageShip(){
    return this->ship_image;
}

void SpaceShip::setImageShip(std::string n_ship_image){
	this->ship_image = n_ship_image;
}

void SpaceShip::update(){
	
}

void SpaceShip::draw(){
	SDL_BlitSurface(this->ship_obj, NULL, this->screen, &this->dest); // Blita a imagem em dest
}

void SpaceShip::setScreen(SDL_Surface * n_screen){
	this->screen = n_screen;
}

int SpaceShip::getPosX(){
        return this->dest.x;
}

int SpaceShip::getPosY(){
	return this->dest.y;
}

void SpaceShip::setPosX(int n_pos_x){
	this->dest.x = n_pos_x;
}

void SpaceShip::setPosY(int n_pos_y){
	this->dest.y = n_pos_y;
}

void SpaceShip::moveX(int n_vel_x){
        this->dest.x = this->dest.x + n_vel_x;
}

void SpaceShip::moveY(int n_vel_y){
        this->dest.y = this->dest.y + n_vel_y;
}

void SpaceShip::setVelY(int n_vel_y){
	this->vel_y = n_vel_y;
}

void SpaceShip::setVelX(int n_vel_x){
	this->vel_x = n_vel_x;
}

int SpaceShip::getHeight(){
	return this->ship_obj->h;
}

int SpaceShip::getWidth(){
	return this->ship_obj->w;
}

void SpaceShip::addEnemy(SpaceShip *n_enemy){
	this->enemies.push_back(n_enemy);
}
