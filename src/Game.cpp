#include "Game.h"
sf::RenderWindow Game::window(sf::VideoMode(800, 600), "Snake", sf::Style::Default);
sf::View Game::view(sf::FloatRect(0, 0, 800, 600));

const float Game::VIEW_WEDITH = 800;
const float Game::VIEW_HIEGHT = 600;



Game::Game()
{
	window.setFramerateLimit(60);

	rightWall.setSize(sf::Vector2f(25, 600));
	rightWall.setPosition(sf::Vector2f(775,0));

	upWall.setSize(sf::Vector2f(800, 25));
	upWall.setPosition(sf::Vector2f(0, 0));


	downWall.setSize(sf::Vector2f(800, 25));
	downWall.setPosition(sf::Vector2f(0, 575));

	leftWall.setSize(sf::Vector2f(25, 600));
	leftWall.setPosition(sf::Vector2f(0, 0));

}

void Game::startGame()
{
	while (window.isOpen())
	{
		window.setView(view);
		eventRecorder();
		input();
		update();
		render();
	}
}

void Game::eventRecorder()
{
	while (window.pollEvent(evnt))
	{
		switch (evnt.type)
		{
		case sf::Event::Closed:
			window.close();
		case sf::Event::Resized:
			resize();
		default:
			break;
		}

	}
}

void Game::resize()
{
	float aspectRaito = float(window.getSize().x) / float(window.getSize().y);

	view.setSize(VIEW_WEDITH * aspectRaito, VIEW_HIEGHT);
}

void Game::input()
{
	snake.input();

}

void Game::update()
{

  

	collison.doCollison(snake, apple);
	collison.doCollisionSpawn(snake, apple);
	snake.update();
	snake.checkGameOver(apple);
	apple.update();



	
}

void Game::render()
{
	window.clear();
	snake.draw(window);
	apple.draw(window);
	window.draw(upWall);
	window.draw(rightWall);
	window.draw(downWall);
	window.draw(leftWall);
	window.display();
}