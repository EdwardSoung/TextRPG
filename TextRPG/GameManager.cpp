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
	//���� ��� �Ǵ� �κ��丮 ������ �� �ϳ� ����
	// �������� ������ ���žȵ�.
	
	//���� �⺻ ��ǥ�� �̵���
}

void GameManager::MonsterDead()
{
	//�������� ���� ���

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
