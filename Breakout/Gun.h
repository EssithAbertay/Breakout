#pragma once
#include "SFML/Graphics.hpp"

class Gun
{
public:
	Gun(sf::RenderWindow* window);
	~Gun();

	void update(sf::Vector2f mouse_pos);

	void render();
private:
	sf::Sprite crosshair;
	sf::Texture text;
	sf::RenderWindow* _window;
};

