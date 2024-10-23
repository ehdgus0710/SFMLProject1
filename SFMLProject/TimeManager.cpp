#include "stdafx.h"
#include "Core.h"


TimeManager::TimeManager()
	: deltaTime(0.f)
	, realDeltatime(0.f)
	, fixedTime(0.f)
	, frameTarget(144)
	, time(0.f)
	, realTime(0.f)
	, timeScale(1)
	, currentFrameTime(0.f)
	, currentFrame(0)
{
}


void TimeManager::Init()
{
	ResourcesManager<sf::Font>::GetInstance().Load("KOMIKAP", "fonts/KOMIKAP_.ttf");
	clock.restart();
	frameText.setPosition({});
	frameText.setFont(ResourcesManager<sf::Font>::GetInstance().Get("KOMIKAP"));
}

void TimeManager::Update()
{
	sfTime = clock.restart();
	realDeltatime = deltaTime = sfTime.asSeconds();
	deltaTime *= timeScale;
	realDeltatime += realDeltatime;
	time += deltaTime;

	FrameCheck();
}

void TimeManager::Render(sf::RenderWindow& renderWindow)
{
	renderWindow.draw(frameText);
}

void TimeManager::FrameCheck()
{
	currentFrameTime += realDeltatime;
	++currentFrame;
	if (currentFrameTime >= 1.f)
	{
		frameText.setString(std::to_string(currentFrame));
		currentFrameTime = 0.f;
		currentFrame = 0;
	}
}