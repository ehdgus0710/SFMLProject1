#include "stdafx.h"
#include "PlayerHPBar.h"
#include "Player.h"
#include "GameManager.h"

PlayerHPBar::PlayerHPBar(const std::string& texId, sf::Vector2f hpBarSzie)
	: UIGameObject(texId)
	, player(nullptr)
	, hpBarScale(hpBarSzie)
	, playerHp(0)
	, playerMaxHp(0)
{
	hpBar.setFillColor(sf::Color::Red);
	hpBar.setSize(hpBarScale);
}

void PlayerHPBar::SetPlayerHp(int hp)
{
	playerHp = hp;

	if (playerHp < 0)
		playerHp = 0;

	hpBar.setSize({ hpBarScale.x * ((float)playerHp / (float)playerMaxHp), hpBarScale.y });
}

void PlayerHPBar::Render(sf::RenderWindow& renderWindow)
{
	renderWindow.draw(hpBar);
}

void PlayerHPBar::Reset()
{
	hpBar.setFillColor(sf::Color::Red);
	hpBar.setSize(hpBarScale);
	player = GameManager::GetInstance().GetPlayer();
	playerMaxHp = player->Getstat().hp;
	hpBar.setOrigin(origin);
	UIGameObject::Reset();
}

void PlayerHPBar::Update(const float& deltaTime)
{
	if (player != nullptr)
	{
		position = player->GetPosition();
		hpBar.setPosition(position);
	}
}

void PlayerHPBar::SetOrigin(Origins preset)
{
	origin = hpBarScale;
	origin.x *= ((int)preset % 3) * 0.5f;
	origin.y = -(hpBarScale.y * 3.f);

	hpBar.setOrigin(origin);
}

void PlayerHPBar::SetOrigin(const sf::Vector2f& newOrigin)
{
	UIGameObject::SetOrigin(newOrigin);
}

