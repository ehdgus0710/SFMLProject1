#pragma once

#include "Stat.h"

class Enemy;

class EnemyManager : public Singleton<EnemyManager>
{
	friend Singleton<EnemyManager>;
private:
	std::unordered_map<int, Enemy*> enemyMap;

	GameObject*		player;
	sf::Vector2f	createPosition;
	Stat			enemyStat;
	float			respawnTime;
	float			currentCreateTime;

	int				createWidthRange;
	int				respawnCount;
	int				currentCreateIndex;
	int				createEnemyCount;


public:

	void SetEnemyStat(Stat stat) { enemyStat = stat; }
	Stat GetEnemyStat() { return enemyStat; }
	void SetCreateInfo(const sf::Vector2f& createPos, int createWidthRange, float respawnTime, int createCount);
	void SetRespawnCount(int count);
	void SetRespawnTime(float time);
	void SetSubRespawnTime(float time) { respawnTime -= time; }

	void RespwanEnemy();
	void CreateEnemy(const std::string& name, int count);
	void SetDisabledEnemy(const std::string& name);
	Enemy* GetMonsterToAEnabled();

	void SetPlayer(GameObject* player);
	GameObject* GetPlayer() { return player; }

public:
	void Init();
	void Release();
	void Update(float deltaTime);

protected:
	EnemyManager();
	virtual ~EnemyManager() = default;
	EnemyManager(const EnemyManager&) = delete;
	EnemyManager& operator=(const EnemyManager&) = delete;
};

