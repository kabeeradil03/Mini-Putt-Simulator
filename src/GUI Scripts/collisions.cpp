#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

//script by Kabeer to manage collision physics

// int main()
// {
// 	sf::RenderWindow window(sf::VideoMode(800, 600), "Movable Bounded Ball");
// 	sf::CircleShape ball(30);
// 	ball.setFillColor(sf::Color::Red);

// 	// Set initial position for the ball
// 	sf::Vector2f ballPosition(100, 100);
// 	ball.setPosition(ballPosition);

// 	// Create a rectangle shape
// 	sf::RectangleShape rectangle(sf::Vector2f(200, 100)); // Width and height of the rectangle
// 	rectangle.setFillColor(sf::Color::Green);			  // Set the fill color

// 	// Set the position of the rectangle
// 	sf::Vector2f rectPosition(350, 275);
// 	rectangle.setPosition(rectPosition);

// 	sf::Vector2f ballVelocity(0.0f, 0.0f); // Initialize the ball's velocity to zero
// 	float ballSpeed = 0.34f;			   // Speed of the ball

// 	while (window.isOpen())
// 	{
// 		sf::Event event;
// 		while (window.pollEvent(event))
// 		{
// 			if (event.type == sf::Event::Closed)
// 			{
// 				window.close();
// 			}
// 		}

// 		// Check for collision between the ball and the rectangle
// 		sf::FloatRect ballBounds = ball.getGlobalBounds();
// 		sf::FloatRect rectBounds = rectangle.getGlobalBounds();

// 		if (ballBounds.intersects(rectBounds))
// 		{
// 			// Collision detected, stop the ball from moving
// 			ballVelocity = sf::Vector2f(0.0f, -0.5f);
// 		}
// 		else
// 		{
// 			// Ball movement
// 			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && ballPosition.x > 0)
// 			{
// 				ballVelocity.x = -ballSpeed; // Move left
// 			}
// 			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && ballPosition.x < window.getSize().x - 2 * ball.getRadius())
// 			{
// 				ballVelocity.x = ballSpeed; // Move right
// 			}
// 			else
// 			{
// 				ballVelocity.x = 0.0f; // Stop horizontal movement
// 			}

// 			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && ballPosition.y > 0)
// 			{
// 				ballVelocity.y = -ballSpeed; // Move up
// 			}
// 			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && ballPosition.y < window.getSize().y - 2 * ball.getRadius())
// 			{
// 				ballVelocity.y = ballSpeed; // Move down
// 			}
// 			else
// 			{
// 				ballVelocity.y = 0.0f; // Stop vertical movement
// 			}
// 		}

// 		// Update the ball's position
// 		ballPosition += ballVelocity;
// 		ball.setPosition(ballPosition);

// 		window.clear();
// 		window.draw(ball);
// 		window.draw(rectangle);
// 		window.display();
// 	}

// 	return 0;
// }

#include <SFML/Graphics.hpp>
#include "GUI.h"

int collision()
{
	sf::RenderWindow window(sf::VideoMode(1600, 1200), "Movable Ball with Rectangle Boundary");

	sf::CircleShape ball(30);
	ball.setFillColor(sf::Color::Red);
	sf::Vector2f ballPosition(100, 300);
	ball.setPosition(ballPosition);
	float ballSpeed = 5.0f;

	sf::RectangleShape rectangle(sf::Vector2f(200, 100));
	rectangle.setFillColor(sf::Color::Blue);
	sf::Vector2f rectPosition(300, 300);
	rectangle.setPosition(rectPosition);
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

		// Ball movement
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			ballPosition.x -= ballSpeed;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			ballPosition.x += ballSpeed;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			ballPosition.y -= ballSpeed;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			ballPosition.y += ballSpeed;
		}

		// Ensure the ball stays within the window bounds
		if (ballPosition.x < 0)
		{
			ballPosition.x = 0;
		}
		if (ballPosition.x > window.getSize().x - 2 * ball.getRadius())
		{
			ballPosition.x = window.getSize().x - 2 * ball.getRadius();
		}
		if (ballPosition.y < 0)
		{
			ballPosition.y = 0;
		}
		if (ballPosition.y > window.getSize().y - 2 * ball.getRadius())
		{
			ballPosition.y = window.getSize().y - 2 * ball.getRadius();
		}

		// Ensure the ball does not intersect with the rectangle
		if (ballPosition.x + 2 * ball.getRadius() > rectPosition.x && ballPosition.x < rectPosition.x + rectangle.getSize().x
			&& ballPosition.y + 2 * ball.getRadius() > rectPosition.y && ballPosition.y < rectPosition.y + rectangle.getSize().y)
		{

			// If there's an intersection, adjust the ball's position
			float horizontalOverlap = std::min(std::abs(ballPosition.x + 2 * ball.getRadius() - rectPosition.x), std::abs(ballPosition.x - (rectPosition.x + rectangle.getSize().x)));
			float verticalOverlap = std::min(std::abs(ballPosition.y + 2 * ball.getRadius() - rectPosition.y), std::abs(ballPosition.y - (rectPosition.y + rectangle.getSize().y)));

			if (horizontalOverlap < verticalOverlap)
			{
				// Adjust horizontally
				if (ballPosition.x + ball.getRadius() < rectPosition.x + rectangle.getSize().x / 2)
				{
					ballPosition.x = rectPosition.x - 2 * ball.getRadius();
				}
				else
				{
					ballPosition.x = rectPosition.x + rectangle.getSize().x;
				}
			}
			else
			{
				// Adjust vertically
				if (ballPosition.y + ball.getRadius() < rectPosition.y + rectangle.getSize().y / 2)
				{
					ballPosition.y = rectPosition.y - 2 * ball.getRadius();
				}
				else
				{
					ballPosition.y = rectPosition.y + rectangle.getSize().y;
				}
			}
		}

		ball.setPosition(ballPosition);

		window.clear();
		window.draw(rectangle);
		window.draw(ball);
		window.display();
	}

	return 0;
}
