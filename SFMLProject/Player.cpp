#include "stdafx.h"
#include "Player.h"

Player::Player(sf::Sprite player,Stat stat, const std::string& texId, const std::string& name)
	: stat(stat), player(player),SpriteGameObject(name)
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
	sprite.setTexture(ResourcesManager<sf::Texture>::GetInstance().Get(textureId));
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



void Player::PlayerMove(Stat st)
{
	if(InputManager::GetInstance().GetKeyDown(sf::Keyboard::Up))
	{
		sprite.move(sf::Vector2f::up*st.GetSpeed());
	}
	if (InputManager::GetInstance().GetKeyDown(sf::Keyboard::Down))
	{
		sprite.move(sf::Vector2f::down * st.GetSpeed());
	}
	if (InputManager::GetInstance().GetKeyDown(sf::Keyboard::Right))
	{
		sprite.move(sf::Vector2f::right * st.GetSpeed());
	}
	if (InputManager::GetInstance().GetKeyDown(sf::Keyboard::Left))
	{
		sprite.move(sf::Vector2f::left * st.GetSpeed());
	}

	if (InputManager::GetInstance().GetKeyDown(sf::Keyboard::Z))
	{
	
	}
	
}
