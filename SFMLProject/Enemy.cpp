#include "stdafx.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Player.h"
#include "EnemyManager.h"
#include "Collider.h"

#include "BulletManager.h"

Enemy::Enemy(const std::string& texId, Stat stat, const std::string& name)
	: SpriteGameObject(texId, name)
	, enemyStat(stat)
	, player(nullptr)
	, isAttack(false)
{
	//bulletPrefab = new Bullet();

	currentReloadTime = enemyStat.GetAttakSpeed();
	moveDirection = sf::Vector2f::down;
}

Enemy::~Enemy()
{
}

void Enemy::Attack()
{
	if (position.y > 1080.f || player == nullptr)
		return;

	CreateBullet();
}

void Enemy::CreateBullet()
{

	for (int i = 0; i <= 10; i++)
	{
		Bullet* bullet = BulletManager::GetInstance().GetBulletToAEnabled();
		//sf::Vector2f direction = GetPosition() - player->GetPosition();
		//direction.Normalized();

		sf::Vector2f direction{ cosf(36.f * (float)i) , sinf(36.f * (float)i) };
		bullet->SetPosition(position);
		bullet->SetDir(direction);
		bullet->SetActive(true);
		bullet->GetCollider()->SetActive(true);
	}

	

	currentReloadTime = enemyStat.GetAttakSpeed();
}

void Enemy::DisableEnemy()
{
	SetActive(false);
}

void Enemy::SetPlayer(GameObject* player)
{ 
	this->player = player;
}

void Enemy::Init()
{
	SpriteGameObject::Init();
	player = EnemyManager::GetInstance().GetPlayer();	
}

void Enemy::Update(const float& deltaTime)
{
	currentReloadTime -= deltaTime;

	if (!isAttack && currentReloadTime <= 0.f)
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
