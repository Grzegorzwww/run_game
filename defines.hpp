#ifndef DEFINES_HPP
#define DEFINES_HPP


#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Image.hpp>
#include <Box2D/Box2D.h>
#include <SFML/Graphics/Rect.hpp>
#include "sstream"





#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))


static const int SCALE = 30;
static const float DEGTORAD = 0.01745;

static const int FRAME_PER_SEK = 60;

//static const int JUMP_MAX_POSITION = 150;
//static const int PLAYER_HEIGHT = 100;
//static const int PLAYER_WIDTH = 50;


//static const bool PAL_RIGHT_HENDED = true;
//static const bool PAL_LEFT_HENDED = false;


static const bool  FORHAND = true;
static const bool  BACKHAND = false;

static const bool PLAYER_1 = true;
static const bool PLAYER_2 = false;


static const float TREE_WIDTH = 220;
static const float TREE_HEIGH = 230;
static const std::string TREE_TEXTURE_PATH = "graphics/tree_v2.jpg";

static const float GROUND_WIDTH = 1000.0f;
static const float GROUND_HEIGH = 130.0f;
static const std::string GROUND_TEXTURE_PATH =  "graphics/ground_texture_2.jpg";

static const float MUSHROOM_WIDTH = 60.0f;
static const float MUSHROOM_HEIGH = 80.0f;
static const std::string MUSHROOM_TEXTURE_PATH =  "graphics/mushroom_60x80.jpg";





#endif // DEFINES_HPP
