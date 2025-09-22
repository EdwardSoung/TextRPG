#pragma once
#include <string>
#include "Enums.h"

class Item
{
public:
	Item(ItemType InType, GradeType InGradeType) : Type(InType), Grade(InGradeType), Amount(1)
	{
		InitSellPrice();
	}
	virtual ~Item() {};
	virtual void PrintItemString();
	std::string GetItemNameString();
	std::string GetGradeString();
	inline bool IsEquip()
	{
		return Type == ItemType::Weapon || Type == ItemType::Armor;
	}

protected:
	int Amount = 1;
	int SellPrice = 0;
	ItemType Type = ItemType::None;
	GradeType Grade = GradeType::None;

private:
	void InitSellPrice();
};

