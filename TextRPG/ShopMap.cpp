#include "ShopMap.h"

void ShopMap::ShowMap()
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

	if (GetMapBlock(PlayerPos) == static_cast<int>(MapBlock::ShopSell))
	{
		auto Inventory = GameManager::GetInstance().ItemInventory;
		int InputItemIndex = 0;
		PrintInventory();
		while (InputItemIndex <= 0 || InputItemIndex > Inventory->GetSize())
		{
			printf("아이템 선택(나가기 -1) : ");
			std::cin >> InputItemIndex;

			if (InputItemIndex < 0)
			{
				ResetPosition(MapState::Shop);
				ShowMap();//재귀가..될것같은데
				return;
			}
		}

		int Input = 0;		
		while (Input < 2)
		{
			printf("[1.판매 ,2:나가기]\n");
			printf("선택 : ");
			std::cin >> Input;

			if (Input == 1)
			{
				auto Items = Inventory->GetItems();
				if (Items[InputItemIndex - 1].IsEquip())
				{
					if (Inventory->SellItem(InputItemIndex))
					{
						PrintInventory();
						printf("%d번 아이템을 판매했습니다.\n", InputItemIndex);
					}
				}
				else
				{
					if (Items[InputItemIndex - 1].GetAmount() > 1)
					{
						int SellAmount = 0;
						while (SellAmount <= 0 || SellAmount > Items[InputItemIndex - 1].GetAmount())
						{
							printf("판매 개수 입력 (나가기 -1) : ");
							std::cin >> SellAmount;

							if (SellAmount == -1)
								break;
						}

						if (SellAmount > 0)
						{
							if (Inventory->SellItem(InputItemIndex, SellAmount))
							{
								PrintInventory();
								printf("%d번 아이템을 %d개 판매했습니다.\n", InputItemIndex, SellAmount);
							}
						}
						
					}
					else
					{
						if (Inventory->SellItem(InputItemIndex))
						{
							PrintInventory();
							printf("%d번 아이템을 판매했습니다.\n", InputItemIndex);
						}
					}
				}
			}
			else if (Input == 2)
			{
				ResetPosition(MapState::Shop);
				ShowMap();
			}
		}

	}
	else
		ShowDirectionInfo();
}

void ShopMap::ResetPosition(MapState PrevMap)
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

int ShopMap::GetMapBlock(Position InPos)
{
	return Map[InPos.Y][InPos.X];
}

void ShopMap::Move(char Input)
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

void ShopMap::CheckPosAndChangeMap(int InBlock)
{
	if (InBlock == 0) return;

	MapBlock BlockItem = static_cast<MapBlock>(InBlock);

	if (BlockItem == MapBlock::Village)
	{
		system("cls");
		MapManager::GetInstance().ChangeMap(MapState::Village);
	}
}
void ShopMap::PrintInventory()
{
	auto Inventory = GameManager::GetInstance().ItemInventory;
	auto Items = Inventory->GetItems();
	system("cls");
	printf("############################################\n");
	printf("#                  Inventory               #\n");
	printf("############################################\n");

	for (int i = 1; i <= 20; i++)
	{
		printf("# %2d. ", i);
		if (i <= Inventory->GetItems().size())
			Items[i - 1].PrintItemStringWithPrice();
		else
			printf("[]\t");
		printf("\n");
	}

	printf("############################################\n");
	printf("# Gold : %d                                 \n", Inventory->GetGold());
	printf("############################################\n");

}