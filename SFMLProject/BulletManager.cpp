#include "stdafx.h"
#include "BulletManager.h"
#include "Bullet.h"
#include "EnemyBullet.h"
#include "PlayerBullet.h"

BulletManager::BulletManager()
    : currentEnemyBulletIndex(0)
    , createEnemyBulletCount(0)
	, createPlayerBulletCount(0)
	, currentPlayerBulletIndex(0)
{
}

void BulletManager::CreateEnemyBullet(const std::string& name, int count)
{
	for (int i = 0; i < count; ++i)
	{
		enemyBulletMap.insert({ createEnemyBulletCount, new EnemyBullet(sf::Vector2f::zero, 50.f, "Bullet", std::to_string(currentEnemyBulletIndex)) });
		enemyBulletMap[createEnemyBulletCount]->CreateCollider(ColliderType::Circle, ColliderLayer::EnemyBullet, sf::Vector2f::zero);
		enemyBulletMap[createEnemyBulletCount++]->SetActive(false);
	}
}

void BulletManager::CreatePlayerBullet(const std::string& name, int count)
{
	for (int i = 0; i < count; ++i)
	{
		playerBulletMap.insert({ createPlayerBulletCount, new PlayerBullet(sf::Vector2f::zero, 50.f, "Bullet",std::to_string(currentPlayerBulletIndex)) });
		playerBulletMap[createPlayerBulletCount]->CreateCollider(ColliderType::Circle, ColliderLayer::PlayerBullet, sf::Vector2f::zero);
		playerBulletMap[createPlayerBulletCount++]->SetActive(false);
	}
}

void BulletManager::SetDisabledEnemyBullet(const std::string& name)
{
	auto iter = enemyBulletMap.find(std::stoi(name));
	if (iter != enemyBulletMap.end())
	{
		//iter->second->Reset();
	}
}

void BulletManager::SetDisabledPlayerBullet(const std::string& name)
{
	auto iter = playerBulletMap.find(std::stoi(name));
	if (iter != playerBulletMap.end())
	{
		//iter->second->Reset();
	}
}

EnemyBullet* BulletManager::GetEnemyBulletToAEnabled()
{
	if (currentEnemyBulletIndex >= createEnemyBulletCount || enemyBulletMap[currentEnemyBulletIndex]->IsActive())
	{
		currentEnemyBulletIndex = 0;
		bool isFindNonActiveEnemy = false;

		for (int i = 0; i < createEnemyBulletCount; ++i)
		{
			currentEnemyBulletIndex = i;
			if (!enemyBulletMap[i]->IsActive())
			{
				isFindNonActiveEnemy = true;
				break;
			}
		}

		if (!isFindNonActiveEnemy)
		{
			CreateEnemyBullet(enemyBulletMap[0]->GetName(), createEnemyBulletCount);
		}
	}

	SceneManager::GetInstance().GetCurrentScene()->AddGameObject(enemyBulletMap[currentEnemyBulletIndex]);
	return enemyBulletMap[currentEnemyBulletIndex];
}

PlayerBullet* BulletManager::GetPlayerBulletToAEnabled()
{
	if (currentPlayerBulletIndex >= createPlayerBulletCount || playerBulletMap[currentPlayerBulletIndex]->IsActive())
	{
		currentPlayerBulletIndex = 0;
		bool isFindNonActivePlayerBullet = false;

		for (int i = 0; i < createPlayerBulletCount; ++i)
		{
			currentPlayerBulletIndex = i;
			if (!playerBulletMap[i]->IsActive())
			{
				isFindNonActivePlayerBullet = true;
				break;
			}
		}

		if (!isFindNonActivePlayerBullet)
		{
			CreatePlayerBullet(playerBulletMap[0]->GetName(), createPlayerBulletCount);
		}
	}
	SceneManager::GetInstance().GetCurrentScene()->AddGameObject(playerBulletMap[currentPlayerBulletIndex]);
	return playerBulletMap[currentPlayerBulletIndex];
}

void BulletManager::Release()
{
	auto currentScene = SceneManager::GetInstance().GetCurrentScene();
	for (int i = 0; i < createEnemyBulletCount; i++)
	{
		currentScene->RemoveGameObject(enemyBulletMap[i]);
		delete enemyBulletMap[i];
		enemyBulletMap[i] = nullptr;
	}

	for (int i = 0; i < createEnemyBulletCount; i++)
	{
		currentScene->RemoveGameObject(playerBulletMap[i]);
		delete playerBulletMap[i];
		playerBulletMap[i] = nullptr;
	}

	currentEnemyBulletIndex = 0;
	createEnemyBulletCount = 0;

	currentPlayerBulletIndex = 0;
	createPlayerBulletCount = 0;

	playerBulletMap.clear();
	enemyBulletMap.clear();
}