#pragma once
#include "Item.h"
class Weapon : public Item
{
public:
	Weapon(ItemType InType, GradeType InGradeType) : Item(InType, InGradeType) {}
	virtual void PrintItemString();
};

