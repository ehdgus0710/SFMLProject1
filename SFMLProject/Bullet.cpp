#include "stdafx.h"
#include "Bullet.h"
#include "Collider.h"
#include "Player.h"

Bullet::Bullet(sf::Vector2f dir, float speed, const std::string& texId, const std::string& name)
	:dir(dir)
	,speed(speed)
	,SpriteGameObject(texId)
	, damage(0)
	, owner(nullptr)
{
}

Bullet::Bullet(const Bullet& other)
	: dir(other.dir)
	, speed(other.speed)
	, SpriteGameObject(other.textureId, other.name)
	, damage(other.damage)
	, owner(other.owner)
{
}

Bullet::~Bullet()
{
	
}

void Bullet::Disable()
{
	if (!active)
		return;

	SetDestory(true);
	SceneManager::GetInstance().GetCurrentScene()->RemoveGameObject(this);
}

void Bullet::Update(const float& deltaTime)
{
	SetPosition(dir * deltaTime * speed + position);

	if (position.x <= -10.f || position.x >= 1930.f
		|| position.y <= -10.f || position.y >= 1100.f)
	{
		Disable();
	}
}

void Bullet::OnCollisionEnter(Collider* target)
{
}

void Bullet::OnCollisionStay(Collider* target)
{
}

void Bullet::OnCollisionEnd(Collider* target)
{
}
