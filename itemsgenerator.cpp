#include "itemsgenerator.h"

ItemsGenerator::ItemsGenerator(int value)
{

    backgorund_items_on_screen = 0;
    max_background_items_on_screen = value;
    time_to_wait = 1;

    std::srand( time( NULL ) );



}



void ItemsGenerator::items_generator(){

     int sek = clock.getElapsedTime().asSeconds();
     if(sek >=  time_to_wait ){
         std::cout << " time_to_wait"<< time_to_wait <<std::endl;
         time_to_wait = (std::rand() % 6 );
         _delegate(1);
         clock.restart();
     }
}


bool ItemsGenerator::addBackGorundItem(){

    if(backgorund_items_on_screen < max_background_items_on_screen){
        backgorund_items_on_screen++;
        return true;
    }else{
        return false;
    }
}

bool ItemsGenerator::removeBackGorundItem(){
    if(backgorund_items_on_screen > 0){
        backgorund_items_on_screen--;
        return true;
    }else{
        return false;
    }

}
