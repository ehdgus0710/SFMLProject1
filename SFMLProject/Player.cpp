#include "stdafx.h"
#include "Player.h"
#include "Bullet.h"

Player::Player(Stat stat, const std::string& texId, const std::string& name)
	: stat(stat),SpriteGameObject(texId)
{

}




void Player::PlayerMove(Stat st)
{
	sf::Vector2f playerCenter = sf::Vector2f(sprite.getPosition().x / 2, sprite.getPosition().y / 2);

	if(InputManager::GetInstance().GetKeyDown(sf::Keyboard::Up))
	{
		sprite.setPosition(sprite.getPosition()*(sf::Vector2f::up*st.GetSpeed()));
	}
	if (InputManager::GetInstance().GetKeyDown(sf::Keyboard::Down))
	{
		sprite.setPosition(sprite.getPosition()*(sf::Vector2f::down *st.GetSpeed()));
	}
	if (InputManager::GetInstance().GetKeyDown(sf::Keyboard::Right))
	{
		sprite.setPosition(sprite.getPosition() * (sf::Vector2f::right * st.GetSpeed()));
	}
	if (InputManager::GetInstance().GetKeyDown(sf::Keyboard::Left))
	{
		sprite.setPosition(sprite.getPosition() * (sf::Vector2f::left * st.GetSpeed()));
	}

	if (InputManager::GetInstance().GetKeyDown(sf::Keyboard::Z))
	{
		Bullet* b = new Bullet({ 0.f , 0.f }, 1.f, "");
		b->SetPosition(playerCenter);
		b->SetDir(sf::Vector2f::up);
		b->SetBulletSpeed(b->GetBulletSpeed() * TimeManager::GetInstance().GetRealDeltatime());

		if (WindowManager::GetInstance().GetResolutionSize().x < b->GetPosition().x ||
			WindowManager::GetInstance().GetResolutionSize().y < b->GetPosition().y ||
			b->GetPosition().x < 0 || b->GetPosition().y < 0)
		{
			delete b;
		}


	}
}
