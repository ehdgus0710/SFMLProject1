#include "stdafx.h"
#include "SpriteGameObject.h"
#include "Collider.h"


SpriteGameObject::SpriteGameObject(const std::string& texId, const std::string& name)
	:textureId(texId)
	, GameObject(name)
{
	sprite.setTexture(ResourcesManager<sf::Texture>::GetInstance().Get(textureId));
	scale = sprite.getScale();
}


void SpriteGameObject::SetPosition(const sf::Vector2f& pos)
{
	GameObject::SetPosition(pos);
	sprite.setPosition(pos);
}

void SpriteGameObject::SetRotation(const sf::Vector2f& rotation)
{
	GameObject::SetRotation(rotation);
	sprite.setRotation(rotation.y * 180.f);
}

void SpriteGameObject::Render(sf::RenderWindow& renderWindow)
{
	renderWindow.draw(sprite);
	GameObject::Render(renderWindow);
}

void SpriteGameObject::Reset()
{
	sprite.setTexture(ResourcesManager<sf::Texture>::GetInstance().Get(textureId));
	SetOrigin(originPreset);

	if (collider != nullptr)
	{
		collider->SetScale((sf::Vector2f)sprite.getTexture()->getSize() * collider->GetScale());
		collider->SetOrigin((sf::Vector2f)sprite.getTexture()->getSize() * collider->GetScale() *0.5f);
	}
}

void SpriteGameObject::Update(const float& deltaTime)
{
	GameObject::Update(deltaTime);
}

void SpriteGameObject::FixedUpdate(const float& deltaTime)
{
	GameObject::FixedUpdate(deltaTime);
}

void SpriteGameObject::LateUpdate(const float& deltaTime)
{
	GameObject::LateUpdate(deltaTime);
}

void SpriteGameObject::SetOrigin(Origins preset)
{
	originPreset = preset;
	origin = Utils::SetOrigin(sprite, preset);

	if (collider != nullptr)
		collider->SetOrigin(origin);
}

void SpriteGameObject::SetOrigin(const sf::Vector2f& newOrigin)
{
	originPreset = Origins::Custom;
	origin = newOrigin;
	sprite.setOrigin(origin);

	if (collider != nullptr)
		collider->SetOrigin(origin);
}

void SpriteGameObject::SetScale(const sf::Vector2f& scale)
{
	sprite.setScale(scale);
	GameObject::SetScale(scale);

	if (collider != nullptr)
		collider->SetScale(scale);
}
