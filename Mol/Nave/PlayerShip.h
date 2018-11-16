#pragma once
#include "SpaceShip.h"
#include "../InputManager.h"
#include "../Hud/HudController.h"
#include <iostream>

class PlayerShip: public SpaceShip{

	private:
        InputManager* input;
        HudController* hud_controller;
		void controlMovement();
	public:
		void load();
		void update();
		void setInputManager(InputManager* n_input);
		void setHudController(HudController* n_hud_controller);
		int gotShot();
};
