#pragma once

#include "constant.h"
#include "point.h"

class snake {
    int num;//蛇的总节数
    point xy[SNAKE_MAX];//存储蛇的坐标的结构体数组
    char way;//方向
public:
    snake();
    int getNum();
    void addNum();
    point& getLocation(int index);//蛇index处的点的位置 index从0开始
    point& head();
    char getWay();
    void setWay(char way);
};