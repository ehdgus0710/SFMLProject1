#include "stdafx.h"
#include "ScoreTextObject.h"
#include "GameManager.h"

ScoreTextObject::ScoreTextObject(const std::string& textId, const std::string& name, unsigned int textSize, sf::Color textColor)
	: UITextGameObject(textId, name, textSize, textColor)
	, score(0)
{
}

void ScoreTextObject::Init()
{
	explanationString = "Score : ";
}

void ScoreTextObject::Reset()
{
	explanationString = "Score : ";
	UITextGameObject::Reset();
}

void ScoreTextObject::Update(const float& deltaTime)
{
	score = GameManager::GetInstance().GetScore();
}
void ScoreTextObject::Render(sf::RenderWindow& window)
{
	UITextGameObject::SetString(explanationString + std::to_string(score));

	UITextGameObject::Render(window);
}
void ScoreTextObject::SetScore(int score)
{
	scoreString = std::to_string(score);
}
