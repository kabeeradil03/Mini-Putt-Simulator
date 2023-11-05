#include "GUI.h"

bool mouseHover(sf::RenderWindow& window, sf::Sprite button) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
    if (button.getGlobalBounds().contains(mousePosF))
    {
        return true;
    }
    else
    {
        return false;
    }
}