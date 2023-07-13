#pragma once
#include "SFML/Graphics.hpp"
#include <vector>
class DirectionSwitch
{
private:

	int health = 4;  

	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time TimePerFrame = sf::seconds(0.2f);

	sf::RectangleShape switcher;

	sf::FloatRect switcherBounds;

	sf::Vector2f switchPostion;
	
	int direction;
	
	void setupSpawnPostion();
	void northSetup();
	void southSetup();




	void checkDeath();





public:

	DirectionSwitch();

	DirectionSwitch(int);

	DirectionSwitch(sf::Vector2f, int,int);
	

	bool operator==(const DirectionSwitch& obj) const;



	void draw(sf::RenderWindow&);
	void damge();

	void setHealth(int);
	
	sf::RectangleShape& getShape();
	int getHealth();
	int getDirection();

};

