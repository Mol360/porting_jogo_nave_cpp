#include "GameController.h"

int GameController::getWindowWidth(){
	return this->window_width;
}

int GameController::getWindowHeight(){
	return this->window_height;
}

string GameController::getGameName(){
	return this->game_name;
}

void GameController::load(){
	SDL_Init(SDL_INIT_VIDEO); // Inicializa o SDL e o sistema de vídeo

	this->window_width = 640;
	this->window_height = 480;

  	this->screen = SDL_SetVideoMode(this->window_width, 480, 16, SDL_SWSURFACE); // Cria a janela

	this->input.load();

	this->player.setScreen(this->screen);
	this->player.load();
}

void GameController::draw(){
	SDL_FillRect(this->screen, NULL, 0x0); // Pinta todo o screen de preto

	this->player.draw();

	SDL_UpdateRect(this->screen, 0,0,0,0); // Atualiza todo o screen
	SDL_Delay(30); // Espera 60 milissegundos
}

void GameController::update(){
	this->input.update();

	if(this->input.isPressClose() == false){
		this->player.setInputManager(this->input);
		this->player.update();
	}
	
	this->draw();
}

SDL_Surface GameController::getScreen(){
	this->screen;
}

PlayerShip GameController::getPlayer(){
	this->player;
}

bool GameController::isPressClose(){
	return this->input.isPressClose();
}

void GameController::quit(){
	SDL_Quit(); // Fecha o SDL
}