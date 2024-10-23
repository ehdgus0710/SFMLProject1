#pragma once
#include "SpriteGameObject.h"
#include "Stat.h"
class Player : public SpriteGameObject
{
private :
	Stat stat;
	sf::Sprite player;
public:
	Player(sf::Sprite player ,Stat stat, const std::string& texId, const std::string& name = "");
	virtual~Player() = default;

	Stat Getstat() { return stat; };
	void Setstat(Stat st) { stat = st; };

	void SetPosition(const sf::Vector2f& pos) override;
	void Render(sf::RenderWindow& renderWindow) override;
	void Reset() override;

	void Update(const float& deltaTime) override;
	void FixedUpdate(const float& deltaTime) override;
	void LateUpdate(const float& deltaTime) override;
	void SetOrigin(Origins preset) override;
	void SetOrigin(const sf::Vector2f& newOrigin) override;

	void Init() override;
	void Release() override;


	void PlayerMove(float dt);
	

};

