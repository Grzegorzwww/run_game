#include "backgrounditem.h"
using namespace std;
BackgroundItem::BackgroundItem()
{

}
BackgroundItem::~BackgroundItem(){

      _body->GetWorld()->DestroyBody( _body );


}
BackgroundItem::BackgroundItem(b2World& World, std::string texture_file, int x, int y,  float width, float height) :
  temp_world_ptr(&World)
{
    //std::cout << "backgorund item created"<<std::endl;


    m_joint = nullptr;
    if (!_texture.loadFromFile(texture_file)) {
        std::cerr << "Can't load file:  "<<texture_file<<std::endl;
    }
    else {
        _sprite.setTexture(_texture);
        _sprite.setOrigin(width/2, height/2);

    }

    window_w_max =0;
    window_h_max = 0;

    _bodyDef.position = b2Vec2(x/SCALE, y/SCALE);

    _bodyDef.type = b2_dynamicBody;

    _body = World.CreateBody(&_bodyDef);

    _body->SetUserData((void *)&_sprite);

    _shape.SetAsBox((width/2)/SCALE, (height/2)/SCALE);

    _fixtureDef.density = 400.0f;
    _fixtureDef.restitution = 0.2f;

    _fixtureDef.shape = &_shape;
    _body->CreateFixture(&_fixtureDef);
    _body->SetFixedRotation(true);



    //rjd.Initialize(_body, padle->getBody(),b2Vec2(0, 0));



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
    //        float impulse = _body->GetMass() / 2;
    //        _body->ApplyLinearImpulse( b2Vec2(impulse * 2.0, 0), _body->GetWorldCenter(), true );
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
        b2Vec2 vel = _body->GetLinearVelocity();
        float desiredVel = -5;
        float velChange = desiredVel - vel.x;
        float force = _body->GetMass() * velChange / (1/60.0); //f = mv/t
        _body->ApplyForce( b2Vec2(force,0), _body->GetWorldCenter(), true );
    }

//   std::cout<< _sprite.getOrigin().x<<", "<<_sprite.getOrigin().y << std::endl;


}

b2Vec2 BackgroundItem::getBodyPossition(){
    if(_body != nullptr){
        return _body->GetPosition();
    }
}
void BackgroundItem::setPosition(int x, int y){
    if(_body != nullptr){
        _body->SetTransform(b2Vec2(x/SCALE,y/SCALE),_body->GetAngle());
    }
}

