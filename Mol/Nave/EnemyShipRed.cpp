#include "EnemyShipRed.h"

void EnemyShipRed::load(){
	this->setShipName("Red Enemy");
	this->setImageShip("nave_inimigo2.png");
	SpaceShip::load();
	this->shot_value = 50;
	this->bullet_vel = 5;
	this->delay_shoot_miliseconds = 2300;
}

int EnemyShipRed::gotShot(){
	int r_life = SpaceShip::gotShot();
	return r_life;
}