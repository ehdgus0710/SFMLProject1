#pragma once
#include "GameObject.h"
class SpriteGameObject : public GameObject
{
protected:
	sf::Sprite sprite;
	std::string textureId;
	//sf::Texture

public:
	void SetPosition(const sf::Vector2f& pos) override;
	void Render(sf::RenderWindow& renderWindow) override;
	void Reset() override;

	void Update(const float& deltaTime) override;
	void FixedUpdate(const float& deltaTime) override;
	void LateUpdate(const float& deltaTime) override;
	void SetOrigin(Origins preset) override;
	void SetOrigin(const sf::Vector2f& newOrigin) override;
public:
	SpriteGameObject(const std::string& texId, const std::string& name = "");
	virtual ~SpriteGameObject() = default;
	SpriteGameObject& operator= (const SpriteGameObject& other) = delete;
};

