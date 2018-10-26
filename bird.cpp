#include "bird.h"

Bird::Bird(b2World& World, int x,  int y, texture_param_t &texture_param) :
   AnimatedMovingObj(World, x, y, texture_param)
{
    setFixtureCollisionFilter(BACKGROUND_MOVING_ITEM, GROUND);


}
