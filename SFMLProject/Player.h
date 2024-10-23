#pragma once
#include "SpriteGameObject.h"
#include "Staitus.h"
class Player : public SpriteGameObject
{
private :
	Staitus staitus;
public:
	Player(Staitus staitus, SpriteGameObject obj);
	virtual~Player() = default;

	void SetPosition(const sf::Vector2f& pos) override;
	void Render(sf::RenderWindow& renderWindow) override;
	void Reset() override;

	void Update(const float& deltaTime) override;
	void FixedUpdate(const float& deltaTime) override;
	void LateUpdate(const float& deltaTime) override;
	void SetOrigin(Origins preset) override;
	void SetOrigin(const sf::Vector2f& newOrigin) override;

	void PlayerMove(float dt);
	

};

