#include "Gun.h"
#include "GameManager.h" 
#include <iostream>

Gun::Gun(sf::RenderWindow* window, GameManager* gameManager) : _window(window), _gameManager(gameManager)
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

void Gun::update(float dt, sf::Vector2f mouse_pos) //probably don't need to pass the mouse position and could do it all in game manager but this feels neater
{
	fire_cd += dt;
	current_position = mouse_pos;
	crosshair.setPosition({ current_position.x-23, current_position.y- 23 });
}




void Gun::fire()
{
	if (fire_cd >= fire_cd_max)
	{
		fire_cd = 0;

		_gameManager->getBrickManager()->checkPointCollision(current_position); //fire the gun wherever mouse is


		//play audio here
	}
}

void Gun::render()
{
	_window->draw(crosshair);
}


