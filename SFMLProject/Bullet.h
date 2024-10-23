#pragma once
#include "SpriteGameObject.h"
class Bullet : public SpriteGameObject
{
private:
	float speed;
	sf::Vector2f dir;
public:

	void SetPosition(const sf::Vector2f& pos) override;
	void Render(sf::RenderWindow& renderWindow) override;
	void Reset() override;

	void Update(const float& deltaTime) override;
	void FixedUpdate(const float& deltaTime) override;
	void LateUpdate(const float& deltaTime) override;
	void SetOrigin(Origins preset) override;
	void SetOrigin(const sf::Vector2f& newOrigin) override;
};

