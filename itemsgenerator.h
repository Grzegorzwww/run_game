#ifndef ITEMSGENERATOR_H
#define ITEMSGENERATOR_H

#include <cstdint>
#include <cassert>
#include <iostream>
#include <cdelegate.h>
#include <SFML/System.hpp>

#include "defines.hpp"

 typedef CDelegate<void, backgorund_item_type_t> delegate_t;


class ItemsGenerator
{
public:
    ItemsGenerator(int value);


    bool addBackGorundItem();
    bool removeBackGorundItem();
    void setMaxBackGroundElements(int val) {max_background_items_on_screen = val;}
    void items_generator();

    void decTimerToWaitInterval();
    void incMaxBackGroundElements();

    void stop();
    void start();


    template<class C, void (C::*Function)(backgorund_item_type_t)>
    void connect(C *instance)
    {
        _delegate.Bind<C, Function>(instance);
    }

private:



    int backgorund_items_on_screen;
    int max_background_items_on_screen;

    int time_to_wait;
    int max_time_to_wait;
    sf::Clock clock; // starts the clock
    sf::Time elapsed1 = clock.getElapsedTime();

    bool generate_on_off;
    delegate_t _delegate;



};

#endif // ITEMSGENERATOR_H
