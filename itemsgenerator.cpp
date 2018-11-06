#include "itemsgenerator.h"

ItemsGenerator::ItemsGenerator(int value)
{

    backgorund_items_on_screen = 0;
    max_background_items_on_screen = value;
    time_to_wait = 1;
    max_time_to_wait = 6;

    std::srand( time( NULL ) );



}

void ItemsGenerator::decTimerToWaitInterval(){
    max_time_to_wait--;
}
void ItemsGenerator::incMaxBackGroundElements(){
    max_background_items_on_screen++;
}

void ItemsGenerator::items_generator(){

    int sek = clock.getElapsedTime().asSeconds();
    if(sek >=  time_to_wait ){
        if(addBackGorundItem()){
            std::cout << " time_to_wait"<< time_to_wait <<std::endl;
            time_to_wait = ((std::rand() % max_time_to_wait )+2);
            int rand_item = ((std::rand() % 5 ));
            // int rand_item = 0;
            //   int rand_item = 3;
            //         if(rand_item <= 3){
            //             rand_item = 3;
            //         }
            //rand_item = 2;
            std::cout << "rand number "<<rand_item<<std::endl;
            _delegate(( backgorund_item_type_t)rand_item);
        }
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
