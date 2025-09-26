#include "Actor.h"
#include "MapManager.h"

void Actor::Attack(Actor* Target)
{
	int TargetDef = Target->GetStat(StatType::Defence);
	int Damage = BaseStat.GetStat(StatType::Attack) - TargetDef;
	//최소 데미지
	if (Damage <= 0)
		Damage = 1;

	Target->OnHit(Damage);
}


