#pragma once

#include "SpriteGameObject.h"
#include "Stat.h"

class Bullet;
class Player;

class Enemy : public SpriteGameObject
{
private:
	GameObject*		player;
	Stat			enemyStat;
	sf::Vector2f	moveDirection;
	float			currentReloadTime;

	float			attackOneReloadTime;
	float			attackThreeReloadTime;
	float			attackThreeAngle;
	float			attackFourReloadTime;

	float			currentHitEffectTime;
	float			HitEffectTime;
	bool			isHit;
	bool			isAttack;

	uint64_t		attackPattern;
	uint64_t		maxAttackPattern;

public:
	void Attack();
	void CreateBullet();
	void DisableEnemy();
	void SetPlayer(GameObject* player);

	void TakeAttack(int damage);

	void AttackPattern(uint64_t pos);

	void Attack1();
	void Attack2();
	void Attack3();
	void Attack4();

	void SetAttackPattern(uint64_t attackNumber);
public:
	void Init() override;
	void Reset() override;
	void Update(const float& deltaTime) override;
	void FixedUpdate(const float& deltaTime) override;
	void LateUpdate(const float& deltaTime) override;

	void OnCollisionEnter(Collider* target) override;
	void OnCollisionStay(Collider* target) override;
	void OnCollisionEnd(Collider* target) override;
public:
	Enemy(const std::string& texId, Stat stat, const std::string& name = "");
	~Enemy();
};

