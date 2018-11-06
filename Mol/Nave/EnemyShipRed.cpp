#include "EnemyShipRed.h"

void EnemyShipRed::load(){
	this->setShipName("Red Enemy");
	this->setImageShip("nave_inimigo2.png");
	SpaceShip::load();
	this->shot_value = 50;
}
