#include <SFML/Graphics.hpp>
#include "GUI.h"

int jordan_2() {
    // Create a window
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML shapes", sf::Style::Default, settings);
    // Define green we want
    sf::Color backgroundGreen(66, 111, 111);
    // Create a green background rectangle
    sf::RectangleShape background(sf::Vector2f(800.0f, 600.0f));
    background.setFillColor(backgroundGreen);

    // Create a white circle shape
    sf::CircleShape circle(20.0f); // Smaller circle
    circle.setFillColor(sf::Color::White);
    circle.setOutlineThickness(3.0f);
    circle.setOutlineColor(sf::Color::Black);

    // Create a black hole in the top right quadrant
    sf::CircleShape hole(25.0f);
    hole.setFillColor(sf::Color::Black);
    hole.setPosition(600.0f, 500.0f);

    // Create obstacle
    sf::RectangleShape obstacle(sf::Vector2f(100.0f, 100.0f));
    obstacle.setFillColor(sf::Color::Black);
    obstacle.setPosition(350, 250);

    // Create break pad
    sf::RectangleShape breakzone(sf::Vector2f(100.0f, 200.0f));
    breakzone.setFillColor(sf::Color::Red);
    breakzone.setPosition(150, 150);


    // Initialize the circle's position
    sf::Vector2f position(100.0f, 100.0f);
    circle.setPosition(position);

    // Initialize the circle's velocity
    sf::Vector2f velocity(0.0f, 0.0f);

    // Variables to track mouse drag
    sf::Vector2f dragStartPosition;
    bool isDragging = false;
    bool isStopped = true;

    while (window.isOpen()) {
        // Handle events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    // Start tracking drag
                    dragStartPosition = sf::Vector2f(sf::Mouse::getPosition(window));
                    isDragging = true;
                }
            }
            if (event.type == sf::Event::MouseButtonReleased) {
                if (event.mouseButton.button == sf::Mouse::Left && isDragging) {
                    // Calculate velocity based on mouse drag displacement
                    sf::Vector2f dragEndPosition = sf::Vector2f(sf::Mouse::getPosition(window));
                    velocity = (dragStartPosition - dragEndPosition) / 100.0f; // Adjust the divisor for desired speed

                    isDragging = false;
                    isStopped = false;
                }
            }
        }

        // Slow down the ball gradually
        velocity *= 0.9994f;

        //        // Truncate velocity
        //        if (!isStopped && (velocity.x + velocity.y) < 0.00001f){
        //            velocity.x = 0;
        //            velocity.y = 0;
        //            isStopped = true;
        //        }

                // Update the circle's position
        position += velocity;

        // Check for collisions with the window borders
        if (position.x < 0 || position.x > 800 - 50) { // 50 is the circle's diameter
            velocity.x = -velocity.x; // Reverse the horizontal velocity
        }
        if (position.y < 0 || position.y > 600 - 50) {
            velocity.y = -velocity.y; // Reverse the vertical velocity
        }

        // Check if the circle enters the hole
        if (hole.getGlobalBounds().intersects(circle.getGlobalBounds())) {
            // Reset the ball's position to the bottom left quadrant
            position = sf::Vector2f(rand() % 600 + 100, rand() % 400 + 100);
            velocity = sf::Vector2f(0.0f, 0.0f);
            hole.setPosition(rand() % 200 + 450, rand() % 400 + 100);
        }


        // Check for collisions with the obstacle
        if (position.x + 50 >= 350 && position.x <= 450 && position.y + 50 >= 250 && position.y <= 350) {
            // Reverse the velocity if a collision with the obstacle occurs
            if (position.x + 50 >= 350 && position.x + 50 < 350 + 25) {
                velocity.x = -velocity.x;
                position.x = 350 - 50;
            }
            if (position.x <= 450 && position.x > 450 - 25) {
                velocity.x = -velocity.x;
                position.x = 450;
            }
            if (position.y + 50 >= 250 && position.y + 50 < 250 + 25) {
                velocity.y = -velocity.y;
                position.y = 250 - 50;
            }
            if (position.y <= 350 && position.y > 350 - 25) {
                velocity.y = -velocity.y;
                position.y = 350;
            }
        }
        int flag = 0;
        // Check if the ball is on the break pad
        if (breakzone.getGlobalBounds().intersects(circle.getGlobalBounds())) {


            velocity += sf::Vector2f(0.0001f, 0.0000f); //must be dependent on break direction and severity
        }

        // Clear the window
        window.clear();

        // Draw the green background
        window.draw(background);

        // Set the updated position of the hole
        window.draw(hole);
        window.draw(obstacle);
        window.draw(breakzone);

        // Set the updated position of the circle
        circle.setPosition(position);

        window.draw(circle);

        // Display the content of the window
        window.display();
    }

    return 0;
}