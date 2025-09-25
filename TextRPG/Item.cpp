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
    printf("-- �Ǹ� : %dG", SellPrice);
}

void Item::PrintItemInfoString()
{
    switch (Type)
    {
    case ItemType::Weapon:
        printf("�ַ� ���ݷ��� �ö󰡴� �����̴�. ������ ���µ� �ö󰣴�.\n");
        break;
    case ItemType::Armor:
        printf("�ַ� ������ �ö󰡴� ���̴�. �ҷ��� ü�µ� �÷��ش�.\n");
        break;
    case ItemType::Wood:
        printf("�ܴ��� �����̴�. ���⸦ ����µ� �ʿ��� �� ����.\n");
        break;
    case ItemType::Leather:
        printf("������ ���� �����̴�. �� ����µ� �ʿ��� �� ����.\n");
        break;
    case ItemType::Mineral:
        printf("ö�����̴�. ��� ����µ� �ʿ��� �� ����.\n");
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
