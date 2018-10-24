#include "GameController.h"

int GameController::window_width = 640;
int GameController::window_height = 480;

int GameController::getWindowWidth(){
	return window_width;
}

int GameController::getWindowHeight(){
	return window_height;
}

string GameController::getGameName(){
	return this->game_name;
}

void GameController::load(){
	SDL_Init(SDL_INIT_VIDEO); // Inicializa o SDL e o sistema de vídeo

  	this->screen = SDL_SetVideoMode(window_width, window_height, 16, SDL_SWSURFACE); // Cria a janela

  	this->input = InputManager();
	this->input.load();

	this->player.setScreen(this->screen);
	this->player.load();
	this->player.setInputManager(&this->input);
}

void GameController::draw(){
	SDL_FillRect(this->screen, NULL, 0x0); // Pinta todo o screen de preto

	this->player.draw();

	SDL_UpdateRect(this->screen, 0,0,0,0); // Atualiza todo o screen
	SDL_Delay(10); // 16.6
}

void GameController::update(){
	this->input.update();

	if(this->input.isPressClose() == false){
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

InputManager GameController::getInputManager(){
	return this->input;
}