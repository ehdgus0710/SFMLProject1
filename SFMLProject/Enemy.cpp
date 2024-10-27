#include "stdafx.h"
#include "Enemy.h"
#include "EnemyBullet.h"
#include "Player.h"
#include "EnemyManager.h"
#include "Collider.h"

#include "BulletManager.h"
#include "GameManager.h"

Enemy::Enemy(const std::string& texId, Stat stat, const std::string& name)
	: SpriteGameObject(texId, name)
	, enemyStat(stat)
	, player(nullptr)
	, isAttack(false)
	, currentHitEffectTime(0.f)
	, HitEffectTime(0.5f)
	, isHit(false)
	, attackOneReloadTime(0.5f)
	, attackThreeReloadTime(0.1f)
	, attackThreeAngle(0.f)
	, attackPattern(0)
	, maxAttackPattern(4)
	, attackFourReloadTime(0.05f)
{
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

	//CreateBullet();
	AttackPattern(attackPattern);
}


void Enemy::AttackPattern(uint64_t pos)
{
	switch (pos)
	{
	case 0:
		Attack1();
		break;
	case 1:
		Attack2();
		break;
	case 2:
		Attack3();
		break;
	case 3:
		Attack4();
		break;
	default:
		break;
	}
}

void Enemy::Attack1()
{
	EnemyBullet* bullet = BulletManager::GetInstance().GetEnemyBulletToAEnabled();
	sf::Vector2f direction = player->GetPosition() - position;

	bullet->SetDestory(false);
	bullet->SetPosition(position);
	direction.Normalized();
	bullet->SetDamage(enemyStat.damege);
	bullet->Reset();
	bullet->SetOwner(this);
	bullet->SetDir(direction);
	bullet->SetBulletSpeed(400.f);
	bullet->SetActive(true);

	currentReloadTime = 3;
}

void Enemy::Attack2()
{
	for (int i = 0; i <= 10; i++)
	{
		EnemyBullet* bullet = BulletManager::GetInstance().GetEnemyBulletToAEnabled();
		sf::Vector2f direction{ cosf(36.f * (float)i) , sinf(36.f * (float)i) };
		bullet->SetPosition(position);

		bullet->SetDamage(enemyStat.damege);
		bullet->Reset();
		bullet->SetOwner(this);
		bullet->SetDir(direction);
		bullet->SetBulletSpeed(400.f);
		bullet->SetActive(true);
	}

	currentReloadTime = enemyStat.GetAttakSpeed();
}

void Enemy::Attack3()
{
	EnemyBullet* bullet = BulletManager::GetInstance().GetEnemyBulletToAEnabled();

	if (attackThreeAngle >= 360.f)
		attackThreeAngle = 0.f;

	sf::Vector2f direction{ cosf(attackThreeAngle) , sinf(attackThreeAngle) };
	bullet->SetPosition(position);
	bullet->SetDamage(enemyStat.damege);
	bullet->Reset();
	bullet->SetOwner(this);
	bullet->SetDir(direction);
	bullet->SetBulletSpeed(400.f);
	bullet->SetActive(true);
	attackThreeAngle += 36.f;

	currentReloadTime = attackThreeReloadTime;
}

void Enemy::Attack4()
{
	EnemyBullet* bullet = BulletManager::GetInstance().GetEnemyBulletToAEnabled();

	if (attackThreeAngle >= 360.f)
		attackThreeAngle = 0.f;

	sf::Vector2f direction{ cosf(attackThreeAngle) , sinf(attackThreeAngle) };
	bullet->SetPosition(position);
	bullet->SetDamage(enemyStat.damege);
	bullet->Reset();
	bullet->SetOwner(this);
	bullet->SetDir(direction);
	bullet->SetBulletSpeed(400.f);
	bullet->SetActive(true);
	attackThreeAngle += 5.f;

	currentReloadTime = attackFourReloadTime;
}
void Enemy::SetAttackPattern(uint64_t attackNumber)
{
	attackPattern = attackNumber % maxAttackPattern;

	switch (attackPattern)
	{
	case 0:
		currentReloadTime = attackOneReloadTime;
		break;
	case 1:
		currentReloadTime = enemyStat.GetAttakSpeed();
		break;
	case 2:
		currentReloadTime = attackThreeReloadTime;
		break;
	case 3:
		currentReloadTime = attackFourReloadTime;
		break;
	default:
		break;
	}
}
void Enemy::CreateBullet()
{

	for (int i = 0; i <= 10; i++)
	{
		EnemyBullet* bullet = BulletManager::GetInstance().GetEnemyBulletToAEnabled();
		//sf::Vector2f direction = GetPosition() - player->GetPosition();
		//direction.Normalized();

		sf::Vector2f direction{ cosf(36.f * (float)i) , sinf(36.f * (float)i) };
		bullet->SetPosition(position);

		bullet->SetDamage(enemyStat.damege);
		bullet->Reset();
		bullet->SetOwner(this);
		bullet->SetDir(direction);
		bullet->SetBulletSpeed(400.f);
		bullet->SetActive(true);
	}
	
	currentReloadTime = enemyStat.GetAttakSpeed();
}

void Enemy::DisableEnemy()
{
	sprite.setColor(sf::Color(255, 255, 255, 255));
	collider->SetDestory(true);
	SceneManager::GetInstance().GetCurrentScene()->RemoveGameObject(this);
}

void Enemy::SetPlayer(GameObject* player)
{ 
	this->player = player;
}

void Enemy::TakeAttack(int damage)
{
	enemyStat.hp -= damage;

	isHit = true;
	currentHitEffectTime = HitEffectTime;

	sprite.setColor(sf::Color(200,0,0,120));

	if (enemyStat.hp <= 0)
	{
		DisableEnemy();
		GameManager::GetInstance().AddScore(10);
	}
}

void Enemy::Init()
{
	SpriteGameObject::Init();
	player = EnemyManager::GetInstance().GetPlayer();	
}

void Enemy::Reset()
{
	SpriteGameObject::Reset();
	
	SetRotation(moveDirection);
	enemyStat = EnemyManager::GetInstance().GetEnemyStat();
}

void Enemy::Update(const float& deltaTime)
{
	currentReloadTime -= deltaTime;

	if (!isAttack && currentReloadTime <= 0.f)
		Attack();
	if (isHit)
	{
		currentHitEffectTime -= deltaTime;

		if (currentHitEffectTime <= 0.f)
		{
			isHit = false;
			sprite.setColor(sf::Color(255, 255, 255, 255));
		}
	}

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

void Enemy::OnCollisionEnter(Collider* target)
{
	if (target->GetOwner() != this && target->GetColliderLayer() == ColliderLayer::Player)
	{
		((Player*)target->GetOwner())->TakeAttack(1);
	}
}

void Enemy::OnCollisionStay(Collider* target)
{
}

void Enemy::OnCollisionEnd(Collider* target)
{
}
