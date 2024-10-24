#pragma once
#include "UITextGameObject.h"

class Timer: public UITextGameObject
{
private:
	sf::RectangleShape timeBar;
	float currentTime;
	float timer;
	float timeBarWidth;
	float timeBarHeight;
	bool isReStart;
public:

	void Init() override;
	void Reset() override;

	void TimeBar(const float& deltaTime);
	void Update(const float& deltaTime) override;
	void Render(sf::RenderWindow& renderWindow);
	void TimeOver();
public:
	Timer(float timer, const std::string& textId, const std::string& name, unsigned int textSize, sf::Color textColor = sf::Color::White);
	virtual ~Timer() = default;
	Timer& operator= (const Timer& other) = delete;
};

