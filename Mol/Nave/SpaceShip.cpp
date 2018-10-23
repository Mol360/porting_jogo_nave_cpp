#include "SpaceShip.h"

void SpaceShip::setShipName(std::string n_ship_name){
	ship_name = n_ship_name;
}

std::string SpaceShip::getShipName(){
	return ship_name;    
}

int SpaceShip::getLife(){
	return life;
}

void SpaceShip::setLife(int n_tot_life){
	life = n_tot_life;
}

void SpaceShip::setShotValue(int n_shot_value){
	shot_value = n_shot_value;
}

int SpaceShip::gotShot(){
	life = life - shot_value;
}

void SpaceShip::load(){
	//SDL_Surface * ship_obj;
	if(ship_image == ""){
		ship_image = "nave_player.png";
	}
	std::string tmp_image = "imgs/"+ship_image;
	ship_obj = IMG_Load(tmp_image.c_str()); // Carrega a imagem
	life = 100;
	shot_value = 20;
	ship_name = "Nave";
	vel_x = 0;
	vel_y = 0;
	dest = {0,0,0,0}; // Destino da imagem no screen
}

std::string SpaceShip::getImageShip(){
    return ship_image;
}

void SpaceShip::setImageShip(std::string n_ship_image){
	ship_image = n_ship_image;
}

void SpaceShip::update(){
	
}

void SpaceShip::draw(){
	SDL_BlitSurface(ship_obj, NULL, screen, &dest); // Blita a imagem em dest
}

void SpaceShip::setScreen(SDL_Surface * n_screen){
	screen = n_screen;
}

int SpaceShip::getPosX(){
        return dest.x;
}

int SpaceShip::getPosY(){
	return dest.y;
}

void SpaceShip::setPosX(int n_pos_x){
	dest.x = n_pos_x;
}

void SpaceShip::setPosY(int n_pos_y){
	dest.y = n_pos_y;
}

void SpaceShip::moveX(int n_vel_x){
        dest.x = dest.x + n_vel_x;
}

void SpaceShip::moveY(int n_vel_y){
        dest.y = dest.y + n_vel_y;
}

void SpaceShip::setVelY(int n_vel_y){
	vel_y = n_vel_y;
}

void SpaceShip::setVelX(int n_vel_x){
	vel_x = n_vel_x;
}

int SpaceShip::getHeight(){
	return ship_obj->h;
}

int SpaceShip::getWidth(){
	return ship_obj->w;
}
