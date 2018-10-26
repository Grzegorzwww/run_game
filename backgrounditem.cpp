#include "backgrounditem.h"
using namespace std;
BackgroundItem::BackgroundItem()
{

}
BackgroundItem::~BackgroundItem(){

      std::cout << "usuniecie elementu BackgroundItem"<<std::endl;
      if(_body != nullptr){
         _body->GetWorld()->DestroyBody( _body );
      }


}
BackgroundItem::BackgroundItem(b2World& World, std::string texture_file, int x, int y,  float width, float height) :
  temp_world_ptr(&World)
{
    //std::cout << "backgorund item created"<<std::endl;

    _num_of_textures_to_animate = 1;
    _actual_animation_iteration = 0;
    _body = nullptr;

    m_joint = nullptr;


    if (!_texture.loadFromFile(texture_file)) {
        std::cerr << "Can't load file:  "<<texture_file<<std::endl;
    }

    else {
        _sprite.setTextureRect(sf::IntRect(0, 0, width,  height));
        _sprite.setTexture(_texture);
        _sprite.setOrigin(width/2, height/2);

    }
    window_w_max =0;
    window_h_max = 0;

    _bodyDef.position = b2Vec2(x/SCALE, y/SCALE);

   // _bodyDef.type = b2_dynamicBody;


     _body = World.CreateBody(&_bodyDef);
    _body->SetUserData((void *)&_sprite);

    _shape.SetAsBox((width/2)/SCALE, (height/2)/SCALE);

    _fixtureDef.density = 0.0f;
    _fixtureDef.restitution = 0.0f;


    _fixtureDef.filter.categoryBits = 0x0000;
     _fixtureDef.filter.maskBits = 0x0000;

    _fixtureDef.shape = &_shape;
    _body->CreateFixture(&_fixtureDef);
    _body->SetFixedRotation(true);


}

void BackgroundItem::setFixtureCollisionFilter(const unsigned short bitsCategory, const unsigned short bitsMask){
    _fixtureDef.filter.categoryBits = bitsCategory;
     _fixtureDef.filter.maskBits = bitsMask;

     _body->CreateFixture(&_fixtureDef);
}
void BackgroundItem::setFixtureCategoryBits(const unsigned short bits){
    _fixtureDef.filter.categoryBits = bits;
}
void BackgroundItem::setFixtureMaskBits(const unsigned short bits){
    _fixtureDef.filter.maskBits = bits;
}

void BackgroundItem::setBodyDensity(const float dens){
    _fixtureDef.density = dens;
    _body->CreateFixture(&_fixtureDef);
}
void BackgroundItem::setBodyRestitution(const float rest){
    _fixtureDef.restitution = rest;
    _body->CreateFixture(&_fixtureDef);
}

void BackgroundItem::setBodyFriction(const float fric){
    _fixtureDef.friction = fric;
    _body->CreateFixture(&_fixtureDef);
}
void BackgroundItem::deleteObject(){
    _body->GetWorld()->DestroyBody( _body );
}

void BackgroundItem::setBodyDef(b2BodyType body_type)
{
    _body->SetType(body_type);
    _body->SetAwake(true);
}


void BackgroundItem::getWindowSize(int w, int h){
    window_h_max = h;
    window_w_max = w;
}

void BackgroundItem::moveRight(){
    if(_body != nullptr){
        b2Vec2 vel = _body->GetLinearVelocity();
        float desiredVel = 5;
        float velChange = desiredVel - vel.x;
        float force = _body->GetMass() * velChange / (1/60.0); //f = mv/t
        _body->ApplyForce( b2Vec2(force,0), _body->GetWorldCenter(), true );
    }

}

void BackgroundItem::moveLeft(){
    //        float impulse = _body->GetMass() / 2;
    //        _body->ApplyLinearImpulse( b2Vec2(-impulse * 2.0, 0), _body->GetWorldCenter(), true );
    if(_body != nullptr){
      //setPosition( _body->GetPosition().x - 0.1,  _body->GetPosition().y);
//         _body->SetTransform(_body->GetPosition().x - 0.1, )
//         _body->SetLinearVelocity( 5 );

//        b2Vec2 vel = _body->GetLinearVelocity();
//        float desiredVel = -5;
//        float velChange = desiredVel - vel.x;
//        float force = _body->GetMass() * velChange / (1/60.0); //f = mv/t
//        _body->ApplyForce( b2Vec2(force,0), _body->GetWorldCenter(), true );
    }

//   std::cout<< _sprite.getOrigin().x<<", "<<_sprite.getOrigin().y << std::endl;


}

void BackgroundItem::run_animation(){

// std::cout << "BackgroundItem animation"<<std::endl;

}

b2Vec2 BackgroundItem::getBodyPossition(){
    if(_body != nullptr){
        return _body->GetPosition();
    }else{
        return b2Vec2(0.0, 0.0);
    }
}
void BackgroundItem::setPosition(int x, int y){
    if(_body != nullptr){
        _body->SetTransform(b2Vec2(x/SCALE,y/SCALE),_body->GetAngle());
    }
}

void BackgroundItem::setAnimationParameters(int animation_num, int actual_animation_iteration){

    _num_of_textures_to_animate = animation_num;
    _actual_animation_iteration = actual_animation_iteration;

}

b2Body * BackgroundItem::getBodyInstance(){
    if(_body != nullptr){
        return _body;
    }else{
        return nullptr;
    }

}

