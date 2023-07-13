#include "Head.h"


Head::Head()
{

	headShape.setSize(sf::Vector2f(25.0f, 25.0f));
	headShape.setPosition(sf::Vector2f(375.0f, 125.0f));

	direction = east;

}





void Head::move()
{

	
	switch (direction)
	{
	case 1:
		moveNorth();
		break;
	case 2: 

		moveEast();
		break;
	case 3:

		moveSouth();
		break;
	case 4:
		moveWest();
		break;

	default:
		break;
	}

}


void Head::moveNorth()
{

	headShape.move(0.0f, -25.0f);
}


void Head::moveEast()
{

	headShape.move(25.0f, 0.0f);

}


void Head::moveSouth()
{


	headShape.move(0.0f, 25.0f);
}

void Head::moveWest()
{

	headShape.move(-25.0f, 0.0f);

}



void Head::draw(sf::RenderWindow* window)
{
	window->draw(headShape);


}


int Head::getDirection() const
{
	return direction;
}

sf::RectangleShape& Head::getShape()
{
	return headShape;
}

void Head::setDirection(int new_direction)
{

		direction = new_direction;
}