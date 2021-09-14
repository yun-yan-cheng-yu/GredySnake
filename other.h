#define _CRT_SECURE_NO_WARNINGS
#ifndef __SNAKE_H_
#define __SNAKE_H_

#include<stdio.h>
#include<conio.h>
#pragma once

#include<time.h>
#include "constant.h"
#include "food.h"


void initGame();//初始化游戏
void drawSnake(snake);//绘制蛇
void refreshFoodLocation(food&);//刷新食物位置
void drawFood(food);//食物绘制


void way(snake&);//蛇的移动
//蛇的方向
void snakemove(snake&);
//蛇的食物


//判断蛇是否吃掉食物
void eatfood(snake&,food&);
//判断蛇是否吃挂掉
void snakedie(snake);
//游戏过程中，按 空格 可以对游戏进行暂停、开始
void again();


#endif

