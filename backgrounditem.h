#ifndef MOVINGBACKGROUNDITEM_H
#define MOVINGBACKGROUNDITEM_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Image.hpp>
#include <Box2D/Box2D.h>
#include <iostream>
#include <defines.hpp>

class BackgroundItem
{
public:
    BackgroundItem();
    BackgroundItem(b2World& World, std::string texture_file, int x, int y,  float width, float height);

   ~BackgroundItem();

    void setPosition(int x, int y);
    void moveRight();
    void moveLeft();

   b2Vec2 getBodyPossition();

   void deleteObject();
   void setBodyDef(b2BodyType body_type);



    sf::Sprite getSprite() {return _sprite;}
    void getWindowSize(int w, int h);



protected:


private:


    int window_w_max;
    int window_h_max;


     b2World *temp_world_ptr;

     sf::Texture _texture;
     sf::Sprite _sprite;

     b2BodyDef _bodyDef;
     b2PolygonShape _shape;
     b2FixtureDef _fixtureDef;
     b2Body* _body;
     b2RevoluteJointDef rjd;
     b2RevoluteJoint* m_joint;



};

#endif // MOVINGBACKGROUNDITEM_H
