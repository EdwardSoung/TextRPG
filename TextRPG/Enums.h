#pragma once

enum class ItemType
{
	None,
	Weapon,
	Armor,
	Mineral,
	Wood,
	Leather,
};

enum class StatType
{
	Attack,
	Health,
	Defence
};

enum class GradeType
{
	None = 0,
	Common,
	Uncommon,
	Rare,
	Unique,
	Legend
};