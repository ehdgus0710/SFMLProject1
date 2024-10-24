#pragma once

class PlayerBullet;
class EnemyBullet;

class BulletManager : public Singleton<BulletManager>
{
	friend Singleton<BulletManager>;
private:
	std::unordered_map<int, EnemyBullet*> enemyBulletMap;
	std::unordered_map<int, PlayerBullet*> playerBulletMap;

	int				currentEnemyBulletIndex;
	int				createEnemyBulletCount;

	int				currentPlayerBulletIndex;
	int				createPlayerBulletCount;

public:
	void CreateEnemyBullet(const std::string& name, int count);
	void CreatePlayerBullet(const std::string& name, int count);

	void SetDisabledEnemyBullet(const std::string& name);
	void SetDisabledPlayerBullet(const std::string& name);

	EnemyBullet* GetEnemyBulletToAEnabled();
	PlayerBullet* GetPlayerBulletToAEnabled();
public:
	void Release();

protected:
	BulletManager();
	virtual ~BulletManager() = default;
	BulletManager(const BulletManager&) = delete;
	BulletManager& operator=(const BulletManager&) = delete;
};

