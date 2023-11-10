#pragma once
#ifndef GUI_H
#define GUI_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>

int main();

//screens
int titleScreen(sf::RenderWindow& window);
int courseSelection(sf::RenderWindow& window);
int course1(sf::RenderWindow& window);
int course2(sf::RenderWindow& window);
int course3(sf::RenderWindow& window);


//mouse checks
bool mouseHover(sf::RenderWindow& window, sf::Sprite button);
bool clickedButton(sf::RenderWindow& window, sf::Sprite button);

//physics scripts
int collision();

#endif
