#pragma once
#include "Inventory.h"
class GameManager
{
public:
	static GameManager& GetInstance() {
		// staitc ������ ���������μ�, instance ������ �ѹ��� �ʱ�ȭ�ǰ�, ���α׷� ���� ���� ���ӵ�.
		// Ư�� C++11���� thread-safe ���� �ʱ�ȭ�� �����.
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

