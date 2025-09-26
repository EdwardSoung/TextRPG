#include "FieldMap.h"

void FieldMap::ShowMap()
{
	Position PlayerPos;

	while (ExitMap == false)
	{
		PlayerPos = MapManager::GetInstance().PlayerPosition;
		for (int i = 0; i < MapHeight; i++)
		{
			for (int j = 0; j < MapWidth; j++)
			{
				if (i == PlayerPos.Y && j == PlayerPos.X)
				{
					printf("@");
				}
				else if (IsMaterialPos(j, i))
				{
					//��� �÷� ������ ǥ��
					PrintMapMaterial(j, i);
				}
				else if (Level == LevelMax && Map[i][j] == static_cast<int>(MapBlock::NextField))
				{
					GetMapString(static_cast<int>(MapBlock::Vertial));
				}
				else
					GetMapString(Map[i][j]);
			}
			printf("\n");
		}
		printf("#####���̵� : %d\n", Level);

		if (GotItem != ItemType::None)
		{
			printf("������ %s�� ȹ���߽��ϴ�!\n", GetItemString(GotItem).c_str());
			GotItem = ItemType::None;
		}
		ShowDirectionInfo();
	}
	 

}

void FieldMap::ResetPosition(MapState PrevMap)
{
	for (int i = 0; i < MapHeight; i++)
	{
		for (int j = 0; j < MapWidth; j++)
		{
			if (Map[i][j] == static_cast<int>(MapBlock::EnterField))
			{
				MapManager::GetInstance().UpdatePosition(j + 1, i);
				return;
			}
		}
	}
}

int FieldMap::GetMapBlock(Position InPos)
{
	return Map[InPos.Y][InPos.X];
}

void FieldMap::Move(char Input)
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
	
	int NextBlock = GetMapBlock(Next);
	if (CanMove(NextBlock))
	{
		MapManager::GetInstance().UpdatePosition(Next);

		//������ġ ������ üũ
		CheckMaterialBlock(Next);

		CheckPosAndChangeMap(NextBlock);

		if (GetCurrentMapBlock() == MapBlock::EmptyBlock)
		{
			int BattleRand = rand() % 10000;
			if (BattleRand < RateData::BattleEncountRate)
			{
				GameManager::GetInstance().BattleStart(Level);
			}
		}
	}

	system("cls");
	//ShowMap();
}

void FieldMap::CheckPosAndChangeMap(int InBlock)
{
	if (InBlock == 0) return;

	MapBlock BlockItem = static_cast<MapBlock>(InBlock);

	if (BlockItem == MapBlock::NextField && Level < LevelMax)
	{
		//���� �ʵ�
		Level++;
		GenerateMaterials();
		ResetPosition(MapState::Field);
		system("cls");
		ShowMap();
	}
	else if(BlockItem == MapBlock::EnterField && Level > 1)
	{
		//���� �ʵ�
		Level--;
		GenerateMaterials();
		ResetPositionToPrev();
		system("cls");
		ShowMap();
	}
	else if (BlockItem == MapBlock::EnterField && Level == 1)
	{
		ExitMap = true;
		system("cls");
		MapManager::GetInstance().ChangeMap(MapState::Village);
	}
}

void FieldMap::GenerateMaterials()
{
	MaterialGenPos.clear();

	int HeightRandom = 0;
	int WidthRandom = 0;
	//�켱 ���� 4�� ��������
	int GenCount = 4;
	int Generated = 0;

	while (Generated < GenCount)
	{
		HeightRandom = rand() % (MapHeight - 5) + 4;
		WidthRandom = rand() % (MapWidth - 1) + 1;

		auto Result = std::find_if(MaterialGenPos.begin(), MaterialGenPos.end(),
			[HeightRandom, WidthRandom](MaterialBlock& BlockData)
			{
				return BlockData.Pos.X == WidthRandom && BlockData.Pos.Y == HeightRandom;
			});
		if (Result != MaterialGenPos.end())
		{
			//������
			continue;
		}

		//32,33,34...
		Position GenPos(WidthRandom, HeightRandom);
		int RandomBlock = rand() % 3 + static_cast<int>(MapBlock::MineralBlock);
		MaterialGenPos.push_back(MaterialBlock(GenPos, static_cast<MapBlock>(RandomBlock)));
		Generated++;
	}
}

void FieldMap::PrintMapMaterial(int InX, int InY)
{
	auto Result = std::find_if(MaterialGenPos.begin(), MaterialGenPos.end(),
		[InX, InY](MaterialBlock& BlockData)
		{
			return BlockData.Pos.X == InX && BlockData.Pos.Y == InY;
		});

	MapBlock Block = (*Result).Block;

	switch (Block)
	{
	case MapBlock::MineralBlock:
		SetBGColor(CC_DARKGRAY);
		printf(" ");
		ResetBgColor();
		break;
	case MapBlock::WoodBlock:
		SetBGColor(CC_DARKYELLOW);
		printf(" ");
		ResetBgColor();
		break;
	case MapBlock::LeatherBlock:
		SetBGColor(CC_DARKMAGENTA);
		printf(" ");
		ResetBgColor();
		break;
	}
}

void FieldMap::CheckMaterialBlock(Position InPos)
{
	//�׳� ��ġ�� �����̸� ����
	auto Result = std::find_if(MaterialGenPos.begin(), MaterialGenPos.end(),
		[InPos](MaterialBlock& BlockData)
		{
			return BlockData.Pos.X == InPos.X && BlockData.Pos.Y == InPos.Y;
		});

	if (Result == MaterialGenPos.end())
		return;

	MapBlock Block = (*Result).Block;

	switch (Block)
	{
	case MapBlock::MineralBlock:
		GameManager::GetInstance().ItemInventory->AddItem(ItemType::Mineral, static_cast<GradeType>(Level));
		GotItem = ItemType::Mineral;
		break;
	case MapBlock::WoodBlock:
		GameManager::GetInstance().ItemInventory->AddItem(ItemType::Wood, static_cast<GradeType>(Level));
		GotItem = ItemType::Wood;
		break;
	case MapBlock::LeatherBlock:
		GameManager::GetInstance().ItemInventory->AddItem(ItemType::Leather, static_cast<GradeType>(Level));
		GotItem = ItemType::Leather;
		break;
	}

	MaterialGenPos.erase(std::remove_if(MaterialGenPos.begin(), MaterialGenPos.end(),
		[InPos](MaterialBlock& BlockData)
		{
			return BlockData.Pos.X == InPos.X && BlockData.Pos.Y == InPos.Y;
		}), MaterialGenPos.end());
}

std::string FieldMap::GetItemString(ItemType InType)
{
	switch (InType)
	{
	default:
		return "";
	case ItemType::Weapon:
		return "����";
	case ItemType::Armor:
		return "����";
	case ItemType::Mineral:
		return "����";
	case ItemType::Leather:
		return "����";
	case ItemType::Wood:
		return "����";
	}
}

void FieldMap::ResetPositionToPrev()
{
	for (int i = 0; i < MapHeight; i++)
	{
		for (int j = 0; j < MapWidth; j++)
		{
			if (Map[i][j] == static_cast<int>(MapBlock::NextField))
			{
				MapManager::GetInstance().UpdatePosition(j - 1, i);
				return;
			}
		}
	}
}
