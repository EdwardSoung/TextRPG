#include "TempleMap.h"

void TempleMap::ShowMap()
{
	auto PlayerPos = MapManager::GetInstance().PlayerPosition;
	for (int i = 0; i < MapHeight; i++)
	{
		for (int j = 0; j < MapWidth; j++)
		{
			if (i == PlayerPos.Y && j == PlayerPos.X)
			{
				printf("@");
			}
			else
				GetMapString(Map[i][j]);
		}
		printf("\n");
	}

	if (GetMapBlock(PlayerPos) == static_cast<int>(MapBlock::Pray))
	{
		int Input = 0;

		while (Input < 2)
		{
			printf("기도를 하시겠습니까?(비용 10G)\n");
			printf("20% 확률로 완전 치유됩니다.\n");
			printf("선택(Yes : 1, No : 2) : ");
			std::cin >> Input;

			if (Input == 1)
			{
				if (GameManager::GetInstance().ItemInventory->UseGold(PriceData::PrayPrice))
				{
					int healRand = rand() % 10000;
					if (healRand < 2000)
					{
						GameManager::GetInstance().Heal();
						printf("치료되었습니다!\n");
					}
					else
						printf("기도를 했습니다.\n");
					
				}
				else
				{
					printf("보유 금액이 부족합니다.\n");
				}
			}
			else if (Input == 2)
				ResetPosition(MapState::Temple);
		}

	}
	else
		ShowDirectionInfo();
}

void TempleMap::ResetPosition(MapState PrevMap)
{
	for (int i = 0; i < MapHeight; i++)
	{
		for (int j = 0; j < MapWidth; j++)
		{
			if (Map[i][j] == static_cast<int>(MapBlock::Village))
			{
				MapManager::GetInstance().UpdatePosition(j - 1, i);
				return;
			}
		}
	}
}

int TempleMap::GetMapBlock(Position InPos)
{
	return Map[InPos.Y][InPos.X];
}

void TempleMap::Move(char Input)
{
	Position Next = MapManager::GetInstance().PlayerPosition;
	if (Input == 'w' || Input == 'W')
	{
		Next.Y--;
	}
	else if (Input == 's' || Input == 'S')
	{
		Next.Y++;
	}
	else if (Input == 'a' || Input == 'A')
	{
		Next.X--;
	}
	else if (Input == 'd' || Input == 'D')
	{
		Next.X++;
	}

	if (CanMove(GetMapBlock(Next)))
	{
		MapManager::GetInstance().UpdatePosition(Next);
		CheckPosAndChangeMap(GetMapBlock(Next));
	}

	system("cls");
	ShowMap();
}

void TempleMap::CheckPosAndChangeMap(int InBlock)
{
	if (InBlock == 0) return;

	MapBlock BlockItem = static_cast<MapBlock>(InBlock);

	if (BlockItem == MapBlock::Village)
	{
		system("cls");
		MapManager::GetInstance().ChangeMap(MapState::Village);
	}
}
