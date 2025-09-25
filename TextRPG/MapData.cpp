#include "MapData.h"

void MapData::ShowDirectionInfo()
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
	else if (Input == 'p')
	{
		//캐릭터 정보..
	}
}

bool MapData::CanMove(int InBlock)
{
	if (InBlock == 0)
		return true;

	if ((InBlock >= static_cast<int>(MapBlock::MineralBlock) && InBlock < static_cast<int>(MapBlock::FieldEnd)))
	{
		return true;
	}

	return false;
}

void MapData::GetMapString(int BlockNum)
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

void MapData::SetBGColor(int Bgcolor)
{
	int Color = CC_ORIGINAL;
	Color &= 0xf;
	Bgcolor &= 0xf;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
		(Bgcolor << 4) | Color);
}