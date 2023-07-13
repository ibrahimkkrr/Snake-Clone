#pragma once
#include "SFML/Graphics.hpp"
class SnakeBodyPart
{
private:

	int direction;

	sf::RectangleShape bodyPartShape;
	sf::Vector2f bodyPartPostion;

	sf::FloatRect bodyPartBounds;

	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time TimePerFrame = sf::seconds(0.2f);


	void northSetup();
	void eastSetup();
	void southSetup();
	void westSetup();

	void moveNorth();
	void moveEast();
	void moveSouth();
	void moveWest();


public:
	SnakeBodyPart(sf::Vector2f,int);

	void input();
	void move();
	void draw(sf::RenderWindow*);
	void setupSpawnPostion();

	sf::RectangleShape& getShape();

	int getDirection() const;
	void setPostion(sf::Vector2f);
	void setDirection(int);
	

};

