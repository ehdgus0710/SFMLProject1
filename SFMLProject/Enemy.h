#pragma once

#include "SpriteGameObject.h"
#include "Stat.h"

class Bullet;
class Player;

class Enemy : public SpriteGameObject
{
private:
	GameObject* player;
	Stat enemyStat;
	sf::Vector2f moveDirection;
	float currentReloadTime;

	bool isAttack;

public:
	void Attack();
	void CreateBullet();
	void DisableEnemy();
	void SetPlayer(GameObject* player);

	void TakeAttack(int damage);

public:
	void Init() override;
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

