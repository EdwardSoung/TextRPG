#include "Armor.h"
#include "Constants.h"

int Armor::GetEnforcePrice()
{
	switch (Grade)
	{
	case GradeType::Common:
		return PriceData::EnforceCommon;
	case GradeType::Uncommon:
		return PriceData::EnforceUncommon;
	case GradeType::Rare:
		return PriceData::EnforceRare;
	case GradeType::Unique:
		return PriceData::EnforceUnique;
	case GradeType::Legend:
		return PriceData::EnforceLegend;
	}

	return 0;
}

int Armor::GetEnforceRate()
{
	switch (Grade)
	{
	case GradeType::Common:
		return RateData::EnForceCommon;
	case GradeType::Uncommon:
		return RateData::EnforceUncommon;
	case GradeType::Rare:
		return RateData::EnforceRare;
	case GradeType::Unique:
		return RateData::EnforceUnique;
	case GradeType::Legend:
		return RateData::EnforceLegend;
	}

	return 0;
}

void Armor::RandomEnforce()
{
	int TypeRandom = rand() % 3;
	StatType type = static_cast<StatType>(TypeRandom);
	int StatValue = rand() % GetStatRangeValue();

	StatData.AddStat(type, StatValue);

	EnforceCount++;
}

void Armor::InitRandomStat()
{
	int Attack = 0;
	int Defence = 0;
	int Health = 0;
	switch (Grade)
	{
	case GradeType::Common:
		Defence = rand() % 100 + 1;
		Health = rand() % 10;
		break;
	case GradeType::Uncommon:
		Defence = rand() % 100 + 50;
		Health = rand() % 15;
		break;
	case GradeType::Rare:
		Defence = rand() % 100 + 100;
		Health = rand() % 20;
		break;
	case GradeType::Unique:
		Defence = rand() % 100 + 150;
		Health = rand() % 25;
		break;
	case GradeType::Legend:
		Defence = rand() % 100 + 200;
		Health = rand() % 30;
		break;
	}


	StatData = Stat(Attack, Defence, Health);
}

int Armor::GetStatRangeValue()
{
	switch (Grade)
	{
	case GradeType::Common:
		return RangeData::EnForceCommon;
	case GradeType::Uncommon:
		return RangeData::EnforceUncommon;
	case GradeType::Rare:
		return RangeData::EnforceRare;
	case GradeType::Unique:
		return RangeData::EnforceUnique;
	case GradeType::Legend:
		return RangeData::EnforceLegend;
	}

	return 0;
}
