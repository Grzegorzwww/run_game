#ifndef MUSHROOM_H
#define MUSHROOM_H
#include "backgrounditem.h"

class Mushroom :  public BackgroundItem
{

public:
    Mushroom();
    Mushroom(b2World& World, int x, int y);




};

#endif // MUSHROOM_H
