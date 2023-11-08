#include "GUI.h"

//checks to see if a button has been pressed
//returns true if yes and false if no
bool clickedButton(sf::RenderWindow& window, sf::Sprite button) {
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		return true;
	}
	else {
		return false;
	}
}