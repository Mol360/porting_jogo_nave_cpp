#include "EnemyShipBlue.h"

void EnemyShipBlue::load(){
	this->setShipName("Blue Enemy");
	this->setImageShip("nave_inimigo1.png");
	SpaceShip::load();
	this->shot_value = 100;
	this->delay_shoot_miliseconds = 2600;
}

int EnemyShipBlue::gotShot(){
	int r_life = SpaceShip::gotShot();
	return r_life;
}
