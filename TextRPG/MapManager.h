#pragma once
#include <string>
#include <Windows.h>
#include <iostream>
#include "Enums.h"
#include "GameManager.h"
#include "MapData.h"
class MapData;

class MapManager
{
public:
	static MapManager& GetInstance() 
	{
		static MapManager Instance;
		return Instance;
	}
	~MapManager();
	void ShowMap();
	void ChangeMap(MapState State);

	Position PlayerPosition = Position(19, 8);
	void UpdatePosition(Position InPos);
	void UpdatePosition(int InPosX, int InPosY);
	
	inline const MapState GetCurrentMap() { return CurrentMap; }
private:
	MapData* CurrentMapData = nullptr;

	MapManager() = default;
	MapManager(const MapManager&) = delete;
	MapManager& operator=(const MapManager&) = delete;
	MapManager(MapManager&&) = delete;
	MapManager& operator=(MapManager&&) = delete;
			
	MapState CurrentMap = MapState::None;
	
};
