#include "GUI.h"

//coded by Jordan and edited for bugs and compatibility by Sam

std::tuple<sf::Vector2f, sf::Vector2f> checkCollision(sf::Vector2f position, sf::Vector2f velocity, sf::CircleShape ballSprite, sf::RectangleShape obstacle) {
	bool collided = false;
	
	if (position.x + 2 * ballSprite.getRadius() >= obstacle.getPosition().x && position.x <= obstacle.getPosition().x + obstacle.getSize().x && position.y + 2 * ballSprite.getRadius() >= obstacle.getPosition().y && position.y <= obstacle.getPosition().y + obstacle.getSize().y) {
		// Reverse the velocity if a collision with the obstacle occurs
		if (position.x + 2 * ballSprite.getRadius() >= obstacle.getPosition().x && position.x + 2 * ballSprite.getRadius() < obstacle.getPosition().x + 25) {
			velocity.x = -velocity.x;
			position.x = obstacle.getPosition().x - 2 * ballSprite.getRadius();
			collided = true;

		}
		if (position.x <= obstacle.getPosition().x + obstacle.getSize().x && position.x > obstacle.getPosition().x + obstacle.getSize().x - 25) {
			velocity.x = -velocity.x;
			position.x = obstacle.getPosition().x + obstacle.getSize().x;
			collided = true;
		}
		if (position.y + 2 * ballSprite.getRadius() >= obstacle.getPosition().y && position.y + 2 * ballSprite.getRadius() < obstacle.getPosition().y + 25) {
			velocity.y = -velocity.y;
			position.y = obstacle.getPosition().y - 2 * ballSprite.getRadius();
			collided = true;
		}
		if (position.y <= obstacle.getPosition().y + obstacle.getSize().y && position.y > obstacle.getPosition().y + obstacle.getSize().y - 25) {
			velocity.y = -velocity.y;
			position.y = obstacle.getPosition().y + obstacle.getSize().y;
			collided = true;
		}
	}
	return std::make_tuple(position, velocity);
}