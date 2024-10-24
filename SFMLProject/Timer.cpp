#include "stdafx.h"
#include "Timer.h"
#include "GameManager.h"
#include "EnemyManager.h"

Timer::Timer(float timer, const std::string& textId, const std::string& name, unsigned int textSize, sf::Color textColor)
	: UITextGameObject(textId, name, textSize, textColor)
	, currentTime(timer)
	, timeBarWidth(1920)
	, timeBarHeight(20)
	, timer(timer)
	, isReStart(false)
	, levelPercent(0.8f)
	, isMaxLevel(false)
{

}

void Timer::TimeBar(const float& deltaTime)
{
	sf::Vector2f Size = timeBar.getSize();
	Size.x -= deltaTime * timeBarWidth / timer;
	timeBar.setSize(Size);
}

void Timer::Update(const float& deltaTime)
{
	currentTime -= deltaTime;
	text.setString(textString + std::to_string((int)currentTime));

	TimeBar(deltaTime);


	if (!isMaxLevel && levelPercent >= currentTime / timer)
	{
		levelPercent -= 0.1f;
		EnemyManager::GetInstance().SetSubRespawnTime(0.5f);

		if (levelPercent >= 0.5f)

			isMaxLevel = true;
	}

	if (currentTime < 0)
		TimeOver();
}

void Timer::Init() 
{
	textString = "Timer : ";
}

void Timer::Reset()
{
	timeBar.setSize({ timeBarWidth,timeBarHeight });
	timeBar.setPosition({ 0.f,1060.f });
	timeBar.setFillColor(sf::Color::Red);
	textString = "Timer : ";
	UITextGameObject::Reset();	
}

void Timer::Render(sf::RenderWindow& renderWindow)
{
	renderWindow.draw(text);
	renderWindow.draw(timeBar);
}

void Timer::TimeOver()
{
	TimeManager::GetInstance().SetTimeScale(0);
	GameManager::GetInstance().OnClear();
}
   