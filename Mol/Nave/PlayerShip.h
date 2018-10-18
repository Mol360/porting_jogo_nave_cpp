#pragma once
#include "SpaceShip.h"
#include "../InputManager.h"
#include <iostream>

class PlayerShip: public SpaceShip{

	private:
        InputManager input;
		void controlMovement();
	public:
		void load();
		void update();
		void setInputManager(InputManager n_input);
};
