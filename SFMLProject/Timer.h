#pragma once
#include "UIGameObject.h"
class Timer: public UIGameObject
{

private:
	float timer;
	float timerSize;
	sf::RectangleShape timeBar;
	sf::Text timerText;
	float timeBarWidth;
	float timeBarHeight;
public:
	Timer(float timer, float timerSize, const std::string& texId);
	virtual~Timer();

	
	void TimeBar(const float& deltaTime);
	void Update(const float& deltaTime) override;
	void Init() override;
	void Render(sf::RenderWindow& renderWindow);
	void TimeOver();

};

