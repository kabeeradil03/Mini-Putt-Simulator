#include "GUI.h"

int realCourse2(sf::RenderWindow& window, GameProgress game) {

	//load in textures and make sprites before the loop starts
	//load background
	sf::Texture background;
	background.loadFromFile("courseBackground.png");

	sf::Sprite backgroundSprite;
	backgroundSprite.setTexture(background);

	//load home button
	sf::Texture homeButton;
	homeButton.loadFromFile("homeButton.png");

	sf::Texture homeButtonClicked;
	homeButtonClicked.loadFromFile("homeButtonClicked.png");

	sf::Sprite homeButtonSprite;
	homeButtonSprite.setTexture(homeButton);
	homeButtonSprite.setPosition(sf::Vector2f(20.f, 20.f));

	//create ball
	sf::CircleShape ballSprite(20.0f); // Smaller ball
	ballSprite.setFillColor(sf::Color::White);
	ballSprite.setOutlineThickness(3.0f);
	ballSprite.setOutlineColor(sf::Color::Black);
	sf::Vector2f position(50.f, 250.f);
	ballSprite.setPosition(position);


	// Initialize the ball's velocity
	sf::Vector2f velocity(0.0f, 0.0f);

	//hole object:
	// Create a black hole in the top right quadrant
	sf::CircleShape hole(20.0f);
	hole.setFillColor(sf::Color::Black);
	hole.setPosition(1250.0f, 300.0f);

	//obstacle object:
	sf::Texture horizontalObstacleTexture;
	horizontalObstacleTexture.loadFromFile("obstacle.png");

	sf::Texture verticalObstacleTexture;
	verticalObstacleTexture.loadFromFile("verticalObstacle.png");

	sf::RectangleShape obstacle1(sf::Vector2f(429.f, 221.f));
	obstacle1.setTexture(&horizontalObstacleTexture);
	sf::Vector2f rectPosition1(500.f, 520.f);
	obstacle1.setPosition(rectPosition1);

	sf::RectangleShape obstacle2(sf::Vector2f(429.f, 221.f));
	obstacle2.setTexture(&horizontalObstacleTexture);
	sf::Vector2f rectPosition2(500.f, 270.f);
	obstacle2.setPosition(rectPosition2);

	sf::RectangleShape obstacle3(sf::Vector2f(221.f, 429.f));
	obstacle3.setTexture(&verticalObstacleTexture);
	sf::Vector2f rectPosition3(1100.f, 600.f);
	obstacle3.setPosition(rectPosition3);

	sf::RectangleShape obstacle4(sf::Vector2f(429.f, 221.f));
	obstacle4.setTexture(&horizontalObstacleTexture);
	sf::Vector2f rectPosition4(500.f, 20.f);
	obstacle4.setPosition(rectPosition4);

	//break object
	sf::Texture rampTexture;
	rampTexture.loadFromFile("ramp.png");

	sf::RectangleShape breakzone(sf::Vector2f(200.0f, 400.0f));
	breakzone.setTexture(&rampTexture);

	breakzone.setPosition(150, 250);

	//load shots text
	sf::Texture shotsText;
	shotsText.loadFromFile("shotsText.png");

	sf::Sprite shotsTextSprite;
	shotsTextSprite.setTexture(shotsText);
	shotsTextSprite.setPosition(sf::Vector2f(1225.f, 20.f));

	//load actual num of shots text
	sf::Text numShots;
	sf::Font font;
	font.loadFromFile("Amatic-Bold.ttf");
	numShots.setFont(font);
	numShots.setString("0");
	numShots.setCharacterSize(80);
	numShots.setFillColor(sf::Color::White);
	numShots.setPosition(sf::Vector2f(1500.f, 5.f));

	//trajectory line functionalities added by Sam
	//create trajectory line
	sf::RectangleShape trajectoryLine(sf::Vector2f(100, 3));
	trajectoryLine.setFillColor(sf::Color::White);
	//match position with the ball
	trajectoryLine.setOrigin(0, 0);
	trajectoryLine.setPosition(position.x + ballSprite.getRadius(), position.y + ballSprite.getRadius());

	//load drag and release text texture
	sf::Texture instructionsText;
	instructionsText.loadFromFile("dragReleaseText.png");

	sf::Sprite instructionsTextSprite;
	instructionsTextSprite.setTexture(instructionsText);
	instructionsTextSprite.setPosition(sf::Vector2f(100.f, 1100.f));

	// Variables to track mouse drag
	sf::Vector2f dragStartPosition;
	bool isDragging = false;
	bool isStopped = true;

	int strokesMade = 0;

	float mostCurrentRotation = 0;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

			if (event.type == sf::Event::MouseButtonPressed && std::abs(velocity.x) < 0.001 && std::abs(velocity.y) < 0.001) {
				if (event.mouseButton.button == sf::Mouse::Left) {
					// Start tracking drag
					//dragStartPosition = sf::Vector2f(sf::Mouse::getPosition(window));
					dragStartPosition = ballSprite.getPosition();
					isDragging = true;
				}
			}

			if (event.type == sf::Event::MouseButtonReleased) {
				if (event.mouseButton.button == sf::Mouse::Left && isDragging) {
					// Calculate velocity based on mouse drag displacement
					sf::Vector2f dragEndPosition = sf::Vector2f(sf::Mouse::getPosition(window));
					velocity = (dragStartPosition - dragEndPosition) / 20.f; // Adjust the divisor for desired speed
					strokesMade++;
					numShots.setString(std::to_string(strokesMade));
					isDragging = false;
					isStopped = false;
				}
			}

		}
		//home button functionality
		if (mouseHover(window, homeButtonSprite)) {
			homeButtonSprite.setTexture(homeButtonClicked);

			if (clickedButton(window, homeButtonSprite)) {
				titleScreen(window, game);
			}
		}
		else {
			homeButtonSprite.setTexture(homeButton);
		}

		//update trajectory line
		if (isDragging) {
			//make right length to signify power
			sf::Vector2f currentMousePosition = sf::Vector2f(sf::Mouse::getPosition(window));

			auto length = dragStartPosition - currentMousePosition;
			trajectoryLine.setSize(sf::Vector2f(sqrt(length.x * length.x + length.y * length.y), 3));

			//rotate relative to mouse
			const float PI = 3.14159265;
			float rotation = (atan2(trajectoryLine.getPosition().y - currentMousePosition.y, trajectoryLine.getPosition().x - currentMousePosition.x)) * 180 / PI;

			trajectoryLine.setRotation(rotation);
		}

		// Slow down the ball gradually
		velocity *= 0.9900f;

		// Truncate velocity -- edited by Sam
		if (!isStopped && !isDragging && (sqrt(velocity.x * velocity.x + velocity.y * velocity.y < 0.2f)) && (sqrt(velocity.x * velocity.x + velocity.y * velocity.y > 0.0f))) {
			velocity.x = 0;
			velocity.y = 0;
			isStopped = true;
		}

		// Update the ball's position
		position += velocity;

		// Check for collisions with the window borders
		if (position.x < 0 || position.x > 1600 - 50) {
			velocity.x = -velocity.x; // Reverse the horizontal velocity
		}
		if (position.y < 0 || position.y > 1200 - 50) {
			velocity.y = -velocity.y; // Reverse the vertical velocity
		}

		// Check if the ball enters the hole
		if (hole.getGlobalBounds().intersects(ballSprite.getGlobalBounds())) {
			//// Reset the ball's position to the bottom left quadrant
			//position = sf::Vector2f(rand() % 600 + 100, rand() % 400 + 100);
			//velocity = sf::Vector2f(0.0f, 0.0f);
			//hole.setPosition(rand() % 200 + 450, rand() % 400 + 100);
			results(window, game, 2, strokesMade);
		}

		std::tie(position, velocity) = checkCollision(position, velocity, ballSprite, obstacle1);
		std::tie(position, velocity) = checkCollision(position, velocity, ballSprite, obstacle2);
		std::tie(position, velocity) = checkCollision(position, velocity, ballSprite, obstacle3);
		std::tie(position, velocity) = checkCollision(position, velocity, ballSprite, obstacle4);

			
		// Check if the ball is on the break pad
		if (breakzone.getGlobalBounds().intersects(ballSprite.getGlobalBounds())) {
			velocity += sf::Vector2f(0.0000f, 1.0f); //must be dependent on break direction and severity
		}


		//draw everything to the window
		window.clear();
		window.draw(backgroundSprite);
		window.draw(breakzone);
		window.draw(obstacle1);
		window.draw(obstacle2);
		window.draw(obstacle3);
		window.draw(obstacle4);
		ballSprite.setPosition(position);
		trajectoryLine.setPosition(position.x + ballSprite.getRadius(), position.y + ballSprite.getRadius());
		if (isDragging) {
			window.draw(trajectoryLine);
		}
		window.draw(instructionsTextSprite);
		window.draw(ballSprite);
		window.draw(shotsTextSprite);
		window.draw(hole);
		window.draw(numShots);
		window.draw(homeButtonSprite);
		window.display();
	}

	return 0;
}