#include <stdio.h>
#include <string>
#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "Mol/InputManager.h"
#include "Mol/Nave/PlayerShip.h"
#include "Mol/GameController.h"

using namespace std;

int main(){

	cout << "Teste" << endl;

	GameController game_controller;
	game_controller.load();

	int done = 0;
	while(done == 0){
		game_controller.update();

		if(game_controller.isPressClose() == true){
			done = 1;
		}else{
			game_controller.draw();
		}
	}

	game_controller.quit();

	return 0;
}