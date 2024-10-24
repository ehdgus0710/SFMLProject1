#pragma once
#include "SpriteGameObject.h"
#include "Stat.h"

class PlayerHPBar;

class Player : public SpriteGameObject
{
private :
	PlayerHPBar*	playerHpbar;
	Stat			playerStat;
	sf::Vector2f	direction;
	float			currentReloadTime;

	float			playerInvincibilityTime;
	float			currentInvinciblityTime;

	bool			isCheat;
	bool			isInvincibility;
	bool			isAttack;

public:
	void SetPlayerHPBar(PlayerHPBar* hpBar);
	PlayerHPBar* GetPlayerHpBar();

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

