#pragma once
#include <iostream>
#include <cstdio>
#include "GameManager.h"

class MapData
{
public:
	MapData() = default;
	virtual ~MapData() {}
	virtual void ShowMap() = 0;
	virtual void ResetPosition(MapState PrevMap) = 0;
	virtual int GetMapBlock(Position InPos) = 0;
	virtual void Move(char Input) = 0;
	virtual void CheckPosAndChangeMap(int InBlock) = 0;

	static constexpr int MapWidth = 40;
	static constexpr int MapHeight = 19;
protected:
	void ShowDirectionInfo();
	bool CanMove(int InBlock);

	void GetMapString(int BlockNum);
	void SetBGColor(int Bgcolor);
	inline void ResetBgColor()
	{
		SetBGColor(CC_BLACK);
	}
	inline bool IsDirectionKey(const char c)
	{
		return c == 'w' || c == 's' || c == 'a' || c == 'd' || c == 'W' || c == 'S' || c == 'A' || c == 'D';
	}
	
};

