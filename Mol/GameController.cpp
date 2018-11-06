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
	this->game_name = "Jogo Nave";
	this->enemy_qtt_col = 10;
	this->enemy_qtt_row = 4;

	this->background_controller = BackgroundController();
	this->background_controller.setScreen(this->screen);
	this->background_controller.load();

	this->player.setScreen(this->screen);
	this->player.load();
	this->player.setInputManager(&this->input);

	this->enemy.setScreen(this->screen);
	this->enemy.load();

	this->player.addEnemy(&this->enemy);

	this->enemy.addEnemy(&this->player);

	this->player.setPosX(300);

	int off_set_top = 50;
	int off_set_left = 50;

	if(this->enemies.size() <= 0){
		for (unsigned i=0; i<this->enemy_qtt_col; ++i){
			std::vector<SpaceShip> n_enemy_vec;
			for (unsigned b=0; b<this->enemy_qtt_row; ++b){
				int n_pos_x = (off_set_left*(i+1))+10;
				int n_pos_y = (off_set_top*(b)+1)+10;
				if(i%2){
					EnemyShipRed n_enemy = EnemyShipRed();
					n_enemy.setScreen(this->screen);
					n_enemy.load();
					n_enemy.setPosX(n_pos_x);
					n_enemy.setPosY(n_pos_y);
					n_enemy.addEnemy(&this->player);
					n_enemy_vec.push_back(n_enemy);
				}else{
					EnemyShipBlue n_enemy = EnemyShipBlue();
					n_enemy.setScreen(this->screen);
					n_enemy.load();
					n_enemy.setPosX(n_pos_x);
					n_enemy.setPosY(n_pos_y);
					n_enemy.addEnemy(&this->player);
					n_enemy_vec.push_back(n_enemy);
				}
			}
			this->enemies.push_back(n_enemy_vec);
		}

		if(this->enemies.size() > 0){
			for (unsigned i=0; i<this->enemies.size(); ++i){
				for (unsigned b=0; b<this->enemies[i].size(); ++b){
					this->player.addEnemy(&this->enemies[i][b]);
				}
			}
		}
	}
}

void GameController::draw(){
	SDL_FillRect(this->screen, NULL, 0x0); // Pinta todo o screen de preto

	this->background_controller.draw();
	this->player.draw();

	this->enemy.draw();

	if(this->enemies.size() > 0){
		for (unsigned i=0; i<this->enemies.size(); ++i){
			for (unsigned b=0; b<this->enemies[i].size(); ++b){
				this->enemies[i][b].draw();
			}
		}
	}

	SDL_UpdateRect(this->screen, 0,0,0,0); // Atualiza todo o screen
	//SDL_Delay(10); // 16.6
	int tempo_inicial = SDL_GetTicks();
	this->controlaFps(tempo_inicial);
}

void GameController::update(){
	SDL_WM_SetCaption(this->game_name.c_str(), NULL);
	this->input.update();

	if(this->input.isPressClose() == false){
		this->background_controller.update();
		this->player.update();
		this->enemy.update();
		this->enemy.shoot();

		if(this->enemies.size() > 0){
			for (unsigned i=0; i<this->enemies.size(); ++i){
				for (unsigned b=0; b<this->enemies[i].size(); ++b){
					this->enemies[i][b].update();
				}
			}
		}
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
	IMG_Quit();
	SDL_Quit(); // Fecha o SDL
}

InputManager GameController::getInputManager(){
	return this->input;
}

void GameController::controlaFps ( int tempo_inicial ){
	int fps = 10; // converte 60 FPS para milissegundos
	int tempo_agora = SDL_GetTicks() - tempo_inicial;

	if(tempo_agora < fps){
		SDL_Delay(fps - tempo_agora);
	}
}