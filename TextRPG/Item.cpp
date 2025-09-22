#include "Item.h"

void Item::PrintItemString()
{
    printf("%s(%s)", GetItemNameString().c_str(), GetGradeString().c_str());
}


std::string Item::GetItemNameString()
{
    switch (Type)
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

std::string Item::GetGradeString()
{
    switch (Grade)
    {
    default:
        return "";
    case GradeType::Common:
        return "�Ϲ�";
    case GradeType::Uncommon:
        return "���";
    case GradeType::Rare:
        return "���";
    case GradeType::Unique:
        return "����";
    case GradeType::Legend:
        return "����";
    }
}

void Item::InitSellPrice()
{
    switch (Grade)
    {
    default:
        SellPrice = 0;
        break;
    case GradeType::Common:
        SellPrice = 10;
        break;
    case GradeType::Uncommon:
        SellPrice = 30;
        break;
    case GradeType::Rare:
        SellPrice = 70;
        break;
    case GradeType::Unique:
        SellPrice = 150;
        break;
    case GradeType::Legend:
        SellPrice = 300;
        break;
    }
}
