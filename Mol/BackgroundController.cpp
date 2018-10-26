#include "BackgroundController.h"
#include "GameController.h"

void BackgroundController::load(){
	this->background_image = "imgs/fundo_paralax.png";

	this->background_01 = IMG_Load(this->background_image.c_str());
	this->background_02 = IMG_Load(this->background_image.c_str());


	short int bg_dest_w = GameController::getWindowWidth();
	short int bg_dest_h = GameController::getWindowHeight();

	short int bg_dest_h_negative = GameController::getWindowHeight()*-1;

	//this->bg_dest_01 = {0,0,bg_dest_w,bg_dest_h};
	//this->bg_dest_02 = {0,bg_dest_h_negative,bg_dest_w,bg_dest_h};

	this->bg_dest_01 = {0,0,0,0};
	this->bg_dest_02 = {0,0,0,0};

	this->bg_dest_01.w = bg_dest_w;
	this->bg_dest_01.h = bg_dest_h;

	this->bg_dest_02.w = bg_dest_w;
	this->bg_dest_02.h = bg_dest_h;
	this->bg_dest_02.y = bg_dest_h_negative;

	this->speed = 2;
}

void BackgroundController::update(){
	//this->bg_dest_01.y = this->bg_dest_01.y+this->speed;
	//this->bg_dest_02.y = this->bg_dest_02.y+this->speed;
	if(this->bg_dest_02.y > GameController::getWindowHeight()){
		this->bg_dest_02.y = this->background_02->h*-1;
	}

	if(this->bg_dest_01.y > GameController::getWindowHeight()){
		this->bg_dest_01.y = this->background_01->h*-1;
	}
}

void BackgroundController::draw(){
	SDL_BlitSurface(this->background_01, NULL, this->screen, &this->bg_dest_01);
	SDL_BlitSurface(this->background_02, NULL, this->screen, &this->bg_dest_02);
}

void BackgroundController::setScreen(SDL_Surface * n_screen){
	this->screen = n_screen;
}