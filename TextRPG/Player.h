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

	inline bool WeaponExists() { return EquipWeapon.GetType() != ItemType::None; }
	inline bool ArmorExists() { return EquipArmor.GetType() != ItemType::None; }
	inline Item GetWeapon() { return EquipWeapon; }
	inline Item GetArmor() { return EquipArmor; }
	
private:
	Item EquipWeapon;
	Item EquipArmor;
};

