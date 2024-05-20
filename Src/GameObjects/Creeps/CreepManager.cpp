#include "CreepManager.h"

CreepManager::CreepManager()
{
	m_creepNum = 10;
	m_currentTime = 0.f;
	m_timeSpwanCreep = 2.f;
	//minN + rand() % (maxN + 1 - minN)
}

CreepManager::~CreepManager()
{
	for (auto it : m_listCreepBat)
		if (it != nullptr)
			delete it;
	m_listCreepBat.clear();
	for (auto it : m_listCreepRino)
		if (it != nullptr)
			delete it;
	m_listCreepRino.clear();
}

void CreepManager::Init(CollisionManager& collisionManager)
{
	
	for (int i = 0; i < m_creepNum; i++)
	{
		CreepBat* creepB = new CreepBat();
		creepB->Init();
		creepB->getHitbox()->setAlive(false);
		m_listCreepBat.push_back(creepB);
		collisionManager.addObj(creepB->getHitbox());

		CreepRino* creepR = new CreepRino();
		creepR->Init();
		creepR->getHitbox()->setAlive(false);
		m_listCreepRino.push_back(creepR);
		collisionManager.addObj(creepR->getHitbox());
	}
}

void CreepManager::Update(float deltaTime)
{
	m_currentTime += deltaTime;
	if (m_currentTime > m_timeSpwanCreep)
	{
		SpwanRino();
		SpwanBat();
		m_currentTime = 0.f;
	}
	for (auto it : m_listCreepBat)
	{
		it->Update(deltaTime);
	}
	for (auto it : m_listCreepRino)
	{
		it->Update(deltaTime);
	}
}

void CreepManager::Render(sf::RenderWindow* window)
{
	for (auto it : m_listCreepBat)
	{
		it->Render(window);
	}
	for (auto it : m_listCreepRino)
	{
		it->Render(window);
	}
}

void CreepManager::SpwanRino()
{
	Creep* creep = nullptr;
	for (auto it : m_listCreepRino)
	{
		if (!it->getHitbox()->getAlive() && it->getStop())
		{
			creep = it;
			break;
		}
	}
	if (creep == nullptr) return;
	creep->getHitbox()->setAlive(true);
	creep->setStartPoint(sf::Vector2f(screenWidth + rand() % (150 + 1 - 50) + 50, groundY));
	creep->getHitbox()->setVelocity(sf::Vector2f(200 + rand() % 100, 0));
	creep->Reset();
}

void CreepManager::SpwanBat()
{
	Creep* creep = nullptr;
	for (auto it : m_listCreepBat)
	{
		if (!it->getHitbox()->getAlive() && it->getStop())
		{
			creep = it;
			break;
		}
	}
	if (creep == nullptr) return;
	creep->getHitbox()->setAlive(true);
	creep->setStartPoint(sf::Vector2f(screenWidth + (rand() % (150 + 1 - 50) + 50), groundY - (rand() % (250 + 1 - 150) + 150)));
	creep->Reset();
}
