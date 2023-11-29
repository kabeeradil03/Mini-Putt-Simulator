#include "GUI.h"

int results(sf::RenderWindow& window, GameProgress game, int courseNum, int numShots) {
	//load in textures and create sprites
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

	//load results window
	sf::Texture resultsWindow;
	resultsWindow.loadFromFile("resultsWindow.png");

	sf::Sprite resultsWindowSprite;
	resultsWindowSprite.setTexture(resultsWindow);
	resultsWindowSprite.setPosition(sf::Vector2f(390.f, 550.f));

	//load course selection screen button
	sf::Texture courseSelectionButton;
	courseSelectionButton.loadFromFile("courseSelectionButton.png");

	sf::Texture courseSelectionButtonHover;
	courseSelectionButtonHover.loadFromFile("courseSelectionButtonClicked.png");

	sf::Sprite courseSelectionButtonSprite;
	courseSelectionButtonSprite.setTexture(courseSelectionButton);
	courseSelectionButtonSprite.setPosition(sf::Vector2f(450.f, 950.f));

	//load title screen button
	sf::Texture titleButton;
	titleButton.loadFromFile("titleButton.png");

	sf::Texture titleButtonClicked;
	titleButtonClicked.loadFromFile("titleButtonClicked.png");

	sf::Sprite titleButtonSprite;
	titleButtonSprite.setTexture(titleButton);
	titleButtonSprite.setPosition(sf::Vector2f(810.f, 950.f));

	//load star textures
	sf::Texture starUnfilled;
	starUnfilled.loadFromFile("starUnfilled.png");

	sf::Texture starFilled;
	starFilled.loadFromFile("starFilled.png");

	//make the stars and have see how many should be filled vs unfilled
	//so firts get the num of stars by checking the score
	int numStars = game.checkScore(numShots, courseNum);

	sf::Sprite star1;
	star1.setTexture(starUnfilled);
	if (numStars >= 1) {
		star1.setTexture(starFilled);
	}
	star1.setScale(2, 2);
	star1.setPosition(sf::Vector2f(610.f, 790.f));

	sf::Sprite star2;
	star2.setTexture(starUnfilled);
	if (numStars >= 2) {
		star2.setTexture(starFilled);
	}
	star2.setScale(2, 2);
	star2.setPosition(sf::Vector2f(730.f, 790.f));

	sf::Sprite star3;
	star3.setTexture(starUnfilled);
	if (numStars >= 3) {
		star3.setTexture(starFilled);
	}
	star3.setScale(2, 2);
	star3.setPosition(sf::Vector2f(850.f, 790.f));

	sf::Text resultsMessage;
	sf::Font font;
	font.loadFromFile("Amatic-Bold.ttf");
	resultsMessage.setFont(font);
	resultsMessage.setFillColor(sf::Color::White);
	resultsMessage.setCharacterSize(130);
	
	if (numStars == 3) {
		resultsMessage.setString("PERFECT!");
		resultsMessage.setPosition(sf::Vector2f(673.f, 620.f));
	}
	else if (numStars == 2) {
		resultsMessage.setString("Great job!");
		resultsMessage.setPosition(sf::Vector2f(630.f, 620.f));
	}
	else if (numStars == 1) {
		resultsMessage.setString("Well done");
		resultsMessage.setPosition(sf::Vector2f(630.f, 620.f));
	}
	else {
		resultsMessage.setString("Try again!");
		resultsMessage.setPosition(sf::Vector2f(630.f, 620.f));
	}


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
		if (mouseHover(window, courseSelectionButtonSprite)) {
			courseSelectionButtonSprite.setTexture(courseSelectionButtonHover);

			if (clickedButton(window, courseSelectionButtonSprite)) {
				courseSelection(window, game);
			}
		}
		else {
			courseSelectionButtonSprite.setTexture(courseSelectionButton);
		}


		if (mouseHover(window, titleButtonSprite)) {
			titleButtonSprite.setTexture(titleButtonClicked);

			if (clickedButton(window, titleButtonSprite)) {
				titleScreen(window, game);
			}
		}
		else {
			titleButtonSprite.setTexture(titleButton);
		}

		window.clear(sf::Color::Black);
		window.draw(backgroundSprite);
		window.draw(titleSprite);
		window.draw(logoSprite);
		window.draw(resultsWindowSprite);
		window.draw(star1);
		window.draw(star2);
		window.draw(star3);
		window.draw(resultsMessage);
		window.draw(courseSelectionButtonSprite);
		window.draw(titleButtonSprite);

		window.display();
	}
	return 0;
}
