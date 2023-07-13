#include "Collison.h"


bool Collison::checkCollison(sf::RectangleShape* head,Apple* apple)
{

    
    bool collision = head->getPosition() == apple->getShape().getPosition();

        if (collision)
            return true;
        else
            return false;


}


bool Collison::checkCollison(Snake* snake, Apple* apple)
{
    bool collision = false;

    for (int i = 0; i < snake->getBody().size(); i++)
      collision = snake->getBody()[i].getPosition() == apple->getShape().getPosition();


    return collision;


}

bool Collison::checkCollison(sf::RectangleShape* head, sf::RectangleShape* wall)
{
    bool collisionX = head->getPosition().x + head->getSize().x >= wall->getPosition().x &&
        wall->getPosition().x + wall->getSize().x >= head->getPosition().x;

    bool collisionY = head->getPosition().y + head->getSize().y >= wall->getPosition().y &&
        wall->getPosition().y + wall->getSize().y >= head->getPosition().y;

    return collisionX && collisionY;
}



void Collison::doCollision(Snake& snake, sf::RectangleShape& wall)
{
    if (checkCollison(&snake.getHead().getShape(), &wall))
        std::cout << "Sike" << std::endl;
}

void Collison::doCollison(Snake& snake,Apple& apple)
{
    

    if (checkCollison(&snake.getHead().getShape(), &apple))
    {
        apple.setSpawnState(false);
        snake.grow();

    }

}


void Collison::doCollisionSpawn(Snake& snake, Apple& apple)
{
    if(checkCollison(&snake,&apple))
          apple.spawn();

}