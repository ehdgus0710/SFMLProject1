#pragma once

class InputManager : public Singleton<InputManager>
{
	friend Singleton<InputManager>;
private:
	std::unordered_map<sf::Keyboard::Key, KeyState> keyboardInputMap;
	std::unordered_map<sf::Mouse::Button, KeyState> mouseInputMap;
	//std::unordered_map<, KeyState> mouseInputMap;

	std::vector<sf::Keyboard::Key> keyUpVector;
	std::vector<sf::Mouse::Button> mouseUpVector;
	sf::Vector2i mousePosition;

public:
	void Init();

	void UpdateEvent(const sf::Event* ev);

	bool GetKeyDown(sf::Keyboard::Key key);
	bool GetKey(sf::Keyboard::Key key);
	bool GetKeyUp(sf::Keyboard::Key key);

	void UpKeyClear();
	void Clear();

	const sf::Vector2i GetMousePosition() const;

protected:
	InputManager() = default;
	~InputManager() = default;
	InputManager(const InputManager&) = delete;
	InputManager& operator=(const InputManager&) = delete;
};

