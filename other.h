#define _CRT_SECURE_NO_WARNINGS
#ifndef __SNAKE_H_
#define __SNAKE_H_

#include<stdio.h>
#include<conio.h>
#pragma once

#include<time.h>
#include "constant.h"
#include "food.h"


void initGame();//��ʼ����Ϸ
void drawSnake(snake);//������
void refreshFoodLocation(food&);//ˢ��ʳ��λ��
void drawFood(food);//ʳ�����


void way(snake&);//�ߵ��ƶ�
//�ߵķ���
void snakemove(snake&);
//�ߵ�ʳ��


//�ж����Ƿ�Ե�ʳ��
void eatfood(snake&,food&);
//�ж����Ƿ�Թҵ�
void snakedie(snake);
//��Ϸ�����У��� �ո� ���Զ���Ϸ������ͣ����ʼ
void again();


#endif

