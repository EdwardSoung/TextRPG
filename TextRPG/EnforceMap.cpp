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
			printf("������ ���Ⱑ �����ϴ�.\n");
			ShowDirectionInfo();
			return;
		}
		else
		{
			printf("-------------------------\n");
			WeaponItem->PrintItemString();
			printf("\n");
			printf("���ݷ� : %d\n", WeaponItem->GetStatValue(StatType::Attack));
			printf("���� : %d\n", WeaponItem->GetStatValue(StatType::Defence));
			printf("ü��   : %d\n", WeaponItem->GetStatValue(StatType::Health));
			printf("-------------------------\n");
			//���� ���� ���
		}
		int Input = 0;

		while (Input < 2)
		{
			//���� ���� ��� �����ͼ� ���...
			printf("������ ���� ��ȭ�� �Ͻðڽ��ϱ�?\n");
			printf("%s ��� : %dG, ���� Ȯ�� %d%%\n", WeaponItem->GetGradeString().c_str(), WeaponItem->GetEnforcePrice(), 10);
			printf("����(Yes : 1, No : 2) : ");
			std::cin >> Input;

			if (Input == 1)
			{
				if (GameManager::GetInstance().ItemInventory->UseGold(WeaponItem->GetEnforcePrice()))
				{
					int enforceRandom = rand() % 10000;
					if (enforceRandom < WeaponItem->GetEnforceRate())
					{
						WeaponItem->RandomEnforce();
						printf("��� ��ȭ ����!!!\n");
						printf("-------------------------\n");
						WeaponItem->PrintItemString();
						printf("\n");
						printf("���ݷ� : %d\n", WeaponItem->GetStatValue(StatType::Attack));
						printf("���� : %d\n", WeaponItem->GetStatValue(StatType::Defence));
						printf("ü��   : %d\n", WeaponItem->GetStatValue(StatType::Health));
						printf("-------------------------\n");
					}
					else
					{
						printf("\n");
						printf("��� ��ȭ�� �����߽��ϴ�.\n");
					}
				}
				else
				{
					printf("��ȭ ����� �����մϴ�.\n");
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
			printf("������ ������ �����ϴ�.\n");
			ShowDirectionInfo();
			return;
		}
		else
		{
			printf("-------------------------\n");
			ArmorItem->PrintItemString();
			printf("\n");
			printf("���ݷ� : %d\n", ArmorItem->GetStatValue(StatType::Attack));
			printf("���� : %d\n", ArmorItem->GetStatValue(StatType::Defence));
			printf("ü��   : %d\n", ArmorItem->GetStatValue(StatType::Health));
			printf("-------------------------\n");
			//���� ���� ���
		}
		int Input = 0;

		while (Input < 2)
		{
			printf("������ ���� ��ȭ�� �Ͻðڽ��ϱ�?\n");
			printf("%s ��� : %dG, ���� Ȯ�� %d%%\n", ArmorItem->GetGradeString().c_str(), ArmorItem->GetEnforcePrice(), ArmorItem->GetEnforceRate() / 100);
			printf("����(Yes : 1, No : 2) : ");
			std::cin >> Input;

			if (Input == 1)
			{
				//Enforce ��ũ��Ʈ���� ����?
				//��� ��� �����ص־��ϳ�..
				if (GameManager::GetInstance().ItemInventory->UseGold(ArmorItem->GetEnforcePrice()))
				{
					int enforceRandom = rand() % 10000;
					if (enforceRandom < ArmorItem->GetEnforceRate())
					{
						ArmorItem->RandomEnforce();
						printf("��� ��ȭ ����!!!\n");
						printf("-------------------------\n");
						ArmorItem->PrintItemString();
						printf("\n");
						printf("���ݷ� : %d\n", ArmorItem->GetStatValue(StatType::Attack));
						printf("���� : %d\n", ArmorItem->GetStatValue(StatType::Defence));
						printf("ü��   : %d\n", ArmorItem->GetStatValue(StatType::Health));
						printf("-------------------------\n");
					}
					else
					{
						printf("\n");
						printf("��� ��ȭ�� �����߽��ϴ�.\n");
					}
				}
				else
				{
					printf("��ȭ ����� �����մϴ�.\n");
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
