#pragma once
#include "Inventory.h"
#include "Player.h"
#include "Stat.h"

class Player;
class Inventory;

class GameManager
{
public:
	static GameManager& GetInstance() {
		static GameManager Instance;
		return Instance;
	}

	Inventory* ItemInventory = nullptr;
	Player* CurrentPlayer = nullptr;

	void Init();
	void PlayerDead();
	bool UseGold(int Gold);
	void Heal();

	GameManager();

private:
	GameManager(const GameManager&) = delete;
	GameManager& operator=(const GameManager&) = delete;
	GameManager(GameManager&&) = delete;
	GameManager& operator=(GameManager&&) = delete;

	~GameManager();
};

