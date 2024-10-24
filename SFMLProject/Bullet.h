#pragma once
#include "SpriteGameObject.h"
class Bullet : public SpriteGameObject
{
protected:
	GameObject*		owner;

	sf::Vector2f	dir;
	float			speed;
	int				damage;

public:
	void SetOwner(GameObject* owner) { this->owner = owner; }
	GameObject* GetOwner() { return owner; }

	void SetBulletSpeed(float spd) { speed = spd; };
	float GetBulletSpeed() { return speed; };
	void SetDir(sf::Vector2f d) { dir = d; };
	sf::Vector2f GetDir() { return dir; };

	void SetDamage(int damage) { this->damage = damage; }
	int GetDamage() { return damage; }

	void Disable();

public:
	void Update(const float& deltaTime) override;
	void OnCollisionEnter(Collider* target) override;
	void OnCollisionStay(Collider* target) override;
	void OnCollisionEnd(Collider* target) override;

public:
	Bullet(sf::Vector2f dir, float speed, const std::string& texId, const std::string& name = "");
	Bullet(const Bullet& other);
	~Bullet();
};

