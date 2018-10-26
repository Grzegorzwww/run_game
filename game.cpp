#include "game.h"
#include "defines.hpp"

#include <SFML/System/Vector2.hpp>

Game::Game() : window(sf::VideoMode(800, 600), "SFML window"),
    overtaking_point_x(0),delaying_point_x(0), player(nullptr)
{
    //cto

    window.setFramerateLimit(60);


    _gravity = b2Vec2(0.0f, 25.0f);
    World = new b2World(_gravity);


    view = window.getView();
    window.setView(view);


    if (!back_ground_tex.loadFromFile("graphics/white_background.jpg")) {
        std::cerr <<"Can't load background Image\n";
    }
    _backGroundSprite.setTextureRect(sf::IntRect(0, 0, ground_texture_parameter.texture_width,  window.getSize().y));
    _backGroundSprite.setTexture(back_ground_tex);
    _backGroundSprite.setPosition(0, 0);

    itemsGenerator = new ItemsGenerator(1);
    itemsGenerator->connect<Game, &Game::create_items>(this);

    ground = new Ground(*World,500, 580, ground_texture_parameter);

    BackgroundItem *temp_ptr;
    if(!(player = new Player(*World, 550 ,450))){
      ;//  player = nullptr;
    }

}

Game::~Game()
{
    //dtor
}

void Game::run() {


    while (window.isOpen()) {
        processEvents();

        update();
        render();
        motion_symulation();
        move_camera();

        itemsGenerator->items_generator();

    }
}

void Game::processEvents() {
    int i= 0;

    sf::Event event;
    while (window.pollEvent(event))
    {
        // check the type of the event...
        switch (event.type)
        {
        // window closed
        case sf::Event::Closed:
            window.close();
            break;
            // key pressed
        case sf::Event::KeyPressed:
            switch(event.key.code)
            {

            break;
            case sf::Keyboard::Right :
                player->moveRight();
                std::cout <<" prawo"<<std::endl;
                break;
            case sf::Keyboard::Left :
                player->moveLeft();
                std::cout <<" lewo"<<std::endl;
                break;
            case sf::Keyboard::Up:
                player->makeJump();
                std::cout <<" up "<<std::endl;
                break;


            case sf::Keyboard::Down :

                break;
            case sf::Keyboard::K :

                break;
            case sf::Keyboard::L :
                break;
            case sf::Keyboard::A :
                break;
            case sf::Keyboard::D :
                break;
            case sf::Keyboard::W :
                break;
            case sf::Keyboard::S : std::cerr << "idle : palyer 2: down"<<std::endl;
                break;
            case sf::Keyboard::V :
                break;
            case sf::Keyboard::B :
                break;
            case sf::Keyboard::Space :
                //                if(ball == nullptr){
                //                    ball = new Ball(*World, "ball_small.png", 400 , 200);
                //                    resumeGame();
                //                }
                //                else {
                //                }
                break;
            case sf::Keyboard::Y :
                // resumeGame();
                break;
            case sf::Keyboard::N :
                //newGame();
                break;


            default:
                break;
            case sf::Keyboard::Escape :
                //menu->showMenu();
                break;

            case sf::Keyboard::Return :
                //                if(menu->getMenuState()){

                //                    switch(menu->GetPresesedItem()) {
                //                    case NEW_GAME: //new game
                //                        newGame();
                //                        menu->hideMenu();
                //                        menu->hideResult();
                //                        break;
                //                    case CONTINUE:
                //                        menu->hideMenu();
                //                        menu->hideResult();
                //                        break;
                //                    case RESULT_MENU:
                //                         menu->showResult();
                //                         menu->hideMenu();
                //                        //TODO: //result here
                //                        break;
                //                    case EXIT:
                //                        window.close();
                //                        break;

                //                    }
                //                }
                break;
            }
        }

    }
}

void Game::update() {

    //    collisionDetection();
    //    constrolLogic();


    sf::Sprite *class_temp_sprite = new sf::Sprite();
    for(b2Body *bodyIterator = World->GetBodyList(); bodyIterator  != 0; bodyIterator  = bodyIterator ->GetNext()) {
        class_temp_sprite = reinterpret_cast<sf::Sprite  *>( bodyIterator->GetUserData());
        class_temp_sprite->setPosition(SCALE * bodyIterator->GetPosition().x, SCALE * bodyIterator->GetPosition().y);
        class_temp_sprite->setRotation(bodyIterator->GetAngle() * 180/b2_pi);
        sprites_buffor.push_back(*class_temp_sprite);
    }
    World->Step(1/60.f, 8, 3);
}




void Game::render()
{
    window.clear();

    window.draw(_backGroundSprite);

    for(const auto &it : sprites_buffor)
        window.draw(it);
    //    menu->draw(window);
    sprites_buffor.clear();
    window.display();







}

void Game::move_camera(){
    sf::Vector2f center =  view.getCenter();


    //std::cout << "player top = "<<player->getSpritePtr()->getGlobalBounds().left<<std::endl;
    center.x =  player->getSpritePtr()->getGlobalBounds().left;
    view.setCenter(center);
    // std::cout <<"center = "<<center.x<<std::endl;
    window.setView(view);




    overtaking_point_x = center.x + (window.getSize().x/2) + OBJ_CREATE_MARGIN;
    delaying_point_x = center.x - (window.getSize().x/2) + OBJ_CREATE_MARGIN;





}

void Game::create_items(backgorund_item_type_t i)
{
    int start_x =  overtaking_point_x;


    BackgroundItem *temp_ptr;
    switch(i){
    case tree:
        temp_ptr = new Tree(*World,start_x,390, tree_texture_parameter);
        backgorud_items.push_back(temp_ptr);
        break;
    case mushroom:
        temp_ptr = new Mushroom(*World, start_x,480, mushroom_texture_parameter);
        backgorud_items.push_back(temp_ptr);
        break;
    case tree2:
        //        if(temp_ptr = new Player(*World, 450 ,300)){
        //            backgorud_items.push_back(temp_ptr);
        //        }

    case bird:
        if(temp_ptr = new AnimatedMovingObj(*World, start_x ,250, bluebird_texture_parameter)){
            backgorud_items.push_back(temp_ptr);
        }
        break;
    case bird2:
        if(temp_ptr = new AnimatedMovingObj(*World, start_x ,250, normal_texture_parameter)){
            backgorud_items.push_back(temp_ptr);
        }
        break;
    }
    std::cout <<"robie item"<<std::endl;
}


void Game::motion_symulation(){
    // std::cout << "motion_symulation"<<std::endl;
    std::vector<BackgroundItem *>::iterator it;
    if(backgorud_items.size() > 0){
        for(it = backgorud_items.begin(); it != backgorud_items.end(); it++){
            if((*it) != nullptr){
                //(*it)->moveLeft();


                if(backgorud_items.size() > 0){
                    if(delaying_point_x > ((*it)->getSpritePtr()->getPosition().x + OBJ_CREATE_MARGIN) )
                    {
                        delete (*it);
                        *it = nullptr;
                        if(backgorud_items.size() == 1)
                            backgorud_items.clear();
                        else
                            backgorud_items.erase((it));
                        std::cout << "po delete"<<std::endl;
                        break;
                    }

                    if((*it)->getBodyPossition().x <= -7){;
                        std::cout << "delete "<<std::endl;
                        delete (*it);
                        *it = nullptr;
                        if(backgorud_items.size() == 1)
                            backgorud_items.clear();
                        else
                            backgorud_items.erase((it));
                        break;
                    }
                }
            }
        }
    }

    int msek = clock.getElapsedTime().asMilliseconds();
    if(msek >= 100){
        int i;
        if(player != nullptr){
            player->run_animation();
        }
        if(backgorud_items.size() > 0){
            std::vector<BackgroundItem *>::iterator it;
            for(it = backgorud_items.begin(); it != backgorud_items.end(); it++){
                if(*it != nullptr){
                    AnimatedMovingObj *temp;
                    Player *temp_player;
                    if(temp = dynamic_cast<AnimatedMovingObj  *>(*it)){
                        temp->run_animation();
                    }

                }
            }
        }
        clock.restart();
    }


}








