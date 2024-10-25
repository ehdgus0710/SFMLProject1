#include "stdafx.h"
#include "SceneDev1.h"
#include "SpriteGameObject.h"
#include "UiTextGameObject.h"
#include "Test.h"
#include "Bullet.h"

#include "Player.h"
#include "BulletManager.h"
#include "Enemy.h"

void SceneDev1::ResourcesLoad()
{
	TEXTURE_MANAGER.Load("player", "graphics/player.png");
	ResourcesManager<sf::Font>::GetInstance().Load("KOMIKAP", "fonts/KOMIKAP_.ttf");
}

void SceneDev1::Init()
{
	ResourcesLoad();

	Scene::Init();
}

void SceneDev1::Enter()
{
	Player* obj = AddGameObject(new Player(Stat(5, 500.f, 0.5f, 1), "player"));

	obj->SetOrigin(Origins::MiddleCenter);
	obj->SetPosition({ 1920.f * 0.5f, 1080 * 0.5f });
	obj->CreateCollider(ColliderType::Circle, ColliderLayer::Player, sf::Vector2f::zero, { 0.5f,0.5f });
	obj->SetActive(true);

	Enemy* enemy = AddGameObject(new Enemy("Enemy", Stat(5, 500.f, 0.5f, 1) ));
	enemy->CreateCollider(ColliderType::Circle, ColliderLayer::Enemy, sf::Vector2f::zero, { 0.5f,0.5f });
	enemy->SetOrigin(Origins::MiddleCenter);
	enemy->SetPosition({ 1920.f * 0.5f, 300.f });
	enemy->SetAttackPattern(0);
	enemy->SetActive(true);
	enemy->SetPlayer(obj);

	BulletManager::GetInstance().CreateEnemyBullet("Bullet", 1);

	ColliderManager::GetInstance().SetCollisionCheck(ColliderLayer::Player, ColliderLayer::EnemyBullet);

	Scene::Enter();
}

void SceneDev1::Exit()
{
	TEXTURE_MANAGER.unLoad("player");
	ColliderManager::GetInstance().Release();
	Scene::Exit();
}

void SceneDev1::Release()
{
	Scene::Release();
}

void SceneDev1::Update(float dt)
{
	Scene::Update(dt);

	if (InputManager::GetInstance().GetKeyUp(sf::Keyboard::F11))
		SCENE_MANAGER.ChangeScene(SceneIds::SceneDev2);
}

void SceneDev1::Render(sf::RenderWindow& window)
{
	Scene::Render(window);
}

SceneDev1::SceneDev1()
	: Scene(SceneIds::SceneDev1)
{

}

SceneDev1::~SceneDev1()
{
}
