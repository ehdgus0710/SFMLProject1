#include "stdafx.h"
#include "GameManager.h"

GameManager::GameManager()
	: score(0)
	, player(nullptr)
	, isGameOver(false)
	, isClear(false)
{
}

void GameManager::OnGameOver()
{
	TimeManager::GetInstance().SetTimeScale(0.f);
	isGameOver = true;
}

void GameManager::OnClear()
{
	TimeManager::GetInstance().SetTimeScale(0.f);
	isClear = true;
}

void GameManager::Init()
{
	score = 0;
	isGameOver = false;
	isClear = false;
}

void GameManager::Release()
{
}

void GameManager::SetPlayer(Player* player)
{
	this->player = player;
}