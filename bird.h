#ifndef BIRD_H
#define BIRD_H
#include "animatedmovingobj.h"
#include <cstdint>
#include <cassert>
#include <iostream>

class Bird : public AnimatedMovingObj
{
public:
    Bird(b2World &World, int x, int y, texture_param_t texture_param);

    bool controlDropObj(int view_param_x);




private:
    unsigned int rand_drop_pos;
};
#endif // BIRD_H
