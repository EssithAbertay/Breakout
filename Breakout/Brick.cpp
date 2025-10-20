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

void Brick::update_hit_time(float time)
{
    hit_time += time;
}

void Brick::decrease_health()
{
    if (hit_time >= hit_time_max)
    {
        hit_time = 0;
        health--;
    }
}

float Brick::get_health()
{
    return health;
}
