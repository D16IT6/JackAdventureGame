#include "GameStateBase.h"
class GSEnd :public GameStateBase
{
public:
	GSEnd();
	~GSEnd();
	void Exit();
	void Pause();
	void Resume();

	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* renderWindow);
private:
	std::list<GameButton*> m_listButton;
	sf::Sprite m_background;
	sf::Text m_title;

	sf::Text m_bestScore;
	sf::Text m_currentScore;
};