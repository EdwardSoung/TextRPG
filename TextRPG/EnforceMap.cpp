#include "EnforceMap.h"
#include "Weapon.h"
#include "Armor.h"

void EnforceMap::ShowMap()
{
	auto PlayerPos = MapManager::GetInstance().PlayerPosition;
	for (int i = 0; i < MapHeight; i++)
	{
		for (int j = 0; j < MapWidth; j++)
		{
			if (i == PlayerPos.Y && j == PlayerPos.X)
				printf("@");
			else
				GetMapString(Map[i][j]);
		}
		printf("\n");
	}
	if (GetMapBlock(PlayerPos) == static_cast<int>(MapBlock::WeaponEnforce))
	{
		Player* CurPlayer = GameManager::GetInstance().CurrentPlayer;
		Weapon* WeaponItem = CurPlayer->GetWeapon();

		if (CurPlayer->WeaponExists() == false)
		{
			printf("착용한 무기가 없습니다.\n");
			ShowDirectionInfo();
			return;
		}
		else
		{
			printf("-------------------------\n");
			WeaponItem->PrintItemString();
			printf("\n");
			printf("공격력 : %d\n", WeaponItem->GetStatValue(StatType::Attack));
			printf("방어력 : %d\n", WeaponItem->GetStatValue(StatType::Defence));
			printf("체력   : %d\n", WeaponItem->GetStatValue(StatType::Health));
			printf("-------------------------\n");
			//무기 정보 출력
		}
		int Input = 0;

		while (Input < 2)
		{
			//장착 무기 등급 가져와서 비용...
			printf("착용한 무기 강화를 하시겠습니까?\n");
			printf("%s 비용 : %dG, 성공 확률 %d%%\n", WeaponItem->GetGradeString().c_str(), WeaponItem->GetEnforcePrice(), 10);
			printf("선택(Yes : 1, No : 2) : ");
			std::cin >> Input;

			if (Input == 1)
			{
				if (GameManager::GetInstance().ItemInventory->UseGold(WeaponItem->GetEnforcePrice()))
				{
					int enforceRandom = rand() % 10000;
					if (enforceRandom < WeaponItem->GetEnforceRate())
					{
						WeaponItem->RandomEnforce();
						printf("장비 강화 성공!!!\n");
						printf("-------------------------\n");
						WeaponItem->PrintItemString();
						printf("\n");
						printf("공격력 : %d\n", WeaponItem->GetStatValue(StatType::Attack));
						printf("방어력 : %d\n", WeaponItem->GetStatValue(StatType::Defence));
						printf("체력   : %d\n", WeaponItem->GetStatValue(StatType::Health));
						printf("-------------------------\n");
					}
					else
					{
						printf("\n");
						printf("장비 강화에 실패했습니다.\n");
					}
				}
				else
				{
					printf("강화 비용이 부족합니다.\n");
				}
			}
			else if (Input == 2)
				ResetPosition(MapState::Enforce);
		}

	}
	else if (GetMapBlock(PlayerPos) == static_cast<int>(MapBlock::ArmorEnforce))
	{
		Player* CurPlayer = GameManager::GetInstance().CurrentPlayer;
		Armor* ArmorItem = CurPlayer->GetArmor();

		if (CurPlayer->ArmorExists() == false)
		{
			printf("착용한 갑옷이 없습니다.\n");
			ShowDirectionInfo();
			return;
		}
		else
		{
			printf("-------------------------\n");
			ArmorItem->PrintItemString();
			printf("\n");
			printf("공격력 : %d\n", ArmorItem->GetStatValue(StatType::Attack));
			printf("방어력 : %d\n", ArmorItem->GetStatValue(StatType::Defence));
			printf("체력   : %d\n", ArmorItem->GetStatValue(StatType::Health));
			printf("-------------------------\n");
			//무기 정보 출력
		}
		int Input = 0;

		while (Input < 2)
		{
			printf("착용한 무기 강화를 하시겠습니까?\n");
			printf("%s 비용 : %dG, 성공 확률 %d%%\n", ArmorItem->GetGradeString().c_str(), ArmorItem->GetEnforcePrice(), ArmorItem->GetEnforceRate() / 100);
			printf("선택(Yes : 1, No : 2) : ");
			std::cin >> Input;

			if (Input == 1)
			{
				//Enforce 스크립트에서 진행?
				//비용 어디 저장해둬야하나..
				if (GameManager::GetInstance().ItemInventory->UseGold(ArmorItem->GetEnforcePrice()))
				{
					int enforceRandom = rand() % 10000;
					if (enforceRandom < ArmorItem->GetEnforceRate())
					{
						ArmorItem->RandomEnforce();
						printf("장비 강화 성공!!!\n");
						printf("-------------------------\n");
						ArmorItem->PrintItemString();
						printf("\n");
						printf("공격력 : %d\n", ArmorItem->GetStatValue(StatType::Attack));
						printf("방어력 : %d\n", ArmorItem->GetStatValue(StatType::Defence));
						printf("체력   : %d\n", ArmorItem->GetStatValue(StatType::Health));
						printf("-------------------------\n");
					}
					else
					{
						printf("\n");
						printf("장비 강화에 실패했습니다.\n");
					}
				}
				else
				{
					printf("강화 비용이 부족합니다.\n");
				}
			}
			else if (Input == 2)
				ResetPosition(MapState::Enforce);
		}


	}
	else
		ShowDirectionInfo();
}

void EnforceMap::ResetPosition(MapState PrevMap)
{
	for (int i = 0; i < MapHeight; i++)
	{
		for (int j = 0; j < MapWidth; j++)
		{
			if (Map[i][j] == static_cast<int>(MapBlock::Village))
			{
				MapManager::GetInstance().UpdatePosition(j + 1, i);
				return;
			}
		}
	}
}

int EnforceMap::GetMapBlock(Position InPos)
{
	return Map[InPos.Y][InPos.X];
}

void EnforceMap::Move(char Input)
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

void EnforceMap::CheckPosAndChangeMap(int InBlock)
{
	if (InBlock == 0) return;

	MapBlock BlockItem = static_cast<MapBlock>(InBlock);

	if (BlockItem == MapBlock::Village)
	{
		system("cls");
		MapManager::GetInstance().ChangeMap(MapState::Village);
	}
}
