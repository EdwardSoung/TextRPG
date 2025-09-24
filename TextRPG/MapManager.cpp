#include "MapManager.h"

void MapManager::ShowVillage()
{
	for (int i = 0; i < MapHeight; i++)
	{
		for (int j = 0; j < MapWidth; j++)
		{
			if (i == PlayerPosition.Y && j == PlayerPosition.X)
				printf("＠");
			else
				GetMapString(VillageMap[i][j]);
		}
		printf("\n");
	}

	ShowDirectionInfo();
}

void MapManager::ShowTemple()
{
	for (int i = 0; i < MapHeight; i++)
	{
		for (int j = 0; j < MapWidth; j++)
		{
			if (i == PlayerPosition.Y && j == PlayerPosition.X)
				printf("＠");
			else
				GetMapString(TempleMap[i][j]);
		}
		printf("\n");
	}
	
	if (TempleMap[PlayerPosition.Y][PlayerPosition.X] == static_cast<int>(MapBlock::Pray))
	{
		int Input = 0;

		while (Input != 1)
		{
			printf("기도를 하시겠습니까?(비용 10G)\n");
			printf("Yes : 1, No : 2");
			std::cin >> Input;

			if (Input == 1)
			{
				if (GameManager::GetInstance().ItemInventory->UseGold(10))
				{
					GameManager::GetInstance().Heal();
				}
			}
		}

	}
	else
		ShowDirectionInfo();
}

void MapManager::ShowDirectionInfo()
{
	char Input = 0;
	printf("이동(w, s, a, d), 가방(i), 캐릭터(p) : ");
	std::cin >> Input;

	//이동이면
	if (IsDirectionKey(Input))
	{
		Move(Input);
	}
	else if (Input == 'i')
	{
		system("cls");
		GameManager::GetInstance().ItemInventory->ShowInventory();
	}
	else if(Input == 'p')
	{
		//캐릭터 정보..
	}

}

void MapManager::Move(char Input)
{
	Position Next;
	if (Input == 'w' || Input == 'W')
	{
		Next = Position(PlayerPosition.X, PlayerPosition.Y - 1);
	}
	else if (Input == 's' || Input == 'S')
	{
		Next = Position(PlayerPosition.X, PlayerPosition.Y + 1);
	}
	else if (Input == 'a' || Input == 'A')
	{
		Next = Position(PlayerPosition.X - 1, PlayerPosition.Y);
	}
	else if (Input == 'd' || Input == 'D')
	{
		Next = Position(PlayerPosition.X + 1, PlayerPosition.Y);		
	}

	if (CanMove(Next))
	{
		PlayerPosition = Next;
	}

	system("cls");
	ShowMap();
}

bool MapManager::IsMapMove()
{
	auto CurrentBlock = GetCurrentMapBlock();
	if (CurrentBlock == MapBlock::EmptyBlock || CurrentBlock >= MapBlock::MineralBlock)
	{
		return true;
	}
	return false;
}

MapBlock MapManager::GetCurrentMapBlock()
{
	int Block = 0;
	switch (CurrentMap)
	{
	case MapState::Village:
		Block = VillageMap[PlayerPosition.Y][PlayerPosition.X];
		break;
	}

	return static_cast<MapBlock>(Block);
}

bool MapManager::CanMove(Position Next)
{
	int NextBlock = VillageMap[Next.Y][Next.X];


	if (NextBlock == 0 || (NextBlock >= static_cast<int>(MapBlock::MineralBlock) && NextBlock < static_cast<int>(MapBlock::FieldEnd)))
	{
		CheckAndChangeMap(NextBlock);
		return true;
	}

	return false;
}

void MapManager::CheckAndChangeMap(int Block)
{
	if (Block == 0) return;

	MapBlock BlockItem = static_cast<MapBlock>(Block);
	switch (BlockItem)
	{
	case MapBlock::Shop:
		ChangeMap(MapState::Shop);
		break;
	case MapBlock::Enforce:
		ChangeMap(MapState::Enforce);
		break;
	case MapBlock::Temple:
		ChangeMap(MapState::Temple);
		break;
	case MapBlock::BlackSmith:
		ChangeMap(MapState::BlackSmith);
		break;
	case MapBlock::Field_Easy01:
		ChangeMap(MapState::Field_Easy01);
		break;
	case MapBlock::Field_Easy02:
		ChangeMap(MapState::Field_Easy02);
		break;
	case MapBlock::Field_Easy03:
		ChangeMap(MapState::Field_Easy03);
		break;
	case MapBlock::Field_Hard01:
		ChangeMap(MapState::Field_Hard01);
		break;
	case MapBlock::Field_Hard02:
		ChangeMap(MapState::Field_Hard02);
		break;
	case MapBlock::Field_Hard03:
		ChangeMap(MapState::Field_Hard03);
		break;
	case MapBlock::Village:
		ChangeMap(MapState::Village);
		break;
	}
}

void MapManager::ChangeMap(MapState State)
{
	CurrentMap = State;
	ShowMap();
}

void MapManager::GetMapString(int BlockNum)
{
	if (BlockNum >= static_cast<int>(MapBlock::A))
	{
		printf("%c", BlockNum);
		return;
	}

	MapBlock Block = static_cast<MapBlock>(BlockNum);

	switch (Block)
	{
	case MapBlock::EmptyBlock:
		printf(" ");
		break;
	case MapBlock::TopLeft:
		printf("┌");
		break;
	case MapBlock::TopRight:
		printf("┐");
		break;
	case MapBlock::BottomLeft:
		printf("└");
		break;
	case MapBlock::BottomRight:
		printf("┘");
		break;
	case MapBlock::LeftCenter:
		printf("├");
		break;
	case MapBlock::RightCenter:
		printf("┤");
		break;
	case MapBlock::TopCenter:
		printf("┬");
		break;
	case MapBlock::BottomCenter:
		printf("┴");
		break;
	case MapBlock::Horizontal:
		printf("─");
		break;
	case MapBlock::Vertial:
		printf("│");
		break;
	case MapBlock::Cross:
		printf("┼");
		break;
	case MapBlock::Pray:
		SetBGColor(CC_BLUE);
		printf(" ");
		ResetBgColor();
		break;
	//case MapBlock::Player:
	//	printf("☆");
	//	break;
	case MapBlock::Temple:
		SetBGColor(CC_GREEN);
		printf(" ");
		ResetBgColor();
		break;
	case MapBlock::Shop:
		SetBGColor(CC_YELLOW);
		printf(" ");
		ResetBgColor();
		break;
	case MapBlock::Enforce:
		SetBGColor(CC_DARKYELLOW);
		printf(" ");
		ResetBgColor();
		break;
	case MapBlock::BlackSmith:
		SetBGColor(CC_GRAY);
		printf(" ");
		ResetBgColor();
		break;
	case MapBlock::Field_Easy01:
		SetBGColor(CC_RED);
		printf(" ");
		ResetBgColor();
		break;
	case MapBlock::Field_Easy02:
		SetBGColor(CC_RED);
		printf(" ");
		ResetBgColor();
		break;
	case MapBlock::Field_Easy03:
		SetBGColor(CC_RED);
		printf(" ");
		ResetBgColor();
		break;
	case MapBlock::Field_Hard01:
		SetBGColor(CC_DARKRED);
		printf(" ");
		ResetBgColor();
		break;
	case MapBlock::Field_Hard02:
		SetBGColor(CC_DARKRED);
		printf(" ");
		ResetBgColor();
		break;
	case MapBlock::Field_Hard03:
		SetBGColor(CC_DARKRED);
		printf(" ");
		ResetBgColor();
		break;
	}
}

void MapManager::SetBGColor(int Bgcolor)
{
	int Color = CC_ORIGINAL;
	Color &= 0xf;
	Bgcolor &= 0xf;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
		(Bgcolor << 4) | Color);
}



void MapManager::ShowMap()
{
	switch (CurrentMap)
	{
	case MapState::Village:
		ShowVillage();
		break;
	case MapState::Temple:
		ShowTemple();
		break;
	}
}

