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
        return "¹«±â";
    case ItemType::Armor:
        return "°©¿Ê";
    case ItemType::Mineral:
        return "±¤¹°";
    case ItemType::Leather:
        return "°¡Á×";
    case ItemType::Wood:
        return "³ª¹«";
    }
}

std::string Item::GetGradeString()
{
    switch (Grade)
    {
    default:
        return "";
    case GradeType::Common:
        return "ÀÏ¹Ý";
    case GradeType::Uncommon:
        return "°í±Þ";
    case GradeType::Rare:
        return "Èñ±Í";
    case GradeType::Unique:
        return "À¯ÀÏ";
    case GradeType::Legend:
        return "Àü¼³";
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
