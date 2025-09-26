#pragma once
#include "Actor.h"

class Monster : public Actor
{
public:
	Monster() = default;
	Monster(std::string InName, Stat InBaseStat) : Actor(InName, InBaseStat)
	{
		Health = GetTotalStat(StatType::Health);
	}
	virtual ~Monster() = default;
	virtual void OnHit(int InDamage) override;
};