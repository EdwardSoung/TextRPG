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

void Stat::AddStat(StatType Type, int AddValue)
{
	switch (Type)
	{
	default:
		return;
	case StatType::Attack:
		Attack += AddValue;
	case StatType::Defence:
		Defence += AddValue;
	case StatType::Health:
		Health += AddValue;
	}
}

void Stat::AddStat(Stat InStat)
{
	Attack += InStat.GetStat(StatType::Attack);
	Defence += InStat.GetStat(StatType::Defence);
	Health += InStat.GetStat(StatType::Health);
}

void Stat::SubStat(Stat InStat)
{
	Attack -= InStat.GetStat(StatType::Attack);
	Defence -= InStat.GetStat(StatType::Defence);
	Health -= InStat.GetStat(StatType::Health);
}
