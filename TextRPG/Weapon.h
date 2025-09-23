#pragma once
#include "Item.h"
#include "Stat.h"
class Weapon : public Item
{
public:
	Weapon(ItemType InType, GradeType InGradeType, int InAmount) : Item(InType, InGradeType, 1) 
	{
		InitRandomStat();
	}
	virtual void PrintItemString();


private:
	Stat StatData;

	void InitRandomStat();
};

