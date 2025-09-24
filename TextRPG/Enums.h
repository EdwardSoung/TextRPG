#pragma once

struct Position
{
	int X = 0;
	int Y = 0;
	Position() = default;
	Position(int InX, int InY) : X(InX), Y(InY)
	{

	}
};

enum class Direction
{
	Up,
	Down,
	Left,
	Right
};
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
	Village,	//건물 안들어간 마을 안
	Shop,
	BlackSmith,
	Enforce,
	Temple,

	Field_Easy01 = 11,
	Field_Easy02,
	Field_Easy03,

	Field_Hard01 = 21,
	Field_Hard02,
	Field_Hard03,

};

enum ConsoleColor {
	CC_BLACK,
	CC_DARKBLUE,
	CC_DARKGREEN,
	CC_DARKCYAN,
	CC_DARKRED,
	CC_DARKMAGENTA,
	CC_DARKYELLOW,
	CC_GRAY,
	CC_DARKGRAY,
	CC_BLUE,
	CC_GREEN,
	CC_CYAN,
	CC_RED,
	CC_MAGENTA,
	CC_YELLOW,
	CC_WHITE,
	CC_LIGHTGRAY = 7,
	CC_ORIGINAL = 7,
	CC_ORIGINALFONT = 7,
	CC_ORIGINALBG = 0
};
enum class MapBlock
{
	EmptyBlock = 0,
	
	TopLeft = 21,
	TopRight = 22,
	BottomLeft = 23,
	BottomRight = 24,
	LeftCenter = 25,
	RightCenter = 26,
	TopCenter = 27,
	BottomCenter = 28,
	Horizontal = 29,
	Vertial = 30,
	Cross = 31,

	MineralBlock = 32,
	WoodBlock = 33,
	LeatherBlock = 34,

	Temple,
	Shop,
	Enforce,
	BlackSmith,

	Village,
	Pray,
	WeaponEnforce,
	ArmorEnforce,
	ShopSell,
	WeaponCraft,
	ArmorCraft,

	Field_Easy01,
	Field_Easy02,
	Field_Easy03,
	Field_Hard01,
	Field_Hard02,
	Field_Hard03,
	FieldEnd,

	A = 65,
	B,
	C,
	D,
	E,
	F,
	G,
	H,
	I,
	J,
	K,
	L,
	M,
	N,
	O,
	P,
	Q,
	R,
	S,
	T,
	U,
	V,
	W,
	X,
	Y,
	Z,

	a = 97,
	b,
	c,
	d,
	e,
	f,
	g,
	h,
	i,
	j,
	k,
	l,
	m,
	n,
	o,
	p,
	q,
	r,
	s,
	t,
	u,
	v,
	w,
	x,
	y,
	z
};