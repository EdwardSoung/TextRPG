#pragma once
#include "Item.h"
class Weapon : public Item
{
public:
	Weapon(GradeType InGradeType) : Item(ItemType::Weapon, InGradeType, 1) 
	{
		InitRandomStat();
	}

	int GetEnforcePrice();
	int GetEnforceRate();
	void RandomEnforce();

private:
	int GetStatRangeValue();
	void InitRandomStat();
};

