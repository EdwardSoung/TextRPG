#pragma once
#include "Inventory.h"
static class GameManager
{
public:
	static Inventory _Inventory;

	static void PlayerDead();
	static void ChaneMap(MapState State);

	static MapState CurrentMap;
};

