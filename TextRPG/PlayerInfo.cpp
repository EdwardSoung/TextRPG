#include "PlayerInfo.h"
#include "GameManager.h"

void PlayerInfo::ShowInfo()
{
	PrintInfo();
	
	int Input = 0;
	while (Input >= 0)
	{
		printf("������(-1) :");
		std::cin >> Input;
	}

	system("cls");
	MapManager::GetInstance().ShowMap();
}
void PlayerInfo::PrintInfo()
{
	system("cls");
	printf("############################################\n");
	printf("#                Player Info               #\n");
	printf("############################################\n");
	PrintPlayerInfo();
	printf("############################################\n");
	PrintWeaponInfo();
	PrintArmorInfo();
	printf("############################################\n");
}

void PlayerInfo::PrintPlayerInfo()
{
	Player* CurPlayer = GameManager::GetInstance().CurrentPlayer;
	printf("#  �̸�   : %s\n", CurPlayer->GetName().c_str());
	if(CurPlayer->GetEquipStat(StatType::Attack) > 0)
		printf("#  ���ݷ� : %d (+ %d)\n", CurPlayer->GetStat(StatType::Attack), CurPlayer->GetEquipStat(StatType::Attack));
	else
		printf("#  ���ݷ� : %d\n", CurPlayer->GetStat(StatType::Attack));
	if(CurPlayer->GetEquipStat(StatType::Defence) > 0)
		printf("#  ���� : %d (+ %d)\n", CurPlayer->GetStat(StatType::Defence), CurPlayer->GetEquipStat(StatType::Defence));
	else
		printf("#  ���� : %d\n", CurPlayer->GetStat(StatType::Defence));
	if(CurPlayer->GetEquipStat(StatType::Health) > 0)
		printf("#  ü��   : %d (+ %d)\n", CurPlayer->GetStat(StatType::Health), CurPlayer->GetEquipStat(StatType::Health));
	else
		printf("#  ü��   : %d\n", CurPlayer->GetStat(StatType::Health));
}

void PlayerInfo::PrintWeaponInfo()
{
	Weapon* EquippedWeapon = GameManager::GetInstance().CurrentPlayer->GetWeapon();
	if (GameManager::GetInstance().CurrentPlayer->GetWeapon() == nullptr)
	{
		printf("#  [�������� ����]\n");
	}
	else
	{
		printf("#  [��������]\n");
		printf("#  ���ݷ� : %d\n", EquippedWeapon->GetStatValue(StatType::Attack));
		printf("#  ���� : %d\n", EquippedWeapon->GetStatValue(StatType::Defence));
		printf("#  ü��   : %d\n", EquippedWeapon->GetStatValue(StatType::Health));
	}

}

void PlayerInfo::PrintArmorInfo()
{
	Armor* EquippedArmor = GameManager::GetInstance().CurrentPlayer->GetArmor();
	if (EquippedArmor == nullptr)
	{
		printf("#  [�������� ����]\n");
	}
	else
	{
		printf("#  [��������]\n");
		printf("#  ���ݷ� : %d\n", EquippedArmor->GetStatValue(StatType::Attack));
		printf("#  ���� : %d\n", EquippedArmor->GetStatValue(StatType::Defence));
		printf("#  ü��   : %d\n", EquippedArmor->GetStatValue(StatType::Health));
	}
}
