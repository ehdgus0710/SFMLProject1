#include "stdafx.h"
#include "Collision.h"

void Collision::Init()
{
}

void Collision::Update()
{
	//collionSprite.setPosition(position);
}

void Collision::Render(sf::RenderWindow& renderWindow)
{
}

void Collision::SetScale(sf::Vector2f size)
{
}

Collision::Collision(ColliderType colliderType)
	: colliderType(colliderType)
	, collisionCount(0)
{
	//
}
