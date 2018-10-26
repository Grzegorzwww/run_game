#include "mushroom.h"

Mushroom::Mushroom(b2World& World, int x, int y, texture_param_t param):
    BackgroundItem(World, param.textures[0], x, y, param.texture_width, param.texture_height)
{


}


