#pragma once
#include <SFML/Graphics.hpp>

class Brick {
public:
    Brick(float x, float y, float width, float height, float starting_health);
    void render(sf::RenderWindow& window);
    sf::FloatRect getBounds() const;

    void decrease_health();
    float get_health();

private:
    sf::RectangleShape _shape;
    bool _isDestroyed;
    float health;
};