#include <stdlib.h>

#include "food.h"

point food::getLocation(){
    return this->fdxy;
}

int food::hasLocation(){
    return this->flag != 0;
}

void food::setFlag(){
    this->flag = 1;
}

void food::randomLocation(){
    this->fdxy.set(rand() % 65 * 10,rand() % 48 * 10);
}

void food::resetFlag(){
    this->flag = 0;
}

void food::addGrade(int grade){
    this->eatgrade += grade;
}
