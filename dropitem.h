#ifndef DROPITEM_H
#define DROPITEM_H
#include "backgrounditem.h"

class DropItem  :  public BackgroundItem
{
public:
    DropItem(b2World& World, int x, int y, texture_param_t param);

};

#endif // DROPITEM_H
