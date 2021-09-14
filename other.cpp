#include <easyx.h>
#include <time.h>

#include "snake.h"
#include "constant.h"
#include "food.h"
#include "point.h"
#include <stdio.h>
#include <conio.h>
#include <iostream>

//初始化游戏
void initGame() {
    srand((unsigned int)time(NULL));//随机数种子，后面随机产生蛇的食物要用到
    initgraph(SCREEN_LENGTH, SCREEN_WIDTH);//初始化图形
    setbkcolor(BACKGROUND_COLOR);//背景色
}

//填充一个point
void fillrectangle(point p) {
    fillrectangle(p.getx(), p.gety(), p.getx() + 10, p.gety() + 10);
}

//绘制蛇
void drawSnake(snake snake) {
    for (int i = 0; i < snake.getNum(); i++){
        setlinecolor(BLUE);
        setfillcolor(YELLOW);
        fillrectangle(snake.getLocation(i));
    }
}

//绘制食物
void drawFood(food food) {
    fillrectangle(food.getLocation());
}

int samePoint(point p1,point p2) {
    return p1.getx() == p2.getx() && p1.gety() == p2.gety();
}

//食物坐标获取
void refreshFoodLocation(food& food) {
    food.setFlag();
    food.randomLocation();
}

//判断蛇是否死亡
void snakedie(snake snake) {
    { //分数
        char grade[100] = { 0 };

        setbkmode(0);//文字背景透明
        outtextxy(570, 20, _T("分数："));

        outtextxy(610, 20, grade);
    }

    int head_x = snake.head().getx();
    int head_y = snake.head().gety();
    if (head_x > 640 || head_x < 0 || head_y > 480 || head_y < 0){
        outtextxy(240, 320, _T("撞墙了，游戏结束!"));

        getchar();
    }

    for (int i = 1; i < snake.getNum(); i++){
        if (samePoint(snake.head(),snake.getLocation(i))){
            outtextxy(240, 320, _T("你咬死了自己，游戏结束"));
            getchar();
        }
    }
}

//吃食物的判断
void eatfood(snake& snake,food& food){
    if (samePoint(snake.head(),food.getLocation())){
        snake.addNum();
        food.addGrade(10);
        food.resetFlag();
    }
}


//蛇的移动
void way(snake& snake) {
    //除了第一节蛇，后面每节都是前面一节蛇的前一次坐标
    for (int i = snake.getNum() - 1; i > 0; i--){
        snake.getLocation(i).set(snake.getLocation(i-1));
    }

    switch (snake.getWay()){
    case RIGHT:
        snake.head().addx(10);
        break;
    case LEFT:
        snake.head().addx(-10);
        break;
    case DOWN:
        snake.head().addy(10);
        break;
    case UP:
        snake.head().addy(-10);
        break;
    default:
        break;
    }


}
//蛇的方向控制
void snakemove(snake& snake){
    char ch = 0;
    ch = _getch();
    switch (ch)
    {
    case UP:
        if (snake.getWay() != DOWN)
            snake.setWay(UP);
        break;
    case DOWN:
        if (snake.getWay() != UP)
            snake.setWay(DOWN);
        break;
    case LEFT:
        if (snake.getWay() != RIGHT)
            snake.setWay(LEFT);
        break;
    case RIGHT:
        if (snake.getWay() != LEFT)
            snake.setWay(RIGHT);
        break;
    default:        break;
    }
}





void again() {
    if (_getch() == 32) {
        while (_getch() != 32);
    }
}

