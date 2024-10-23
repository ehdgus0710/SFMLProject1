#include "stdafx.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Player.h"
#include "EnemyManager.h"

Enemy::Enemy(const std::string& texId, Stat stat, const std::string& name)
	: SpriteGameObject(texId, name)
	, enemyStat(stat)
	, bulletPrefab(nullptr)
	, player(nullptr)
{
	//bulletPrefab = new Bullet();

	currentReloadTime = enemyStat.GetAttakSpeed();
	moveDirection = sf::Vector2f::down;
}

Enemy::~Enemy()
{
	if(nullptr != bulletPrefab)
		delete bulletPrefab;
}

void Enemy::Attack()
{
	if (position.y > 1080.f || player == nullptr)
		return;

	CreateBullet();
}

void Enemy::CreateBullet()
{
	//Bullet* bullet = new Bullet(*bulletPrefab);
	//currentReloadTime = enemyStat.GetAttakSpeed();
	//sf::Vector2f direction = GetPosition() - player->GetPosition();
	//direction.Normalized();
	//bullet->SetDir(direction);
}

void Enemy::DisableEnemy()
{
	SetActive(false);
}

void Enemy::Init()
{
	SpriteGameObject::Init();
	player = EnemyManager::GetInstance().GetPlayer();	
}

void Enemy::Update(const float& deltaTime)
{
	currentReloadTime -= deltaTime;

	if (currentReloadTime <= 0.f)
		Attack();

	position += moveDirection * enemyStat.GetSpeed() * deltaTime;
	SetPosition(position);

	if (position.y > 1200.f)
		DisableEnemy();
}

void Enemy::FixedUpdate(const float& deltaTime)
{
}

void Enemy::LateUpdate(const float& deltaTime)
{
}
