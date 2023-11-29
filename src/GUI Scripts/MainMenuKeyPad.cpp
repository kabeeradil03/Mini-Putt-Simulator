// main funtion for opening a main menu
// ability to navigate to sub-menus using KEYPAD

#include <SFML/Graphics.hpp>
#include "MainMenu.h"
using namespace sf;

int main() {
    //Make a main window
    RenderWindow MENU(VideoMode(1500,800), "Main Menu", Style::Default);
    MainMenu mainMenuText(MENU.getSize().x, MENU.getSize().y);

    while (MENU.isOpen()) {
        Event mainEvent;
        while (MENU.pollEvent(mainEvent)){
            if(mainEvent.type == Event::Closed)
                MENU.close();
            if(mainEvent.type == Event::MouseMoved) {
                // display mouse position- comment out for final game use
                cout << mainEvent.mouseMove.y << endl;
                cout << mainEvent.mouseMove.x << endl;
            }
            if(mainEvent.type == Event::MouseButtonReleased){             
                
                    // Check if the mouse click is within a "Play" area
                    if (mainEvent.mouseButton.x > 650 && mainEvent.mouseButton.x < 750 &&
                        mainEvent.mouseButton.y > 225 && mainEvent.mouseButton.y < 295) {
                        // Create a new window for a certain area
                        RenderWindow START(VideoMode(1500,800), "MINI-PUTT GAME");
                        
                        // Keep the new window open until it's closed
                        while (START.isOpen()) {
                            Event startEvent;
                            while (START.pollEvent(startEvent)) {
                                if (startEvent.type == Event::Closed) {
                                    START.close();
                                }
                            }

                            START.clear();
                            // Draw content in the new window
                            START.display();
                        }
                    }

                    // Check if the mouse click is within a "Options" area
                    if (mainEvent.mouseButton.x > 650 && mainEvent.mouseButton.x < 750 &&
                        mainEvent.mouseButton.y > 365 && mainEvent.mouseButton.y < 410) {
                        // Create a new window for a certain area
                        RenderWindow OPTIONS(VideoMode(1500,800), "OPTIONS");
                        
                        // Keep the new window open until it's closed
                        while (OPTIONS.isOpen()) {
                            Event optionsEvent;
                            while (OPTIONS.pollEvent(optionsEvent)) {
                                if (optionsEvent.type == Event::Closed) {
                                    OPTIONS.close();
                                }
                            }

                            OPTIONS.clear();
                            // Draw content in the new window
                            OPTIONS.display();
                        }
                    }

                    // Check if the mouse click is within a "Rules" area
                    if (mainEvent.mouseButton.x > 650 && mainEvent.mouseButton.x < 750 &&
                        mainEvent.mouseButton.y > 465 && mainEvent.mouseButton.y < 510) {
                        // Create a new window for a certain area
                        RenderWindow RULES(VideoMode(1500,800), "RULES");
                        
                        // Keep the new window open until it's closed
                        while (RULES.isOpen()) {
                            Event rulesEvent;
                            while (RULES.pollEvent(rulesEvent)) {
                                if (rulesEvent.type == Event::Closed) {
                                    RULES.close();
                                }
                            }

                            RULES.clear();
                            // Draw content in the new window
                            RULES.display();
                        }
                    }
                
            }
        MENU.clear();
        mainMenuText.draw(MENU);
        MENU.display();
        }
    }
}