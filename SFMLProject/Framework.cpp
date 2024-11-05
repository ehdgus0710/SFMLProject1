#include "stdafx.h"

#include "Framework.h"
#include "Core.h"


void Framework::Init()
{
    WindowManager::GetInstance().init({ 1920, 1080 }, "haha");
    renderWindow = WindowManager::GetInstance().GetRenderWindow();

    InputManager::GetInstance().Init();
    ColliderManager::GetInstance().Init();
    SceneManager::GetInstance().Init();
    TimeManager::GetInstance().Init();
}

void Framework::Update()
{
    while (renderWindow->isOpen())
    {
        SceneManager::GetInstance().Destory();
        InputManager::GetInstance().UpKeyClear();
        TimeManager::GetInstance().Update();

        while (renderWindow->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                renderWindow->close();

            InputManager::GetInstance().UpdateEvent(&event);
        }

        SceneManager::GetInstance().Update(TimeManager::GetInstance().GetDeletaTime());
        ColliderManager::GetInstance().Update();

        renderWindow->clear();
        SceneManager::GetInstance().Render(*renderWindow);
        TimeManager::GetInstance().Render(*renderWindow);
        renderWindow->display();
    }

}

void Framework::Release()
{
    SceneManager::GetInstance().Release();
}

Framework::Framework()
{
}

Framework::~Framework()
{
    Release();
}
