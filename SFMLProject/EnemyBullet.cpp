#include "stdafx.h"
#include "EnemyBullet.h"

#include "Collider.h"

void EnemyBullet::Update(const float& deltaTime)
{
	SetPosition(dir * speed + position);

	if (position.x <= -10.f || position.x <= 1930.f
		|| position.y <= -10.f || position.y <= 1100.f)
	{
		SetActive(false);
	}
}

void EnemyBullet::FixedUpdate(const float& deltaTime)
{
}

void EnemyBullet::LateUpdate(const float& deltaTime)
{
}

void EnemyBullet::OnCollisionEnter(Collider* target)
{
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
