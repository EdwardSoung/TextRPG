#include "GameManager.h"

GameManager::GameManager()
{
	Init();
}
GameManager::~GameManager()
{
	delete CurrentPlayer;
	delete ItemInventory;
	delete CurrentMonster;
}

void GameManager::Init()
{
	CurrentPlayer = new Player("�÷��̾�", Stat(50, 20, 300));
	ItemInventory = new Inventory();
}

void GameManager::PlayerDead()
{
	printf("\n");
	printf("�÷��̾ ����߽��ϴ�\n");
	printf("�������� �й��Ͽ� �������� �������� ������ϴ�.\n\n");

	std::cin.clear();
	while (_kbhit()) {  // Ű�� ���� �ִٸ�
		(void)_getch();       // �ϳ��� �о ����
	}
	printf("��� �Ϸ��� �ƹ�Ű�� ��������\n");
	(void)_getch();

	// �κ��丮 ������ �� �ϳ� ����
	// �������� ������ ���žȵ�.
	system("cls");

	ItemInventory->RemoveRandom();	
	
	MapManager::GetInstance().ResetMap();
	MapManager::GetInstance().ChangeMap(MapState::Village);

	CurrentPlayer->Heal();
}

void GameManager::MonsterDead()
{
	//�������� ���� ���
	printf("\n");
	printf("�������� �¸��߽��ϴ�.\n");

	delete CurrentMonster;
	CurrentMonster = nullptr;
}

void GameManager::BattleStart(int FieldLevel)
{
	CreateMonster(FieldLevel);

	printf("�߻��� ���� [%s]�� �����ƴ�.\n", CurrentMonster->GetName().c_str());
	printf("������ �����մϴ�.\n\n");
	//�� �� ��������� �ݺ�
	while (!CurrentPlayer->IsDead && (CurrentMonster != nullptr && !CurrentMonster->IsDead))
	{
		//�÷��̾� ��
		printf("[%s ����]\n", CurrentPlayer->GetName().c_str());
		CurrentPlayer->Attack(CurrentMonster);

		Sleep(500);

		//���� ��
		printf("\n");
		if (CurrentMonster != nullptr)
		{
			printf("[%s ����]\n", CurrentMonster->GetName().c_str());
			CurrentMonster->Attack(CurrentPlayer);
		}
		Sleep(500);
		printf("\n");
	}

	std::cin.clear();
	while (_kbhit()) {  // Ű�� ���� �ִٸ�
		(void)_getch();       // �ϳ��� �о ����
	}
	printf("��� �Ϸ��� �ƹ�Ű�� ��������\n");	
	(void)_getch();

}	

void GameManager::CreateMonster(int FieldLevel)
{
	//��޿� ���� ���� �������� ���� ����
	CurrentMonster = new Monster(GetMonsterName(FieldLevel), GetMonsterStat(FieldLevel));	
}

Stat GameManager::GetMonsterStat(int FieldLevel)
{
	//�⺻ ���� +- 20% ����
	int BaseAttack = (RangeData::MonsterAttackBase * FieldLevel) * (1 + (rand() % 40 - 20) * 0.01f);
	int BaseDefence = (RangeData::MonsterDefenceBase * FieldLevel)* (1 + (rand() % 40 - 20) * 0.01f);
	int BaseHealth = (RangeData::MonsterHealthBase * FieldLevel)* (1 + (rand() % 40 - 20) * 0.01f);
	return Stat(BaseAttack, BaseDefence, BaseHealth);
}

std::string GameManager::GetMonsterGradeString(GradeType InGrade)
{
	switch (InGrade)
	{
	case GradeType::Common:
		return "";
	case GradeType::Uncommon:
		return " Soldier";
	case GradeType::Rare:
		return " Commander";
	case GradeType::Unique:
		return " Warlord";
	case GradeType::Legend:
		return " King";
	}
	return "";
}

std::string GameManager::GetMonsterName(int FieldLevel)
{
	int NameRandom = rand() % MonsterNames.size();
	
	return MonsterNames[NameRandom] + GetMonsterGradeString(static_cast<GradeType>(FieldLevel));
}

bool GameManager::UseGold(int Gold)
{
	return ItemInventory->UseGold(Gold);
}

void GameManager::Heal()
{
	CurrentPlayer->Heal();
}
