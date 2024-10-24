#pragma once
class GameObject : public Entity
{
protected:
	sf::Vector2f position;
	sf::Vector2f rotation;
	sf::Vector2f scale;

	Collider* collider;
	sf::Vector2f origin;
	Origins		originPreset;

	std::string name;
	bool active = true;
	bool isDestory;
public:
	void Awake() override;
	void Start() override;

	virtual void Init();
	virtual void Release();
	virtual void Reset();

	void Update(const float& deltaTime) override;
	void FixedUpdate(const float& deltaTime) override;
	void LateUpdate(const float& deltaTime) override;
	virtual void Render(sf::RenderWindow& renderWindow);

	virtual void OnCollisionEnter(Collider* target);
	virtual void OnCollisionStay(Collider* target);
	virtual void OnCollisionEnd(Collider* target);

public:
	void SetDestory(bool destory);
	bool GetDestory() { return isDestory; }
	const bool IsActive() const { return active; }
	void SetActive(const bool active);
	const std::string& GetName() const { return name; }
	void SetName(const std::string& name) { this->name = name; }

	sf::Vector2f GetPosition() const { return position; }
	virtual void SetPosition(const sf::Vector2f& pos);

	sf::Vector2f GetOrigin() const { return origin; }
	virtual void SetOrigin(Origins preset);
	virtual void SetOrigin(const sf::Vector2f& newOrigin)
	{
		origin = newOrigin;
		originPreset = Origins::Custom;
	}

	virtual void SetScale(const sf::Vector2f& scale);
	virtual sf::Vector2f GetScale() { return scale; }


	virtual bool CreateCollider(ColliderType colliderType, ColliderLayer layer, sf::Vector2f offset = sf::Vector2f::zero, sf::Vector2f size = sf::Vector2f::one);
	Collider* GetCollider() { return collider; }
public:
	bool Save() const override;
	bool Load() override;
public:
	GameObject(const std::string& name);
	virtual ~GameObject();
	GameObject(const GameObject& other);
	//GameObject& operator=(const GameObject&& other);
};

