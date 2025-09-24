#pragma once
#include <vector>
#include "Enums.h";
#include "Item.h"
#include "Inventory.h"
#include "GameManager.h"

class BlackSmith
{
	//대장간 
public:
	bool CraftWeapon(GradeType Grade);
	bool CraftArmor(GradeType Grade);
	
private:
	//제작 재료 반환
	std::vector<Item> GetMaterials(ItemType Type, GradeType Grade);
};

