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


static const int JUMP_MAX_POSITION =200;

static const bool PLAYER_1 = true;
static const bool PLAYER_2 = false;

static const float GROUND_WIDTH = 100000.0f;
static const float GROUND_HEIGH = 150.0f;
static const std::string GROUND_TEXTURE_PATH =  "graphics/ground_texture_2.jpg";


typedef struct {
    float texture_width;
    float texture_height;
    std::string textures[10];
    int num_textures;

} texture_param_t;



static const float TREE_WIDTH = 220;
static const float TREE_HEIGH = 230;
static const std::string TREE_TEXTURE_PATH = "graphics/tree_v2.jpg";

static const texture_param_t tree_texture_parameter = {
    220.0f,
    230.0f,
    "graphics/tree_v2.gif", "", "", "", "", "", "" ,  " ", " ", " ",
    1
};


static const float TREE2_WIDTH = 480;
static const float TREE2_HEIGH = 540;
static const std::string TREE2_TEXTURE_PATH = "graphics/tree_2.gif";


static const  texture_param_t tree2_texture_parameter = {
    480.0f,
    540.0f,
    "graphics/tree_2.gif", "", "", "", "", "", "" ,  " ", " ", " ",
    1
};

static const int MAX_TEXTURES = 7;




static const  texture_param_t ground_texture_parameter = {
    10000.0f,
    130.0f,
    {"graphics/ground_texture_2.jpg", "", "", "", "", "", "" },
    1
};


static const float MUSHROOM_WIDTH = 60.0f;
static const float MUSHROOM_HEIGH = 80.0f;
static const std::string MUSHROOM_TEXTURE_PATH =  "graphics/mushroom_60x80.jpg";


static const  texture_param_t mushroom_texture_parameter = {
    60.0f,
    80.0f,
    {"graphics/mushroom_60x80.jpg", "", "", "", "", "", "" },
    1
};



static const float BLUEBIRD_WIDTH = 200.0f;
static const float BLUEBIRD_HEIGH = 120.0f;
static const std::string BLUEBIRD_TEXTURE_PATH[7] = {
    "graphics/animated/bird_blue/1.png",
    "graphics/animated/bird_blue/2.png",
    "graphics/animated/bird_blue/3.png",
    "graphics/animated/bird_blue/4.png",
    "graphics/animated/bird_blue/5.png",
    "graphics/animated/bird_blue/6.png",
    "graphics/animated/bird_blue/7.png",

};


static const  texture_param_t bluebird_texture_parameter = {
    100.0f,
    80.0f,
    {"graphics/animated/bird_blue/1.gif",
    "graphics/animated/bird_blue/2.gif",
    "graphics/animated/bird_blue/3.gif",
    "graphics/animated/bird_blue/4.gif",
    "graphics/animated/bird_blue/5.gif",
    "graphics/animated/bird_blue/6.gif",
    "graphics/animated/bird_blue/7.gif" },
    7
};

static const  texture_param_t normal_texture_parameter = {
    200.0f,
    120.0f,
    {"graphics/animated/normal_bird/1.gif",
    "graphics/animated/normal_bird/2.gif",
    "graphics/animated/normal_bird/3.gif",
    "graphics/animated/normal_bird/4.gif",
    "graphics/animated/normal_bird/5.gif",
    "graphics/animated/normal_bird/6.gif",
    "graphics/animated/normal_bird/7.gif" },
    7
};


static const  texture_param_t player_dir_r_texture_parameter = {
    70.0f,
    120.0f,
    {"graphics/animated/player/to_right/1.gif",
    "graphics/animated/player/to_right/2.gif",
    "graphics/animated/player/to_right/3.gif",
    "graphics/animated/player/to_right/4.gif",
    "graphics/animated/player/to_right/5.gif",
    "graphics/animated/player/to_right/6.gif",
    "graphics/animated/player/to_right/7.gif",
    "graphics/animated/player/to_right/8.gif",
    "graphics/animated/player/to_right/9.gif",
    "graphics/animated/player/to_right/10.gif"},
    10
};

static const  texture_param_t player_dir_l_texture_parameter = {
    70.0f,
    120.0f,
    {"graphics/animated/player/to_left/1.gif",
    "graphics/animated/player/to_left/2.gif",
    "graphics/animated/player/to_let/3.gif",
    "graphics/animated/player/to_left/4.gif",
    "graphics/animated/player/to_left/5.gif",
    "graphics/animated/player/to_left/6.gif",
    "graphics/animated/player/to_left/7.gif",
    "graphics/animated/player/to_left/8.gif",
    "graphics/animated/player/to_left/9.gif",
    "graphics/animated/player/to_left/10.gif"},
    10
};


typedef enum  {tree, mushroom, tree2, bird, bird2} backgorund_item_type_t;


static const int OBJ_CREATE_MARGIN = 200;

typedef enum {FORWARD = 0, BACKWARD} player_direction_t;

enum _entityCategory {
    GROUND =                 0x0001,
    BACKGROUND_ITEM =        0x0002,
    BACKGROUND_MOVING_ITEM = 0x0004,
    PLAYER =                 0x0008
  };





#endif // DEFINES_HPP
