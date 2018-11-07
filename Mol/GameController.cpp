#include "GameController.h"

#include <string>
#include <stdio.h>
#include <chrono>

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
	this->enemy_shoot_proximity = 50;
	this->enemy_speed_x = -2;
	this->enemy_speed_y = 10;
	this->enemy_moves_y = false;
	this->enemy_movement_delay = 1000;
	this->enemy_movement_timer = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

	this->background_controller = BackgroundController();
	this->background_controller.setScreen(this->screen);
	this->background_controller.load();

	this->player.setScreen(this->screen);
	this->player.load();
	this->player.setInputManager(&this->input);

	this->player.setPosX(300);
	this->player.setPosY(440);

	int off_set_top = 50;
	int off_set_left = 50;

	if(this->enemies.size() <= 0){
		for (int i=0; i<this->enemy_qtt_col; ++i){
			std::vector<SpaceShip> n_enemy_vec;
			for (int b=0; b<this->enemy_qtt_row; ++b){
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
			for (int i=0; i<this->enemies.size(); ++i){
				for (int b=0; b<this->enemies[i].size(); ++b){
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

	if(this->enemies.size() > 0){
		for (int i=0; i<this->enemies.size(); ++i){
			for (int b=0; b<this->enemies[i].size(); ++b){
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

		this->enemiesUpdate();
	}
	
	this->draw();
}

void GameController::controlEnemiesMovement(){
	if(this->enemies.size() > 0){
		if(this->enemy_speed_x > 0){
			for (int i=this->enemies.size(); i>0; --i){
				bool can_break = false;
				for (int b=this->enemies[i-1].size(); b>0; --b){
					if(this->enemies[i-1][b-1].isDead() == false){
						if(this->enemies[i-1][b-1].getPosX() >= (window_width-20-this->enemies[i-1][b-1].getWidth())){
							this->enemy_speed_x = this->enemy_speed_x * -1;
							if(this->enemies[i-1][b-1].getPosY() >= 300){
								this->enemy_speed_y = this->enemy_speed_y * -1;
							}else if(this->enemies[i-1][0].getPosY() <= 20){
								this->enemy_speed_y = this->enemy_speed_y * -1;
							}
							this->enemy_moves_y = true;
						}
						can_break = true;
						break;
					}
				}
				if(can_break == true){
					break;
				}
			}
		}else{
			for (int i=0; i<this->enemies.size(); ++i){
				bool can_break = false;
				for (int b=this->enemies[i-1].size(); b>0; --b){
					if(this->enemies[i-1][b-1].isDead() == false){
						if(this->enemies[i-1][b-1].getPosX()<=20){
							this->enemy_speed_x = this->enemy_speed_x * -1;

							if(this->enemies[i-1][b-1].getPosY() >= 300){
								this->enemy_speed_y = this->enemy_speed_y * -1;
							}else if(this->enemies[i-1][0].getPosY() <= 10){
								this->enemy_speed_y = this->enemy_speed_y * -1;
							}

							this->enemy_moves_y = true;
						}
						can_break = true;
						break;
					}
				}
				if(can_break == true){
					break;
				}
			}
		}
	}	
}

void GameController::enemiesUpdate(){
	if(this->enemies.size() > 0){
		this->controlEnemiesMovement();


		Uint64 current_time = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
		int time_diff = current_time - this->enemy_movement_timer;

		for (int i=0; i<this->enemies.size(); ++i){
			for (int b=0; b<this->enemies[i].size(); ++b){

				if(time_diff >= this->enemy_movement_delay){
					if(this->enemy_moves_y == true){
						this->enemies[i][b].moveY(this->enemy_speed_y);
					}else{
						this->enemies[i][b].moveX(this->enemy_speed_x);
					}
				}
				this->enemies[i][b].update();
			}
		}

		if(time_diff >= this->enemy_movement_delay){
			this->enemy_movement_timer = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
			if(this->enemy_moves_y == true){
				this->enemy_moves_y = false;
			}
		}

		if(this->player.isDead() == false){
			for (int i=0; i<this->enemies.size(); ++i){
				int b = 0;
				if( (this->player.getPosX() > (this->enemies[i][b].getPosX()-this->enemy_shoot_proximity) && this->player.getPosX() < (this->enemies[i][b].getPosX()+this->enemy_shoot_proximity)) 
					||
					(this->player.getPosX()+this->player.getWidth() > (this->enemies[i][b].getPosX()-this->enemy_shoot_proximity) && this->player.getPosX()+this->player.getWidth() < (this->enemies[i][b].getPosX()+this->enemy_shoot_proximity)) ){

					for (int c = this->enemies[i].size(); c > 0; --c){
						if(this->enemies[i][c-1].isDead() == false){
							this->enemies[i][c-1].shoot();
							break;
						}
					}
				}
			}
		}
	}
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