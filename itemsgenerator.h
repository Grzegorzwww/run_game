#ifndef ITEMSGENERATOR_H
#define ITEMSGENERATOR_H

#include <cstdint>
#include <cassert>
#include <iostream>
#include <cdelegate.h>
#include <SFML/System.hpp>

 typedef CDelegate<void,int> delegate_t;


class ItemsGenerator
{
public:
    ItemsGenerator(int value);


    bool addBackGorundItem();
    bool removeBackGorundItem();
    void setMaxBackGroundElements(int val) {max_background_items_on_screen = val;}
    void items_generator();


    template<class C, void (C::*Function)(int)>
    void connect(C *instance)
    {
        _delegate.Bind<C, Function>(instance);
    }

private:


    int backgorund_items_on_screen;
    int max_background_items_on_screen;

    int time_to_wait;
    sf::Clock clock; // starts the clock
    sf::Time elapsed1 = clock.getElapsedTime();

    delegate_t _delegate;



};

#endif // ITEMSGENERATOR_H
