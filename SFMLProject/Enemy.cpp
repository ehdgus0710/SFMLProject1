#include "stdafx.h"
#include "Enemy.h"
#include "EnemyBullet.h"
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
		EnemyBullet* bullet = BulletManager::GetInstance().GetEnemyBulletToAEnabled();
		//sf::Vector2f direction = GetPosition() - player->GetPosition();
		//direction.Normalized();

		sf::Vector2f direction{ cosf(36.f * (float)i) , sinf(36.f * (float)i) };
		bullet->SetPosition(position);

		bullet->SetDamage(enemyStat.damege);
		bullet->Reset();
		bullet->SetOwner(this);
		bullet->SetDir(direction);
		bullet->SetBulletSpeed(200.f);
		bullet->SetActive(true);
	}
	
	currentReloadTime = enemyStat.GetAttakSpeed();
}

void Enemy::DisableEnemy()
{
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

	if (enemyStat.hp <= 0)
		DisableEnemy();
}

void Enemy::Init()
{
	SpriteGameObject::Init();
	player = EnemyManager::GetInstance().GetPlayer();	
}

void Enemy::Reset()
{
	SpriteGameObject::Reset();
	enemyStat = EnemyManager::GetInstance().GetEnemyStat();
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

void Enemy::OnCollisionEnter(Collider* target)
{
}

void Enemy::OnCollisionStay(Collider* target)
{
}

void Enemy::OnCollisionEnd(Collider* target)
{
}
