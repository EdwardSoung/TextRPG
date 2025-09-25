#pragma once
#include "Actor.h"
#include "Item.h"
#include "GameManager.h"
#include "Weapon.h"
#include "Armor.h"

class Player : public Actor
{
public:
	Player() = default;
	Player(Stat InBaseStat) : Actor(InBaseStat)
	{
		Health = BaseStat.GetStat(StatType::Health);
	}
	virtual ~Player();
	virtual void OnHit(int Damage) override;

	void Equip(Item InItem);
	bool UnEquipWeapon();
	bool UnEquipArmor();
	void Heal();

	inline bool WeaponExists() { return EquipWeapon != nullptr; }
	inline bool ArmorExists() { return EquipArmor != nullptr; }
	inline Weapon* GetWeapon() { return EquipWeapon; }
	inline Armor* GetArmor() { return EquipArmor; }
	
private:
	Weapon* EquipWeapon = nullptr;
	Armor* EquipArmor = nullptr;
};

