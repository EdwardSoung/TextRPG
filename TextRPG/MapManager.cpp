#include "MapManager.h"

void MapManager::ShowVillage()
{
	CurrentMap = MapState::Village;

	for (int i = 0; i < MapHeight; i++)
	{
		for (int j = 0; j < MapWidth; j++)
		{
			if (i == PlayerPosition.Y && j == PlayerPosition.X)
				printf("☆");
			else
				GetMapString(VillageMap[i][j]);
		}
		printf("\n");
	}

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
		//i면 맵 지우고 나가기면 다시 표기.. 현재가 맵 어딘지 보고...
		system("cls");
		GameManager::GetInstance()._Inventory->ShowInventory();
	}
	else if(Input == 'p')
	{
		//캐릭터 정보..
	}

}

void MapManager::Move(char Input)
{
	if (Input == 'w' || Input == 'W')
	{
		Position Next(PlayerPosition.X, PlayerPosition.Y - 1);
		if (CanMove(Next))
		{
			PlayerPosition = Next;
			ShowVillage();
		}
	}
}

void MapManager::ChangeMap(MapState State)
{
}

bool MapManager::CanMove(Position Next)
{
	int NextBlock = VillageMap[Next.Y][Next.X];

	if (NextBlock == 0 || (NextBlock >= static_cast<int>(MapBlock::MineralBlock) && NextBlock < static_cast<int>(MapBlock::Player)))
		return true;

	return false;
}

void MapManager::GetMapString(int block)
{
	if (block >= static_cast<int>(MapBlock::A))
	{
		printf("%c", block);
		return;
	}

	MapBlock Block = static_cast<MapBlock>(block);

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
	case MapBlock::Player:
		printf("☆");
		break;
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
	case MapBlock::Field:
		SetBGColor(CC_RED);
		printf(" ");
		ResetBgColor();
		break;
	}
}

void MapManager::SetBGColor(int bgcolor)
{
	int color = CC_ORIGINAL;
	color &= 0xf;
	bgcolor &= 0xf;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
		(bgcolor << 4) | color);
}
