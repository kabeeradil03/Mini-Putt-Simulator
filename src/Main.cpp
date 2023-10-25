#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	// Create a window
	sf::RenderWindow window(sf::VideoMode(800, 600), "Mini Golf Game");
	window.setFramerateLimit(60);

	// Define golf ball and hole positions
	sf::Vector2f ballPosition(50, 50);
	sf::Vector2f holePosition(700, 500);

	// Create golf ball and hole shapes
	sf::CircleShape ball(10);
	ball.setFillColor(sf::Color::White);
	ball.setPosition(ballPosition);

	sf::CircleShape hole(15);
	hole.setFillColor(sf::Color::Red);
	hole.setPosition(holePosition);

	sf::Texture texture;
	if (!texture.loadFromFile("src/Assets/d6gfouv-d8377271-7f1b-4256-8dca-8263f3e7a64b.png"))
	{
		std::cout << "could not load";
		return 0;
	}

	sf::Sprite sprite;
	sprite.setTexture(texture);

	// Variables for controlling the ball's movement
	bool isMoving = false;
	sf::Vector2f velocity;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (!isMoving)
				{
					// Get the mouse click position
					sf::Vector2f clickPosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));

					// Calculate velocity to move the ball towards the click position
					velocity = clickPosition - ballPosition;
					float length = sqrt(velocity.x * velocity.x + velocity.y * velocity.y);
					velocity /= length;

					isMoving = true;
				}
			}
		}

		if (isMoving)
		{
			// Move the ball
			ballPosition += velocity;

			// Check if the ball reaches the hole
			if (ball.getGlobalBounds().intersects(hole.getGlobalBounds()))
			{
				isMoving = false;
				// Handle winning condition here
			}
		}

		window.clear(sf::Color(0, 128, 0)); // Background color

		// Draw the course, obstacles, and other game elements here

		window.draw(ball);
		window.draw(hole);
		window.draw(sprite);
		window.display();
	}

	return 0;
}