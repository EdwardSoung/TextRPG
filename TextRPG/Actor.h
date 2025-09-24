#pragma once
#include "Stat.h"

class Actor
{
public:
	Actor() = default;
	Actor(Stat InBaseStat) :BaseStat(InBaseStat) {}
	void Attack(Actor& Target);
	virtual void OnHit(int Damage) = 0;
protected:
	Stat BaseStat;	
	int Health = 0;
	bool IsDead = false;
};

