#include "stdafx.h"

#include "CollisionRectangle.h"

CollisionRectangle::CollisionRectangle(sf::Vector2f size)
	: rectangleSize(size)
	, rectanglePosition(size)
	, Collision(ColliderType::Rectangle)
	, rectanleRender(size)
{
	rectanleRender.setOutlineColor(sf::Color::Green);
}

CollisionRectangle::~CollisionRectangle()
{
}

void CollisionRectangle::Update()
{
	Collision::Update();
}

void CollisionRectangle::Render(sf::RenderWindow& renderWindow)
{
	if (collisionCount > 0)
		rectanleRender.setOutlineColor(sf::Color::Red);
	else
		rectanleRender.setOutlineColor(sf::Color::Green);

	renderWindow.draw(rectanleRender);
}

void CollisionRectangle::SetSize(sf::Vector2f size)
{
	rectangleSize = size;
}

