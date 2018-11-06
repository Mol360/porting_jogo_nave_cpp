#include "ObjectBase.h"

void ObjectBase::setObjName(std::string n_obj_name){
	this->object_name = n_obj_name;
}

std::string ObjectBase::getObjName(){
	return this->object_name;    
}

void ObjectBase::load(){
	if(this->object_image == ""){
		this->object_image = "tiro.png";
	}
	std::string tmp_image = "imgs/"+this->object_image;
	this->base_obj = IMG_Load(tmp_image.c_str()); // Carrega a imagem
	this->object_name = "Base Object";
	this->dest = {0,0,0,0}; // Destino da imagem no screen
	this->is_visible = true;
	this->is_dead = false;
}

std::string ObjectBase::getImageObj(){
    return this->object_image;
}

void ObjectBase::setImageObj(std::string n_obj_image){
	this->object_image = n_obj_image;
}

void ObjectBase::update(){
	
}

void ObjectBase::draw(){
	if(this->isVisible()){
		SDL_BlitSurface(this->base_obj, NULL, this->screen, &this->dest); // Blita a imagem em dest
	}
}

void ObjectBase::setScreen(SDL_Surface * n_screen){
	this->screen = n_screen;
}

int ObjectBase::getPosX(){
        return this->dest.x;
}

int ObjectBase::getPosY(){
	return this->dest.y;
}

void ObjectBase::setPosX(int n_pos_x){
	this->dest.x = n_pos_x;
}

void ObjectBase::setPosY(int n_pos_y){
	this->dest.y = n_pos_y;
}

void ObjectBase::moveX(int n_vel_x){
        this->dest.x = this->dest.x + n_vel_x;
}

void ObjectBase::moveY(int n_vel_y){
        this->dest.y = this->dest.y + n_vel_y;
}

int ObjectBase::getHeight(){
	return this->base_obj->h;
}

int ObjectBase::getWidth(){
	return this->base_obj->w;
}

void ObjectBase::hide(){
	this->is_visible = false;
}

void ObjectBase::show(){
	this->is_visible = true;
}

bool ObjectBase::isVisible(){
	return this->is_visible;
}

bool ObjectBase::collided(ObjectBase other_object){
	bool collided = false;

	if(this->getPosX() >= other_object.getPosX() && this->getPosX() <= (other_object.getPosX() + other_object.getWidth())){
		if(this->getPosY() >= other_object.getPosY() && this->getPosY() <= (other_object.getPosY() + other_object.getHeight())){
			collided = true;
		}
	}else if(other_object.getPosX() >= this->getPosX() && other_object.getPosX() <= (this->getPosX() + this->getWidth())){
		if(other_object.getPosY() >= this->getPosY() && other_object.getPosY() <= (this->getPosY() + this->getHeight())){
			collided = true;
		}
	}

	return collided;
}

bool ObjectBase::isDead(){
	return this->is_dead;
}

void ObjectBase::die(){
	this->is_dead = true;
	this->is_visible = false;
}

void ObjectBase::alive(){
	this->is_dead = false;
	this->is_visible = true;
}