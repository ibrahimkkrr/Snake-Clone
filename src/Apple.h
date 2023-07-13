#pragma once
#include "SFML/Graphics.hpp"
#include <random>
class Apple
{
private:

	bool spawnState = false;

	sf::RectangleShape appleShape;
	sf::Texture texture;



public:

	Apple();
	void update();
	void draw(sf::RenderWindow&);

	void spawn();
	void setSpawnState(bool);

	sf::RectangleShape& getShape();

};

