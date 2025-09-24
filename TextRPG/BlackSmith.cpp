#include "BlackSmith.h"

bool BlackSmith::CraftWeapon(GradeType Grade)
{
    if (GameManager::GetInstance().ItemInventory->IsFull())
    {
        printf("Inventory is Full\n");
        return false;
    }

    auto materials = GetMaterials(ItemType::Weapon, Grade);
    if (GameManager::GetInstance().ItemInventory->ConsumeIfEnough(materials))
    {
        //���� �κ��丮 ����
        int random = rand() % 10000;
        
        if (random < 1000)
        {
            //10%
            GameManager::GetInstance().ItemInventory->AddItem(ItemType::Weapon, Grade, 1);
            return true;
        }

        return false;
    }
    else
    {
        printf("��ᰡ �����մϴ�.\n");
    }

    return false;
}

bool BlackSmith::CraftArmor(GradeType Grade)
{
    if (GameManager::GetInstance().ItemInventory->IsFull())
    {
        printf("Inventory is Full\n");
        return false;
    }

    auto materials = GetMaterials(ItemType::Armor, Grade);
    if (GameManager::GetInstance().ItemInventory->ConsumeIfEnough(materials))
    {
        //���� �κ��丮 ����
        int random = rand() % 10000;

        if (random < 1000)
        {
            //10%
            GameManager::GetInstance().ItemInventory->AddItem(ItemType::Armor, Grade, 1);
            return true;
        }

        return false;
    }
    else
    {
        printf("��ᰡ �����մϴ�.\n");
    }

    return false;
}

std::vector<Item> BlackSmith::GetMaterials(ItemType Type, GradeType Grade)
{
    std::vector<Item> materials;

    if (Type == ItemType::Weapon)
        materials.push_back(Item(ItemType::Wood, Grade, 10 * static_cast<int>(Grade)));
    else if (Type == ItemType::Armor)
        materials.push_back(Item(ItemType::Leather, Grade, 10 * static_cast<int>(Grade)));
    
    materials.push_back(Item(ItemType::Mineral, Grade, 10 * static_cast<int>(Grade)));

    //�����̸� ���� + ����
    //�����̸� ���� + ����
    return materials;
}
