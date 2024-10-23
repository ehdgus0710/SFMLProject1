#pragma once
#include "SpriteGameObject.h"
class Bullet : public SpriteGameObject
{
private:
	float speed;
	sf::Vector2f dir;
public:
	Bullet(sf::Vector2f dir,float speed, const std::string& texId, const std::string& name = "");
	Bullet(const Bullet& other);
	virtual~Bullet() = default;
	void SetPosition(const sf::Vector2f& pos) override;
	void Render(sf::RenderWindow& renderWindow) override;
	void Reset() override;

	void Update(const float& deltaTime) override;
	void FixedUpdate(const float& deltaTime) override;
	void LateUpdate(const float& deltaTime) override;
	void SetOrigin(Origins preset) override;
	void SetOrigin(const sf::Vector2f& newOrigin) override;

	float GetBulletSpeed() { return speed; };
	sf::Vector2f GetDir() { return dir; };

	void SetBulletSpeed(float spd) { speed = spd; };
	void SetDir(sf::Vector2f d) { dir = d; };


};

