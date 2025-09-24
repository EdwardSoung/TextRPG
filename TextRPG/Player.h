#pragma once
#include "Actor.h"
#include "Item.h"
#include "GameManager.h"

class Player : public Actor
{
public:
	Player();
	Player(Stat InBaseStat) : Actor(InBaseStat)
	{
		Health = BaseStat.GetStat(StatType::Health);
	}
	virtual void OnHit(int Damage) override;

	void Equip(Item Item);
	bool UnEquipWeapon();
	bool UnEquipArmor();
	void Heal();
	
private:
	Item EquipWeapon;
	Item EquipArmor;
};

