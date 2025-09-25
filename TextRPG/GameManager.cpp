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
	CurrentPlayer = new Player(Stat(50, 20, 300));
	ItemInventory = new Inventory();
}

void GameManager::PlayerDead()
{
	//장착 장비 또는 인벤토리 아이템 중 하나 제거
	// 아이템이 없으면 제거안됨.
	
	//마을 기본 좌표로 이동함
}

void GameManager::MonsterDead()
{
	//전투중인 몬스터 사망

	delete CurrentMonster;
	CurrentMonster = nullptr;
}

void GameManager::CreateMonster()
{

}

bool GameManager::UseGold(int Gold)
{
	return ItemInventory->UseGold(Gold);
}

void GameManager::Heal()
{
	CurrentPlayer->Heal();
}
