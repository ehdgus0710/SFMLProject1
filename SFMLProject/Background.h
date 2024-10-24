#pragma once
#include "SpriteGameObject.h"
class Background : public SpriteGameObject
{
private:
	sf::Vector2u spriteSize;

	float moveSpeed;
	int moveMax;

public:
	void Update(const float& deltaTime) override;
	void Reset() override;

public:
	Background(const std::string& texId, const std::string& name = "");
	~Background();
};

