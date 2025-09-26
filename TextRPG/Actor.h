#pragma once
#include <string>
#include "Stat.h"

class Actor
{
public:
	Actor() = default;
	Actor(std::string InName, Stat InBaseStat) :Name(InName), BaseStat(InBaseStat) {}
	virtual ~Actor() {}
	void Attack(Actor* InTarget);
	virtual void OnHit(int InDamage) = 0;

	inline std::string GetName() { return Name; }

	inline int GetStat(StatType InType)
	{
		return BaseStat.GetStat(InType);
	}

	inline int GetEquipStat(StatType InType)
	{
		return EquipStat.GetStat(InType);
	}

	inline int GetTotalStat(StatType InType)
	{
		return  BaseStat.GetStat(InType) + EquipStat.GetStat(InType);
	}
	bool IsDead = false;
	
protected:
	Stat BaseStat;
	Stat EquipStat;

	int Health = 0;
	std::string Name = "";
};

