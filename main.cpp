#include<easyx.h>//easyxͼ�ο�ͷ�ļ�#

#include"snake.h"
#include "food.h"
#include "other.h"

int main() {
    snake snake;
    food food;

    initGame();

    while (true) {
        cleardevice();
        if (!food.hasLocation()){//û��λ��
           refreshFoodLocation(food);//ˢ��λ��
        }
        drawFood(food);//��ʳ��
        drawSnake(snake);//����
        
        snakedie(snake);//�ж�������û
        
        eatfood(snake,food);//��ʳ��
        way(snake);
        Sleep(100);
        while (_kbhit()) {//�����ǰ��������Ҽ������ߵ��ƶ�
            again();
            snakemove(snake);
        }
    }

    closegraph();
    return 0;
}

