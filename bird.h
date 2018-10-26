#ifndef BIRD_H
#define BIRD_H
#include "animatedmovingobj.h"

class Bird : public AnimatedMovingObj
{
public:
    Bird(b2World &World, int x, int y, texture_param_t &texture_param);
};

#endif // BIRD_H
