#include "InputManager.h"

bool InputManager::isPressRight(){
	return is_right_press;
}

bool InputManager::isPressLeft(){
	return is_left_press;
}

bool InputManager::isPressUp(){
        return is_up_press;
}

bool InputManager::isPressDown(){
        return is_down_press;
}

bool InputManager::isPressSpacebar(){
        return is_spacebar_press;
}

void InputManager::load(){
	is_right_press = false;
	is_left_press = false;
	is_up_press = false;
	is_down_press = false;
	is_close_press = false;
  is_spacebar_press = false;
}

void InputManager::update(){
	while (SDL_PollEvent(&event)){
        	if (event.type == SDL_QUIT){ // Se o usuário clicou para fechar a janela
                	is_close_press = true; // Encerre o loop
                }
		// Verifica se o evento mais antigo é do tipo SDL_KEYDOWN
	        if (event.type == SDL_KEYDOWN) // Se o usuário apertou um botão do teclado
        	{
          	// Verifica qual tecla foi apertada
          		switch (event.key.keysym.sym)
          		{
            			case SDLK_UP:
            				is_up_press = true;
            				break;
            			case SDLK_DOWN:
            				is_down_press = true;
            				break;
            			case SDLK_RIGHT:
			              is_right_press = true;
			              break;
    			        case SDLK_LEFT:
			              is_left_press = true;
			              break;
                  case SDLK_SPACE:
                    is_spacebar_press = true;
                    break;
    			        default:
                  				break;
          		}
        	}
        	if (event.type == SDL_KEYUP) // Se o usuário soltou um botão do teclado
        	{
          		// Verifica qual tecla foi solta
          		switch (event.key.keysym.sym)
          		{
		            case SDLK_UP:
              			is_up_press = false;
			              break;
		            case SDLK_DOWN:
              			is_down_press = false;
              			break;
		            case SDLK_RIGHT:
		                is_right_press = false;
		              	break;
		            case SDLK_LEFT:
              			is_left_press = false;
		              	break;
                case SDLK_SPACE:
                    is_spacebar_press = false;
                    break;
		           default:
              			break;
          		}
        	}

       	}
}

bool InputManager::isPressClose(){
	return is_close_press;
}
