#include "Item.h"
#include "Constants.h"

void Item::PrintItemString()
{
    if (IsEquip())
    {
        if (EnforceCount > 0)
            printf("%s(%s)+%d", GetItemNameString().c_str(), GetGradeString().c_str(), EnforceCount);
        else
            printf("%s(%s)", GetItemNameString().c_str(), GetGradeString().c_str());
    }
    else
    {
        printf("%s(%s) x%d", GetItemNameString().c_str(), GetGradeString().c_str(), Amount);
    }
}

void Item::PrintItemStringWithPrice()
{
    PrintItemString();
    printf("-- 판매 : %dG", SellPrice);
}

void Item::PrintItemInfoString()
{
    switch (Type)
    {
    case ItemType::Weapon:
        printf("주로 공격력이 올라가는 무기이다. 왜인지 방어력도 올라간다.\n");
        break;
    case ItemType::Armor:
        printf("주로 방어력이 올라가는 방어구이다. 소량의 체력도 올려준다.\n");
        break;
    case ItemType::Wood:
        printf("단단한 목재이다. 무기를 만드는데 필요할 것 같다.\n");
        break;
    case ItemType::Leather:
        printf("몬스터의 질긴 가죽이다. 방어구 만드는데 필요할 것 같다.\n");
        break;
    case ItemType::Mineral:
        printf("철광석이다. 장비를 만드는데 필요할 것 같다.\n");
        break;
    }
}


std::string Item::GetItemNameString()
{
    switch (Type)
    {
    default:
        return "";
    case ItemType::Weapon:
        return "무기";
    case ItemType::Armor:
        return "갑옷";
    case ItemType::Mineral:
        return "광물";
    case ItemType::Leather:
        return "가죽";
    case ItemType::Wood:
        return "나무";
    }
}

std::string Item::GetGradeString()
{
    switch (Grade)
    {
    default:
        return "";
    case GradeType::Common:
        return "일반";
    case GradeType::Uncommon:
        return "고급";
    case GradeType::Rare:
        return "희귀";
    case GradeType::Unique:
        return "유일";
    case GradeType::Legend:
        return "전설";
    }
}

bool Item::IsEnough(Item item)
{
    return Type == item.GetType() && Grade == item.GetGrade() && Amount >= item.GetAmount();
}

void Item::Use(int InAmount)
{
    Amount -= InAmount;
}

void Item::SetStat(Stat InStat)
{
    StatData = InStat;
}

void Item::InitSellPrice()
{
    if (IsMaterial())
    {
        switch (Grade)
        {
        default:
            SellPrice = 0;
            break;
        case GradeType::Common:
            SellPrice = PriceData::SellMaterialCommon;
            break;
        case GradeType::Uncommon:
            SellPrice = PriceData::SellMaterialUncommon;
            break;
        case GradeType::Rare:
            SellPrice = PriceData::SellMaterialUnique;
            break;
        case GradeType::Unique:
            SellPrice = PriceData::SellMaterialRare;
            break;
        case GradeType::Legend:
            SellPrice = PriceData::SellMaterialLegend;
            break;
        }
    }
    else
    {
        switch (Grade)
        {
        default:
            SellPrice = 0;
            break;
        case GradeType::Common:
            SellPrice = PriceData::SellEquipCommon + PriceData::SellEnforceCommon * EnforceCount;
            break;
        case GradeType::Uncommon:
            SellPrice = PriceData::SellEquipUncommon + PriceData::SellEnforceUncommon * EnforceCount;
            break;
        case GradeType::Rare:
            SellPrice = PriceData::SellEquipRare + PriceData::SellEnforceRare * EnforceCount;
            break;
        case GradeType::Unique:
            SellPrice = PriceData::SellEquipUnique + PriceData::SellEnforceUnique * EnforceCount;
            break;
        case GradeType::Legend:
            SellPrice = PriceData::SellEquipLegend + PriceData::SellEnforceLegend * EnforceCount;
            break;
        }
    }

}
