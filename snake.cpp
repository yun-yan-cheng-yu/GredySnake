#include "snake.h"
#include "other.h"

snake::snake() {
	this->num = 3;
	this->way = RIGHT;
    this->xy[0].set(20,0);
    this->xy[1].set(10, 0);
    this->xy[2].set(0, 0);
}

int snake::getNum() {
    return this->num;
}

void snake::addNum(){
    this->num++;
}

point& snake::getLocation(int index){
    return this->xy[index];
}

point& snake::head(){
    return this->xy[0];
}

char snake::getWay(){
    return this->way;
}

void snake::setWay(char way){
    this->way = way;
}
