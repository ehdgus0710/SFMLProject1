#include "stdafx.h"
#include "SceneDev2.h"
#include "SpriteGameObject.h"
#include "UiTextGameObject.h"

#include "BulletManager.h"
#include "EnemyManager.h"
#include "GameManager.h"
#include "Background.h"

#include "Player.h"
#include "Timer.h"
#include "ScoreTextObject.h"
#include "PlayerHPBar.h"

void SceneDev2::BackgroundCreate()
{
	 auto size = TEXTURE_MANAGER.Get("Map").getSize();
	 GameObject* backGround = AddGameObject(new Background("Map", "Map1"));
	 backGround->SetOrigin(Origins::MiddleCenter);
	 
	 
	 backGround->SetPosition({ 1920.f * 0.5f, size.y * -0.5f });
	 backGround->SetScale({ 10.0f, 1.f });
	 backGround->SetActive(true);
	 
	 backGround = AddGameObject(new Background("Map", "Map2"));
	 backGround->SetOrigin(Origins::MiddleCenter);
	 backGround->SetPosition({ 1920.f * 0.5f, size.y * 0.5f });
	 backGround->SetScale({ 10.0f, 1.f });
	 backGround->SetActive(true);
}

void SceneDev2::ResourcesLoad()
{
	ResourcesManager<sf::Font>::GetInstance().Load("KOMIKAP", "fonts/KOMIKAP_.ttf");
	TEXTURE_MANAGER.Load("Map", "graphics/MapTile.png");
	TEXTURE_MANAGER.Load("player", "graphics/player.png");
	TEXTURE_MANAGER.Load("Enemy", "graphics/Harrier.png");
	TEXTURE_MANAGER.Load("Bullet", "graphics/Bullet.png");
}

void SceneDev2::Init()
{
	ResourcesLoad();

	Scene::Init();
	GameManager::GetInstance().Init();
}

void SceneDev2::Enter()
{
	ResourcesLoad();

	BackgroundCreate();
	GameObject* obj = AddGameObject(new Player(Stat(5, 500.f, 0.5f, 1), "player"));

	obj->SetOrigin(Origins::MiddleCenter);
	obj->SetPosition({ 1920.f * 0.5f, 1080 * 0.5f });	
	obj->CreateCollider(ColliderType::Circle, ColliderLayer::Player, sf::Vector2f::zero, { 0.5f,0.5f });
	obj->SetActive(true);

	EnemyManager::GetInstance().Init();
	EnemyManager::GetInstance().SetPlayer(obj);
	EnemyManager::GetInstance().SetEnemyStat(Stat(3, 100.f, 3.f, 1));
	EnemyManager::GetInstance().CreateEnemy("Enemy", 50);
	EnemyManager::GetInstance().SetCreateInfo({ 1920.f * 0.5f , -25.f }, 300, 3.f, 1);
	
	BulletManager::GetInstance().CreatePlayerBullet("Bullet", 100);
	BulletManager::GetInstance().CreateEnemyBullet("Bullet", 300);
	
	ColliderManager::GetInstance().SetCollisionCheck(ColliderLayer::Player, ColliderLayer::EnemyBullet);
	ColliderManager::GetInstance().SetCollisionCheck(ColliderLayer::Player, ColliderLayer::Enemy);
	ColliderManager::GetInstance().SetCollisionCheck(ColliderLayer::PlayerBullet, ColliderLayer::Enemy);

	GameManager::GetInstance().SetPlayer((Player*)obj);

	PlayerHPBar* playerHpBar = AddGameObject(new PlayerHPBar("HpBar", {80.f,20.f}));
	playerHpBar->SetPlayer((Player*)obj);
	playerHpBar->SetOrigin(Origins::BottomCenter);

	((Player*)obj)->SetPlayerHPBar(playerHpBar);

	Timer* timeObj = AddGameObject(new Timer(300.f, "KOMIKAP", "Timer", 35));
	timeObj->SetOrigin(Origins::BottomLeft);
	timeObj->SetPosition({ 10.f, 1020.f });

	ScoreTextObject* scoreText = AddGameObject(new ScoreTextObject("KOMIKAP", "ScoreText", 35));
	scoreText->SetOrigin(Origins::BottomLeft);
	scoreText->SetPosition({ 10.f,980.f });

	Scene::Enter();
}

void SceneDev2::Exit()
{
	TEXTURE_MANAGER.unLoad("player");
	TEXTURE_MANAGER.unLoad("Enemy");
	TEXTURE_MANAGER.unLoad("Bullet");

	EnemyManager::GetInstance().Release();
	BulletManager::GetInstance().Release();
	ColliderManager::GetInstance().Release();
	GameManager::GetInstance().Release();

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

	if ((GameManager::GetInstance().IsGameOver() || GameManager::GetInstance().IsClear()) &&  InputManager::GetInstance().GetKeyUp(sf::Keyboard::Space))
	{
		SCENE_MANAGER.ChangeScene(SceneIds::SceneDev2);
		GameManager::GetInstance().Init();
		TimeManager::GetInstance().SetTimeScale(1.f);
	}
}

void SceneDev2::Render(sf::RenderWindow& window)
{
	Scene::Render(window);
	GameManager::GetInstance().Render(window);
}

SceneDev2::SceneDev2()
	: Scene(SceneIds::SceneDev2)
{

}

SceneDev2::~SceneDev2()
{
}
