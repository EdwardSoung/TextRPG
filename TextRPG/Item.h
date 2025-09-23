#pragma once
#include <string>
#include "Enums.h"

class Item
{
public:
	Item() = default;
	Item(ItemType InType, GradeType InGradeType, int InAmount) : Type(InType), Grade(InGradeType), Amount(InAmount)
	{
		InitSellPrice();
	}
	virtual ~Item() {};
	virtual void PrintItemString();
	std::string GetItemNameString();
	std::string GetGradeString();
	void AddAmount(int InAmount) { Amount += InAmount; }
	bool IsEnough(Item item);

	inline bool IsMaterial() { return Type == ItemType::Wood || Type == ItemType::Leather || Type == ItemType::Mineral; }

	inline ItemType GetType() { return Type; }
	inline GradeType GetGrade() { return Grade; }
	inline int GetSellPrice() { return SellPrice; }
	inline int GetAmount() { return Amount; }
	
	inline bool IsEquip()
	{
		return Type == ItemType::Weapon || Type == ItemType::Armor;
	}

protected:
	int Amount = 0;
	int SellPrice = 0;
	ItemType Type = ItemType::None;
	GradeType Grade = GradeType::None;

private:
	void InitSellPrice();
};

