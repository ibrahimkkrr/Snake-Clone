#pragma once
#include "SFML/Graphics.hpp"
#include "Head.h"
#include "Snake.h"
#include "Apple.h"
#include "Collison.h"
#include <iostream>
#include <vector>
class Game
{
private:

	sf::RectangleShape upWall;
	sf::RectangleShape rightWall;
	sf::RectangleShape downWall;
	sf::RectangleShape leftWall;




	static const float VIEW_WEDITH;
	static const float VIEW_HIEGHT;


	int frameCount = 0;


	Head head;
	Collison collison;
	Snake snake;
	Apple apple;

	static sf::RenderWindow window;
	static sf::View view;



	sf::Event evnt;
	sf::Clock clock;
	sf::Clock clock2;



	float time = 0.0f;
	float delay = 0.25f;

	void input();
	void update();
	void render();
	void eventRecorder();
	void resize();



public:
	Game();
	void startGame();

};

