#include<iostream>

int Update(int row, int col, std::array<int, 2>coordinates, std::array<int, 2> choice, std::array<int, 2> memories)
{
	if (row == coordinates[0] && coordinates[0]==choice[0] && col == coordinates[1] && choice[1] == coordinates[1])
	{
		return 2;
	}

	else if(row == choice[0] && col == choice[1])
	{
		return 1;
	}

	else if(memories[0] == row && memories[1] == col)
	{
		return 1;
	}

	return 0;
}

void Print(int answer)
{
	if (answer == 1)
	{
		std::cout << "1 ";
	}
	else if (answer==2)
	{
		std::cout << "2 ";
	}
	else {
		std::cout << "0 ";
	}
}