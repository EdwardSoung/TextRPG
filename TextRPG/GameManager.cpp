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
	CurrentPlayer = new Player("플레이어", Stat(50, 20, 300));
	ItemInventory = new Inventory();
}

void GameManager::PlayerDead()
{
	printf("\n");
	printf("플레이어가 사망했습니다\n");
	printf("전투에서 패배하여 랜덤으로 아이템이 사라집니다.\n\n");

	std::cin.clear();
	while (_kbhit()) {  // 키가 남아 있다면
		(void)_getch();       // 하나씩 읽어서 버림
	}
	printf("계속 하려면 아무키나 누르세요\n");
	(void)_getch();

	// 인벤토리 아이템 중 하나 제거
	// 아이템이 없으면 제거안됨.
	system("cls");

	ItemInventory->RemoveRandom();	
	
	MapManager::GetInstance().ResetMap();
	MapManager::GetInstance().ChangeMap(MapState::Village);

	CurrentPlayer->Heal();
}

void GameManager::MonsterDead()
{
	//전투중인 몬스터 사망
	printf("\n");
	printf("전투에서 승리했습니다.\n");

	delete CurrentMonster;
	CurrentMonster = nullptr;
}

void GameManager::BattleStart(int FieldLevel)
{
	CreateMonster(FieldLevel);

	printf("야생의 몬스터 [%s]를 마주쳤다.\n", CurrentMonster->GetName().c_str());
	printf("전투를 시작합니다.\n\n");
	//둘 다 살아있으면 반복
	while (!CurrentPlayer->IsDead && (CurrentMonster != nullptr && !CurrentMonster->IsDead))
	{
		//플레이어 턴
		printf("[%s 공격]\n", CurrentPlayer->GetName().c_str());
		CurrentPlayer->Attack(CurrentMonster);

		Sleep(500);

		//몬스터 턴
		printf("\n");
		if (CurrentMonster != nullptr)
		{
			printf("[%s 공격]\n", CurrentMonster->GetName().c_str());
			CurrentMonster->Attack(CurrentPlayer);
		}
		Sleep(500);
		printf("\n");
	}

	std::cin.clear();
	while (_kbhit()) {  // 키가 남아 있다면
		(void)_getch();       // 하나씩 읽어서 버림
	}
	printf("계속 하려면 아무키나 누르세요\n");	
	(void)_getch();

}	

void GameManager::CreateMonster(int FieldLevel)
{
	//등급에 따른 랜덤 스탯으로 몬스터 생성
	CurrentMonster = new Monster(GetMonsterName(FieldLevel), GetMonsterStat(FieldLevel));	
}

Stat GameManager::GetMonsterStat(int FieldLevel)
{
	//기본 스탯 +- 20% 랜덤
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
