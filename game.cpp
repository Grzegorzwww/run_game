#include "game.h"
#include "defines.hpp"

#include <SFML/System/Vector2.hpp>

Game::Game() : window(sf::VideoMode(800, 600), "SFML window"),
    overtaking_point_x(0),delaying_point_x(0), player(nullptr)
{
    //cto

    window.setFramerateLimit(60);
    first_run = true;


    _gravity = b2Vec2(0.0f, 25.0f);
    World = new b2World(_gravity);


    view = window.getView();
    window.setView(view);
    
    menu = new Menu(window.getSize().x,window.getSize().y);
    distance = 0;
    player_freeze_flag  = true;



    if (!back_ground_tex.loadFromFile("graphics/white_background.jpg")) {
        std::cerr <<"Can't load background Image\n";
    }
    _backGroundSprite.setTextureRect(sf::IntRect(0, 0, ground_texture_parameter.texture_width,  window.getSize().y));
    _backGroundSprite.setTexture(back_ground_tex);
    _backGroundSprite.setPosition(0, 0);

    itemsGenerator = new ItemsGenerator(4);
    itemsGenerator->connect<Game, &Game::create_items>(this);

    ground = new Ground(*World,500, 580, ground_texture_parameter);


    BackgroundItem *temp_ptr;
    if(!(player = new Player(*World, 550 ,450))){
        ;//  player = nullptr;
    }


    resultloger = new ResultLoger("results.txt");
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


void Game::newGame() {

    player->setPosition(500, 500);
    distance = 0;
    player_freeze_flag = false;
    itemsGenerator->start();


    for(std::vector<BackgroundItem *>::iterator it = backgorud_items.begin(); it != backgorud_items.end(); it++){
        if((*it) != nullptr){
               delete (*it);
        }
    }

    backgorud_items.clear();
}

void Game::processEvents() {
    int i= 0;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        if(!player_freeze_flag){
            player->moveRight();
        }
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        if(!player_freeze_flag){
            player->moveLeft();
        }
    }


    DropItem *item;

    sf::Event event;
    while (window.pollEvent(event))
    {

        switch (event.type)
        {
        // window closed



        case sf::Event::TextEntered :
            if (event.text.unicode < 128)
            {
                 entered_text += static_cast<char>(event.text.unicode);
                 menu->enterPlayerName(entered_text);
            }
            break;

        case sf::Event::Closed:
            window.close();
            break;
            // key pressed
        case sf::Event::KeyPressed:                     // KEY PRESED
            switch(event.key.code)
            {
            case sf::Keyboard::Right :
                break;
            case sf::Keyboard::Left :
                break;
            case sf::Keyboard::Up:
                if(!menu->getMenuState()){ player->makeJump();}
                else{ menu->MoveUp();}

                break;
            case sf::Keyboard::Down :
                if(!menu->getMenuState()){ player->makeKneel();}
                else{ menu->MoveDown();}

                break;
            case sf::Keyboard::R :
                player->setRunning(true);
                break;
            case sf::Keyboard::L :
                break;
            case sf::Keyboard::A :
                break;
            case sf::Keyboard::D :
                break;
            case sf::Keyboard::W :
                break;
            case sf::Keyboard::S :
                break;
            case sf::Keyboard::V :
                break;
            case sf::Keyboard::B :
                break;
            case sf::Keyboard::Space :
                break;
            case sf::Keyboard::Y :
                break;
            case sf::Keyboard::N :
                break;
            default:
                break;
            case sf::Keyboard::Escape :
                 menu->showMenu();
                break;
            case sf::Keyboard::Return :

                if(menu->swapEnterNameFlag()){
                    menu->enterPlayerName(entered_text);
                    player_name = entered_text;
                    itemsGenerator->start();
                    player_freeze_flag = false;
                }

                if(menu->getMenuState()){

                    switch(menu->GetPresesedItem()) {
                    case NEW_GAME: //new game
                        newGame();
                        menu->hideMenu();
                        menu->hideResult();
                        break;
                    case CONTINUE:
                        menu->hideMenu();
                        menu->hideResult();
                        break;
                    case RESULT_MENU:
                        menu->getResultData(resultloger->showScore());
                        menu->showResult();
                        menu->hideMenu();
                        //TODO: //result here
                        break;
                    case EXIT:
                         //TODO: Dorobic nawiększy wynik i poprawić zapis
                        if( overtaking_point_x / 100 > 30) {
                            resultloger->addScore(player_name,  overtaking_point_x / 100);
                        }
                        window.close();
                        break;
                    }
                }

                break;
            }
            break;
        case sf::Event::KeyReleased:                        // KEY RELEASED
            switch(event.key.code)
            {
            case sf::Keyboard::R :
                player->setRunning(false);
                break;
            }
            break;
        }
    }
}

void Game::update() {

        collisionDetection();


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
     //   menu->draw(window);
    menu->reflash_possition(window.getSize().x,window.getSize().y, delaying_point_x);
    menu->draw(window);
    sprites_buffor.clear();
    window.display();

}

void Game::move_camera(){
    sf::Vector2f center =  view.getCenter();
    center.x =  player->getSpritePtr()->getGlobalBounds().left;
    view.setCenter(center);
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
    case stone:
        if(temp_ptr = new Stone(*World, start_x ,450, stone_texture_parameter )){
            backgorud_items.push_back(temp_ptr);
        }

    case bird:
        if(temp_ptr = new Bird(*World, start_x ,(std::rand() % 300), bluebird_texture_parameter)){
            backgorud_items.push_back(temp_ptr);
        }
        break;
    case bird2:
        if(temp_ptr = new Bird(*World, start_x ,(std::rand() % 300), normal_texture_parameter)){
            backgorud_items.push_back(temp_ptr);
        }
        break;
    }
}


void Game::motion_symulation(){
    std::vector<BackgroundItem *>::iterator it;
    if(backgorud_items.size() > 0){
        for(it = backgorud_items.begin(); it != backgorud_items.end(); it++){
            if((*it) != nullptr){
                Bird *temp;
                if(temp = dynamic_cast<Bird  *>(*it)){
                    temp->moveLeft();
                }
                if(backgorud_items.size() > 0){
                    if(delaying_point_x > ((*it)->getSpritePtr()->getPosition().x + OBJ_CREATE_MARGIN) )
                    {
                        delete (*it);
                        itemsGenerator->removeBackGorundItem();
                        *it = nullptr;
                        if(backgorud_items.size() == 1)
                            backgorud_items.clear();
                        else
                            backgorud_items.erase((it));
                        break;
                    }
                    if((*it)->getBodyPossition().x <= -7){;
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
        menu->setScore(delaying_point_x);
        int i;
        if(player != nullptr){
            player->run_animation();
        }
        if(backgorud_items.size() > 0){
            std::vector<BackgroundItem *>::iterator it;
            for(it = backgorud_items.begin(); it != backgorud_items.end(); it++){
                if(*it != nullptr){
                    AnimatedMovingObj *temp;
                    if(temp = dynamic_cast<AnimatedMovingObj  *>(*it)){
                        temp->run_animation();
                    }
                    Bird *temp_bird_obj;
                    if(typeid(Bird) ==  typeid(*(*it))){
                        if(temp_bird_obj = static_cast< Bird  *>(*it)){
                            if(temp_bird_obj->controlDropObj(delaying_point_x )){
                                BackgroundItem *item;
                                //std::cout<< "temp_bird_obj->getBodyPossition().x"<<temp_bird_obj->getBodyPossition().x<<std::endl;
                                 item = new DropItem(*World,temp_bird_obj->getSpritePtr()->getGlobalBounds().left, temp_bird_obj->getSpritePtr()->getGlobalBounds().top, drop_item[std::rand()%3]);
                                 backgorud_items.push_back(item);
                                 break;
                            }
                        }
                    }
                }
            }
        }
        clock.restart();
    }
}

void Game::incLevel(){
    if(delaying_point_x % 1000 == 0){
        itemsGenerator->decTimerToWaitInterval();
    }
    if(delaying_point_x % 2500 == 0){
        itemsGenerator->incMaxBackGroundElements();
    }
}

void Game::collisionDetection(){
    if(player != nullptr ){
        std::vector<BackgroundItem *>::iterator it;
        for(it = backgorud_items.begin(); it != backgorud_items.end(); it++){
            if(typeid(DropItem) ==  typeid(*(*it))){
                if(player->getSpritePtr()->getGlobalBounds().intersects((*it)->getSpritePtr()->getGlobalBounds())){
                    itemsGenerator->stop();
                    menu->setResulMenu("PRZEGRANA");
                    menu->showResult();
                    player_freeze_flag = true;

                }
            }
        }
    }
}








