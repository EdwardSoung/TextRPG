#pragma once
#include <cstdio>
#include <Windows.h>
#include <vector>
#include <iostream>
#include <vector>
#include "Item.h"
#include "MapManager.h"

//그냥 아이템 목록만 글자로 하자...
//예시
//##########################################
//#           Inventory
//######################################
//# 1.	[광석(희귀) x 100]	11.	[광석(1) x 100]
//# 2.	가죽(1) x 10		12. []
//# 3.	나무(1) x 5		13. []
//# 4.	무기(일반)		14. []
//# 5.	무기(일반)		15. []
//# 6.	무기(일반)		16. []
//# 7.	갑옷(일반)		17. []
//# 8.	갑옷(희귀)		18. []
//# 9.	갑옷(희귀)		19. []
//# 10.	갑옷(희귀)		20. []
//#######################################
//아이템 선택 : 10
//(1 정보, 2 장착) : 1
//[갑옷(희귀) : 방어력 24, HP 322]
//아이템 선택 : 10
//(1 정보, 2 장착) : 2
//아이템을 장착했습니다.
//-> 장착한 아이템이 있으면 얘를 인벤토리로 이동
//재료 선택 시 정보만 볼 수 있음
//인벤토리 최대 20개
//11번 - % 10 해서 정보..?
//for 10번
//printf("# %d.\t%s\t%d.\t%s", i, GetItemString(Inventory[i]), i * 10 + 1, GetItemString(Inventory[i*10+1])); 
class Inventory
{
public:
	Inventory();
	
	void ShowInventory();
	void AddItem(ItemType InType, GradeType InGrade, int count);
	void AddItem(Item* InItem);
	bool SellItem(int Index, int Amount = 1);
	void Equip(int Index);
	void UnEquip(ItemType InType);
	bool ConsumeIfEnough(std::vector<Item> Consumes);
	bool IsFull();
	bool UseGold(int InGold);

	inline const int GetSize() { return Items.size(); }
	inline const std::vector<Item> GetItems() { return Items; }
	inline const int GetGold() { return Gold; }

private:
	void PrintInventory();
	static constexpr int InventoryMax = 20;
	std::vector<Item> Items;
	int Gold = 10000;
};

