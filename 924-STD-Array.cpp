// 924-STD-Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <array>
#include "Functions.hpp"

int main()
{

	std::array<std::string, 5>map;

	srand(time(0));

	std::array<int, 2>answer={0,0};
	std::array<int, 5> save = { -1,-1,-1,-1,-1 };
	int attempts = 0;
	bool matches = true;
	Menu();

	do
	{
		std::array<int, 2>coordinates = { rand() % 5,rand() % 5 };
		int end_condition = 0;
		Game(answer, coordinates, save, attempts);
		std::cout << "Do you wish to play again ?\n1 - Yes | 2 - No\n";
		std::cin >> end_condition;
		std::cout << "\n\n";
		if (end_condition==2)
		{
			break;
		}
	} while (matches == true);


}

//1 - Create a map
//2 - Put something in one of the coordinate
//3 - Ask for the player input
//4 - Win Condition