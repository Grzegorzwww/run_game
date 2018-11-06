#ifndef STONE_H
#define STONE_H
#include "backgrounditem.h"
#include <defines.hpp>

class Stone : public BackgroundItem
{
public:
    Stone(b2World& World, int x, int y, texture_param_t param);



};

#endif // STONE_H
