#ifndef GAME_H
#define GAME_H


#include <cstdint>
#include <cassert>
#include <iostream>
#include <sstream>
#include <defines.hpp>



#include "ground.h"
#include "tree.h"
#include "backgrounditem.h"
#include "mushroom.h"
#include "animatedmovingobj.h"
#include "itemsgenerator.h"
#include "player.h"
#include "bird.h"

#include "dropitem.h"
#include "stone.h"



#include "menu.h"
#include "resultloger.h"


/*

class MyContactListener : public b2ContactListener
{
public:
    void BeginContact(b2Contact* contact) {

        //check if fixture A was a ball
        void* bodyUserData = contact->GetFixtureA()->GetBody()->GetUserData();
        if ( bodyUserData )
            static_cast<Ball*>( bodyUserData )->startContact();

        //check if fixture B was a ball
        bodyUserData = contact->GetFixtureB()->GetBody()->GetUserData();
        if ( bodyUserData )
            static_cast<Ground*>( bodyUserData )->startContact();

    }

    void EndContact(b2Contact* contact) {

        //check if fixture A was a ball
        void* bodyUserData = contact->GetFixtureA()->GetBody()->GetUserData();
        if ( bodyUserData )
            static_cast<Ball*>( bodyUserData )->endContact();

        //check if fixture B was a ball
        bodyUserData = contact->GetFixtureB()->GetBody()->GetUserData();
        if ( bodyUserData )
            static_cast<Ground*>( bodyUserData )->endContact();
    }


};*/





class Game {
public:

    Game();
    void run();
    virtual ~Game();

protected:

private:

    void processEvents();
    void update();
    void render();
    void move_camera();
    void motion_symulation();
    void create_items(backgorund_item_type_t i);
    void collisionDetection();
    void newGame();
    void incLevel();


    const int SCALE = 30;
    sf::RenderWindow window;
    sf::View view;

    std::string entered_text;
    std::string player_name;

    b2Vec2 _gravity;
    b2World *World;

    sf::Texture back_ground_tex;
    sf::Sprite _backGroundSprite;

    Ground *ground;
    Tree * tree_sample;
    Mushroom * _mushroom;


    BackgroundItem *item_1;
    BackgroundItem *item_2;
    sf::Clock clock;
    sf::Time elapsed1 = clock.getElapsedTime();

    Player *player;
    Menu *menu;
    ResultLoger * resultloger;


    unsigned int distance;
    bool is_failed;
    bool first_run;





    std::vector<BackgroundItem *> backgorud_items;

    std::vector<sf::Sprite > sprites_buffor;

    ItemsGenerator *itemsGenerator;

    unsigned int overtaking_point_x;
    unsigned int delaying_point_x;



};

#endif // GAME_H
