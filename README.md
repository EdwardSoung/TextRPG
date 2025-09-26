# Gacha World!

#### 목차
- [게임 설명](###-게임-설명)<br>
- [등급](###-등급)<br>
- [재료 아이템](###-재료-아이템)<br>
- [사냥터 정보](###-사냥터-정보)<br>
- [캐릭터의 사망](###-캐릭터의-사망)<br>
- [코드 설명](#-코드-설명)<br>

---
### 게임 설명
  1. **기본 키 입력**
     - 방향 : w(위) , s(아래), a(왼쪽), d(오른쪽)
     - 인벤토리 : i
     - 캐릭터 정보 : p
  2. **마을** : 마을에서 건물 4종 및 사냥터로 이동할 수 있다.
     <br>
     <img width="397" height="402" alt="마을" src="https://github.com/user-attachments/assets/a389eb4b-56f7-43e9-9361-55e93f65fbf7" />
     <br>
    **1) 신전(Temple)** : 기도 공간으로 이동하면 일정 금액을 내고 10% 확률로 체력을 회복한다.
     <br>
     <img width="350" height="383" alt="신전" src="https://github.com/user-attachments/assets/82d9f350-e8cd-4366-b087-aaa43be0f1f4" />
     <br>
    **2) 상점(Shop)** : 판매 공간으로 이동 시 인벤토리 보유 아이템을 판매할 수 있다.
      <br>
      <img width="392" height="429" alt="상점" src="https://github.com/user-attachments/assets/452ba4f8-df1e-4254-ae8a-0e0f572392a0" />
      <br>
    **3) 강화(Enforce)** : 장착하고 있는 장비를 등급 별 확률에 따라 강화할 수 있다. (무기 / 갑옷 공간에 따라 선택)
      <br>
      <img width="359" height="378" alt="장비강화" src="https://github.com/user-attachments/assets/860ee55f-7b99-4cf3-9090-b834b9d34585" />
      <br>
    **4) 대장간(BlackSmith)** : 등급 별 확률에 따라 장비를 제작할 수 있다.(재료 필요, 무기 / 갑옷 공간에 따라 선택)
       <br>
      <img width="360" height="415" alt="대장간" src="https://github.com/user-attachments/assets/e75b7798-4e74-47fb-aa01-d0617c5c97f0" />
      <br>
    **5) 인벤토리(Inventory)** : 보유한 아이템(장착 제외)을 보여준다. 최대 20개
     - 아이템 인덱스로 선택 후 정보 확인 가능
     - 장비 아이템의 경우 장착 가능(장착 장비 존재 시 Swap)
     - 재료는 동일 등급 중복 보유 가능. 장비는 중복보유 불가
      <br>
      <img width="394" height="344" alt="인벤토리" src="https://github.com/user-attachments/assets/7b163813-01a4-425a-93a6-ebba40159504" />
      <br><br>
      **6) 캐릭터 정보** : 캐릭터 이름, 스탯과 장착한 장비 정보를 보여준다.
      <br>
      <img width="387" height="339" alt="플레이어 정보" src="https://github.com/user-attachments/assets/a468342c-3573-4ef0-b011-8147bb63a2a1" />
      <br>

### 등급
> 사냥터, 장비, 재료, 몬스터에 사용되며, 높을 수록 강해진다.
1. 장비 및 재료 등급
  - 일반(Common)
  - 고급(Uncommon)
  - 희귀(Rare)
  - 유일(Unique)
  - 전설(Legend)
2. 몬스터 등급
  - 일반
  - 병사(Soldier)
  - 사령관(Commander)
  - 장군(Warlord)
  - 왕(King)

### 재료 아이템
>재료 아이템을 모아 동일 등급의 장비를 제작할 수 있다.
1. 광석(Minearal)
2. 나무(Wood)
3. 가죽(Leather)

### 사냥터 정보
- 난이도는 등급과 동일하게 올라가며, 난이도에 해당하는 등급의 재료가 랜덤 드랍된다.(4개)
<img width="365" height="420" alt="재료 획득" src="https://github.com/user-attachments/assets/9035a442-314f-4aa0-9635-b504d4b89e22" />
<br>
- 이동 시 10% 확률로 몬스터와 마주치고, 전투가 진행된다.

### 캐릭터의 사망
- 사망 시 마을로 자동 이동한다.
- 사망 시 인벤토리 아이템 중 하나를 개수와 상관없이 **"무조건"** 드랍한다.
- 아이템이 없을 시 드랍하지 않는다.
<br>
<img width="393" height="204" alt="플레이어 사망" src="https://github.com/user-attachments/assets/34f96f87-c716-4fdf-8277-f4991a5f88bc" />
<br>
<br>

# 코드 설명
#### 1. Managing
 - GameManager : 게임 진행과 전투를 관리한다. 사망, 생성 관리
 - MapManager : 지역 이동과 플레이어의 현재 위치를 관리한다.
#### 2. Map 데이터 파일
- 각 지역별 VillageMap, ShopMap, TempleMap, EnforceMap, BlackSmithMap, FieldMap
- MapData를 상속받는다.
- 지도별 표기 및 이동에 따른 조건을 관리한다.
  예시) : 신전에서 기도 위치에 도달했는지 체크.
- 맵 이동 시 다음 맵 시작 위치로 플레이어 위치 갱신
#### 3. Player/Monster
- Actor를 상속받아 사용한다.
- 공격/데미지 처리 및 장비, 스탯 정보를 담고 있다.
#### 4. Popup
- 인벤토리, 캐릭터 정보 화면
- 화면을 바꿨다가 돌아가는 경우를 Popup으로 명명
