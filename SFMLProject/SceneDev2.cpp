#include "stdafx.h"
#include "SceneDev2.h"
#include "SpriteGameObject.h"
#include "UiTextGameObject.h"

#include "BulletManager.h"
#include "EnemyManager.h"
#include "Background.h"

#include "Player.h"

void SceneDev2::BackgroundCreate()
{
	auto size = TEXTURE_MANAGER.Get("Map").getSize();

	ResourcesManager<sf::Font>::GetInstance().Load("KOMIKAP", "fonts/KOMIKAP_.ttf");

	GameObject* backGround = AddGameObject(new Background("Map", "Map1"));
	backGround->SetOrigin(Origins::MiddleCenter);


	backGround->SetPosition({ 1920.f * 0.5f, size.y * -0.5f });
	backGround->SetScale({ 10.0f, 1.f });

	backGround = AddGameObject(new Background("Map", "Map2"));
	backGround->SetOrigin(Origins::MiddleCenter);
	backGround->SetPosition({ 1920.f * 0.5f, size.y * 0.5f });
	backGround->SetScale({ 10.0f, 1.f });

}

void SceneDev2::ResourcesLoad()
{
	TEXTURE_MANAGER.Load("Map", "graphics/MapTile.png");
	TEXTURE_MANAGER.Load("player", "graphics/player.png");
	TEXTURE_MANAGER.Load("Harrier", "graphics/Harrier.png");
	TEXTURE_MANAGER.Load("Bullet", "graphics/Bullet.png");
}

void SceneDev2::Init()
{
	ResourcesLoad();

	Scene::Init();

}

void SceneDev2::Enter()
{
	ResourcesLoad();

	GameObject* obj = AddGameObject(new Player(Stat(5, 500.f, 5, 1), "Harrier"));

	obj->SetOrigin(Origins::MiddleCenter);
	obj->SetPosition({ 1920.f * 0.5f, 1080 * 0.5f });
	obj->CreateCollider(ColliderType::Circle, ColliderLayer::Player);
	obj->SetActive(true);

	obj = AddGameObject(new UITextGameObject("KOMIKAP", "", 100));
	obj->SetOrigin(Origins::TopLeft);
	obj->SetPosition({ });
	((UITextGameObject*)obj)->SetString("SceneDev2");

	//BackgroundCreate();

	EnemyManager::GetInstance().Init();
	EnemyManager::GetInstance().SetPlayer(obj);
	EnemyManager::GetInstance().CreateEnemy("Harrier", 50);
	EnemyManager::GetInstance().SetCreateInfo({ 1920.f * 0.5f , -25.f }, 300, 3.f, 1);

	BulletManager::GetInstance().CreatePlayerBullet("Bullet", 100);
	BulletManager::GetInstance().CreateEnemyBullet("Bullet", 300);

	ColliderManager::GetInstance().SetCollisionCheck(ColliderLayer::Player, ColliderLayer::EnemyBullet);
	ColliderManager::GetInstance().SetCollisionCheck(ColliderLayer::Player, ColliderLayer::Enemy);
	ColliderManager::GetInstance().SetCollisionCheck(ColliderLayer::PlayerBullet, ColliderLayer::Enemy);

	Scene::Enter();
}

void SceneDev2::Exit()
{
	TEXTURE_MANAGER.unLoad("player");
	TEXTURE_MANAGER.unLoad("Harrier");
	TEXTURE_MANAGER.unLoad("Bullet");


	EnemyManager::GetInstance().Release();
	BulletManager::GetInstance().Release();
	ColliderManager::GetInstance().Release();
	Scene::Exit();
}

void SceneDev2::Release()
{
	Scene::Release();
}

void SceneDev2::Update(float dt)
{
	Scene::Update(dt);

	EnemyManager::GetInstance().Update(dt);

	if (InputManager::GetInstance().GetKeyUp(sf::Keyboard::F11))
	{
		SCENE_MANAGER.ChangeScene(SceneIds::SceneDev1);
		std::cout << "Input" << std::endl;
	}
}

void SceneDev2::Render(sf::RenderWindow& window)
{
	Scene::Render(window);
}

SceneDev2::SceneDev2()
	: Scene(SceneIds::SceneDev2)
{

}

SceneDev2::~SceneDev2()
{
}
