#include "VillageMap.h"

void VillageMap::ShowMap()
{
	auto PlayerPos = MapManager::GetInstance().PlayerPosition;
	for (int i = 0; i < MapHeight; i++)
	{
		for (int j = 0; j < MapWidth; j++)
		{
			if (i == PlayerPos.Y && j == PlayerPos.X)
				printf("@");
			else
				GetMapString(Map[i][j]);
		}
		printf("\n");
	}

	ShowDirectionInfo();
}

//다른맵에서 여기로 올 때...
void VillageMap::ResetPosition(MapState PrevMap)
{
	//맵 초기화 상태
	if (PrevMap == MapState::None)
	{
		MapManager::GetInstance().UpdatePosition(19, 8);
		return;
	}

	MapBlock TargetMapBlock = MapBlock::EmptyBlock;
	Position Offset(0, 0);
	if (PrevMap == MapState::Temple)
	{
		TargetMapBlock = MapBlock::Temple;
		Offset = Position(1, 0);
	}
	else if (PrevMap == MapState::Shop)
	{
		TargetMapBlock = MapBlock::Shop;
		Offset = Position(1, 0);
	}
	else if (PrevMap == MapState::Enforce)
	{
		TargetMapBlock = MapBlock::Enforce;
		Offset = Position(-1, 0);
	}
	else if (PrevMap == MapState::BlackSmith)
	{
		TargetMapBlock = MapBlock::BlackSmith;
		Offset = Position(-1, 0);
	}
	else if (PrevMap == MapState::Field)
	{
		TargetMapBlock = MapBlock::EnterField;
		Offset = Position(-1, 0);
	}

	for (int i = 0; i < MapHeight; i++)
	{
		for (int j = 0; j < MapWidth; j++)
		{
			if (Map[i][j] == static_cast<int>(TargetMapBlock))
			{
				MapManager::GetInstance().UpdatePosition(j + Offset.X, i + Offset.Y);
				return;
			}
		}
	}
}

int VillageMap::GetMapBlock(Position InPos)
{
	return Map[InPos.Y][InPos.X];
}

void VillageMap::Move(char Input)
{
	Position Next = MapManager::GetInstance().PlayerPosition;
	if (Input == 'w' || Input == 'W')
	{
		Next.Y--;
	}
	else if (Input == 's' || Input == 'S')
	{
		Next.Y++;
	}
	else if (Input == 'a' || Input == 'A')
	{
		Next.X--;
	}
	else if (Input == 'd' || Input == 'D')
	{
		Next.X++;
	}

	if (CanMove(GetMapBlock(Next)))
	{
		MapManager::GetInstance().UpdatePosition(Next);
		CheckPosAndChangeMap(GetMapBlock(Next));
	}

	system("cls");
	ShowMap();
}

void VillageMap::CheckPosAndChangeMap(int InBlock)
{
	if (InBlock == 0) return;

	MapBlock BlockItem = static_cast<MapBlock>(InBlock);

	system("cls");
	MapState MoveState = BlockToMap(BlockItem);
	//ResetPosition(MoveState);
	MapManager::GetInstance().ChangeMap(MoveState);
}

MapState VillageMap::BlockToMap(MapBlock InBlock)
{
	switch (InBlock)
	{
	case MapBlock::Enforce:
		return MapState::Enforce;
	case MapBlock::Temple:
		return MapState::Temple;		
	case MapBlock::Shop:
		return MapState::Shop;		
	case MapBlock::BlackSmith:
		return MapState::BlackSmith;		
	case MapBlock::EnterField:
		return MapState::Field;		
	default:
		return MapState::Village;
	}
}

