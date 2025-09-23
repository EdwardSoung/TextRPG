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

enum class MapState
{
	Village,	//�ǹ� �ȵ� ���� ��
	Shop,
	BlackSmith,
	Temple,

	Field_Easy01 = 11,
	Field_Easy02,
	Field_Easy03,

	Field_Hard01 = 21,
	Field_Hard02,
	Field_Hard03,

};