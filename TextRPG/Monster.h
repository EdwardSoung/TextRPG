#pragma once
#include "Actor.h"

class Monster : public Actor
{
public:
	Monster() = default;
	Monster(Stat InBaseStat) : Actor(InBaseStat)
	{
		Health = BaseStat.GetStat(StatType::Health);
	}
	virtual ~Monster() = default;
	virtual void OnHit(int Damage) override;
};