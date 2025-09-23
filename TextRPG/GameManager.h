#pragma once
#include "Inventory.h"
class GameManager
{
public:
	static GameManager& GetInstance() {
		// staitc 변수로 선언함으로서, instance 뱐수는 한번만 초기화되고, 프로그램 수명 내내 지속됨.
		// 특히 C++11부터 thread-safe 변수 초기화가 보장됨.
		static GameManager instance;
		return instance;
	}

	Inventory* _Inventory;
	void PlayerDead();

private:

	GameManager(const GameManager&) = delete;
	GameManager& operator=(const GameManager&) = delete;
	GameManager(GameManager&&) = delete;
	GameManager& operator=(GameManager&&) = delete;

	GameManager()
	{
		_Inventory = new Inventory();
	}
	~GameManager();



};

