#pragma once
#include <cstdio>
#include <iostream>

class PlayerInfo
{
public:
	PlayerInfo() = default;

	void ShowInfo();

private:
	void PrintInfo();
	void PrintPlayerInfo();
	void PrintWeaponInfo();
	void PrintArmorInfo();
};

