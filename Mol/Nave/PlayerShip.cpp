#include "PlayerShip.h"

using namespace std;

void PlayerShip::load(){
	this->setShipName("Player");
	this->setImageShip("nave_player.png");
	SpaceShip::load();
}

void PlayerShip::setInputManager(InputManager n_input){
	this->input = n_input;
}

void PlayerShip::update(){
	this->controlMovement();
}

void PlayerShip::controlMovement(){
	int velX = 0;
        int velY = 0;

        if(this->input.isPressRight() == true){
	        cout << "Pressionado Right" << endl;
                velX = 5;
        }
        if(this->input.isPressLeft() == true){
                cout << "Pressionado Left" << endl;
                velX = -5;
        }
                        
        if(this->input.isPressDown() == true){
        	cout << "Pressionado Down" << endl;
                velY = 5;
        }
        if(this->input.isPressUp() == true){
        	cout << "Pressionado Up" << endl;
                velY = -5;
        }

	this->moveX(velX);
        this->moveY(velY);
}
