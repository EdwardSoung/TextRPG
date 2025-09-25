#pragma once
#include "Item.h"

class Armor : public Item
{
public:
	Armor(GradeType InGradeType) : Item(ItemType::Armor, InGradeType, 1)
	{
		InitRandomStat();
	}
	int GetEnforcePrice();
	int GetEnforceRate();
	void RandomEnforce();
		
private:
	void InitRandomStat();
	int GetStatRangeValue();
};

