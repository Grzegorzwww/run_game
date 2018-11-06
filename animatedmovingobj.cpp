#include "animatedmovingobj.h"

AnimatedMovingObj::AnimatedMovingObj(b2World& World, int x, int y, texture_param_t tekst_param) :
    BackgroundItem(World,  tekst_param.textures[0], x, y,tekst_param.texture_width, tekst_param.texture_height)
{
   std::cout << "AnimatedMovingObj" << std::endl;
    BackgroundItem::setAnimationParameters(7, 2);

    setObjSpeed((float)(std::rand() % 10) + 5.0);


    int i;
    for(i = 0; i < tekst_param.num_textures; i++){
        textures[i] = tekst_param.textures[i];
    }

}

AnimatedMovingObj::~AnimatedMovingObj()
{
    std::cout << "destruktor AnimatedMovingObj "<<std::endl;
}

void  AnimatedMovingObj::moveRight(){
    b2Body *temp_body =  BackgroundItem::getBodyInstance();
    if(temp_body  != nullptr){
        b2Vec2 vel = temp_body->GetLinearVelocity();
        float desiredVel = 5;
        float velChange = desiredVel - vel.x;
        float force = 0.0f; //f = mv/t
        temp_body->ApplyForce( b2Vec2(force,0),temp_body->GetWorldCenter(), true );
    }
}

void  AnimatedMovingObj::moveLeft(){
    b2Body *temp_body =  BackgroundItem::getBodyInstance();
    if(temp_body != nullptr){
        float force_y = speed;
        float force_x = (temp_body->GetMass()/2.4)  / (1/60.0); //f = mv/t
        temp_body->ApplyForce( b2Vec2(-force_y,-force_x), temp_body->GetWorldCenter(), true );
    }
}

void AnimatedMovingObj::run_animation(){
    if(BackgroundItem::getNumOfTextures() > 1){
        int temp_animation_inter_counter = BackgroundItem::getNumOfAnimationIter();
            sf::Texture *texture_temp =  BackgroundItem::getTexturePtr();
            //sf::Texture texture_temp;
            sf::Sprite *sprite_temp =  BackgroundItem::getSpritePtr();
                if(!texture_temp->loadFromFile(textures[temp_animation_inter_counter])){
                    std::cout <<"nie mozna zaladowac tekstury: "<<textures[temp_animation_inter_counter]<<std::endl;
                }else{
                    sprite_temp->setTexture(*texture_temp);
                }
                if(temp_animation_inter_counter++ < 6){
                    ;
                }else{
                    temp_animation_inter_counter = 0;
                }
                BackgroundItem::setNumOfAnimationIter(temp_animation_inter_counter);
        }
}

void AnimatedMovingObj::setObjSpeed(const float x){
    if(x < 250.0f ){
        speed = x;
    }else{
        speed = 250.0f;
    }
}




