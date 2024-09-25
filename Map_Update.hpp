#include<iostream>


bool Map_Memories(int row, int col, std::array<int, 5>memory)
{
	for (int i = 0; i < 5; ++i)
	{
		int local_memory = memory[i];
		if (local_memory / 10 == row && local_memory % 10 == col) {
			return true;
		}
	}
	return false;
}

int Update(int row, int col, std::array<int, 2>coordinates, std::array<int, 2> choice, std::array<int, 5> memories)
{
	bool memory_check = false;
	if (row == coordinates[0] && coordinates[0]==choice[0] && col == coordinates[1] && choice[1] == coordinates[1])
	{
		return 2;
	}

	else if(row == choice[0] && col == choice[1])
	{
		return 1;
	}
	memory_check = Map_Memories(row, col, memories);
	if (memory_check==true)
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