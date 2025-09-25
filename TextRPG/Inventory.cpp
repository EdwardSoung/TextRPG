#include "Inventory.h"

Inventory::Inventory()
{
	//Gold = 0;
	Items.clear();
}

void Inventory::ShowInventory()
{
	int InputChoice = 0;
	PrintInventory();
	while (InputChoice >= 0)
	{
		if (InputChoice == 0)
		{
			printf("������ ���� (������ -1) : ");
			std::cin >> InputChoice;
			if (InputChoice < 0)
				continue;

			if (InputChoice > Items.size())
			{
				InputChoice = 0;
				PrintInventory();
				continue;
			}
			
			int Selection = 0;
			if(Items[InputChoice - 1].IsMaterial())
			{
				printf("���� [1 ����] : ");
				std::cin >> Selection;

				if (Selection != 1)
				{
					InputChoice = 0;
					PrintInventory();
					continue;
				}
				else
				{
					//����..
					printf("%d�� ������ ����\n", InputChoice);
					Items[InputChoice - 1].PrintItemInfoString();
					InputChoice = 0;
				}
			}
			else
			{
				printf("���� [1 ����, 2 ����] : ");
				std::cin >> Selection;

				if (Selection == 1)
				{
					printf("%d�� ������ ����\n", InputChoice);
					Items[InputChoice - 1].PrintItemInfoString();
					printf("-------------------------\n");
					Items[InputChoice - 1].PrintItemString();
					printf("\n");
					printf("���ݷ� : %d\n", Items[InputChoice - 1].GetStatValue(StatType::Attack));
					printf("���� : %d\n", Items[InputChoice - 1].GetStatValue(StatType::Defence));
					printf("ü��   : %d\n", Items[InputChoice - 1].GetStatValue(StatType::Health));
					printf("-------------------------\n");
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

	//����..
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

void Inventory::AddItem(Item* InItem)
{
	Items.push_back(*InItem);
}

bool Inventory::SellItem(int Index, int Amount)
{
	if (Index > Items.size())
	{
		printf("�߸��� �κ��丮 �������Դϴ�.\n");
		return false;
	}
	auto Remove = &Items[Index - 1];
	int SoldGold = Remove->GetSellPrice() * Amount;
	Remove->AddAmount(-Amount);
	Gold += SoldGold;

	if(Remove->GetAmount() <= 0)
		Items.erase(Items.begin() + (Index - 1));

	return true;
}

void Inventory::Equip(int Index)
{
	auto Equipment = Items[Index];

	Items.erase(Items.begin() + Index);

	//�÷��̾ ���� ����
	GameManager::GetInstance().CurrentPlayer->Equip(Equipment);
	ShowInventory();
}

void Inventory::UnEquip(ItemType InType)
{
	if (InType == ItemType::Weapon)
	{
		bool isSuccess = GameManager::GetInstance().CurrentPlayer->UnEquipWeapon();
		if (isSuccess)
			printf("���� ���� ����!");
		else
			printf("�κ��丮�� �� ���� ���� ����.");
	}
	else if(InType == ItemType::Armor)
	{
		bool isSuccess = GameManager::GetInstance().CurrentPlayer->UnEquipArmor();
		if (isSuccess)
			printf("���� ���� ����!");
		else
			printf("�κ��丮�� �� ���� ���� ����.");
	}

	printf("��� �ƴմϴ�.\n");
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

	//�Ҹ�
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
