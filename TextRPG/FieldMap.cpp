#include "FieldMap.h"

void FieldMap::ShowMap()
{
	auto PlayerPos = MapManager::GetInstance().PlayerPosition;
	for (int i = 0; i < MapHeight; i++)
	{
		for (int j = 0; j < MapWidth; j++)
		{
			if (i == PlayerPos.Y && j == PlayerPos.X)
			{
				printf("@");
			}
			else
				GetMapString(Map[i][j]);
		}
		printf("\n");
	}

	ShowDirectionInfo();
	//이동 후 몬스터 만남(확률)
}

void FieldMap::ResetPosition(MapState PrevMap)
{
}

int FieldMap::GetMapBlock(Position InPos)
{
    return 0;
}

void FieldMap::Move(char Input)
{
}

void FieldMap::CheckPosAndChangeMap(int InBlock)
{
}
