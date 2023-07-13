#include <iostream>
#include <random>
int main()
{


    int playerInput, cpuInput;

    std::cout << "Enter Your Input: " << std::endl;

    std::cout << " 1.paper \n 2.rock \n 3.scissore" << std::endl;

    std::string inputStack[3] = { "Paper","Rock","Scissore" };

    std::string grid[3][3] = { {"Tie","Computer Won","Player Won"}, {"Player Won","Tie","Computer"},{"Computer Won","Player Won","Tie"} };


    do
    {

        std::cin >> playerInput;


    } while (playerInput > 3 || playerInput < 1);


    cpuInput = rand() % 3;


    std::cout << "Computer Choice vs  Player Choice" << std::endl;
    std::cout << " " << inputStack[cpuInput] << " " << inputStack[playerInput - 1] << std::endl;


    std::cout << grid[cpuInput][playerInput - 1] << std::endl;



}