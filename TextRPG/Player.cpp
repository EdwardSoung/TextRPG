#include "Player.h"

void Player::OnHit(int Damage)
{
	Health -= Damage;
	if (Health <= 0)
	{
		IsDead = true;
		GameManager::PlayerDead();
	}
}