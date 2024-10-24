#pragma once
#include "UIGameObject.h"

class Timer: public UIGameObject
{

private:

	sf::RectangleShape timeBar;
	sf::Text timerText;
	float timer;
	float timerSize;
	float timeBarWidth;
	float timeBarHeight;
	bool isReStart;
public:
	Timer(float timer, const std::string& texId);
	virtual~Timer();

	void Init() override;
	void Reset() override;

	void TimeBar(const float& deltaTime);
	void Update(const float& deltaTime) override;
	void Render(sf::RenderWindow& renderWindow);
	void TimeOver();

};

