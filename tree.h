#ifndef TREE_H
#define TREE_H
#include "backgrounditem.h"
#include <defines.hpp>

class Tree : public BackgroundItem
{
public:
     Tree(b2World& World, int x, int y, texture_param_t param);

};

class Tree2 : public BackgroundItem
{
public:
     Tree2(b2World& World, int x, int y, texture_param_t param);

};

#endif // TREE_H
