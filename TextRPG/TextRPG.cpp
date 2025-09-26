
#include <iostream>
#include <Windows.h>
#include <vector>
#include "Inventory.h"
#include "GameManager.h"
#include "MapManager.h"
#include "BlackSmithMap.h"

int main()
{
    //기본 아이템 지급
    auto& gameManager = GameManager::GetInstance();
    gameManager.GetInstance().Init();
    gameManager.GetInstance().ItemInventory->AddItem(ItemType::Mineral, GradeType::Common, 10);
    gameManager.GetInstance().ItemInventory->AddItem(ItemType::Wood, GradeType::Common, 10);
    Weapon* TempWeapon = new Weapon(GradeType::Common);
    gameManager.GetInstance().ItemInventory->AddItem(TempWeapon);
    
    auto& mapManger = MapManager::GetInstance();
    
    mapManger.ChangeMap(MapState::Village);

    delete TempWeapon;
}