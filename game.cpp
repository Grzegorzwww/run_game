#include "game.h"



Game::Game() : window(sf::VideoMode(800, 600), "SFML window")
{
    //cto

    window.setFramerateLimit(60);





    _gravity = b2Vec2(0.0f, 25.0f);
    World = new b2World(_gravity);




    if (!back_ground_tex.loadFromFile("graphics/white_background.jpg")) {
        std::cerr <<"Can't load background Image\n";
    }
    _backGroundSprite.setTexture(back_ground_tex);
    _backGroundSprite.setPosition(0, 0);

    itemsGenerator = new ItemsGenerator(2);
    itemsGenerator->connect<Game, &Game::create_items>(this);

    ground = new Ground(*World,400, 580);

    tree_sample = new Tree(*World, 500,500);

    mushroom = new Mushroom(*World, 300,540);


    //item_1 = new  MovingBackgroundItem(*World, "graphics/tree_v2.jpg", 900, 503, 221, 231);
   // item_2 = new  MovingBackgroundItem(*World, "graphics/mushroom_2d_2.jpg", 400, 520, 160, 180);


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
                break;

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

    motion_symulation();


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

void Game::create_items(int i)
{
    std::cout <<"robie item"<<std::endl;
}


void Game::motion_symulation(){

//    if(item_1 != nullptr){
//        item_1->moveLeft();
//        if(item_1->getBodyPossition().x <= -7){
//            std::cout <<"usun" << std::endl;
//           // item_1->deleteObject();
//            delete item_1;
//            item_1 = nullptr;
//        }
//    }

//    if(item_2 != nullptr){
//        item_2->moveLeft();
//        if(item_2->getBodyPossition().x <= -7){
//            std::cout <<"usun" << std::endl;
//           // item_1->deleteObject();
//            delete item_2;
//            item_2 = nullptr;
//        }
//    }





}






//void Game::collisionDetection(){
//    if((ground != nullptr) && (ball != nullptr)){

//            float y = ball->getSprite().getPosition().y;
//            if(prev_ball_altitude <= 500){
//                if(y > 500 && (game_sate != MENU_DISPLAYED_PLAYER_1 || game_sate != MENU_DISPLAYED_PLAYER_2)){
//                    switch(game_sate){
//                    case WAIT_TO_FAIL_PLAYER_1:
//                        game_sate = FAIL_DETECTED_PLAYER_1;
//                        menu->hideResult();
//                        break;
//                    case WAIT_TO_FAIL_PLAYER_2:
//                        game_sate = FAIL_DETECTED_PLAYER_2;
//                        menu->hideResult();
//                        break;
//                    case FAIL_DETECTED_PLAYER_1:

//                        break;
//                    case FAIL_DETECTED_PLAYER_2:
//                        //nop
//                        break;
//                    default:
//                        break;
//                    }
//                }
//            }
//            prev_ball_altitude = y;
//    }

//    if(ball != nullptr){
//        if(player_one->getSprite().getGlobalBounds().intersects(ball->getSprite().getGlobalBounds()) && !fail_detcted){
//               game_sate = WAIT_TO_FAIL_PLAYER_2;
//        }
//        if(player_one->getPaddleSprite().getGlobalBounds().intersects(ball->getSprite().getGlobalBounds()) && !fail_detcted){
//               game_sate = WAIT_TO_FAIL_PLAYER_2;
//        }
//        if(player_two->getSprite().getGlobalBounds().intersects(ball->getSprite().getGlobalBounds()) && !fail_detcted){
//               game_sate = WAIT_TO_FAIL_PLAYER_1;
//        }
//        if(player_two->getPaddleSprite().getGlobalBounds().intersects(ball->getSprite().getGlobalBounds()) && !fail_detcted){
//               game_sate = WAIT_TO_FAIL_PLAYER_1;
//        }
//    }
//}





