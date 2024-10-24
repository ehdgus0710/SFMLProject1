#include "stdafx.h"
#include "EnemyManager.h"
#include "Enemy.h"


void EnemyManager::Init()
{
	currentCreateTime = respawnTime;
}

void EnemyManager::SetCreateInfo(const sf::Vector2f& createPos, int createWidthRange, float respawnTime, int respawnCount)
{
	this->createPosition = createPos;
	this->createWidthRange = createWidthRange;
	SetRespawnTime(respawnTime);
	SetRespawnCount(respawnCount);

	currentCreateTime = respawnTime;
}

void EnemyManager::SetRespawnCount(int count)
{
	respawnCount = count;
}

void EnemyManager::SetRespawnTime(float respawnTime)
{
	this->respawnTime = respawnTime;
}

void EnemyManager::RespwanEnemy()
{
	Enemy* enemy;
	for (int i = 0; i < respawnCount; ++i)
	{
		enemy = GetMonsterToAEnabled();
		enemy->Reset();
		enemy->SetPlayer(player);
		enemy->SetActive(true);
		int createWidth = (rand() % createWidthRange) - createWidthRange / 2;
		enemy->SetPosition({ createPosition.x + (float)createWidth, createPosition.y });
	}

	currentCreateTime = respawnTime;
}

void EnemyManager::CreateEnemy(const std::string& name, int count)
{
	for (int i = 0; i < count; ++i)
	{
		enemyMap.insert({ i, new Enemy(name, enemyStat, std::to_string(createEnemyCount)) });
		enemyMap[createEnemyCount]->SetOrigin(Origins::MiddleCenter);
		enemyMap[createEnemyCount]->CreateCollider(ColliderType::Circle, ColliderLayer::Enemy, sf::Vector2f::zero,sf::Vector2f::one * 0.5f);
		enemyMap[createEnemyCount++]->SetActive(false);
	}
}

void EnemyManager::SetDisabledEnemy(const std::string& name)
{
	auto iter = enemyMap.find(std::stoi(name));
	if (iter != enemyMap.end())
	{
		//iter->second->Reset();
	}
}

Enemy* EnemyManager::GetMonsterToAEnabled()
{
	if (currentCreateIndex >= createEnemyCount || enemyMap[currentCreateIndex]->IsActive())
	{
		currentCreateIndex = 0;
		bool isFindNonActiveEnemy = false;

		for (int i = 0; i < createEnemyCount; ++i)
		{
			currentCreateIndex = i;
			if (!enemyMap[i]->IsActive())
			{
				isFindNonActiveEnemy = true;
				break;
			}
		}

		if (!isFindNonActiveEnemy)
		{
			CreateEnemy(enemyMap[0]->GetName(), createEnemyCount);
		}
	}

	SceneManager::GetInstance().GetCurrentScene()->AddGameObject(enemyMap[currentCreateIndex]);
	return enemyMap[currentCreateIndex];
}

void EnemyManager::SetPlayer(GameObject* player)
{
	this->player = player;
}

void EnemyManager::Release()
{
	auto currentScene = SceneManager::GetInstance().GetCurrentScene();

	for (int i = 0; i < createEnemyCount; i++)
	{
		currentScene->RemoveGameObject(enemyMap[i]);
		delete enemyMap[i];
		enemyMap[i] = nullptr;
	}


	createEnemyCount = 0;
	currentCreateIndex = 0;
	currentCreateTime = 0.f;
	respawnCount = 0;
	player = nullptr;
	
	enemyMap.clear();
}

void EnemyManager::Update(float deltaTime)
{
	currentCreateTime -= deltaTime;

	if (currentCreateTime <= 0)
	{
		RespwanEnemy();
	}
}

EnemyManager::EnemyManager()
	: createEnemyCount(0)
	, currentCreateIndex(0)
	, respawnTime(3.f)
	, currentCreateTime(0.f)
	, respawnCount(0)
	, createPosition()
	, createWidthRange(0)
	, player(nullptr)
	, enemyStat()
{
}
