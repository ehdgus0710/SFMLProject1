#include "stdafx.h"
#include "Timer.h"

Timer::Timer(float timer,float timerSize,const std::string& texId)
	:timer(timer),
	timeBarWidth(400),
	timeBarHeight(10),
	timerSize(timerSize),
	UIGameObject(texId)
{

}



Timer::~Timer()
{
}

void Timer::TimeBar(const float& deltaTime)
{	
	sf::Vector2f Size = timeBar.getSize();
	float timeSpeed = timeBarWidth / timerSize;
	Size.x -= deltaTime*timeSpeed;
	timeBar.setSize(Size);
	
}

void Timer::Update(const float& deltaTime)
{
	timer -= deltaTime;
	//timerText.setString(std::to_string((int)timer));
	TimeBar(deltaTime);
	TimeOver();
}


void Timer::Init() 
{	
	
	timeBar.setSize({ timeBarWidth,timeBarHeight });
	timeBar.setFillColor(sf::Color::White);
	timerText.setPosition({});
	timerText.setFont(ResourcesManager<sf::Font>::GetInstance().Get("KOMIKAP"));

}




void Timer::Render(sf::RenderWindow& renderWindow)
{
	renderWindow.draw(timerText);
	renderWindow.draw(timeBar);
}

void Timer::TimeOver()
{
	if (timer < 0)
	{
		
		TimeManager::GetInstance().SetTimeScale(0);
		timerText.setString("GAMEOVER");

		if (InputManager::GetInstance().GetKeyDown(sf::Keyboard::Space))
		{ 
			SCENE_MANAGER.ChangeScene(SceneIds::SceneDev2);
			TimeManager::GetInstance().SetTimeScale(1);
		}

	}

	

	
}
