#include "Player.h"

Player::Player()
{
	EquipWeapon.Reset();
	EquipArmor.Reset();
}

void Player::OnHit(int Damage)
{
	Health -= Damage;
	if (Health <= 0)
	{
		IsDead = true;
		GameManager::GetInstance().PlayerDead();
	}
}

void Player::Heal()
{
	Health = BaseStat.GetStat(StatType::Health);
}

void Player::Equip(Item Item)
{
	if (Item.GetType() == ItemType::Weapon && EquipWeapon.GetType() != ItemType::None)
	{
		GameManager::GetInstance().ItemInventory->AddItem(EquipWeapon);
		EquipWeapon.Reset();
	}
	else if (Item.GetType() == ItemType::Armor && EquipArmor.GetType() != ItemType::None)
	{
		GameManager::GetInstance().ItemInventory->AddItem(EquipArmor);
		EquipArmor.Reset();
	}

	if (Item.GetType() == ItemType::Weapon)
		EquipWeapon = Item;
	else if (Item.GetType() == ItemType::Armor)
		EquipArmor = Item;
}

bool Player::UnEquipWeapon()
{
	if (GameManager::GetInstance().ItemInventory->IsFull())
		return false;

	GameManager::GetInstance().ItemInventory->AddItem(EquipWeapon);

	return true;
}

bool Player::UnEquipArmor()
{
	if (GameManager::GetInstance().ItemInventory->IsFull())
		return false;

	return true;
}
