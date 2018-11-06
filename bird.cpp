#include "bird.h"

Bird::Bird(b2World& World, int x,  int y, texture_param_t texture_param) :
   AnimatedMovingObj(World, x, y, texture_param)
{
    setFixtureCollisionFilter(BACKGROUND_MOVING_ITEM, GROUND);

    setBodyDef(b2_dynamicBody);

    std::srand( time( NULL ));
    rand_drop_pos = (std::rand() % 680);
    std::cout << "kontruktor rand = "<<rand_drop_pos<<std::endl;
}

bool Bird::controlDropObj(int view_param_x)
{
    int diff =   BackgroundItem::getSpritePtr()->getGlobalBounds().left - view_param_x;
    if(  diff > 0 ){
        if(rand_drop_pos <= diff){
            rand_drop_pos = diff + 1;
            return true;
        }
        else
            return false;
    }
    return false;



}
