#include "Monster.h"
#include "GameManager.h"

void Monster::OnHit(int Damage)
{
	Health -= Damage;
	if (Health <= 0)
	{
		IsDead = true;
		GameManager::GetInstance().MonsterDead();
	}
}
