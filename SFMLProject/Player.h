#pragma once
#include "SpriteGameObject.h"
#include "Stat.h"
class Player : public SpriteGameObject
{
private :
	Stat	playerStat;
	sf::Vector2f direction;

	float	currentReloadTime;
	bool	isAttack;

public:
	Player(Stat stat, const std::string& texId, const std::string& name = "");
	virtual~Player() = default;

	Stat Getstat() { return playerStat; };
	void Setstat(Stat st) { playerStat = st; };

	void Update(const float& deltaTime) override;

	void PlayerMove(float deltaTime);
	void Attack();
	

};

