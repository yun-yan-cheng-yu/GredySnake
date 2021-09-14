#include<easyx.h>//easyx图形库头文件#

#include"snake.h"
#include "food.h"
#include "other.h"

int main() {
    snake snake;
    food food;

    initGame();

    while (true) {
        cleardevice();
        if (!food.hasLocation()){//没有位置
           refreshFoodLocation(food);//刷新位置
        }
        drawFood(food);//画食物
        drawSnake(snake);//画蛇
        
        snakedie(snake);//判断蛇死了没
        
        eatfood(snake,food);//吃食物
        way(snake);
        Sleep(100);
        while (_kbhit()) {//这里是按上下左右键控制蛇的移动
            again();
            snakemove(snake);
        }
    }

    closegraph();
    return 0;
}

