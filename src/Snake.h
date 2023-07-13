#pragma once
#include "SFML/Graphics.hpp"
#include "Head.h"
#include "SnakeBodyPart.h"
#include "DirectionSwitch.h"
#include "Apple.h"
#include <vector>
#include <array>
#include <cmath>
class Snake
{
private:

	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time TimePerFrame = sf::seconds(0.2f);


static std::vector<DirectionSwitch> switches;
std::vector<int>  inputRecorder;

std::vector<sf::RectangleShape> body;

Head head;

std::array<sf::Keyboard, 4> inputs;

int bodySize = 1;

int north = 1;
int east = 2;
int south = 3;
int west = 4;


bool check_direction_change();
void changeDirection();
void moveBody();
void drawBody();
void updateBody();
void damgeSwitches();
void clearInput();
void wallHitGameOver(Apple*);
void selfHit(Apple*);

public:
	Snake();
	void input();
	void update();
	void draw(sf::RenderWindow&);
	void checkGameOver(Apple&);
	void grow();
	Head& getHead();
	std::vector<sf::RectangleShape>& getBody();

};

