#include "player.h"

Player::Player(b2World& Worl, int x, int y) :
    BackgroundItem(Worl, player_dir_r_texture_parameter.textures[0], x, y, player_dir_r_texture_parameter.texture_width, player_dir_r_texture_parameter.texture_height)


{
   BackgroundItem::setAnimationParameters(10, 2);
    int i;
    for(i = 0; i <  player_dir_r_texture_parameter.num_textures; i++){
        textures[i] =  player_dir_r_texture_parameter.textures[i];
    }

    setBodyDef(b2_dynamicBody);

    setBodyRestitution(0.2f);
    setBodyDensity(400.0f);
    setBodyFriction(0.3f);

    std::cout << "konstruktor Player "<<std::endl;

    setFixtureCollisionFilter(PLAYER, GROUND);

    player_direction = FORWARD;

}

Player::~Player()
{
    std::cout << "destruktor Player "<<std::endl;
}

void Player::run_animation(){
    if(BackgroundItem::getNumOfTextures() > 1){
       if(getBodyInstance()->IsAwake()){
            int temp_animation_inter_counter = BackgroundItem::getNumOfAnimationIter();
            sf::Texture *texture_temp =  BackgroundItem::getTexturePtr();
            //sf::Texture texture_temp;
            sf::Sprite *sprite_temp =  BackgroundItem::getSpritePtr();
            if(player_direction == FORWARD){
                if(!texture_temp->loadFromFile(player_dir_r_texture_parameter.textures[temp_animation_inter_counter])){
                    std::cout <<"nie mozna zaladowac tekstury: "<<player_dir_r_texture_parameter.textures[temp_animation_inter_counter]<<std::endl;
                }else{
                    sprite_temp->setTexture(*texture_temp);
                }
            } else if(player_direction == BACKWARD){

                if(!texture_temp->loadFromFile(player_dir_l_texture_parameter.textures[temp_animation_inter_counter])){
                    std::cout <<"nie mozna zaladowac tekstury: "<<player_dir_l_texture_parameter.textures[temp_animation_inter_counter]<<std::endl;
                }else{
                    sprite_temp->setTexture(*texture_temp);
                }

            }
            if(temp_animation_inter_counter++ < 9){
                ;
            }else{
                temp_animation_inter_counter = 0;
            }
            BackgroundItem::setNumOfAnimationIter(temp_animation_inter_counter);
        }
    }
}


void Player::moveRight(){
//    std::cout << "plater move right"<<std::endl;
    b2Body *temp_body =  BackgroundItem::getBodyInstance();
    if(temp_body  != nullptr){
        b2Vec2 vel = temp_body->GetLinearVelocity();
        float desiredVel = 5;
         if(is_runing) {desiredVel *= RUN_ACCELERATION;}
        float velChange = desiredVel - vel.x;
        float force = temp_body->GetMass() * velChange / (1/60.0); //f = mv/t
        temp_body->ApplyForce( b2Vec2(force,0), temp_body->GetWorldCenter(), true );
        player_direction = FORWARD;
    }
}

void Player::moveLeft(){
//    std::cout << "plater move left"<<std::endl;
    b2Body *temp_body =  BackgroundItem::getBodyInstance();
    if(temp_body != nullptr){
        b2Vec2 vel = temp_body->GetLinearVelocity();

        float desiredVel = -5;
        if(is_runing) {desiredVel *= RUN_ACCELERATION;}
        float velChange = desiredVel - vel.x;
        float force = temp_body->GetMass() * velChange / (1/60.0); //f = mv/t
        temp_body->ApplyForce( b2Vec2(force,0), temp_body->GetWorldCenter(), true );
        player_direction = BACKWARD;
    }
}
void Player::makeJump(){

    b2Body *temp_body =  BackgroundItem::getBodyInstance();
    if(temp_body != nullptr){
        std::cout <<"robie skok"<<std::endl;
        b2Vec2 pos = temp_body->GetPosition();
        b2Vec2 vel = temp_body->GetLinearVelocity();
        if(pos.y * SCALE > JUMP_MAX_POSITION+JUMP_MAX_POSITION){
            vel.y = -13;//upwards - don't change x velocity
           temp_body->SetLinearVelocity( vel );
        }
    }

}



void Player::setObjSpeed(const float x){
    if(x < 250.0f ){
        speed = x;
    }else{
        speed = 250.0f;
    }
}
