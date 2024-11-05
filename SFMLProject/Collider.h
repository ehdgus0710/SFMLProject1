#pragma once

#include "Collision.h"

class Collider
{
private:
	static int		globalCount;
	Collision*		collision;
	GameObject*		owner;
	sf::Vector2f	offsetPosition;
	sf::Vector2f	colliderScale;
	sf::Vector2f	position;
	ColliderLayer	colliderLayer;
	uint64_t		iD;
	int				collisionCount;
	bool			active;
	bool			isDestory;

	std::vector<Collider*> collisionTagetVector;
public:
	Collision* GetCollision() const { return collision; }
	ColliderType GetColliderType();
	uint64_t GetID() const { return iD; }

	ColliderLayer GetColliderLayer() { return colliderLayer; }

	void SetActive(bool active) { this->active = active; isDestory = active;	}
	bool GetActive() const { return active; }
	void SetDestory(bool destory) { isDestory = destory; active = destory; }
	bool GetDestory() { return isDestory; }

	void SetOrigin(sf::Vector2f origin);

	void SetPosition(sf::Vector2f pos);
	void SetScale(sf::Vector2f size);
	sf::Vector2f GetPosition();
	sf::Vector2f GetScale();

	void SetOwner(GameObject* owner) { this->owner = owner; }
	GameObject* GetOwner() { return owner; }


	const std::vector<Collider*>& GetCollisionTarget() { return collisionTagetVector; }
public:

	void CreateCollision(ColliderType colliderType, ColliderLayer layer, sf::Vector2f offset = sf::Vector2f::zero, sf::Vector2f size = sf::Vector2f::one);

	virtual void Render(sf::RenderWindow& renderWindow);
	void OnCollisionEnter(Collider* target);
	void OnCollisionStay(Collider* target);
	void OnCollisionEnd(Collider* target);

public:
	Collider(ColliderType colliderType, ColliderLayer layer, sf::Vector2f offset = sf::Vector2f::zero, sf::Vector2f size = sf::Vector2f::one);
	~Collider();
};
