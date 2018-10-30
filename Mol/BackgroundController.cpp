#include "BackgroundController.h"
#include "GameController.h"

void BackgroundController::load(){
	this->background_image = "imgs/fundo_paralax.png";

	this->background_01 = IMG_Load(this->background_image.c_str());
	this->background_02 = IMG_Load(this->background_image.c_str());


	short int bg_dest_w = GameController::getWindowWidth();
	short int bg_dest_h = GameController::getWindowHeight();

	short int bg_dest_h_negative = this->background_01->h*-1;

	this->bg_dest_01 = {0,0,0,0};
	this->bg_dest_02 = {0,0,0,0};

	this->bg_dest_01.w = bg_dest_w;
	this->bg_dest_01.h = bg_dest_h*2;
	this->bg_dest_01.y = 0;

	this->bg_dest_02.w = bg_dest_w;
	this->bg_dest_02.h = bg_dest_h*2;
	this->bg_dest_02.y = this->background_01->h;

	this->speed = 5;

	std::cout << "IMAGE :: " << this->background_01->w << std::endl;
}

void BackgroundController::update(){
	this->bg_dest_01.y = this->bg_dest_01.y-this->speed;
	this->bg_dest_02.y = this->bg_dest_02.y-this->speed;
	if(this->bg_dest_02.y < -this->background_02->h){
		this->bg_dest_02.y = this->bg_dest_01.y+this->background_01->h;
	}

	if(this->bg_dest_01.y < -this->background_01->h){
		this->bg_dest_01.y = this->bg_dest_02.y+this->background_02->h;
	}
}

void BackgroundController::draw(){
	SDL_Rect dest_tmp = {0,0,0,0};
	dest_tmp.w = GameController::getWindowWidth();
	dest_tmp.h = GameController::getWindowHeight();

	SDL_Rect dest_tmp_02 = {0,0,0,0};
	dest_tmp_02.w = GameController::getWindowWidth();
	dest_tmp_02.h = GameController::getWindowHeight();

	SDL_BlitSurface(this->background_01, &this->bg_dest_01, this->screen, &dest_tmp);
	SDL_BlitSurface(this->background_02, &this->bg_dest_02, this->screen, &dest_tmp_02);
}

void BackgroundController::setScreen(SDL_Surface * n_screen){
	this->screen = n_screen;
}