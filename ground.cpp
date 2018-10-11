#include "ground.h"
#include "backgrounditem.h"

Ground::Ground()
{
}

Ground::Ground(b2World& World, int x, int y):
    BackgroundItem(World, GROUND_TEXTURE_PATH, x, y, GROUND_WIDTH, GROUND_HEIGH)
{

   setBodyDef(b2_staticBody);
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



