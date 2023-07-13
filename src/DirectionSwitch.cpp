#include "DirectionSwitch.h"


DirectionSwitch::DirectionSwitch()
{
	switcher.setSize(sf::Vector2f(25.0f, 25.0f));
	switcherBounds = switcher.getGlobalBounds();

	switchPostion = sf::Vector2f(375.0f, 125.0f);
	direction = 2;

}


DirectionSwitch::DirectionSwitch(int health_checker)
	:health(health_checker)
{
	
}


DirectionSwitch::DirectionSwitch(sf::Vector2f postion, int spawnDirection, int new_health)
	: switchPostion(postion), direction(spawnDirection), health(new_health)
{
	switcher.setSize(sf::Vector2f(25.0f, 25.0f));
	switcher.setPosition(postion);
	switcher.setFillColor(sf::Color::Red);
	switcherBounds = switcher.getGlobalBounds();

}



void DirectionSwitch::setupSpawnPostion()
{
	switch (direction)
	{
	case 1:
		northSetup();
	case 3:
		southSetup();

	default:
		break;
	}
}



void DirectionSwitch::northSetup()
{

	switcher.setPosition(switchPostion.x, switchPostion.y + switcherBounds.height);


}





void DirectionSwitch::southSetup()
{


	switcher.setPosition(switchPostion.x , switchPostion.y - switcherBounds.height);

}







void DirectionSwitch::damge()
{
	sf::Time elapsedTime = clock.restart();
	timeSinceLastUpdate += elapsedTime;
	while (timeSinceLastUpdate > TimePerFrame)
	{
		timeSinceLastUpdate -= TimePerFrame;

		health -= 1;
	}
}


void DirectionSwitch::checkDeath()
{
	if (health < 1)
		delete this;
}


void DirectionSwitch::draw(sf::RenderWindow& window)
{

	window.draw(switcher);

}


sf::RectangleShape& DirectionSwitch::getShape() 
{
	return switcher;
}

int DirectionSwitch::getHealth()
{
	return health;
}


int DirectionSwitch::getDirection()
{
	return direction;
}

bool DirectionSwitch::operator==(const DirectionSwitch& obj) const
{
	return health == obj.health;
}

void DirectionSwitch::setHealth(int new_health)
{
	health = new_health;
}