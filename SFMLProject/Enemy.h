#pragma once

#include "SpriteGameObject.h"
#include "Stat.h"

class Bullet;

class Enemy : public SpriteGameObject
{
private:
	Stat enemyStat;
	sf::Vector2f moveDirection;
	Bullet* bulletPrefab;
	float currentReloadTime;
	GameObject* player;
	

public:
	void Attack();
	void CreateBullet();
	void DisableEnemy();

public:
	void Init() override;
	void Update(const float& deltaTime) override;
	void FixedUpdate(const float& deltaTime) override;
	void LateUpdate(const float& deltaTime) override;
public:
	Enemy(const std::string& texId, Stat stat, const std::string& name = "");
	~Enemy();
};

