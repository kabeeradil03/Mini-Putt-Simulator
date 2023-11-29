#include "GUI.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(1600, 1200), "Mini-Golf Simulator");

	//set framerate to 60 for speed consistency
	window.setFramerateLimit(60);

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	
	GameProgress newGame = GameProgress();

	titleScreen(window, newGame);
	
	//for testing (remove later)

	//realCourse2(window);
	//realCourse3(window, newGame);
	//map2();
	//map3();
	//jordan_4();
	return 0;
}