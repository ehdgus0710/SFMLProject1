#include "stdafx.h"
#include "SceneDev2.h"
#include "SpriteGameObject.h"
#include "UiTextGameObject.h"

#include "EnemyManager.h"

void SceneDev2::Init()
{
	GameObject* obj = AddGameObecjt(new SpriteGameObject("Player"));


	obj->SetOrigin(Origins::MiddleCenter);
	obj->SetPosition({ 1920.f * 0.5f, 1080 * 0.5f });

	obj = AddGameObecjt(new UITextGameObject("KOMIKAP", "", 100));
	obj->SetOrigin(Origins::TopLeft);
	obj->SetPosition({ });
	((UITextGameObject*)obj)->SetString("SceneDev2");


	EnemyManager::GetInstance().Init();
	EnemyManager::GetInstance().CreateEnemy(this,"Harrier", 50);
	EnemyManager::GetInstance().SetPlayer(obj);
	EnemyManager::GetInstance().SetCreateInfo({ 1920.f * 0.5f , -25.f }, 300, 5, 3);

	Scene::Init();

}

void SceneDev2::Enter()
{

	TEXTURE_MANAGER.Load("player", "graphics/player.png");
	TEXTURE_MANAGER.Load("Harrier", "graphics/Harrier.png");

	ResourcesManager<sf::Font>::GetInstance().Load("KOMIKAP", "fonts/KOMIKAP_.ttf");
	Scene::Enter();
}

void SceneDev2::Exit()
{
	TEXTURE_MANAGER.unLoad("player");
	ResourcesManager<sf::Font>::GetInstance().Load("KOMIKAP", "fonts/KOMIKAP_.ttf");
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
	/*if (InputManager::GetInstance().GetKeyUp(sf::Keyboard::Space))
		SCENE_MANAGER.ChangeScene(SceneIds::SceneDev2);*/
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
