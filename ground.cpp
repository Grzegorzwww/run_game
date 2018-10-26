#include "ground.h"
#include "backgrounditem.h"


Ground::Ground()
{
}

Ground::Ground(b2World& World, int x, int y,  texture_param_t param):
    BackgroundItem(World, param.textures[0], x, y, param.texture_width, param.texture_height)
{

  // setBodyDef(b2_dynamicBody);
     setBodyDef(b2_staticBody);

      sf::Texture *texture_temp = getTexturePtr();
     texture_temp->setRepeated(true);
     setFixtureCollisionFilter(GROUND,
                               BACKGROUND_ITEM |
                               BACKGROUND_MOVING_ITEM |
                               PLAYER);


}


Ground::~Ground()
{
    //dtor
}

void Ground::startContact(){
    //std::cout <<"ZIEMIA START\n";
   // ColisionCollector *instanceCollerctorPtr =  ColisionCollector::GetColisionCollector();
    //instanceCollerctorPtr->setGroundColision(true);
}

void Ground::endContact(){
   // std::cout <<"ZIEMIA STOP\n";
    //ColisionCollector *instanceCollerctorPtr =  ColisionCollector::GetColisionCollector();
    //instanceCollerctorPtr->setGroundColision(false);
}



