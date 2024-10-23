#pragma once
#include "SpriteGameObject.h"
#include "Stat.h"
class Player : public SpriteGameObject
{
private :
	Stat stat;
public:
	Player(Stat stat, const std::string& texId, const std::string& name = "");
	virtual~Player() = default;

	Stat Getstat() { return stat; };
	void Setstat(Stat st) { stat = st; };


	void PlayerMove(Stat st);
	

};

