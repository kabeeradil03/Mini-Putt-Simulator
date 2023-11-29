#include "MainMenu.h"
#include <SFML/Graphics/Font.hpp>

// MainMenu constructor
MainMenu::MainMenu(float width, float height)
{
    // handle error
    if (!font.loadFromFile("./Amatic-Bold.ttf")) {
        cout << "No font is here";
    }

    //Start
    mainMenuText[0].setFont(font);
    mainMenuText[0].setFillColor(Color::White);
    mainMenuText[0].setString("Start");
    mainMenuText[0].setPosition((width/2) - 100, 200); 
    mainMenuText[0].setCharacterSize(100);

    //Options
    mainMenuText[1].setFont(font);
    mainMenuText[1].setFillColor(Color::White);
    mainMenuText[1].setString("Options");
    mainMenuText[1].setPosition((width/2) - 100, 350);
    mainMenuText[1].setCharacterSize(70);

    //Rules
    mainMenuText[2].setFont(font);
    mainMenuText[2].setFillColor(Color::White);
    mainMenuText[2].setString("Rules");
    mainMenuText[2].setPosition((width/2) - 100, 450);
    mainMenuText[2].setCharacterSize(70);

    menuSelected = -1; // doesn't select any menus by defauly
}

// destructor
MainMenu::~MainMenu()
{
}

//Draw MainMenu
void MainMenu::draw(RenderWindow& window) {
    for (int i=0; i<MAX_MAIN_TABS; ++i) {
        window.draw(mainMenuText[i]);
    }
}

//MoveUp
void MainMenu::MoveUp()
{
    if (menuSelected - 1 >= 0) { // can move up a menu
        mainMenuText[menuSelected].setFillColor(Color::White);
        menuSelected--;
        mainMenuText[menuSelected].setFillColor(Color::Red);
    }
}

//MoveDown
void MainMenu::MoveDown() {
    if (menuSelected + 1 <= MAX_MAIN_TABS)
    {
        mainMenuText[menuSelected].setFillColor(Color::White);
        menuSelected++;
        mainMenuText[menuSelected].setFillColor(Color::Red);        
    }
}