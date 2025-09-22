#pragma once
#include <cstdio>
#include <Windows.h>
#include "Item.h"

//�׳� ������ ��ϸ� ���ڷ� ����...
//����
//##########################################
//#           Inventory
//######################################
//# 1.	[����(���) x 100]	11.	[����(1) x 100]
//# 2.	����(1) x 10		12. []
//# 3.	����(1) x 5		13. []
//# 4.	����(�Ϲ�)		14. []
//# 5.	����(�Ϲ�)		15. []
//# 6.	����(�Ϲ�)		16. []
//# 7.	����(�Ϲ�)		17. []
//# 8.	����(���)		18. []
//# 9.	����(���)		19. []
//# 10.	����(���)		20. []
//#######################################
//������ ���� : 10
//(1 ����, 2 ����) : 1
//[����(���) : ���� 24, HP 322]
//������ ���� : 10
//(1 ����, 2 ����) : 2
//�������� �����߽��ϴ�.
//-> ������ �������� ������ �긦 �κ��丮�� �̵�
//��� ���� �� ������ �� �� ����
//�κ��丮 �ִ� 20��
//11�� - % 10 �ؼ� ����..?
//for 10��
//printf("# %d.\t%s\t%d.\t%s", i, GetItemString(Inventory[i]), i * 10 + 1, GetItemString(Inventory[i*10+1])); 
class Inventory
{
public:
	
	void ShowInventory();
	void AddItem(ItemType InType, GradeType InGrade);
	void SellItem(int Index);

private:
	static constexpr int InventoryMax = 20;
	Item Items[InventoryMax];
};

