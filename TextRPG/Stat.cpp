#include "Stat.h"

int Stat::GetStat(StatType Type) const
{
	switch (Type)
	{
	default:
		return 0;
	case StatType::Attack:
		return Attack;
	case StatType::Defence:
		return Defence;
	case StatType::Health:
		return Health;
	}
	return 0;
}
