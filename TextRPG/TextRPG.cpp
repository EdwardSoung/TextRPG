
#include <iostream>
#include <Windows.h>
#include <vector>
#include "Inventory.h"
#include "GameManager.h"
#include "MapManager.h"
#include "BlackSmithMap.h"

int main()
{
    //std::cout << "Hello World!\n";

   // Inventory inven;
   // inven.AddItem(ItemType::Weapon, GradeType::Common, 5);
   // inven.AddItem(ItemType::Leather, GradeType::Uncommon, 10);
   // inven.AddItem(ItemType::Wood, GradeType::Uncommon, 10);
 

   //// inven.SellItem(2);

   // std::vector<Item> items;
   // items.push_back(Item(ItemType::Wood, GradeType::Uncommon, 10));
   // items.push_back(Item(ItemType::Leather, GradeType::Uncommon, 10));

   // if (inven.ConsumeIfEnough(items))
   //     printf("재료 충분");

   // inven.ShowInventory();
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

//1. 캐릭터창 - 스탯 + 인벤토리
//2. 맵 - 마을, 던전(2개 ? )
//3. 마을 - 상점, 치료, 강화
//4. 던전 단계별로 2종(쉬움, 어려움) - 쉬움 몬스터 난이도별 3종, 어려움 3종
//5. 몬스터 맵에서 돌아다니게 ? (옵션), 몬스터 일정 개수 밑으로 떨어지면 랜덤 위치 재생성


//class
//플레이어
//스탯
//무기
//갑옷

//아이템
//골드
//몬스터별로 나오는 아이템 - 이름/판매금액
//아이템은 몬스터 잡으면 확률로 획득...

//던전 -> v (마을
//치료 (t)
//마을 신전 가면 (t글자) 치료 하겠냐는 텍스트
//100골드 무조건 풀로 채워줌.
//상점 (s) : 무기/갑옷 구매
//쉬운 던전 (e)
//어려운 던전 (h)
//강화 f : 스탯
// 

//맵, UI 구조는 txt로 만들어놓고...

//크기 40 * 18...

//마을 : 파랑
//신전 : 녹색
//강화 : 주황
//상점 : 노랑
//인벤 : 흰색
//벽   : 다크 그레이?
//########################################
//v                                      #
//#                                      #
//#                                      #
//#                                      #
//#                                      #
//#                                      #
//#                                      #
//#                                      #
//#                                      #
//#                                      #
//#                                      #
//#                                      #
//#                                      #
//#                                      #
//#                                      #
//#                                      #
//########################################

// 
//
//########################################
//#             Village                  #
//###################e####################
//#                #   #                 # 
//#                #   #                 #   
//#    Temple      #   #     Enforce     #  
//#                #   #                 #
//#                t   f                 #  
//##################   ###################
//#                                      h
//##################    ##################
//#                s    I                #
//#                #    #                # 
//#      Shop      #    #     Storage    #
//#                #    #                #
//#                #    #                #
//########################################
// 
// 
// 
//########################################
//#               Temple                 #
//########################################
//#                                      #
//#      Lv.1  oooooooooo (100/100)      #
//#                                      #
//########################################
//#                                      #
//#                                      #
//#                                      #
//#                                      #
//#                                      #
//#                                      #
//#                                      #
//#                                      #
//#                                      #
//#                                      #
//#                                      v
//########################################
//기도 : 10골드 내고 5% 확률로 체력 회복
//예시
//신전 들어가면 맵 다 클리어하고
//****************
//*    신전
//* 1. 치료 (100G)
//* 2. 나가기
//***************
//* 보유 골드 : %d
//***************
//선택 : 1
//골드가 부족합니다.  //치료되었습니다.
// 
// 
//인벤토리 누르면 맵을 덮어 써서 인벤토리
//아이템
//정보

//***********************************
//*           강화
//***********************************
//*Name : %s
//*STR : %d
//*DEF : %d
//*HP  : %d
//***********************************
//*1. 무기
//*Name : %s
//*STR : %d
//*DEF : %d
//*HP  : %d
//*1. 갑옷
//*Name : %s
//*STR : %d
//*DEF : %d
//*HP  : %d
//************************************

//************************************
//#            Inventory
//#***********************************
//#  1.%s\t\tx%d
//#  2.%s
//#  3. 
//#  4.
//#  5.
//#  Gold : 100
//#  
//#  
//#
//#
//#
//####################################