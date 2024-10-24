#include "stdafx.h"
#include "Timer.h"
#include "GameManager.h"

Timer::Timer(float timer,const std::string& texId)
	:timer(timer),
	timeBarWidth(600),
	timeBarHeight(20),
	timerSize(timer),
	UIGameObject(texId)
	, isReStart(false)
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
	if (timer < 0)
		TimeOver();
}

void Timer::Init() 
{	
}

void Timer::Reset()
{
	timeBar.setSize({ timeBarWidth,timeBarHeight });
	timeBar.setFillColor(sf::Color::Red);
	timerText.setPosition({});	timerText.setFont(ResourcesManager<sf::Font>::GetInstance().Get("KOMIKAP"));
}

void Timer::Render(sf::RenderWindow& renderWindow)
{
	renderWindow.draw(timerText);
	renderWindow.draw(timeBar);
}

void Timer::TimeOver()
{
	TimeManager::GetInstance().SetTimeScale(0);
	timerText.setString("GAMEOVER");
	isReStart = true;

	if (InputManager::GetInstance().GetKeyDown(sf::Keyboard::Space))
	{
 		GameManager::GetInstance().SetReStart(true);
	}
}
   