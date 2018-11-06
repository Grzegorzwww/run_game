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

    virtual ~BackgroundItem();

    void setPosition(int x, int y);
    void setAnimationParameters(int animation_num, int actual_animation_iteration);

    virtual void moveRight();
    virtual void moveLeft();
    virtual void run_animation();

   b2Vec2 getBodyPossition();

   b2Body *getBodyInstance();

   void deleteObject();
   void setBodyDef(b2BodyType body_type);



    sf::Sprite *getSprite() {return &_sprite;}
    void getWindowSize(int w, int h);

    int getNumOfTextures() {return _num_of_textures_to_animate;}
    int getNumOfAnimationIter() {return _actual_animation_iteration;}
    int setNumOfAnimationIter(const int num) {_actual_animation_iteration = num;}


    sf::Sprite * getSpritePtr() {return &_sprite;}
    sf::Texture * getTexturePtr() {return &_texture;}


    void setBodyDensity(const float dens);
    void setBodyRestitution(const float rest);
    void setBodyFriction(const float fric);

    void setFixtureCategoryBits(const unsigned short bits);
    void setFixtureMaskBits(const unsigned short bits);

    void setBodyFixedRotation(bool x);
    void setCircleShape(float val);

    void setFixtureCollisionFilter(const unsigned short bitsCategory, const unsigned short bitsMask);

protected:


private:


    int window_w_max;
    int window_h_max;


     b2World *temp_world_ptr;

     sf::Texture _texture;
     sf::Sprite _sprite;

     b2BodyDef _bodyDef;
     b2PolygonShape _shape;
     b2CircleShape _shape_circle;
     b2FixtureDef _fixtureDef;
     b2Body* _body;
     b2RevoluteJointDef rjd;
     b2RevoluteJoint* m_joint;

     int _num_of_textures_to_animate;
     int _actual_animation_iteration;



};

#endif // MOVINGBACKGROUNDITEM_H
