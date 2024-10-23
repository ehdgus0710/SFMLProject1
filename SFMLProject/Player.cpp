#include "stdafx.h"
#include "Player.h"

Player::Player(sf::Sprite player,Stat stat, SpriteGameObject obj)
	:SpriteGameObject(obj), stat(stat), player(player)
{
}

void Player::SetPosition(const sf::Vector2f& pos)
{
	GameObject::SetPosition(pos);
	sprite.setPosition(pos);
}

void Player::Render(sf::RenderWindow& renderWindow)
{
	GameObject::Render(renderWindow);
	renderWindow.draw(sprite);
	
	
}

void Player::Reset()
{
	sprite.setTexture(ResourcesManager<sf::Texture>::GetInstance().Get(" "));
	SetOrigin(originPreset);
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

void Player::Init()
{
	
}

void Player::Release()
{
	
}



void Player::PlayerMove(float dt)
{
	if (InputManager::GetKeyDown)
	{
		
	}
	
}
