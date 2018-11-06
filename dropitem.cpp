#include "dropitem.h"

DropItem::DropItem(b2World& World, int x, int y, texture_param_t param):
          BackgroundItem(World, param.textures[0], x, y, param.texture_width, param.texture_height)
{

    setFixtureCollisionFilter(DROP_ITEM, PLAYER |  GROUND);

    setBodyDef(b2_dynamicBody);

    setBodyFixedRotation(false);
    setBodyDensity(1.0f);
    setBodyFriction(0.5);
    setBodyRestitution(0.2);
    setCircleShape(0.75f);

   // std::cout <<"konstrukor drop item "<<std::endl;

    if(rand() % 2 == 0){
        moveLeft();
    }else{
        moveRight();
    }

}
