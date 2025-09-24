#include "GameManager.h"

GameManager::GameManager()
{
	Init();
}
GameManager::~GameManager()
{
	delete CurrentPlayer;
	delete ItemInventory;
}

void GameManager::Init()
{
	CurrentPlayer = new Player(Stat(10, 10, 100));
	ItemInventory = new Inventory();
}

void GameManager::PlayerDead()
{
	//���� ��� �Ǵ� �κ��丮 ������ �� �ϳ� ����
	// �������� ������ ���žȵ�.
	
	//���� �⺻ ��ǥ�� �̵���
}

bool GameManager::UseGold(int Gold)
{
	return ItemInventory->UseGold(Gold);
}

void GameManager::Heal()
{
	CurrentPlayer->Heal();
}
