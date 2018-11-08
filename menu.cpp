#include "menu.h"

using namespace std;

Menu::Menu()
{


}

Menu::Menu(float width, float height) {

    if(!font.loadFromFile("fonts/Grande_October_Three.otf")) {
        cerr << "can not load font: SnakeStitch.ttf"<<endl;
    }
    show_hide_flag = false;
    show_result_menu_flag = false;
    show_enter_name_flag = true;

    menu[NEW_GAME].setFont(font);
    menu[NEW_GAME].setColor(sf::Color::Green);
    menu[NEW_GAME].setString("New Game");
    menu[NEW_GAME].setPosition(sf::Vector2f(width /4 , height / (MAX_NUMBER_ITEMS+ 1) * 1));

    menu[CONTINUE].setFont(font);
    menu[CONTINUE].setColor(sf::Color::Green);
    menu[CONTINUE].setString("Continue");
    menu[CONTINUE].setPosition(sf::Vector2f(width /4 , height / (MAX_NUMBER_ITEMS+ 1) * 2));

    menu[RESULT_MENU].setFont(font);
    menu[RESULT_MENU].setColor(sf::Color::Green);
    menu[RESULT_MENU].setString("WYNIKI");
    menu[RESULT_MENU].setPosition(sf::Vector2f(width /4 , height / (MAX_NUMBER_ITEMS+ 1) * 3));

    menu[ EXIT].setFont(font);
    menu[ EXIT].setColor(sf::Color::Green);
    menu[ EXIT].setString("Exit");
    menu[ EXIT].setPosition(sf::Vector2f(width /3 , height / (MAX_NUMBER_ITEMS+ 1) * 4));

    menu[RESULT_TEXT].setFont(font);
    menu[RESULT_TEXT].setColor(sf::Color::Green);
    menu[RESULT_TEXT].setString(" - ");
    menu[RESULT_TEXT].setPosition(sf::Vector2f(width /4 , height / 3 ));

    menu[SCORE_TEXT_PL1].setFont(font);
    menu[SCORE_TEXT_PL1].setColor(sf::Color::Green);
    menu[SCORE_TEXT_PL1].setString(" - ");
    menu[SCORE_TEXT_PL1].setPosition(sf::Vector2f(width - 40 , 20));

    menu[SCORE_TEXT_PL2].setFont(font);
    menu[SCORE_TEXT_PL2].setColor(sf::Color::Green);
    menu[SCORE_TEXT_PL2].setString(" - ");
    menu[SCORE_TEXT_PL2].setPosition(sf::Vector2f( 20, 20));

    menu[ENTER_NAME].setFont(font);
    menu[ENTER_NAME].setColor(sf::Color::Black);
    menu[ENTER_NAME].setString("Wpisz imie: ");
    menu[ENTER_NAME].setPosition(sf::Vector2f(width /2 , height / (MAX_NUMBER_ITEMS+ 1) * 2));



    selectedItemIndex = 0;
}

void Menu::reflash_possition(float width, float height, int x_move){

    menu[NEW_GAME].setPosition(sf::Vector2f((width /4) + x_move , height / (MAX_NUMBER_ITEMS+ 1) * 1));
    menu[CONTINUE].setPosition(sf::Vector2f((width /4 + x_move) , height / (MAX_NUMBER_ITEMS+ 1) * 2));
    menu[RESULT_MENU].setPosition(sf::Vector2f((width /4 + x_move), height / (MAX_NUMBER_ITEMS+ 1) * 3));
    menu[ EXIT].setPosition(sf::Vector2f((width /4 + x_move) , height / (MAX_NUMBER_ITEMS+ 1) * 4));
    menu[RESULT_TEXT].setPosition(sf::Vector2f((width /4 + x_move) , height / 3 ));
    menu[SCORE_TEXT_PL1].setPosition(sf::Vector2f((width ) + x_move - 100, 20));
    menu[SCORE_TEXT_PL2].setPosition(sf::Vector2f( x_move- 40, 20));
    menu[ENTER_NAME].setPosition(sf::Vector2f((width /4 + x_move) , height / 3 ));

}

void Menu::draw(sf::RenderWindow &window) {
    if(show_hide_flag) {

        for(int i = 0; i < MAX_NUMBER_ITEMS ; i++) {
            window.draw(menu[i]);
        }
    }
    if(show_result_menu_flag == true && show_hide_flag != true){
        //std::cout <<" wyswietlam wyniki: \n";
        window.draw(menu[RESULT_TEXT]);
        window.draw(menu[SCORE_TEXT_PL1]);

    }
    else if(show_enter_name_flag){
          window.draw(menu[ENTER_NAME]);
    }

      window.draw(menu[SCORE_TEXT_PL2]);
}
void Menu::enterPlayerName(const std::string str){
//    player_name = str;
    std::string temp("Wpisz imie: ");
    temp.append(str);
    menu[ENTER_NAME].setString(temp);
}

void Menu::setScore(unsigned int score){
    menu[SCORE_TEXT_PL2].setString("Dystans: " + std::to_string(score));
}

void  Menu::setResulMenu(std::string str) {
    menu[RESULT_TEXT].setString(str+"\n"  );
}


void  Menu::showMenu() {
     show_hide_flag = true;

}
void  Menu::hideMenu() {
    show_hide_flag = false;
}
void Menu::showResult() {
    show_result_menu_flag = true;



}
void Menu::hideResult() {
        show_result_menu_flag = false;
}



void Menu::MoveUp() {
    if(selectedItemIndex - 1 >= 0) {
        menu[selectedItemIndex].setColor(sf::Color::Green);
        selectedItemIndex--;
        menu[selectedItemIndex].setColor(sf::Color::Red);
    }
}
void Menu::MoveDown() {
    if(selectedItemIndex + 1 < MAX_NUMBER_ITEMS ) {
        menu[selectedItemIndex].setColor(sf::Color::Green);
        selectedItemIndex++;
        menu[selectedItemIndex].setColor(sf::Color::Red);

    }
}

bool Menu::swapEnterNameFlag(){
    if(show_enter_name_flag == true){
        show_enter_name_flag = !show_enter_name_flag;
        return !show_enter_name_flag;
    }
}


