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

void Bullet::SetPosition(const sf::Vector2f& pos)
{
}

void Bullet::Render(sf::RenderWindow& renderWindow)
{
}

void Bullet::Reset()
{
	sprite.setTexture(ResourcesManager<sf::Texture>::GetInstance().Get(" "));
	SetOrigin(originPreset);
}

void Bullet::Update(const float& deltaTime)
{
}

void Bullet::FixedUpdate(const float& deltaTime)
{
}

void Bullet::LateUpdate(const float& deltaTime)
{
}

void Bullet::SetOrigin(Origins preset)
{
}

void Bullet::SetOrigin(const sf::Vector2f& newOrigin)
{
}