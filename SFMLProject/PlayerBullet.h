#pragma once
#include "Bullet.h"
class PlayerBullet : public Bullet
{
public:
	void OnCollisionEnter(Collider* target) override;
	void OnCollisionStay(Collider* target) override;
	void OnCollisionEnd(Collider* target) override;
public:
	PlayerBullet(sf::Vector2f dir, float speed, const std::string& texId, const std::string& name = "");
	PlayerBullet(const Bullet& other);
	virtual~PlayerBullet() = default;
};

