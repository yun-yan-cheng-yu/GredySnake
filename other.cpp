#include <easyx.h>
#include <time.h>

#include "snake.h"
#include "constant.h"
#include "food.h"
#include "point.h"
#include <stdio.h>
#include <conio.h>
#include <iostream>

//��ʼ����Ϸ
void initGame() {
    srand((unsigned int)time(NULL));//��������ӣ�������������ߵ�ʳ��Ҫ�õ�
    initgraph(SCREEN_LENGTH, SCREEN_WIDTH);//��ʼ��ͼ��
    setbkcolor(BACKGROUND_COLOR);//����ɫ
}

//���һ��point
void fillrectangle(point p) {
    fillrectangle(p.getx(), p.gety(), p.getx() + 10, p.gety() + 10);
}

//������
void drawSnake(snake snake) {
    for (int i = 0; i < snake.getNum(); i++){
        setlinecolor(BLUE);
        setfillcolor(YELLOW);
        fillrectangle(snake.getLocation(i));
    }
}

//����ʳ��
void drawFood(food food) {
    fillrectangle(food.getLocation());
}

int samePoint(point p1,point p2) {
    return p1.getx() == p2.getx() && p1.gety() == p2.gety();
}

//ʳ�������ȡ
void refreshFoodLocation(food& food) {
    food.setFlag();
    food.randomLocation();
}

//�ж����Ƿ�����
void snakedie(snake snake) {
    { //����
        char grade[100] = { 0 };

        setbkmode(0);//���ֱ���͸��
        outtextxy(570, 20, _T("������"));

        outtextxy(610, 20, grade);
    }

    int head_x = snake.head().getx();
    int head_y = snake.head().gety();
    if (head_x > 640 || head_x < 0 || head_y > 480 || head_y < 0){
        outtextxy(240, 320, _T("ײǽ�ˣ���Ϸ����!"));

        getchar();
    }

    for (int i = 1; i < snake.getNum(); i++){
        if (samePoint(snake.head(),snake.getLocation(i))){
            outtextxy(240, 320, _T("��ҧ�����Լ�����Ϸ����"));
            getchar();
        }
    }
}

//��ʳ����ж�
void eatfood(snake& snake,food& food){
    if (samePoint(snake.head(),food.getLocation())){
        snake.addNum();
        food.addGrade(10);
        food.resetFlag();
    }
}


//�ߵ��ƶ�
void way(snake& snake) {
    //���˵�һ���ߣ�����ÿ�ڶ���ǰ��һ���ߵ�ǰһ������
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
//�ߵķ������
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

