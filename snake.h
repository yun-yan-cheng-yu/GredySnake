#pragma once

#include "constant.h"
#include "point.h"

class snake {
    int num;//�ߵ��ܽ���
    point xy[SNAKE_MAX];//�洢�ߵ�����Ľṹ������
    char way;//����
public:
    snake();
    int getNum();
    void addNum();
    point& getLocation(int index);//��index���ĵ��λ�� index��0��ʼ
    point& head();
    char getWay();
    void setWay(char way);
};