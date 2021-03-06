#pragma once
#include <SDL/SDL.h>
#include <string>

class InputManager{
	private:
		std::string current_event;
		std::string last_event;
		bool is_right_press;
		bool is_left_press;
		bool is_up_press;
		bool is_down_press;
		bool is_close_press;
		bool is_spacebar_press;
		bool is_enter_press;
		SDL_Event event;
	public:
		std::string getCurrentEvent();
		bool isPressRight();
		bool isPressLeft();
		bool isPressUp();
		bool isPressDown();
		bool isPressClose();
		bool isPressSpacebar();
		bool isPressEnter();
		void load();
		void update();

};
