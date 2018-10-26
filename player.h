#ifndef PLAYER_H
#define PLAYER_H
#include "animatedmovingobj.h"

class Player : public BackgroundItem
{
public:

    Player(b2World &Worl, int x, int y);
    ~Player();
    void moveRight();
    void moveLeft();
    void run_animation();
    void makeJump();
    void setObjSpeed(const float x);


private:


    std::string textures[20];
    float speed;
    player_direction_t player_direction;


};

#endif // PLAYER_H
