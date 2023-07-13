#include "SnakeBodyPart.h"


SnakeBodyPart::SnakeBodyPart(sf::Vector2f postion, int spawn_direction)
	:bodyPartPostion(postion),direction(spawn_direction)
{
	bodyPartShape.setSize(sf::Vector2f(25.0f, 25.0f));
	bodyPartShape.setPosition(postion);
	bodyPartBounds = bodyPartShape.getGlobalBounds();

}
void SnakeBodyPart::setupSpawnPostion()
{
	switch (direction)
	{
	case 1:
		northSetup();
		break;
	case 2:
		eastSetup();
		break;
	case 3:
		southSetup();
		break;
	case 4:
		westSetup();
		break;
	default:
		break;
	}
}



void SnakeBodyPart::northSetup()
{

	bodyPartShape.setPosition(bodyPartPostion.x, bodyPartPostion.y + bodyPartBounds.height);


}


void SnakeBodyPart::eastSetup()
{

	bodyPartShape.setPosition(bodyPartPostion.x - bodyPartBounds.width, bodyPartPostion.y);


}


void SnakeBodyPart::southSetup()
{


	bodyPartShape.setPosition(bodyPartPostion.x, bodyPartPostion.y - bodyPartBounds.height);

}




void SnakeBodyPart::westSetup()
{


	bodyPartShape.setPosition(bodyPartPostion.x + bodyPartBounds.width, bodyPartPostion.y);

}



void SnakeBodyPart::move()
{

	sf::Time elapsedTime = clock.restart();
	timeSinceLastUpdate += elapsedTime;
	while (timeSinceLastUpdate > TimePerFrame)
	{
		timeSinceLastUpdate -= TimePerFrame;
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
}


void SnakeBodyPart::moveNorth()
{
	bodyPartShape.move(0.0f, -25.0f);
}


void SnakeBodyPart::moveEast()
{

	bodyPartShape.move(25.0f, 0.0f);

}


void SnakeBodyPart::moveSouth()
{

	bodyPartShape.move(0.0f, 25.0f);
}

void SnakeBodyPart::moveWest()
{
	bodyPartShape.move(-25.0f, 0.0f);

}



void SnakeBodyPart::draw(sf::RenderWindow* window)
{
	window->draw(bodyPartShape);
}


int SnakeBodyPart::getDirection() const
{
	return direction;
}

sf::RectangleShape& SnakeBodyPart::getShape()
{
	return bodyPartShape;
}

void SnakeBodyPart::setDirection(int new_direction)
{

	direction = new_direction;
}