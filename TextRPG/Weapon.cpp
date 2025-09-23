#include "Weapon.h"

void Weapon::PrintItemString()
{
	Item::PrintItemString();
	printf(" x %d", Amount);
}

void Weapon::InitRandomStat()
{
	//무기
	//공격력
	//등급에 따라 1~100 / 50 ~ 150 / 100 ~ 200 / 150 ~ 250 / 200 ~ 300
	//
}
