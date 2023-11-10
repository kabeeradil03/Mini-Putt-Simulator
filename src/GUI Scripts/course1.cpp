#include "GUI.h"

int course1(sf::RenderWindow& window) 
{
	//load in textures and make sprites before the loop starts
	//load background
	sf::Texture background;
	background.loadFromFile("courseBackground.png");

	sf::Sprite backgroundSprite;
	backgroundSprite.setTexture(background);

	//load golf ball (use powerBall sprite for now)
	sf::Texture powerBall;
	powerBall.loadFromFile("powerBall.png");

	sf::Sprite golfBallSprite;
	golfBallSprite.setTexture(powerBall);
	golfBallSprite.setPosition(sf::Vector2f(300.f, 700.f));

	//load trajectory line
	sf::Texture trajectoryLine;
	trajectoryLine.loadFromFile("directionLine.png");

	sf::Sprite trajectoryLineSprite;
	trajectoryLineSprite.setTexture(trajectoryLine);
	trajectoryLineSprite.setPosition(sf::Vector2f(330.f, 465.f));
	
	//load power bar
	sf::Texture powerBar;
	powerBar.loadFromFile("powerBar.png");
	
	sf::Sprite powerBarSprite;
	powerBarSprite.setTexture(powerBar);
	powerBarSprite.setPosition(sf::Vector2f(500.f, 1000.f));

	//load power ball
	sf::Texture accuracyBall;
	accuracyBall.loadFromFile("accuracyBall.png");

	sf::Sprite powerBallSprite;
	powerBallSprite.setTexture(accuracyBall);
	powerBallSprite.setPosition(sf::Vector2f(515.f, 1020.f));

	//load accuracy bar
	sf::Texture accuracyBar;
	accuracyBar.loadFromFile("accuracyBar.png");

	sf::Sprite accuracyBarSprite;
	accuracyBarSprite.setTexture(accuracyBar);
	accuracyBarSprite.setPosition(sf::Vector2f(520.f, 1000.f));

	//load accuracy ball
	sf::Sprite accuracyBallSprite;
	accuracyBallSprite.setTexture(powerBall);
	accuracyBallSprite.setPosition(sf::Vector2f(535.f, 1025.f));

	//load text(3)
	sf::Texture trajectoryText;
	trajectoryText.loadFromFile("directionText.png");

	sf::Sprite trajectoryTextSprite;
	trajectoryTextSprite.setTexture(trajectoryText);
	trajectoryTextSprite.setPosition(sf::Vector2f(350.f, 1125.f));

	sf::Texture powerText;
	powerText.loadFromFile("powerText.png");

	sf::Sprite powerTextSprite;
	powerTextSprite.setTexture(powerText);
	powerTextSprite.setPosition(sf::Vector2f(355.f, 1125.f));
	
	sf::Texture accuracyText;
	accuracyText.loadFromFile("accuracyText.png");

	sf::Sprite accuracyTextSprite;
	accuracyTextSprite.setTexture(accuracyText);
	accuracyTextSprite.setPosition(sf::Vector2f(345.f, 1125.f));

	//load shots text
	sf::Texture shotsText;
	shotsText.loadFromFile("shotsText.png");

	sf::Sprite shotsTextSprite;
	shotsTextSprite.setTexture(shotsText);
	shotsTextSprite.setPosition(sf::Vector2f(1225.f, 20.f));

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

		//check mouse stuff here

		window.clear();
		window.draw(backgroundSprite);
		//window.draw(trajectoryTextSprite);
		window.draw(trajectoryLineSprite);
		//window.draw(powerTextSprite);
		//window.draw(powerBarSprite);
		//window.draw(powerBallSprite);
		window.draw(accuracyBarSprite);
		window.draw(accuracyTextSprite);
		window.draw(accuracyBallSprite);
		window.draw(golfBallSprite);
		window.draw(shotsTextSprite);
		window.display();
	}

	return 0;
}