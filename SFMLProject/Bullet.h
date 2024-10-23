#pragma once
#include "SpriteGameObject.h"
class Bullet : public SpriteGameObject
{
protected:
	float speed;

	sf::Vector2f dir;

public:
	Bullet(sf::Vector2f dir,float speed, const std::string& texId, const std::string& name = "");
	Bullet(const Bullet& other);
	~Bullet();
	float GetBulletSpeed() { return speed; };
	sf::Vector2f GetDir() { return dir; };
	void Update(const float& deltaTime) override;

	void SetBulletSpeed(float spd) { speed = spd; };
	void SetDir(sf::Vector2f d) { dir = d; };


};

