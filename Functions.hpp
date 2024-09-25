#include <iostream>
#include <complex>
#include "Map_Update.hpp"

void Map(std::array<int, 2> coordinates, std::array<int, 2> choice, std::array<int, 5> memories) {

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
	bool choice1 = true;
	do {
		std::cout << "Insert choice for Y coordinate : \n";
		std::cin >> player_choice[0];
		if (player_choice[0] > 4 || player_choice[0]<0)
		{
			std::cout<<"The coordinate does not fit on the map, please try again.\n\n";
			continue;
		}
		break;
	} while (choice1==true);

	do {
		std::cout << "Insert choice for X coordinate : \n";
		std::cin >> player_choice[1];
		if (player_choice[1] > 4 || player_choice[1] < 0)
		{
			std::cout << "The coordinate does not fit on the map, please try again.\n\n";
			continue;
		}
		break;
	} while (choice1 = true);

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

std::array<int, 5> Memory(std::array<int, 2> choice, std::array<int, 5>memory, int attempts) {

	memory[attempts] = choice[0] * 10 + choice[1];
	return memory;
}

void Game(std::array<int, 2> answer, std::array<int, 2> coordinates, std::array<int, 5> save, int attempts) {
	bool game = true;
	while (attempts!=5)
	{
		std::cout << "Number of attempts left : " << 5-attempts << "\n";
		answer = Choice(answer);
		Map(coordinates, answer, save);
		game = Verification(coordinates, answer);
		if (game == false){
			break; }
		save=Memory(answer, save, attempts);
		attempts = ++attempts;
	}
	if(game==true)
	{
		std::cout << "Game over !\nThe correct coordinates were : X - " << coordinates[1]<< " | Y - " << coordinates[0];
	}
}

void Menu() {
	int menu = 0;
	std::cout << "!!! Welcome to treasure hunt !!!\nWhat do you want to do ?\n1 - Play | 2 - Rules\n";
	std::cin >> menu;
	if (menu == 2)
	{
		std::cout << "To play, you will need to find the hidden treasure by inserting the correct coordinates in a maximum of 5 attempts.\n";
		std::cout << "Each turn, you will be asked to enter a X coordinate and a Y coordinate.\n";
		std::cout << "There's how the coordinates are represented on the map\n";
		std::cout << "---Map--- \n";
		std::cout << "# 0 1 2 3 4 - X\n";
		for (int row = 0; row < 5; ++row)
		{
			std::cout << row;
			std::cout << " 0 ";
			int test = 0;
			for (int col = 0; col < 4; ++col)
			{
				std::cout << "0 ";
			}
			std::cout << "\n";
		}
		std::cout << "|\n";
		std::cout << "Y\n";
		std::cout << "\n- - - - -\n";
		std::cout << "If the spot is undug, it will be a 0.\nIf the spot is dug but wrong, it will be a 1.\nIf the spot is dug and correct, it will be a 2.\n\n";
		std::cout << "##########################\n\n";
	}
}