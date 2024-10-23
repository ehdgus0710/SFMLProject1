#pragma once

class Collision;
class Collider;

class ColliderManager : public Singleton<ColliderManager>
{
	friend Singleton<ColliderManager>;
private:
	std::unordered_map<std::string, bool> collisionMap;

	// �ӽ�
	std::vector<std::vector<Collider*>> colliderVector;
	std::vector<std::vector<bool>> collisionCheckVector;

public:
	void Init();
	void Update();

	void Release();
	//bool isCo

	void LayerCollision(int left, int right);
	bool CheckCollision(Collider* left, Collider* right);
	void SetCollisionCheck(ColliderLayer left, ColliderLayer right);

	void AddCollider(Collider* newCollision, ColliderLayer layer);

	bool IsPointToPointCollision(Collider* left, Collider* right);
	bool IsRectToRectCollision(Collider* left, Collider* right);
	bool IsCircleToCircleCollision(Collider* left, Collider* right);

	bool IsCircleToRectCollision(Collider* left, Collider* right);
	bool IsPointToRectCollision(Collider* left, Collider* right);
	bool IsCircleToPointCollision(Collider* left, Collider* right);

protected:
	ColliderManager();
	~ColliderManager() override {};
	ColliderManager(const ColliderManager&) = delete;
	ColliderManager& operator=(const ColliderManager&) = delete;
};

