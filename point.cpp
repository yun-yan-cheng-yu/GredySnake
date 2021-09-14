#include "point.h"

void point::set(int x,int y) {
	this->x = x;
	this->y = y;
}

void point::set(point point){
	this->x = point.getx();
	this->y = point.gety();
}

void point::setx(int x){
	this->x = x;
}

void point::addx(int x){
	this->x += x;
}

void point::addy(int y){
	this->y += y;
}

int point::getx() {
	return this->x;
}

int point::gety() {
	return this->y;
}
