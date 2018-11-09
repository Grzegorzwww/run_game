#ifndef MENU_H
#define MENU_H

#include "iostream"
#include "ostream"
#include "sstream"
#include "defines.hpp"

#include "SFML/Graphics.hpp"

static const int MAX_NUMBER_ITEMS = 4;
static const int MAX_NUMBER_ALL_ITEMS = 8;


static const int NEW_GAME =0;
static const int CONTINUE = 1;
static const int RESULT_MENU = 2;
static const int EXIT = 3;
static const int RESULT_TEXT = 4;

static const int SCORE_TEXT_PL1 = 5;
static const int SCORE_TEXT_PL2 = 6;
static const int ENTER_NAME = 7;



class Menu
{
public:


    Menu(float width, float height);
    ~Menu();

    int GetPresesedItem() {return selectedItemIndex;}
    void draw(sf::RenderWindow &window);
    void showMenu();
    void hideMenu();

    void reflash_possition(float width, float height, int x_move);

    void showResult();
    void hideResult();

    bool getMenuState() {return show_hide_flag;}
    bool swapEnterNameFlag();
    void MoveUp();
    void MoveDown();
    void setResulMenu(std::string str);
    void setScore(unsigned int score);
    void enterPlayerName(const std::string str);
    void getResultData(const results_data_t x);





private:

      Menu();
      int selectedItemIndex;
      sf::Font font;
      std::string player_name;
      sf::Text menu[MAX_NUMBER_ALL_ITEMS];
      volatile bool show_hide_flag;
      volatile bool show_result_menu_flag;
      volatile bool  show_enter_name_flag;

      results_data_t temp_results;






};

#endif // MENU_H
