#pragma once

#include "UITextGameObject.h"

class ScoreTextObject : public UITextGameObject
{
private:
	std::string scoreString;
	std::string explanationString;
	int score;

public:
	void SetScore(int score);

public:
	void Init() override;
	void Reset() override;
	void Update(const float& deltaTime) override;
	void Render(sf::RenderWindow& window) override;
public:
	ScoreTextObject(const std::string& textId, const std::string& name, unsigned int textSize, sf::Color textColor = sf::Color::White);
	virtual ~ScoreTextObject() = default;
	ScoreTextObject& operator= (const ScoreTextObject& other) = delete;
};

