#include "stdafx.h"
#include "Player.h"
#include "Bullet.h"
#include "BulletManager.h"

Player::Player(Stat stat, const std::string& texId, const std::string& name)
	: playerStat(stat),SpriteGameObject(texId)
	, currentReloadTime(0.f)
	, isAttack(true)

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

	if (isAttack && InputManager::GetInstance().GetKeyUp(sf::Keyboard::Z))
	{
		Attack();
	}
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

	SetPosition(position);
	direction = sf::Vector2f::zero;

}

void Player::Attack()
{
	Bullet* bullet = BulletManager::GetInstance().GetBulletToAEnabled();

	bullet->SetPosition(position);
	bullet->Reset();
	bullet->SetBulletSpeed(100.f);
	bullet->SetDir(sf::Vector2f::up);
	bullet->SetActive(true);

	isAttack = false;
	currentReloadTime = playerStat.attakSpeed;
}
