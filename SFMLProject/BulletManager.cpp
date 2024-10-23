#include "stdafx.h"
#include "BulletManager.h"
#include "Bullet.h"

BulletManager::BulletManager()
    : currentCreateIndex(0)
    , createBulletCount(0)
{
}

void BulletManager::CreateBullet(Scene* createScene, const std::string& name, int count)
{
	for (int i = 0; i < count; ++i)
	{
		bulletMap.insert({ createBulletCount, new Bullet(sf::Vector2f::zero, 50.f, "Bullet",std::to_string(currentCreateIndex)) });
		createScene->AddGameObject(bulletMap[createBulletCount]);

		bulletMap[createBulletCount]->CreateCollider(ColliderType::Circle,sf::Vector2f::zero);
		bulletMap[createBulletCount++]->SetActive(false);
	}
}

void BulletManager::SetDisabledBullet(const std::string& name)
{
	auto iter = bulletMap.find(std::stoi(name));
	if (iter != bulletMap.end())
	{
		//iter->second->Reset();
	}
}

Bullet* BulletManager::GetBulletToAEnabled()
{
	if (currentCreateIndex >= createBulletCount || bulletMap[currentCreateIndex]->IsActive())
	{
		currentCreateIndex = 0;
		bool isFindNonActiveEnemy = false;

		for (int i = 0; i < createBulletCount; ++i)
		{
			currentCreateIndex = i;
			if (!bulletMap[i]->IsActive())
			{
				isFindNonActiveEnemy = true;
				break;
			}
		}

		if (!isFindNonActiveEnemy)
		{
			CreateBullet(SceneManager::GetInstance().GetCurrentScene(), bulletMap[0]->GetName(), createBulletCount);
		}
	}

	return bulletMap[currentCreateIndex];
}

void BulletManager::Release()
{
	for (int i = 0; i < createBulletCount; i++)
	{
		delete bulletMap[i];
		bulletMap[i] = nullptr;
	}

	bulletMap.clear();
}