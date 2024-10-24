#include "stdafx.h"
#include "Background.h"

void Background::Update(const float& deltaTime)
{
	position.y += deltaTime * moveSpeed;

	if (position.y > spriteSize.y + moveMax)
	{
		sprite.setPosition(position.x, (float)spriteSize.y * -0.5f);
		position.y = (float)spriteSize.y * -0.5f;
	}
	else
	{
		sprite.setPosition(position);
	}
}

void Background::Reset()
{
	SpriteGameObject::Reset();
	auto size = TEXTURE_MANAGER.Get("Map").getSize();
	spriteSize = size;
	moveMax = spriteSize.y / 2;
}

Background::Background(const std::string& texId, const std::string& name)
	: SpriteGameObject(texId, name)
	, moveSpeed(300.f)
	, moveMax(0)
{
}

Background::~Background()
{
}
