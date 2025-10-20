#include "Brick.h"

Brick::Brick(float x, float y, float width, float height, float starting_health)
    : _isDestroyed(false)
{
    _shape.setPosition(x, y);
    _shape.setSize(sf::Vector2f(width, height));

    switch (int(starting_health))
    {
    case(1):
        _shape.setFillColor(sf::Color::Red);
        break;
    case(2):
        _shape.setFillColor(sf::Color::Yellow);
        break;
    case(3):
        _shape.setFillColor(sf::Color::Blue);
        break;
    case(4):
        _shape.setFillColor(sf::Color::Green);
        break;
    case(5):
        _shape.setFillColor(sf::Color::Magenta);

        break;
    default:
        break;
    }

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

        switch (int(health))
        {
        case(1):
            _shape.setFillColor(sf::Color::Red);
            break;
        case(2):
            _shape.setFillColor(sf::Color::Yellow);
            break;
        case(3):
            _shape.setFillColor(sf::Color::Blue);
            break;
        case(4):
            _shape.setFillColor(sf::Color::Green);
            break;
        case(5):
            _shape.setFillColor(sf::Color::Magenta);

            break;
        default:
            break;
        }
    }
}

float Brick::get_health()
{
    return health;
}
