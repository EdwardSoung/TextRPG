#include "Weapon.h"

void Weapon::PrintItemString()
{
	Item::PrintItemString();
	printf(" x %d", Amount);
}