#pragma once
#include "Actor.h"
#include "Item.h"
#include "GameManager.h"

class Player : public Actor
{
public:
	Player() = default;
	Player(Stat InBaseStat) : Actor(InBaseStat)
	{
		Health = BaseStat.GetStat(StatType::Health);
	}
	virtual void OnHit(int Damage);
	
private:

	Item EquipWeapon;
	Item EquipArmor;
};

