#pragma once
#include <map>
#include "Enums.h"
class Stat
{
public:
	Stat() = default;
	Stat(int InAttack, int InDefence, int InHealth) : Attack(InAttack), Defence(InDefence), Health(InHealth) {}
	int GetStat(StatType Type) const;
	
private:
	int Attack = 0;
	int Defence = 0;
	int Health = 0;
};

Stat operator+(const Stat& BaseStat, const Stat& ItemStat)
{
	int Attack = BaseStat.GetStat(StatType::Attack) + ItemStat.GetStat(StatType::Attack);
	int Defence = BaseStat.GetStat(StatType::Attack) + ItemStat.GetStat(StatType::Attack);
	int Health = BaseStat.GetStat(StatType::Attack) + ItemStat.GetStat(StatType::Attack);
	return Stat(Attack, Defence, Health);
}