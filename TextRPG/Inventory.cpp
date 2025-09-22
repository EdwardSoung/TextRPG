#include "Inventory.h"

void Inventory::ShowInventory()
{
	printf("##########################################\n");
	printf("#                Inventory               #\n");
	printf("##########################################\n");

	for (int i = 1; i <= 10; i++)
	{
		printf("# %d.\t", i);
		Items[i - 1].PrintItemString();
		printf("\t%d.\t", i + 10);
		Items[i + 9].PrintItemString();
		printf("\n");
	}

	printf("##########################################\n");

}

void Inventory::AddItem(ItemType InType, GradeType InGrade)
{
	//
}
