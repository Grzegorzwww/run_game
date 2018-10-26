#ifndef ANIMATED_MOVING_OBJ_H
#define ANIMATED_MOVING_OBJ_H

#include "backgrounditem.h"

class AnimatedMovingObj : public BackgroundItem
{
public:
    AnimatedMovingObj(b2World& Worl, int x, int y, texture_param_t tekst_param);
    virtual ~AnimatedMovingObj();
    virtual void moveRight();
    virtual void moveLeft();
    virtual void run_animation();
    virtual void setObjSpeed(const float x);

private:

    std::string textures[7];
    float speed;

};

#endif // ANIMATED_MOVING_OBJ_H
