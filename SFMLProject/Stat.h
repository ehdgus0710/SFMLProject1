#pragma once
class Stat
{
private:
	int hp;
	float speed = 1.f;
	float attakSpeed = 1.f;
	int damege;
public:
	Stat(int hp,float speed,float attakSpeed,int damege);
	virtual ~Stat() = default;

	virtual int Gethp() const { return hp; }
	virtual float GetSpeed() const  { return speed; }
	virtual float GetAttakSpeed() const { return attakSpeed; }
	virtual int Getdamege() const { return damege; }

	virtual void Sethp(const int h) {  hp =h; }
	virtual void SetSpeed(const float spd) { speed = spd + 8.f; }
	virtual void SetAttakSpeed(const float atkSpd) {  attakSpeed = atkSpd + 8.f; }
	virtual void Setdamege(const int dmg) {  damege = dmg; }



};

