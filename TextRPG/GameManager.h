#pragma once
#include "Inventory.h"
#include "Player.h"
#include "Monster.h"
#include "Stat.h"
#include "Constants.h"

class Player;
class Inventory;

class GameManager
{
public:
	static GameManager& GetInstance() {
		static GameManager Instance;
		return Instance;
	}
	GameManager();
	~GameManager();

	Monster* CurrentMonster = nullptr;
	Inventory* ItemInventory = nullptr;
	Player* CurrentPlayer = nullptr;

	void Init();
	void PlayerDead();
	bool UseGold(int Gold);
	void Heal();

	void MonsterDead();
	void CreateMonster();

private:
	GameManager(const GameManager&) = delete;
	GameManager& operator=(const GameManager&) = delete;
	GameManager(GameManager&&) = delete;
	GameManager& operator=(GameManager&&) = delete;
	
};

