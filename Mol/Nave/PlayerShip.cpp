#include "PlayerShip.h"
#include "../GameController.h"

using namespace std;

void PlayerShip::load(){
	this->setShipName("Player");
	this->setImageShip("nave_player.png");
	SpaceShip::load();
}

void PlayerShip::setInputManager(InputManager* n_input){
	this->input = n_input;
}

void PlayerShip::update(){
	this->controlMovement();
}

void PlayerShip::controlMovement(){
	int velX = 0;
        int velY = 0;
        int space_ship_vel = 5;

        if(this->input->isPressRight() == true && this->getPosX() < GameController::getWindowWidth()){
	        cout << "Pressionado Right" << endl;
                velX = space_ship_vel;
        }
        if(this->input->isPressLeft() == true && this->getPosX() > 0){
                cout << "Pressionado Left" << endl;
                velX = -space_ship_vel;
        }
                        
        if(this->input->isPressDown() == true && this->getPosY() < GameController::getWindowHeight()){
        	cout << "Pressionado Down" << endl;
                velY = space_ship_vel;
        }
        if(this->input->isPressUp() == true && this->getPosY() > 0){
        	cout << "Pressionado Up" << endl;
                velY = -space_ship_vel;
        }

	this->moveX(velX);
        this->moveY(velY);
}
