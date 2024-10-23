#pragma once

class Bullet;

class BulletManager : public Singleton<BulletManager>
{
	friend Singleton<BulletManager>;
private:
	std::unordered_map<int, Bullet*> bulletMap;

	int				currentCreateIndex;
	int				createBulletCount;

public:
	void CreateBullet(Scene* createScene, const std::string& name, int count);
	void SetDisabledBullet(const std::string& name);
	Bullet* GetBulletToAEnabled();
public:
	void Release();

protected:
	BulletManager();
	virtual ~BulletManager() = default;
	BulletManager(const BulletManager&) = delete;
	BulletManager& operator=(const BulletManager&) = delete;
};

