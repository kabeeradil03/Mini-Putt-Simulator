#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

#define MAX_MAIN_TABS 3
class MainMenu
{

public:
    MainMenu(float width, float height);

    void draw(RenderWindow& window);
    void MoveUp(); // triggered by up button
    void MoveDown(); // triggered by down button

    int MainMenuPressed() {
        return menuSelected;
    }
    ~MainMenu();

private:
    int menuSelected; // tracks item selected at current time
    Font font;
    Text mainMenuText[MAX_MAIN_TABS];

};