#include "BlackSmithMap.h"

bool BlackSmithMap::CraftWeapon(GradeType InGrade)
{
    if (GameManager::GetInstance().ItemInventory->IsFull())
    {
        printf("인벤토리가 가득 찼습니다.\n");
        return false;
    }

    auto materials = GetCraftMaterials(ItemType::Weapon, InGrade);
    if (GameManager::GetInstance().ItemInventory->ConsumeIfEnough(materials))
    {
        //만들어서 인벤토리 저장
        int random = rand() % 10000;
        
        if (random < GetCraftRate(InGrade))
        {
            //10%
            GameManager::GetInstance().ItemInventory->AddItem(new Weapon(InGrade));
            printf("무기 제작에 성공했습니다!\n");
            //무기정보..
            return true;
        }
        else
        {
            printf("무기 제작에 실패했습니다!\n");            
        }

        return false;
    }
    else
    {
        printf("재료가 부족합니다.\n");
    }

    return false;
}

bool BlackSmithMap::CraftArmor(GradeType InGrade)
{
    if (GameManager::GetInstance().ItemInventory->IsFull())
    {
        printf("Inventory is Full\n");
        return false;
    }

    auto materials = GetCraftMaterials(ItemType::Armor, InGrade);
    if (GameManager::GetInstance().ItemInventory->ConsumeIfEnough(materials))
    {
        //만들어서 인벤토리 저장
        int CraftRandom = rand() % 10000;

        if (CraftRandom < GetCraftRate(InGrade))
        {
            //10%
            GameManager::GetInstance().ItemInventory->AddItem(new Armor(InGrade));
            printf("갑옷 제작에 성공했습니다!\n");
            return true;
        }
        else
        {
            printf("갑옷 제작에 실패했습니다!\n");
        }

        return false;
    }
    else
    {
        printf("재료가 부족합니다.\n");
    }

    return false;
}

int BlackSmithMap::GetCraftRate(GradeType InGrade)
{
    switch (InGrade)
    {
    case GradeType::Common:
        return RateData::CraftCommon;
    case GradeType::Uncommon:
        return RateData::CraftUncommon;
    case GradeType::Rare:
        return RateData::CraftRare;
    case GradeType::Unique:
        return RateData::CraftUnique;
    case GradeType::Legend:
        return RateData::CraftrLegend;
    }

    return 0;
}

void BlackSmithMap::ShowMap()
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
    
    int Input = 0;

    if (GetMapBlock(PlayerPos) == static_cast<int>(MapBlock::WeaponCraft))
    {
        while (Input < 2)
        {
            printf("[1.무기 제작, 2. 나가기]\n");
            printf("메뉴 선택 : ");
            std::cin >> Input;

            if (Input == 1)
            {
                int GradeInput = 0;
                while (GradeInput < 1 || GradeInput > 5)
                {
                    printf("[1:Common, 2:Uncommon, 3:Rare, 4:Unique, 5:Legend]\n");
                    printf("제작 등급 선택 : \n");
                    std::cin >> GradeInput;

                    if (GradeInput < 0)
                        break;

                    if (GradeInput >= 1 && GradeInput <= 5)
                        CraftWeapon(static_cast<GradeType>(GradeInput));
                }
            }
            else if (Input == 2)
                ResetPosition(MapState::BlackSmith);
        }

    }
    else if (GetMapBlock(PlayerPos) == static_cast<int>(MapBlock::ArmorCraft))
    {
        while (Input < 2)
        {
            printf("[1.무기 제작, 2. 나가기]\n");
            printf("메뉴 선택 : ");
            std::cin >> Input;

            if (Input == 1)
            {
                int GradeInput = 0;
                while (GradeInput < 1 || GradeInput > 5)
                {
                    printf("[1:Common, 2:Uncommon, 3:Rare, 4:Unique, 5:Legend]\n");
                    printf("제작 등급 선택 : \n");
                    std::cin >> GradeInput;

                    if (GradeInput < 0)
                        break;

                    if (GradeInput >= 1 && GradeInput <= 5)
                        CraftArmor(static_cast<GradeType>(GradeInput));
                }
            }
            else if (Input == 2)
                ResetPosition(MapState::BlackSmith);
        }
    }
    else
        ShowDirectionInfo();
}

void BlackSmithMap::ResetPosition(MapState PrevMap)
{
    for (int i = 0; i < MapHeight; i++)
    {
        for (int j = 0; j < MapWidth; j++)
        {
            if (Map[i][j] == static_cast<int>(MapBlock::Village))
            {
                MapManager::GetInstance().UpdatePosition(j + 1, i);
                return;
            }
        }
    }
}

int BlackSmithMap::GetMapBlock(Position InPos)
{
    return Map[InPos.Y][InPos.X];
}

void BlackSmithMap::Move(char Input)
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

void BlackSmithMap::CheckPosAndChangeMap(int InBlock)
{
    if (InBlock == 0) return;

    MapBlock BlockItem = static_cast<MapBlock>(InBlock);

    if (BlockItem == MapBlock::Village)
    {
        system("cls");    
        MapManager::GetInstance().ChangeMap(MapState::Village);
    }
}

std::vector<Item> BlackSmithMap::GetCraftMaterials(ItemType Type, GradeType Grade)
{
    std::vector<Item> materials;

    if (Type == ItemType::Weapon)
        materials.push_back(Item(ItemType::Wood, Grade, 10 * static_cast<int>(Grade)));
    else if (Type == ItemType::Armor)
        materials.push_back(Item(ItemType::Leather, Grade, 10 * static_cast<int>(Grade)));
    
    materials.push_back(Item(ItemType::Mineral, Grade, 10 * static_cast<int>(Grade)));

    //무기이면 광물 + 나무
    //갑옷이면 광물 + 가죽
    return materials;
}
