#include <SFML/Graphics.hpp>
#include "GUI.h"

int map3()
{
    sf::RenderWindow window(sf::VideoMode(1600, 1200), "Third Map: Most Complex So Far.");
    sf::Texture Background;
    Background.loadFromFile("courseBackground.png");
    sf::Sprite s(Background);

    //ball object:
    sf::CircleShape ball(30);
    ball.setFillColor(sf::Color::White);
    sf::Vector2f ballPosition(50, 250);
    ball.setPosition(ballPosition);
    float ballSpeed = 1.0f;

    //hole object:
    sf::CircleShape hole(40);
    hole.setFillColor(sf::Color::Black);
    sf::Vector2f holePosition(650,250);
    hole.setPosition(holePosition);

    //obstacle object1:
    sf::RectangleShape rectangle(sf::Vector2f(180, 80));
    sf::Color MyBrown(100,0,0);
    rectangle.setFillColor(MyBrown);
    sf::Vector2f rectPosition(300, 500);
    rectangle.setPosition(rectPosition);

    //obstacle object2:
    sf::RectangleShape rectangle2(sf::Vector2f(180, 80));
    rectangle2.setFillColor(MyBrown);
    sf::Vector2f rect2Position(450, 250);
    rectangle2.setPosition(rect2Position);

    //break object
    sf::RectangleShape slowdown(sf::Vector2f(200,100));
    slowdown.setFillColor(sf::Color::Red);
    sf::Vector2f breakPosition(150,200);
    slowdown.setPosition(breakPosition);

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

        // Ensure the ball does not intersect with the first rectangle
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

            // Ensure the ball does not intersect with the second rectangle
        if (ballPosition.x + 2 * ball.getRadius() > rect2Position.x && ballPosition.x < rect2Position.x + rectangle2.getSize().x
            && ballPosition.y + 2 * ball.getRadius() > rect2Position.y && ballPosition.y < rect2Position.y + rectangle2.getSize().y)
        {

            // If there's an intersection, adjust the ball's position
            float horizontalOverlap = std::min(std::abs(ballPosition.x + 2 * ball.getRadius() - rect2Position.x), std::abs(ballPosition.x - (rect2Position.x + rectangle2.getSize().x)));
            float verticalOverlap = std::min(std::abs(ballPosition.y + 2 * ball.getRadius() - rect2Position.y), std::abs(ballPosition.y - (rect2Position.y + rectangle2.getSize().y)));

            if (horizontalOverlap < verticalOverlap)
            {
                // Adjust horizontally
                if (ballPosition.x + ball.getRadius() < rect2Position.x + rectangle2.getSize().x / 2)
                {
                    ballPosition.x = rect2Position.x - 2 * ball.getRadius();
                }
                else
                {
                    ballPosition.x = rect2Position.x + rectangle2.getSize().x;
                }
            }
            else
            {
                // Adjust vertically
                if (ballPosition.y + ball.getRadius() < rect2Position.y + rectangle2.getSize().y / 2)
                {
                    ballPosition.y = rect2Position.y - 2 * ball.getRadius();
                }
                else
                {
                    ballPosition.y = rect2Position.y + rectangle2.getSize().y;
                }
            }
        }

        //slow down ball if it runs over the break object
        if (ballPosition.x + 2 * ball.getRadius() > breakPosition.x && ballPosition.x < breakPosition.x + slowdown.getSize().x
            && ballPosition.y + 2 * ball.getRadius() > breakPosition.y && ballPosition.y < breakPosition.y + slowdown.getSize().y) {
            ballSpeed = 0.2;
            }

        ball.setPosition(ballPosition);

        window.clear();
        window.draw(s);
        window.draw(rectangle);
        window.draw(rectangle2);
        window.draw(slowdown);
        window.draw(ball);
        window.draw(hole);
        window.display();
    }

    return 0;
}
