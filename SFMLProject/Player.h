#pragma once
#include "SpriteGameObject.h"
#include "Stat.h"
class Player : public SpriteGameObject
{
private :
	Stat			playerStat;
	sf::Vector2f	direction;
	float			currentReloadTime;
	bool			isAttack;

public:
	Stat Getstat() { return playerStat; };
	void Setstat(Stat st) { playerStat = st; };

	void PlayerMove(float deltaTime);
	void TakeAttack(int damage);
	void Attack();

public:

	void Update(const float& deltaTime) override;
	void OnCollisionEnter(Collider* target) override;
	void OnCollisionStay(Collider* target) override;
	void OnCollisionEnd(Collider* target) override;
public:
	Player(Stat stat, const std::string& texId, const std::string& name = "");
	virtual~Player() = default;
};

