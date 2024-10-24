#include "stdafx.h"
#include "EnemyBullet.h"
#include "Player.h"

#include "Collider.h"

void EnemyBullet::Update(const float& deltaTime)
{
	Bullet::Update(deltaTime);
}
void EnemyBullet::OnCollisionEnter(Collider* target)
{
	if (target->GetOwner() != owner && target->GetColliderLayer() == ColliderLayer::Player)
	{
		((Player*)target->GetOwner())->TakeAttack(damage);
		Disable();
	}
}

void EnemyBullet::OnCollisionStay(Collider* target)
{
}

void EnemyBullet::OnCollisionEnd(Collider* target)
{
}

EnemyBullet::EnemyBullet(sf::Vector2f dir, float speed, const std::string& texId, const std::string& name)
	: Bullet(dir, speed, texId, name)
{
}

EnemyBullet::EnemyBullet(const Bullet& other)
	: Bullet(other)
{
}
