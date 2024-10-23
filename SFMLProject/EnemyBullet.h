#pragma once

#include "Bullet.h"

class EnemyBullet : public Bullet
{
public:
	void Update(const float& deltaTime) override;
	void FixedUpdate(const float& deltaTime) override;
	void LateUpdate(const float& deltaTime) override;

	void OnCollisionEnter(Collider* target) override;
	void OnCollisionStay(Collider* target) override;
	void OnCollisionEnd(Collider* target) override;
public:
	EnemyBullet(sf::Vector2f dir, float speed, const std::string& texId, const std::string& name = "");
	EnemyBullet(const Bullet& other);
	virtual~EnemyBullet() = default;

};

