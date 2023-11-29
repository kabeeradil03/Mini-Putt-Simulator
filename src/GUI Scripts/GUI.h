#pragma once
#ifndef GUI_H
#define GUI_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>

//game progress class (keep track of courses unlocked + stars + equipment?)
class GameProgress {
private:
	int coursesUnlocked;
	
	//maybe??
	int equipmentUnlocked;

	int course1Stars;
	int course2Stars;
	int course3Stars;

public:
	GameProgress();

	//changes num of stars and returns info
	int checkScore(int numShots, int courseNum);

	int getAmtCourses();
	int getAmtEquipment();
	int getAmtC1();
	int getAmtC2();
	int getAmtC3();
};

int main();

//screens
int titleScreen(sf::RenderWindow& window, GameProgress game);
int courseSelection(sf::RenderWindow& window, GameProgress game);
int results(sf::RenderWindow& window, GameProgress game, int courseNumber, int numShots);

////temp ones
//int course1(sf::RenderWindow& window);
//int course2(sf::RenderWindow& window);
//int course3(sf::RenderWindow& window);
//
////temp maps for reference)
//int map1();
//int map2();
//int map3();
//
////reference physics 
//int jordan_4();

//real ones/combination of the above
int realCourse1(sf::RenderWindow& window, GameProgress game);
int realCourse2(sf::RenderWindow& window, GameProgress game);
int realCourse3(sf::RenderWindow& window, GameProgress game);

//mouse checks for GUI
bool mouseHover(sf::RenderWindow& window, sf::Sprite button);
bool clickedButton(sf::RenderWindow& window, sf::Sprite button);

//collision check
std::tuple<sf::Vector2f, sf::Vector2f> checkCollision(sf::Vector2f position, sf::Vector2f velocity, sf::CircleShape ballSprite, sf::RectangleShape obstacle);

#endif
