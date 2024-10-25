#include "stdafx.h"
#include "Player.h"
#include "BulletManager.h"
#include "PlayerBullet.h"
#include "PlayerHPBar.h"
#include "GameManager.h"

Player::Player(Stat stat, const std::string& texId, const std::string& name)
	: playerStat(stat),SpriteGameObject(texId)
	, currentReloadTime(0.f)
	, isAttack(true)
	, playerHpbar(nullptr)
	, playerInvincibilityTime(0.5f)
	, currentInvinciblityTime(0.f)
	, isInvincibility(false)
	, isCheat(false)
{
}

void Player::Update(const float& deltaTime)
{
	PlayerMove(deltaTime);

	if (!isAttack)
	{
		currentReloadTime -= deltaTime;
		isAttack = currentReloadTime <= 0.f ? true : false;
	}

	if (isInvincibility)
	{
		currentInvinciblityTime -= deltaTime;

		if (currentInvinciblityTime <= 0.f)
		{
			isInvincibility = false;
			auto color = sprite.getColor();
			color.a = 255;
			sprite.setColor(color);
		}
	}
	
	if (InputManager::GetInstance().GetKeyUp(sf::Keyboard::F1))
	{
		isCheat = !isCheat;
	}

	if (isAttack && InputManager::GetInstance().GetKeyDown(sf::Keyboard::Z))
	{
		Attack();
	}
}

void Player::OnCollisionEnter(Collider* target)
{
}

void Player::OnCollisionStay(Collider* target)
{
}

void Player::OnCollisionEnd(Collider* target)
{
}

void Player::SetPlayerHPBar(PlayerHPBar* hpBar)
{
	playerHpbar = hpBar;
}

PlayerHPBar* Player::GetPlayerHpBar()
{
	return playerHpbar;
}

void Player::PlayerMove(float deltaTime)
{
	if (InputManager::GetInstance().GetKeyDown(sf::Keyboard::Up))
	{
		direction += sf::Vector2f::up;
	}
	if (InputManager::GetInstance().GetKeyDown(sf::Keyboard::Down))
	{
		direction += sf::Vector2f::down;
	}
	if (InputManager::GetInstance().GetKeyDown(sf::Keyboard::Right))
	{
		direction += sf::Vector2f::right;
	}
	if (InputManager::GetInstance().GetKeyDown(sf::Keyboard::Left))
	{
		direction += sf::Vector2f::left;
	}

	if (direction.x == 0.f && direction.y == 0.f)
		return;

	direction.Normalized();
	position.x += direction.x * playerStat.GetSpeed() * deltaTime;
	position.y += direction.y * playerStat.GetSpeed() * deltaTime;

	if (position.x > 1920.f)
		position.x = 1920.f;
	if (position.x < 0.f)
		position.x = 0.f;
	if (position.y > 1080.f)
		position.y = 1080.f;
	if (position.y < 0.f)
		position.y = 0.f;
	SetPosition(position);
	direction = sf::Vector2f::zero;

}

void Player::TakeAttack(int damage)
{
	if (isInvincibility || isCheat)
		return;

	playerStat.hp -= damage;
	isInvincibility = true;
	currentInvinciblityTime = playerInvincibilityTime;

	auto color = sprite.getColor();
	color.a = 120;
	sprite.setColor(color);

	if (playerHpbar != nullptr)
	{
		playerHpbar->SetPlayerHp(playerStat.hp);
	}
	if (playerStat.hp <= 0)
	{
		GameManager::GetInstance().OnGameOver();
	}
}

void Player::Attack()
{
	PlayerBullet* bullet = BulletManager::GetInstance().GetPlayerBulletToAEnabled();

	bullet->SetPosition(position);
	bullet->SetOwner(this);
	bullet->SetDamage(playerStat.damege);
	bullet->Reset();
	bullet->SetBulletSpeed(800.f);
	bullet->SetDir(sf::Vector2f::up);
	bullet->SetActive(true);

	isAttack = false;
	currentReloadTime = playerStat.attakSpeed;
}
