#include "Monster.h"
#include "GameManager.h"

void Monster::OnHit(int Damage)
{
	Health -= Damage;
	printf("[%s] : 데미지 %d를 입었습니다.\n", Name.c_str(), Damage);
	if (Health <= 0)
	{
		IsDead = true;
		GameManager::GetInstance().MonsterDead();
	}
	else
		printf("[%s] 남은 체력 : %d\n", Name.c_str(), Health);
}