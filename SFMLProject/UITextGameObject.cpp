#include "stdafx.h"
#include "UITextGameObject.h"


UITextGameObject::UITextGameObject(const std::string& textId, const std::string& name, unsigned int textSize, sf::Color textColor)
	: UIGameObject(name)
	, textId(textId)
	, textSize(textSize)
	, textColor(textColor)
{
}

void UITextGameObject::Init()
{
	text.setFont(ResourcesManager<sf::Font>::GetInstance().Get(textId));
	SetOrigin(originPreset);

	text.setFillColor(textColor);
	text.setCharacterSize(textSize);
	text.setString(textString);
}

void UITextGameObject::Reset()
{
	text.setFont(ResourcesManager<sf::Font>::GetInstance().Get(textId));
	SetOrigin(originPreset);

	text.setFillColor(textColor);
	text.setCharacterSize(textSize);
	text.setString(textString);
}

void UITextGameObject::SetOrigin(Origins preset)
{
	originPreset = preset;
	Utils::SetOrigin(text, preset);
}

void UITextGameObject::SetOrigin(const sf::Vector2f& newOrigin)
{
	originPreset = Origins::Custom;
	origin = newOrigin;
	text.setOrigin(origin);
}

void UITextGameObject::SetPosition(const sf::Vector2f& pos)
{
	UIGameObject::SetPosition(pos);
	text.setPosition(pos);
}

void UITextGameObject::SetString(const std::string& string)
{
	textString = string;
	text.setString(textString);
}

void UITextGameObject::Update(const float& deltaTime)
{
	UIGameObject::Update(deltaTime);
}

void UITextGameObject::FixedUpdate(const float& deltaTime)
{
	UIGameObject::FixedUpdate(deltaTime);
}

void UITextGameObject::LateUpdate(const float& deltaTime)
{
	UIGameObject::LateUpdate(deltaTime);
}

void UITextGameObject::Render(sf::RenderWindow& window)
{
	UIGameObject::Render(window);
	window.draw(text);
}
