#include "Monster.h"
#include "GameManager.h"

void Monster::OnHit(int Damage)
{
	Health -= Damage;
	printf("[%s] : ������ %d�� �Ծ����ϴ�.\n", Name.c_str(), Damage);
	if (Health <= 0)
	{
		IsDead = true;
		GameManager::GetInstance().MonsterDead();
	}
	else
		printf("[%s] ���� ü�� : %d\n", Name.c_str(), Health);
}