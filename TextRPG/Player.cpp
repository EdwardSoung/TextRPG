#include "Player.h"

Player::~Player()
{
	delete EquipWeapon;
	delete EquipArmor;
}

void Player::OnHit(int Damage)
{
	Health -= Damage;
	printf("[%s] : 데미지 %d를 입었습니다.\n", Name.c_str(), Damage);
	if (Health <= 0)
	{
		Health = 0;
		IsDead = true;
		GameManager::GetInstance().PlayerDead();
	}
	else
		printf("[%s] 남은 체력 : %d\n", Name.c_str(), Health);
}
void Player::Heal()
{
	Health = GetTotalStat(StatType::Health);
}

void Player::Equip(Item InItem)
{
	if (InItem.GetType() == ItemType::Weapon && EquipWeapon != nullptr)
	{
		GameManager::GetInstance().ItemInventory->AddItem(EquipWeapon);
		EquipStat.SubStat(EquipWeapon->GetStat());

		delete EquipWeapon;
		EquipWeapon = nullptr;
	}
	else if (InItem.GetType() == ItemType::Armor && EquipArmor != nullptr)
	{
		GameManager::GetInstance().ItemInventory->AddItem(EquipArmor);
		EquipStat.SubStat(EquipArmor->GetStat());

		delete EquipArmor;
		EquipArmor = nullptr;
	}
	//스탯값 안변하게 주소를 저장
	if (InItem.GetType() == ItemType::Weapon)
	{
		EquipWeapon = static_cast<Weapon*>(&InItem);
		EquipStat.AddStat(EquipWeapon->GetStat());
	}
	else if (InItem.GetType() == ItemType::Armor)
	{
		EquipArmor = static_cast<Armor*>(&InItem);
		EquipStat.AddStat(EquipArmor->GetStat());
	}
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
