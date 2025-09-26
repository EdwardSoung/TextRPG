#pragma once
#include <Windows.h>
#include <string>
#include <conio.h>
#include "Inventory.h"
#include "Player.h"
#include "Monster.h"
#include "Stat.h"
#include "Constants.h"
#include "MapManager.h"

class Player;
class Inventory;

class GameManager
{
public:
	static GameManager& GetInstance() {
		static GameManager Instance;
		return Instance;
	}
	GameManager() = default;
	~GameManager();

	Monster* CurrentMonster = nullptr;
	Inventory* ItemInventory = nullptr;
	Player* CurrentPlayer = nullptr;

	void PlayerDead();
	bool UseGold(int Gold);
	void Heal();

	void MonsterDead();
	void BattleStart(int FieldLevel);

	void PlayNewGame(std::string PlayerName);

private:
	GameManager(const GameManager&) = delete;
	GameManager& operator=(const GameManager&) = delete;
	GameManager(GameManager&&) = delete;
	GameManager& operator=(GameManager&&) = delete;
	
	void Init(std::string InPlayerName);
	void CreateMonster(int FieldLevel);
	Stat GetMonsterStat(int FieldLevel);
	std::string GetMonsterGradeString(GradeType InGrade);
	std::string GetMonsterName(int FieldLevel);
};

