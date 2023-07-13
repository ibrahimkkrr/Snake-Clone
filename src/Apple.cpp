#include "Apple.h"

Apple::Apple()
{

	appleShape.setSize(sf::Vector2f(25.0f,25.0f));
	appleShape.setFillColor(sf::Color::Red);
	spawn();
	texture.loadFromFile("apple.png");
	appleShape.setTexture(&texture);
}


void Apple::spawn()
{
	int x = rand() % 775;
	int y = rand() % 600;

	x = std::round(x / 25.f) * 25.f;
	y = std::round(y / 25.f) * 25.f;
	appleShape.setPosition(x, y);

	spawnState = true;

}


void Apple::update()
{
	if (!spawnState)
		spawn();
}


void Apple::draw(sf::RenderWindow& window)
{
	window.draw(appleShape);
}


void Apple::setSpawnState(bool new_state)
{
	spawnState = new_state;
}


sf::RectangleShape& Apple::getShape()
{
	return appleShape;
}