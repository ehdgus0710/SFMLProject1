#pragma once
class Stat
{
public:
	int hp;
	float speed;
	float attakSpeed;
	int damege;
public:
	Stat() = default;
	Stat(int hp,float speed,float attakSpeed,int damege);
	virtual ~Stat() = default;

	virtual int Gethp() const { return hp; }
	virtual float GetSpeed() const  { return speed; }
	virtual float GetAttakSpeed() const { return attakSpeed; }
	virtual int Getdamege() const { return damege; }

	virtual void Sethp(const int h) {  hp =h; }
	virtual void SetSpeed(const float spd) { speed = spd; }
	virtual void SetAttakSpeed(const float atkSpd) {  attakSpeed = atkSpd; }
	virtual void Setdamege(const int dmg) {  damege = dmg; }



};

