#include "PlayerInfo.h"
#include "GameManager.h"

void PlayerInfo::ShowInfo()
{
	PrintInfo();
	
	int Input = 0;
	while (Input >= 0)
	{
		printf("나가기(-1) :");
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
	printf("#  이름   : %s\n", CurPlayer->GetName().c_str());
	if(CurPlayer->GetEquipStat(StatType::Attack) > 0)
		printf("#  공격력 : %d (+ %d)\n", CurPlayer->GetStat(StatType::Attack), CurPlayer->GetEquipStat(StatType::Attack));
	else
		printf("#  공격력 : %d\n", CurPlayer->GetStat(StatType::Attack));
	if(CurPlayer->GetEquipStat(StatType::Defence) > 0)
		printf("#  방어력 : %d (+ %d)\n", CurPlayer->GetStat(StatType::Defence), CurPlayer->GetEquipStat(StatType::Defence));
	else
		printf("#  방어력 : %d\n", CurPlayer->GetStat(StatType::Defence));
	if(CurPlayer->GetEquipStat(StatType::Health) > 0)
		printf("#  체력   : %d (+ %d)\n", CurPlayer->GetStat(StatType::Health), CurPlayer->GetEquipStat(StatType::Health));
	else
		printf("#  체력   : %d\n", CurPlayer->GetStat(StatType::Health));
}

void PlayerInfo::PrintWeaponInfo()
{
	Weapon* EquippedWeapon = GameManager::GetInstance().CurrentPlayer->GetWeapon();
	if (GameManager::GetInstance().CurrentPlayer->GetWeapon() == nullptr)
	{
		printf("#  [장착무기 없음]\n");
	}
	else
	{
		printf("#  [장착무기]\n");
		printf("#  공격력 : %d\n", EquippedWeapon->GetStatValue(StatType::Attack));
		printf("#  방어력 : %d\n", EquippedWeapon->GetStatValue(StatType::Defence));
		printf("#  체력   : %d\n", EquippedWeapon->GetStatValue(StatType::Health));
	}

}

void PlayerInfo::PrintArmorInfo()
{
	Armor* EquippedArmor = GameManager::GetInstance().CurrentPlayer->GetArmor();
	if (EquippedArmor == nullptr)
	{
		printf("#  [장착갑옷 없음]\n");
	}
	else
	{
		printf("#  [장착갑옷]\n");
		printf("#  공격력 : %d\n", EquippedArmor->GetStatValue(StatType::Attack));
		printf("#  방어력 : %d\n", EquippedArmor->GetStatValue(StatType::Defence));
		printf("#  체력   : %d\n", EquippedArmor->GetStatValue(StatType::Health));
	}
}
