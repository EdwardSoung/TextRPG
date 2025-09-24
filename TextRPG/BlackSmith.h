#pragma once
#include <vector>
#include "Enums.h";
#include "Item.h"
#include "Inventory.h"
#include "GameManager.h"

class BlackSmith
{
	//���尣 
public:
	bool CraftWeapon(GradeType Grade);
	bool CraftArmor(GradeType Grade);
	
private:
	//���� ��� ��ȯ
	std::vector<Item> GetMaterials(ItemType Type, GradeType Grade);
};

