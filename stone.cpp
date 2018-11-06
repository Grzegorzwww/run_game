#include "stone.h"

Stone::Stone(b2World& World, int x, int y, texture_param_t param):
    BackgroundItem(World, param.textures[0], x, y, param.texture_width, param.texture_height)
{

    setFixtureCollisionFilter(STONE,
                              BACKGROUND_ITEM |
                              GROUND |
                              PLAYER);


  setCircleShape(1.0f);

}

