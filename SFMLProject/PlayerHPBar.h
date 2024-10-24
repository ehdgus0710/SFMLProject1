#pragma once
#include "UIGameObject.h"

class Player;

class PlayerHPBar : public UIGameObject
{
private:
	Player* player;
	sf::RectangleShape hpBar;

	sf::Vector2f hpBarScale;

	int playerMaxHp;
	int playerHp;

public:
	void SetPlayer(Player* player) { this->player = player; }
	Player* GetPlayer() { return player; }

	void SetPlayerHp(int hp);

public:
	void Render(sf::RenderWindow& renderWindow) override;
	void Reset() override;

	void Update(const float& deltaTime) override;
	void SetOrigin(Origins preset) override;
	void SetOrigin(const sf::Vector2f& newOrigin) override;
public:
	PlayerHPBar(const std::string& texId, sf::Vector2f hpBarSzie);
	virtual ~PlayerHPBar() = default;
	PlayerHPBar& operator= (const PlayerHPBar& other) = delete;
};

