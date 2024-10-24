#include "stdafx.h"
#include "PlayerBullet.h"
#include "Collider.h"
#include "Enemy.h"

void PlayerBullet::OnCollisionEnter(Collider* target)
{
	if (target->GetOwner() != owner && target->GetColliderLayer() == ColliderLayer::Enemy)
	{
		((Enemy*)target->GetOwner())->TakeAttack(damage);
		Disable();
	}
}

void PlayerBullet::OnCollisionStay(Collider* target)
{
}

void PlayerBullet::OnCollisionEnd(Collider* target)
{
}

PlayerBullet::PlayerBullet(sf::Vector2f dir, float speed, const std::string& texId, const std::string& name)
	: Bullet(dir, speed, texId, name)
{
}

PlayerBullet::PlayerBullet(const Bullet& other)
	: Bullet(other)
{
}
