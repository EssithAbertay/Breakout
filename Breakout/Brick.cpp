#include "Brick.h"

Brick::Brick(float x, float y, float width, float height, float starting_health)
    : _isDestroyed(false)
{
    _shape.setPosition(x, y);
    _shape.setSize(sf::Vector2f(width, height));
    _shape.setFillColor(sf::Color::Red);

    health = starting_health;
}

void Brick::render(sf::RenderWindow& window)
{
    if (!_isDestroyed) {
        window.draw(_shape);
    }
}

sf::FloatRect Brick::getBounds() const
{
    return _shape.getGlobalBounds();
}

void Brick::decrease_health()
{
    health--;
}

float Brick::get_health()
{
    return health;
}
