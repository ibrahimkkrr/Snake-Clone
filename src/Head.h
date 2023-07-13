#pragma once
#include "SFML/Graphics.hpp"
#include <vector>
#include <iostream>

class Head
{
private:

	

	std::vector<sf::RectangleShape> body;


	sf::RectangleShape headShape;

	int direction;

	int bodySize = 0;

	int north = 1;
	int east = 2;
	int south = 3;
	int west = 4;

	
	void moveNorth();
	void moveEast();
	void moveSouth();
	void moveWest();


public:


	Head();
	void input();
	void move();
	void draw(sf::RenderWindow*);

	sf::RectangleShape& getShape();

	int getDirection() const;
	void setDirection(int);
};

