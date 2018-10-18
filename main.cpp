#include <stdio.h>
#include <string>
#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "Mol/InputManager.h"
#include "Mol/Nave/PlayerShip.h"

using namespace std;

int main(){

	cout << "Teste" << endl;

	SDL_Init(SDL_INIT_VIDEO); // Inicializa o SDL e o sistema de vídeo
	SDL_Surface * screen; // A janela principal

  	screen = SDL_SetVideoMode(640, 480, 16, SDL_SWSURFACE); // Cria a janela

	InputManager input;
	input.load();

	PlayerShip player;
	player.setScreen(screen);
	player.load();

	int done = 0;
	while(done == 0){
		input.update();

		if(input.isPressClose() == true){
			done = 1;
		}else{

   	 		SDL_FillRect(screen, NULL, 0x0); // Pinta todo o screen de preto
			player.setInputManager(input);
			player.update();
			player.draw();
    			SDL_UpdateRect(screen, 0,0,0,0); // Atualiza todo o screen
    			SDL_Delay(30); // Espera 60 milissegundos
		}
	}

	SDL_Quit(); // Fecha o SDL
	return 0;
}
