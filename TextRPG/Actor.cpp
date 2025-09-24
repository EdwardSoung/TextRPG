#include "Actor.h"
#include "MapManager.h"

void Actor::Attack(Actor& Target)
{
	int Damage = BaseStat.GetStat(StatType::Attack) - Target.BaseStat.GetStat(StatType::Defence);

	//최소 데미지
	if (Damage <= 0)
		Damage = 1;

	Target.OnHit(Damage);
}


