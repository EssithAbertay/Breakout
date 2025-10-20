#include "Gun.h"

#include <iostream>

Gun::Gun(sf::RenderWindow* window) : _window(window)
{
	if(text.loadFromFile("gfx/crosshair.png"))
	{
		crosshair.setTexture(text);
	}
	else
	{
		std::cout << "ERROR LOADING TEXTURE" << std::endl;
	}
}

Gun::~Gun()
{
}

void Gun::update(sf::Vector2f mouse_pos)
{
	crosshair.setPosition({ mouse_pos.x-23, mouse_pos.y- 23 });
}

void Gun::render()
{
	_window->draw(crosshair);
}


