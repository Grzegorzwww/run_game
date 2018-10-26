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
    void setRunning(const bool x) {is_runing = x;}
    bool isRunning() {return is_runing;}


private:


    std::string textures[20];
    float speed;
    player_direction_t player_direction;
    bool is_runing;


};

#endif // PLAYER_H
