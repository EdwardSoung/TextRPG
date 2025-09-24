#include "MapManager.h"

void MapManager::ShowVillage()
{
	for (int i = 0; i < MapHeight; i++)
	{
		for (int j = 0; j < MapWidth; j++)
		{
			if (i == PlayerPosition.Y && j == PlayerPosition.X)
				printf("◆");
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
			{
				printf("◆");					
			}
			else
				GetMapString(TempleMap[i][j]);
		}
		printf("\n");
	}
	
	if (TempleMap[PlayerPosition.Y][PlayerPosition.X] == static_cast<int>(MapBlock::Pray))
	{
		int Input = 0;

		while (Input < 2)
		{
			printf("기도를 하시겠습니까?(비용 10G)\n");
			printf("10% 확률로 완전 치유됩니다.\n");
			printf("선택(Yes : 1, No : 2) : ");
			std::cin >> Input;

			if (Input == 1)
			{
				if (GameManager::GetInstance().ItemInventory->UseGold(PriceData::PrayPrice))
				{
					GameManager::GetInstance().Heal();
				}
			}
			else if (Input == 2)
				ResetPosition(MapState::Temple, MapState::Temple);
		}

	}
	else
		ShowDirectionInfo();
}
void MapManager::ShowEnforce()
{
	for (int i = 0; i < MapHeight; i++)
	{
		for (int j = 0; j < MapWidth; j++)
		{
			if (i == PlayerPosition.Y && j == PlayerPosition.X)
				printf("◆");
			else
				GetMapString(EnforceMap[i][j]);
		}
		printf("\n");
	}

	if (EnforceMap[PlayerPosition.Y][PlayerPosition.X] == static_cast<int>(MapBlock::WeaponEnforce))
	{
		if (GameManager::GetInstance().CurrentPlayer->WeaponExists())
		{
			printf("착용한 무기가 없습니다.\n");
			ShowDirectionInfo();
			return;
		}
		else
		{
			//무기 정보 출력
		}
		int Input = 0;

		while (Input < 2)
		{
			//장착 무기 등급 가져와서 비용...
			printf("착용한 무기 강화를 하시겠습니까?\n");
			printf("전설 비용 : 1000G, 성공 확률 10%\n");
			printf("선택(Yes : 1, No : 2) : ");
			std::cin >> Input;

			if (Input == 1)
			{
				//Enforce 스크립트에서 진행?
				//비용 어디 저장해둬야하나..
				if (GameManager::GetInstance().ItemInventory->UseGold(100))
				{
					
				}
			}
			else if (Input == 2)
				ResetPosition(MapState::Temple, MapState::Temple);
		}

	}
	else if (EnforceMap[PlayerPosition.Y][PlayerPosition.X] == static_cast<int>(MapBlock::ArmorEnforce))
	{
		if (GameManager::GetInstance().CurrentPlayer->ArmorExists())
		{
			printf("착용한 무기가 없습니다.\n");
			ShowDirectionInfo();
			return;
		}
		else
		{
			//갑옷 정보 출력
		}
		int Input = 0;

		while (Input < 2)
		{
			//장착 무기 등급 가져와서 비용...
			printf("착용한 갑옷 강화를 하시겠습니까?\n");
			printf("전설 비용 : 1000G, 성공 확률 10%\n");
			printf("선택(Yes : 1, No : 2) : ");
			std::cin >> Input;

			if (Input == 1)
			{
				//Enforce 스크립트에서 진행?
				//비용 어디 저장해둬야하나..
				if (GameManager::GetInstance().ItemInventory->UseGold(100))
				{

				}
				else
				{
					//돈부족
				}
			}
			else if (Input == 2)
				ResetPosition(MapState::Temple, MapState::Temple);
		}

	}
	else
		ShowDirectionInfo();
}
void MapManager::ShowShop()
{
	for (int i = 0; i < MapHeight; i++)
	{
		for (int j = 0; j < MapWidth; j++)
		{
			if (i == PlayerPosition.Y && j == PlayerPosition.X)
			{
				printf("◆");
			}
			else
				GetMapString(ShopMap[i][j]);
		}
		printf("\n");
	}

	if (ShopMap[PlayerPosition.Y][PlayerPosition.X] == static_cast<int>(MapBlock::ShopSell))
	{
		int Input = 0;

		while (Input < 2)
		{
			std::cin >> Input;

			if (Input == 1)
			{
				
			}
			else if (Input == 2)
				ResetPosition(MapState::Temple, MapState::Temple);
		}

	}
	else
		ShowDirectionInfo();
}
void MapManager::ShowBlackSmith()
{
	for (int i = 0; i < MapHeight; i++)
	{
		for (int j = 0; j < MapWidth; j++)
		{
			if (i == PlayerPosition.Y && j == PlayerPosition.X)
			{
				printf("◆");
			}
			else
				GetMapString(BlackSmithMap[i][j]);
		}
		printf("\n");
	}

	if (BlackSmithMap[PlayerPosition.Y][PlayerPosition.X] == static_cast<int>(MapBlock::WeaponCraft))
	{
		int Input = 0;

		while (Input < 2)
		{
			std::cin >> Input;

			if (Input == 1)
			{

			}
			else if (Input == 2)
				ResetPosition(MapState::Temple, MapState::Temple);
		}

	}
	else if (BlackSmithMap[PlayerPosition.Y][PlayerPosition.X] == static_cast<int>(MapBlock::ArmorCraft))
	{

	}
	else
		ShowDirectionInfo();
}
void MapManager::ShowField(MapState InMap)
{
	for (int i = 0; i < MapHeight; i++)
	{
		for (int j = 0; j < MapWidth; j++)
		{
			if (i == PlayerPosition.Y && j == PlayerPosition.X)
			{
				printf("◆");
			}
			else
				GetMapString(ShopMap[i][j]);
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
	Position Next = PlayerPosition;
	if (Input == 'w' || Input == 'W')
	{
		Next.X = PlayerPosition.X;
		Next.Y = PlayerPosition.Y - 1;
	}
	else if (Input == 's' || Input == 'S')
	{
		Next.X = PlayerPosition.X;
		Next.Y = PlayerPosition.Y + 1;
	}
	else if (Input == 'a' || Input == 'A')
	{
		Next.X = PlayerPosition.X - 1;
		Next.Y = PlayerPosition.Y;
	}
	else if (Input == 'd' || Input == 'D')
	{
		Next.X = PlayerPosition.X + 1;
		Next.Y = PlayerPosition.Y;
	}

	if (CanMove(Next))
	{
		PlayerPosition = Next;
		CheckAndChangeMap(GetNextMapBlock(Next));
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
	case MapState::Temple:
		Block = TempleMap[PlayerPosition.Y][PlayerPosition.X];
		break;
	case MapState::Enforce:
		Block = EnforceMap[PlayerPosition.Y][PlayerPosition.X];
		break;
	case MapState::Shop:
		Block = ShopMap[PlayerPosition.Y][PlayerPosition.X];
		break;
	case MapState::BlackSmith:
		Block = BlackSmithMap[PlayerPosition.Y][PlayerPosition.X];
		break;

	}

	return static_cast<MapBlock>(Block);
}

int MapManager::GetNextMapBlock(const Position Next)
{
	int Block = 0;
	switch (CurrentMap)
	{
	case MapState::Village:
		Block = VillageMap[Next.Y][Next.X];
		break;
	case MapState::Temple:
		Block = TempleMap[Next.Y][Next.X];
		break;
	case MapState::Enforce:
		Block = EnforceMap[Next.Y][Next.X];
		break;
	case MapState::Shop:
		Block = ShopMap[Next.Y][Next.X];
		break;
	case MapState::BlackSmith:
		Block = BlackSmithMap[Next.Y][Next.X];
		break;
	}

	return Block;
}

bool MapManager::CanMove(Position Next)
{
	int NextBlock = GetNextMapBlock(Next);

	if (NextBlock == 0)
		return true;

	if ((NextBlock >= static_cast<int>(MapBlock::MineralBlock) && NextBlock < static_cast<int>(MapBlock::FieldEnd)))
	{		
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
		system("cls");
		ResetPosition(CurrentMap, MapState::Shop);
		ChangeMap(MapState::Shop);
		break;
	case MapBlock::Enforce:
		system("cls");
		ResetPosition(CurrentMap, MapState::Enforce);
		ChangeMap(MapState::Enforce);
		break;
	case MapBlock::Temple:
		system("cls");
		ResetPosition(CurrentMap, MapState::Temple);
		ChangeMap(MapState::Temple);
		break;
	case MapBlock::BlackSmith:
		system("cls");
		ResetPosition(CurrentMap, MapState::BlackSmith);
		ChangeMap(MapState::BlackSmith);
		break;
	case MapBlock::Field_Easy01:
		system("cls");
		ResetPosition(CurrentMap, MapState::Field_Easy01);
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
		//현재 맵이 어디냐에 따라서...
		system("cls");
		ResetPosition(CurrentMap, MapState::Village);
		ChangeMap(MapState::Village);
		break;
	}
}

void MapManager::ResetPosition(MapState PrevMap, MapState Map)
{
	switch (Map)
	{
	case MapState::Temple:
	{
		for (int i = 0; i < MapHeight; i++)
		{
			for (int j = 0; j < MapWidth; j++)
			{
				if (TempleMap[i][j] == static_cast<int>(MapBlock::Village))
				{
					PlayerPosition.X = j - 1;
					PlayerPosition.Y = i;
					return;
				}
			}
		}
	}
	break;
	case MapState::Village:
	{
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
		else if (PrevMap == MapState::Field_Easy01)
		{
			TargetMapBlock = MapBlock::Field_Easy01;
			Offset = Position(-1, 0);
		}

		for (int i = 0; i < MapHeight; i++)
		{
			for (int j = 0; j < MapWidth; j++)
			{
				if (VillageMap[i][j] == static_cast<int>(TargetMapBlock))
				{
					PlayerPosition.X = j + Offset.X;
					PlayerPosition.Y = i + Offset.Y;
					return;
				}
			}
		}
	}
	break;
	case MapState::Enforce:
	{
		for (int i = 0; i < MapHeight; i++)
		{
			for (int j = 0; j < MapWidth; j++)
			{
				if (EnforceMap[i][j] == static_cast<int>(MapBlock::Village))
				{
					PlayerPosition.X = j + 1;
					PlayerPosition.Y = i;
					return;
				}
			}
		}
	}
	break;
	case MapState::Shop:
	{
		for (int i = 0; i < MapHeight; i++)
		{
			for (int j = 0; j < MapWidth; j++)
			{
				if (ShopMap[i][j] == static_cast<int>(MapBlock::Village))
				{
					PlayerPosition.X = j - 1;
					PlayerPosition.Y = i;
					return;
				}
			}
		}
	}
	break;
	case MapState::BlackSmith:
	{
		for (int i = 0; i < MapHeight; i++)
		{
			for (int j = 0; j < MapWidth; j++)
			{
				if (BlackSmithMap[i][j] == static_cast<int>(MapBlock::Village))
				{
					PlayerPosition.X = j + 1;
					PlayerPosition.Y = i;
					return;
				}
			}
		}
	}
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

	case MapBlock::Village:
		SetBGColor(CC_CYAN);
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
	case MapBlock::ShopSell:
		SetBGColor(CC_MAGENTA);
		printf(" ");
		ResetBgColor();
		break;
	case MapBlock::Enforce:
		SetBGColor(CC_DARKYELLOW);
		printf(" ");
		ResetBgColor();
		break;
	case MapBlock::WeaponEnforce:
		SetBGColor(CC_DARKGRAY);
		printf(" ");
		ResetBgColor();
		break;
	case MapBlock::ArmorEnforce:
		SetBGColor(CC_DARKGREEN);
		printf(" ");
		ResetBgColor();
		break;
	case MapBlock::BlackSmith:
		SetBGColor(CC_GRAY);
		printf(" ");
		ResetBgColor();
		break;
	case MapBlock::WeaponCraft:
		SetBGColor(CC_DARKGRAY);
		printf(" ");
		ResetBgColor();
		break;
	case MapBlock::ArmorCraft:
		SetBGColor(CC_DARKGREEN);
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
	case MapState::Enforce:
		ShowEnforce();
		break;
	case MapState::Shop:
		ShowShop();
		break;
	case MapState::BlackSmith:
		ShowBlackSmith();
		break;
	case MapState::Field_Easy01:
	case MapState::Field_Easy02:
	case MapState::Field_Easy03:
	case MapState::Field_Hard01:
	case MapState::Field_Hard02:
	case MapState::Field_Hard03:
		ShowField(CurrentMap);
		break;

	}
}

