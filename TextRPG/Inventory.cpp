#include "Inventory.h"

Inventory::Inventory()
{
	Gold = 0;
	Items.clear();
}

void Inventory::ShowInventory()
{
	int InputChoice = 0;
	PrintInventory();
	while (InputChoice <= 0)
	{
		if (InputChoice <= 0)
		{
			printf("아이템 선택 : ");
			std::cin >> InputChoice;
			if (InputChoice < 1 || InputChoice > Items.size())
			{
				InputChoice = 0;
				PrintInventory();
				continue;
			}
			
			int Selection = 0;
			if(Items[InputChoice - 1].IsMaterial())
			{
				printf("[1 정보] : ");
				std::cin >> Selection;

				if (Selection != 1)
				{
					InputChoice = 0;
					PrintInventory();
					continue;
				}
				else
				{
					//정보..
					printf("%d번 아이템 정보 : \n", InputChoice);
					InputChoice = 0;
				}
			}
			else
			{
				printf("[1 정보, 2 장착] : ");
				std::cin >> Selection;

				if (Selection == 1)
				{
					printf("%d번 아이템 정보 : \n", InputChoice);
					InputChoice = 0;
				}
				else if (Selection == 2)
				{
					Equip(InputChoice - 1);
					InputChoice = 0;
				}
				else
				{
					InputChoice = 0;
					PrintInventory();
					continue;
				}
			}
		}
	}

	//나감..
	MapManager::GetInstance().ShowMap();

}

void Inventory::AddItem(ItemType InType, GradeType InGrade, int count)
{
	if (Items.empty())
	{
		Items.push_back(Item(InType, InGrade, count));
		return;
	}

	if (InType == ItemType::Weapon || InType == ItemType::Armor)
	{
		Items.push_back(Item(InType, InGrade, count));
		return;
	}

	auto Find = std::find_if(Items.begin(), Items.end(), [InType, InGrade](Item& data) { return data.GetType() == InType && data.GetGrade() == InGrade; });

	if (Find == Items.end())
	{
		Items.push_back(Item(InType, InGrade, count));
	}
	else
	{
		auto item = (*Find);
		if (item.IsMaterial())
		{
			item.AddAmount(count);
		}
		else
		{
			Items.push_back(Item(InType, InGrade, count));
		}
	}
}

void Inventory::AddItem(Item InItem)
{

}

void Inventory::SellItem(int Index)
{
	auto Remove = Items.at(Index);
	Gold += Remove.GetSellPrice();

	Items.erase(Items.begin() + Index);
}

void Inventory::Equip(int Index)
{
	auto Equipment = Items[Index];

	Items.erase(Items.begin() + Index);

	//플레이어에 장착 적용
	GameManager::GetInstance().CurrentPlayer->Equip(Equipment);
}

void Inventory::UnEquip(ItemType InType)
{
	if (InType == ItemType::Weapon)
	{
		bool isSuccess = GameManager::GetInstance().CurrentPlayer->UnEquipWeapon();
		if (isSuccess)
			printf("장착 해제 성공!");
		else
			printf("인벤토리가 꽉 차서 해제 실패.");
	}
	else if(InType == ItemType::Armor)
	{
		bool isSuccess = GameManager::GetInstance().CurrentPlayer->UnEquipArmor();
		if (isSuccess)
			printf("장착 해제 성공!");
		else
			printf("인벤토리가 꽉 차서 해제 실패.");
	}

	printf("장비가 아닙니다.\n");
}

bool Inventory::ConsumeIfEnough(std::vector<Item> Consumes)
{	
	for (Item consume : Consumes)
	{
		auto Enough = std::find_if(Items.begin(), Items.end(), 
			[&consume](Item& findItem)
			{
				return findItem.IsEnough(consume); 
			});
		if (Enough == Items.end())
		{
			return false;
		}
	}

	//소모
	for (Item consume : Consumes)
	{
		if (consume.IsEquip())
			continue;

		auto found = std::find_if(Items.begin(), Items.end(),
			[&consume](Item& Current)
			{
				return consume.GetType() == Current.GetType() && consume.GetGrade() == Current.GetGrade();
			});

		(*found).Use(consume.GetAmount());
	}

	auto Remove = std::remove_if(Items.begin(), Items.end(),
		[](Item& Current)
		{
			return Current.GetAmount() == 0;
		});

	Items.erase(Remove, Items.end());

	return true;
}

bool Inventory::IsFull()
{
	return Items.size() == InventoryMax;
}

bool Inventory::UseGold(int InGold)
{
	if (Gold < InGold)
		return false;

	Gold -= InGold;
	return true;
}
void Inventory::PrintInventory()
{
	system("cls");
	printf("############################################\n");
	printf("#                  Inventory               #\n");
	printf("############################################\n");

	for (int i = 1; i <= 10; i++)
	{
		printf("# %2d. ", i);
		if (i <= Items.size())
			Items[i - 1].PrintItemString();
		else
			printf("[]\t");
		printf("\t%d. ", i + 10);
		if (i + 10 <= Items.size())
			Items[i + 9].PrintItemString();
		else
			printf("[]\t");
		printf("\n");
	}

	printf("############################################\n");
	printf("# Gold : %d                                 \n", Gold);
	printf("############################################\n");

}
