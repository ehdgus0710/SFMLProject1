#include "stdafx.h"
#include "GameManager.h"

void GameManager::SetReStart(bool reStart)
{
	this->reStart = reStart;
}

void GameManager::Release()
{
}

GameManager::GameManager()
	: reStart(false)
{
}
