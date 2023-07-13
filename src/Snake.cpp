#include "Snake.h"

std::vector<DirectionSwitch> Snake::switches;
Snake::Snake()
{
	inputRecorder.emplace_back(head.getDirection());

}

void Snake::input()
{

	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && head.getDirection() != south)
			inputRecorder.emplace_back(north);
		




	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && head.getDirection() != west)
		inputRecorder.emplace_back(east);



	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && head.getDirection() != north)
			inputRecorder.emplace_back(south);
	


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && head.getDirection() != east)
		inputRecorder.emplace_back(west);
		

	
 

}


void Snake::update()
{


	sf::Time elapsedTime = clock.restart();
	timeSinceLastUpdate += elapsedTime;
	while (timeSinceLastUpdate > TimePerFrame)
	{
		head.setDirection(inputRecorder[inputRecorder.size()- 1]);
		timeSinceLastUpdate -= TimePerFrame;

		head.move();
		updateBody();
		check_direction_change();
		//clearInput();

	}

	
}

void Snake::clearInput()
{
	if (inputRecorder.size() > 0)
	{
		inputRecorder.clear();
		inputRecorder.emplace_back(head.getDirection());
	}
}

void Snake::updateBody()
{

	sf::RectangleShape part(sf::Vector2f(25.0f, 25.0f));
	part.setPosition(head.getShape().getPosition());
	body.emplace_back(part);


}

void Snake::draw(sf::RenderWindow& window)
{
	head.draw(&window);
	std::cout << inputRecorder.size() << std::endl;
	for (int i = 0; i < body.size(); i++)
		window.draw(body[i]);

}


void Snake::wallHitGameOver(Apple* apple)
{
	if (head.getShape().getPosition().x > 775 || head.getShape().getPosition().x < 0)
	{
		std::cout << "Game Over" << std::endl;

		bodySize = 1;
		head.getShape().setPosition(sf::Vector2f(375.0f, 125.0f));
		body.clear();
		apple->setSpawnState(false);

	}else if (head.getShape().getPosition().y > 575 || head.getShape().getPosition().y < 25)
	{

		std::cout << "Game Over" << std::endl;
		bodySize = 1;
		head.getShape().setPosition(sf::Vector2f(375.0f, 125.0f));
		body.clear();
		apple->setSpawnState(false);
	}

}

void Snake::selfHit(Apple* apple)
{
	for (int i = 0; i < body.size(); i++)
	{
		for (int j = 0; j < body.size(); j++)
		{
			if (body[i].getPosition() == body[j].getPosition() && i != j)
			{
				std::cout << "Game Over" << std::endl;
				bodySize = 1;
				head.getShape().setPosition(sf::Vector2f(375.0f, 125.0f));
				body.clear();
				apple->setSpawnState(false);
			}

		}


	}
		
} 

void Snake::checkGameOver(Apple& apple)
{
	selfHit(&apple);
	wallHitGameOver(&apple);
}


void Snake::grow()
{

	bodySize++;
}



bool Snake::check_direction_change()
{
	
 
	if (body.size() > bodySize)
		body.erase(body.begin());

	return false;
}



std::vector<sf::RectangleShape>& Snake::getBody()
{
	return body;
}


Head& Snake::getHead()
{
	return head;
}