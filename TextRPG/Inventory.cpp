#include "Inventory.h"

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

}

void Inventory::AddItem(ItemType InType, GradeType InGrade, int count)
{
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

void Inventory::SellItem(int Index)
{
	auto Remove = Items.at(Index);
	Gold += Remove.GetSellPrice();

	Items.erase(Items.begin() + Index);
}

void Inventory::Equip(int Index)
{
	auto Equipment = Items[Index];

	//플레이어에 장착 적용

	Items.erase(Items.begin() + Index);
}

bool Inventory::ConsumeIfEnough(std::vector<Item> Consumes)
{	
	for (Item consume : Consumes)
	{
		auto Enough = std::find_if(Items.begin(), Items.end(), [consume](Item& findItem) {return findItem.IsEnough(consume); });
		if (Enough == Items.end())
		{
			return false;
		}
	}

	return true;
}

bool Inventory::IsFull()
{
	return Items.size() == InventoryMax;
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
