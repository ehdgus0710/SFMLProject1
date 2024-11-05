#pragma once

#include "Collision.h"

struct Rectangle
{
	float leftPosition;
	float rightPosition;
	float topPosition;
	float bottomPosition;

	Rectangle(float left, float rgiht, float top, float bottom)
		: leftPosition(left)
		, rightPosition(rgiht)
		, topPosition(top)
		, bottomPosition(bottom)
	{

	}

	Rectangle(sf::Vector2f position, sf::Vector2f size)
		: leftPosition(position.x - size.x * 0.5f)
		, rightPosition(position.x + size.x * 0.5f)
		, topPosition(position.y - size.y * 0.5f)
		, bottomPosition(position.y + size.y * 0.5f)
	{

	}
};


class CollisionRectangle : public Collision
{
private:
	sf::Vector2f rectangleSize;
	sf::RectangleShape rectanleRender;

public:
	void Init() override;

	void Update() override;
	virtual void Render(sf::RenderWindow& renderWindow);

	void SetSize(sf::Vector2f size);

	Rectangle GetRectangle() { return Rectangle(position, rectanleRender.getSize()); }
	sf::Vector2f GetScale() const override { return rectanleRender.getSize(); }
	void SetPosition(const sf::Vector2f& pos) override;
	void SetOrigin(const sf::Vector2f& origin) override;

	sf::Vector2f GetLeftTopPosition() { return { GetLeftPosition(),GetTopPosition() }; }
	sf::Vector2f GetRightBottomPosition() { return { GetRightPosition(),GetBottomPosition() }; }
	sf::Vector2f GetRightTopPosition() { return { GetRightPosition(),GetTopPosition() }; }
	sf::Vector2f GetLeftBottomPosition() { return { GetLeftPosition(),GetBottomPosition() }; }

	float GetLeftPosition() { return position.x - rectanleRender.getSize().x * 0.5f; }
	float GetRightPosition() { return position.x + rectanleRender.getSize().x * 0.5f; }
	float GetTopPosition() { return  position.y - rectanleRender.getSize().y * 0.5f; }
	float GetBottomPosition() { return position.y + rectanleRender.getSize().y * 0.5f; }


public:
	CollisionRectangle(sf::Vector2f size = sf::Vector2f::one);
	~CollisionRectangle();

};

