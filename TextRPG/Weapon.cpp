#include "Weapon.h"

void Weapon::PrintItemString()
{
	Item::PrintItemString();
	printf(" x %d", Amount);
}

void Weapon::InitRandomStat()
{
	//����
	//���ݷ�
	//��޿� ���� 1~100 / 50 ~ 150 / 100 ~ 200 / 150 ~ 250 / 200 ~ 300
	//
}
