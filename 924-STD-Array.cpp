// 924-STD-Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <array>
#include "Functions.hpp"

int main()
{
	std::array<std::string, 5>map;

	std::array<int, 2>coordinates={3,4};
	std::array<int, 2>answer={0,0};
	std::array<int, 2> save = { -1,-1 };
	bool game = true;

	while(game==true)
	{
		answer = Choice(answer);
		Map(coordinates, answer, save);
		game=Verification(coordinates, answer);
		save = Memory(answer);
		std::cout << save[0];
	}

}

//1 - Create a map
//2 - Put something in one of the coordinate
//3 - Ask for the player input
//4 - Win Condition