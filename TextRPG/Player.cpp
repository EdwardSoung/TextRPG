#include "Player.h"

Player::~Player()
{
	delete EquipWeapon;
	delete EquipArmor;
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

void Player::Equip(Item InItem)
{
	if (InItem.GetType() == ItemType::Weapon && EquipWeapon != nullptr)
	{
		GameManager::GetInstance().ItemInventory->AddItem(EquipWeapon);
		delete EquipWeapon;
		EquipWeapon = nullptr;
	}
	else if (InItem.GetType() == ItemType::Armor && EquipArmor != nullptr)
	{
		GameManager::GetInstance().ItemInventory->AddItem(EquipArmor);
		delete EquipArmor;
		EquipArmor = nullptr;
	}
	//스탯값 안변하게 주소를 저장
	if (InItem.GetType() == ItemType::Weapon)
		EquipWeapon = static_cast<Weapon*>(&InItem);
	else if (InItem.GetType() == ItemType::Armor)
		EquipArmor = static_cast<Armor*>(&InItem);
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
