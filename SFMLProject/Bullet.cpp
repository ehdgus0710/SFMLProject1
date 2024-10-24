#include "stdafx.h"
#include "Bullet.h"

Bullet::Bullet(sf::Vector2f dir, float speed, const std::string& texId, const std::string& name)
	:dir(dir),speed(speed),SpriteGameObject(texId)
{
}

Bullet::Bullet(const Bullet& other)
	: dir(other.dir)
	, speed(other.speed)
	, SpriteGameObject(other.textureId, other.name)
{
}

Bullet::~Bullet()
{
	
}

void Bullet::Update(const float& deltaTime)
{
	SetPosition(dir * deltaTime * speed + position);

	if (position.x <= -10.f || position.x >= 1930.f
		|| position.y <= -10.f || position.y >= 1100.f)
	{
		SetActive(false);
		SceneManager::GetInstance().GetCurrentScene()->RemoveGameObject(this);
	}
}