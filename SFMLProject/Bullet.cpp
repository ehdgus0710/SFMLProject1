#include "stdafx.h"
#include "Bullet.h"

Bullet::Bullet(Stat stat,sf::Vector2f dir, float speed, const std::string& texId, const std::string& name)
	:stat(stat),dir(dir),speed(speed),SpriteGameObject(texId)
{
}

Bullet::Bullet(const Bullet& other)
	: dir(other.dir)
	, speed(other.speed)
	, stat(other.stat)
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

void Bullet::UpMove()
{
	sprite.move(dir.up * GetBulletSpeed());
}

void Bullet::DownMove()
{
	sprite.move(dir.down * GetBulletSpeed());
}
