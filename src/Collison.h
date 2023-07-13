#pragma once
#include "SFML/Graphics.hpp"
#include "Snake.h"
#include "Apple.h"

class Collison
{

private:



	bool checkCollison(sf::RectangleShape*,Apple*);
	bool checkCollison(Snake*, Apple*);
	bool checkCollison(sf::RectangleShape*, sf::RectangleShape*);


public:

	void doCollison(Snake&,Apple&);
	void doCollision(Snake&, sf::RectangleShape&);
	void doCollisionSpawn(Snake&, Apple&);



};

