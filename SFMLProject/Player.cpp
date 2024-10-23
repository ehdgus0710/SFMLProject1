#include "stdafx.h"
#include "Player.h"

Player::Player(Staitus staitus, SpriteGameObject obj)
	:SpriteGameObject(obj), staitus(staitus)
{
}

void Player::SetPosition(const sf::Vector2f& pos)
{
	
}

void Player::Render(sf::RenderWindow& renderWindow)
{

}

void Player::Reset()
{
}

void Player::Update(const float& deltaTime)
{
}

void Player::FixedUpdate(const float& deltaTime)
{
}

void Player::LateUpdate(const float& deltaTime)
{
}

void Player::SetOrigin(Origins preset)
{
}

void Player::SetOrigin(const sf::Vector2f& newOrigin)
{
}

void Player::PlayerMove(float dt)
{
}
