#pragma once
#include <string>
#include "Stat.h"
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
	void PrintItemString();
	void PrintItemStringWithPrice();
	void PrintItemInfoString();
	std::string GetItemNameString();
	std::string GetGradeString();
	void AddAmount(int InAmount) { Amount += InAmount; }
	bool IsEnough(Item item);
	void Use(int InAmount);
	void SetStat(Stat InStat);

	inline bool IsMaterial() { return Type == ItemType::Wood || Type == ItemType::Leather || Type == ItemType::Mineral; }

	inline ItemType GetType() { return Type; }
	inline GradeType GetGrade() { return Grade; }
	inline int GetSellPrice() { return SellPrice; }
	inline int GetAmount() { return Amount; }
	
	inline bool IsEquip()
	{
		return Type == ItemType::Weapon || Type == ItemType::Armor;
	}
	inline const int GetEnforceCount() { return EnforceCount; }

	inline int GetStatValue(StatType InType)
	{
		if (IsMaterial())
			return 0;

		return StatData.GetStat(InType);
	}

	inline const Stat GetStat() { return StatData; }
protected:
	int Amount = 0;
	int SellPrice = 0;
	ItemType Type = ItemType::None;
	GradeType Grade = GradeType::None;

	int EnforceCount = 0;
	Stat StatData;

private:
	void InitSellPrice();
};

