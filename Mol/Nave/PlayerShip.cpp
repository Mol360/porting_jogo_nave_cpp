#include "PlayerShip.h"
#include "../GameController.h"

using namespace std;

void PlayerShip::load(){
	this->setShipName("Player");
	this->setImageShip("nave_player.png");
        SpaceShip::load();
        this->bullet_vel = -10;
        this->shot_value = 20;
}

void PlayerShip::setInputManager(InputManager* n_input){
	this->input = n_input;
}

void PlayerShip::update(){
	this->controlMovement();
        SpaceShip::update();
}

void PlayerShip::controlMovement(){
	int velX = 0;
        int velY = 0;
        int space_ship_vel = 5;

        if(this->input->isPressRight() == true && this->getPosX() < (GameController::getWindowWidth() - this->getWidth())){
	        cout << "Pressionado Right" << endl;
                velX = space_ship_vel;

                cout << "Pos " << this->getPosX() << "x" << this->getPosY() << endl;
        }
        if(this->input->isPressLeft() == true && this->getPosX() > 0){
                cout << "Pressionado Left" << endl;
                velX = -space_ship_vel;

                cout << "Pos " << this->getPosX() << "x" << this->getPosY() << endl;
        }
                        
        if(this->input->isPressDown() == true && this->getPosY() < (GameController::getWindowHeight() - this->getHeight())){
        	cout << "Pressionado Down" << endl;
                velY = space_ship_vel;

                cout << "Pos " << this->getPosX() << "x" << this->getPosY() << endl;
        }
        if(this->input->isPressUp() == true && this->getPosY() > 0){
        	cout << "Pressionado Up" << endl;
                velY = -space_ship_vel;

                cout << "Pos " << this->getPosX() << "x" << this->getPosY() << endl;
        }

        if(this->input->isPressSpacebar() == true){
                this->shoot();
        }

	this->moveX(velX);
        this->moveY(velY);
}
