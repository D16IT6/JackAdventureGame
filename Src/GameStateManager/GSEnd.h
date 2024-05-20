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

};