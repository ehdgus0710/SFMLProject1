#pragma once

class TimeManager : public Singleton<TimeManager>
{
	friend Singleton<TimeManager>;
private:
	sf::Clock		clock;
	sf::Time		sfTime;
	sf::Text		frameText;

	float			time;
	float			realTime;

	float			timeScale;
	float			deltaTime;
	float			realDeltatime;
	float			fixedTime;
	unsigned int	frameTarget;

	unsigned int	currentFrame;
	float			currentFrameTime;

public:
	void Init();
	void Update();
	void Render(sf::RenderWindow& renderWindow);

	float GetUnScaleDeletaTime() const { return deltaTime; }
	float GetUnScaleFixedDeletaTime() const { return fixedTime; }
	float GetDeletaTime() const { return deltaTime * timeScale; }
	float GetFixedDeletaTime() const { return fixedTime * timeScale; }
	float GetTime() const 	{ return time; }
	float GetRealTime() const { return realTime; }
	float GetRealDeltatime() const { return realDeltatime; }
	float GetTimeScale() const { return timeScale; }

	void SetTimeScale(float newTimeScale) { timeScale = newTimeScale; }
	void FrameCheck();


protected:
	TimeManager();
	~TimeManager() override {}
	TimeManager(const TimeManager&) = delete;
	TimeManager& operator=(const TimeManager&) = delete;
};

