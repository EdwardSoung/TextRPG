#include "MapManager.h"
#include "VillageMap.h"
#include "TempleMap.h"
#include "EnforceMap.h"
#include "ShopMap.h"
#include "BlackSmithMap.h"
#include "FieldMap.h"

void MapManager::ChangeMap(MapState State)
{
	if (CurrentMapData != nullptr)
		delete CurrentMapData;

	switch (State)
	{
	case MapState::Village:
		CurrentMapData = new VillageMap();
		break;
	case MapState::Enforce:
		CurrentMapData = new EnforceMap();
		break;
	case MapState::Temple:
		CurrentMapData = new TempleMap();
		break;
	case MapState::BlackSmith:
		CurrentMapData = new BlackSmithMap();
		break;
	case MapState::Shop:
		CurrentMapData = new ShopMap();
		break;
	case MapState::Field:
		auto Field = new FieldMap();
		Field->GenerateMaterials();
		CurrentMapData = Field;
		break;
	}
	CurrentMapData->ResetPosition(CurrentMap);
	CurrentMap = State;
	ShowMap();
}

void MapManager::UpdatePosition(Position InPos)
{
	PlayerPosition.X = InPos.X;
	PlayerPosition.Y = InPos.Y;
}

void MapManager::UpdatePosition(int InPosX, int InPosY)
{
	PlayerPosition.X = InPosX;
	PlayerPosition.Y = InPosY;
}

MapManager::~MapManager()
{
	delete CurrentMapData;
}

void MapManager::ShowMap()
{
	if(CurrentMapData != nullptr)
		CurrentMapData->ShowMap();
}

