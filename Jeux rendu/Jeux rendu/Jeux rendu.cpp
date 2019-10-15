#include <iostream>
#include <vector>
#include <string>


bool gameWin = false;
std::vector<std::vector<char> > map(20, std::vector<char>(20));
char playerPosX = 0;
char playerPosY = 0;


void mapUpdate()
{
	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[i].size(); j++)
		{
			std::cout << "   " << map[i][j];
		}
		std::cout << "\n";
	}
}

void createMap()
{
	char randNum = (rand() % 6) + 1;
	char randNum2 = (rand() % 7) + 7;

	playerPosX = randNum;
	playerPosY = randNum2;

	char wallSymbol ='?';
	char playerSymbol = '1';
	for (int i = 0; i < 4; i++)
	{
		map[i + 2][1] = wallSymbol;
		map[i + 2][2] = wallSymbol;
		map[i + 2][3] = wallSymbol;
		map[i + 2][4] = wallSymbol;
		map[i + 2][5] = wallSymbol;
		map[i + 2][9] = wallSymbol;
		map[i + 2][10] = wallSymbol;
		map[i + 2][11] = wallSymbol;
		map[i + 2][12] = wallSymbol;
	}

	for (int i = 0; i < 6; i++)
	{
		map[i + 9][11] = wallSymbol;
		map[i + 9][12] = wallSymbol;
		map[i + 9][13] = wallSymbol;
	}

	map[playerPosY][playerPosX] = playerSymbol;

	int lastElement = map.size() - 1;

	for (int i = 0; i < map.size(); i++)
	{
		map[i][0] = wallSymbol;
		map[0][i] = wallSymbol;
		map[lastElement][i] = wallSymbol;
		map[i][lastElement] = wallSymbol;
	}
}

int main()
{
	int playerHp = 5;
	std::string command;
	std::cout << "map informations : \n";
	std::cout << " = ground\n";
	std::cout << "? = wall\n";
	std::cout << "1 = player\n";
	
	createMap();

	mapUpdate();

	std::cout << "which direction to go ?\n";
	std::cin >> command;

	while (!gameWin)
	{
		system("cls");
		std::cout << "player hp = " << playerHp << "\n";

		if (command == "right")
		{
			std::cout << "you go one case to the right\n";
			map[playerPosY][playerPosX] = 0;
			playerPosX++;
			if (map[playerPosY][playerPosX] == 4)
			{
				std::cout << "potion found, hp + 5\n";
				playerHp = playerHp + 5;
				map[playerPosY][playerPosX] = 1;
				
			}
			else if (map[playerPosY][playerPosX] == 5)
			{
				playerPosX--;
				std::cout << "not possible to go\n";
			}
			map[playerPosY][playerPosX] = 1;
			mapUpdate();
		}
		else if (command == "left")
		{
			std::cout << "you go one case to the left\n";
			map[playerPosY][playerPosX] = 0;
			playerPosX--;
			if (map[playerPosY][playerPosX] == 4)
			{
				std::cout << "potion found, hp + 5\n";
				playerHp = playerHp + 5;
				map[playerPosY][playerPosX] = 1;
			
			}
			else if (map[playerPosY][playerPosX] == 5)
			{
				playerPosX++;
				std::cout << "not possible to go\n";
			}
			map[playerPosY][playerPosX] = 1;
			mapUpdate();
		}
		else if (command == "up")
		{
			std::cout << "you go one case up\n";
			map[playerPosY][playerPosX] = 0;
			playerPosY--;
			if (map[playerPosY][playerPosX] == 4)
			{
				std::cout << "potion found, hp + 5\n";
				playerHp = playerHp + 5;
				map[playerPosY][playerPosX] = 1;
				
			}
			else if (map[playerPosY][playerPosX] == 5)
			{
				playerPosY++;
				std::cout << "not possible to go\n";
			}
			map[playerPosY][playerPosX] = 1;
			mapUpdate();
		}
		else if (command == "down")
		{
			std::cout << "you go one case down\n";
			map[playerPosY][playerPosX] = 0;
			playerPosY++;
			if (map[playerPosY][playerPosX] == 4)
			{
				std::cout << "potion found, hp + 5\n";
				playerHp = playerHp + 5;
				map[playerPosY][playerPosX] = 1;
				
			}
			else if (map[playerPosY][playerPosX] == 5)
			{
				playerPosY--;
				std::cout << "not possible to go\n";
			}
			map[playerPosY][playerPosX] = 1;
			mapUpdate();
		}
		else
		{
			std::cout << "please give a funtional direction (right / left / up / down)\n";
			mapUpdate();
		}

		std::cout << "which direction to go ?\n";

		std::cin >> command;
	}

	std::cout << "congratulations you found all the potions\n";

	system("pause");
	return EXIT_SUCCESS;
}
