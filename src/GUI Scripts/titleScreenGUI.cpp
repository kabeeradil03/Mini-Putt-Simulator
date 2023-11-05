#include "GUI.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1600, 1200), "Mini-Golf Simulator");

	//load background
	sf::Texture background;
	background.loadFromFile("titleBackground.png");

	sf::Sprite backgroundSprite;
	backgroundSprite.setTexture(background);

	//load title
	sf::Texture title;
	title.loadFromFile("title.png");

	sf::Sprite titleSprite;
	titleSprite.setTexture(title);
	titleSprite.setPosition(sf::Vector2f(300.f, 90.f));

	//load flag logo
	sf::Texture logo;
	logo.loadFromFile("logo.png");

	sf::Sprite logoSprite;
	logoSprite.setTexture(logo);
	logoSprite.setPosition(sf::Vector2f(1100.f, 100.f));

	//load play button
	sf::Texture playButton;
	playButton.loadFromFile("playButton.png");

	sf::Sprite playButtonSprite;
	playButtonSprite.setTexture(playButton);
	playButtonSprite.setPosition(650.f, 650.f);

	//load settings button
	sf::Texture settingsButton;
	settingsButton.loadFromFile("settingsButton.png");

	sf::Sprite settingsButtonSprite;
	settingsButtonSprite.setTexture(settingsButton);
	settingsButtonSprite.setPosition(650.f, 860.f);

	//load equipment button
	sf::Texture equipmentButton;
	equipmentButton.loadFromFile("equipmentButton.png");

	sf::Sprite equipmentButtonSprite;
	equipmentButtonSprite.setTexture(equipmentButton);
	equipmentButtonSprite.setPosition(650.f, 760.f);
	equipmentButtonSprite.setScale(0.9f, 0.9f);

	//load hover button sprites
	sf::Texture playButtonHover;
	playButtonHover.loadFromFile("playButtonClicked.png");

	sf::Texture settingsButtonHover;
	settingsButtonHover.loadFromFile("settingsButtonClicked.png");

	sf::Texture equipmentButtonHover;
	equipmentButtonHover.loadFromFile("equipmentButtonClicked.png");

	while (window.isOpen()) 
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) 
			{
				window.close();
			}
		}

		//check to see if the mouse is hovering over any of the buttons
		if (mouseHover(window, playButtonSprite)) {
			playButtonSprite.setTexture(playButtonHover);
		}
		else {
			playButtonSprite.setTexture(playButton);
		}


		if (mouseHover(window, settingsButtonSprite)) {
			settingsButtonSprite.setTexture(settingsButtonHover);
		}
		else {
			settingsButtonSprite.setTexture(settingsButton);
		}


		if (mouseHover(window, equipmentButtonSprite)) {
			equipmentButtonSprite.setTexture(equipmentButtonHover);
		}
		else {
			equipmentButtonSprite.setTexture(equipmentButton);
		}

		window.clear(sf::Color::Black);
		window.draw(backgroundSprite);
		window.draw(titleSprite);
		window.draw(logoSprite);
		window.draw(playButtonSprite);
		window.draw(settingsButtonSprite);
		window.draw(equipmentButtonSprite);
		window.display();
	}
	return 0;
}