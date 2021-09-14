#pragma once

#include "point.h"

class food {
    point fdxy; // ≥ŒÔŒª÷√
    int flag = 0;
    int eatgrade = 0;
public:
    point getLocation();
    int hasLocation();
    void setFlag();
    void randomLocation();
    void resetFlag();
    void addGrade(int grade);
};

