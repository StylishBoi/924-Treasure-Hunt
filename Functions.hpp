#include <iostream>
#include <complex>
#include "Map_Update.hpp"
#include "Classes.h"

void Map(std::array<int, 2> coordinates, std::array<int, 2> choice, std::array<int, 2> memories) {

	std::cout << "---Map--- \n";
	for (int row = 0; row < 5; ++row)
	{
		int test = 0;
		for (int col = 0; col < 5; ++col)
		{
			test = 0;
			test = Update(row, col, coordinates, choice, memories);
			Print(test);
		}
		std::cout << "\n";
	}
}

std::array<int, 2> Choice(std::array<int, 2>player_choice)
{
	std::cout << "Insert choice for Y coordinate : \n";
	std::cin >> player_choice[0];

	std::cout << "Insert choice for X coordinate : \n";
	std::cin >> player_choice[1];

	std::cout << "\n";

	return player_choice;
}

bool Verification(std::array<int, 2>coordinates, std::array<int, 2>choice)
{
	if (coordinates[0] == choice[0] && coordinates[1] == choice[1])
	{
		std::cout << "The treasure is here\n\n";
		return false;
	}
	else
	{
		std::cout << "The treasure is not here\n\n";
		return true;
	}
}

std::array<int, 2> Memory(std::array<int, 2> Choice)
{
	std::array<int, 2> Memories;
	for (int i = 0; i < Choice.size(); ++i)
	{
		Memories[i] = Choice[0];
	}
	return Memories;
}

void Game(bool game, std::array<int, 2> answer, std::array<int, 2> coordinates, std::array<int, 2> save, int attempts) {
	while (game == true)
	{
		std::cout << "Number of attempts left : " << attempts << "\n";
		answer = Choice(answer);
		Map(coordinates, answer, save);
		game = Verification(coordinates, answer);
		save=Memory(answer);
		attempts = --attempts;
	}
}

/*void Map_Memory(std::array<int, 2>coordinates)
{
	Memory_System first(coordinates[0], coordinates[1]);
}*/