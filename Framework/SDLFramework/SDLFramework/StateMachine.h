#pragma once
#include "State.h"
#include "MovingEntity.h"
#include <memory>
template <class entity_type>
class StateMachine
{
private:
	entity_type* m_owner;

	std::shared_ptr<State<entity_type>> m_currentState;
	std::shared_ptr<State<entity_type>> m_previousState;

public:
	StateMachine(entity_type*);
	void changeState(std::shared_ptr<State<entity_type>>);
	void revert();
	void update(double deltaTime);
	void setCurrentState(std::shared_ptr<State<entity_type>> s) { m_currentState = s; }
	void setPreviousState(std::shared_ptr<State<entity_type>> s) { m_previousState = s; }
	std::shared_ptr<State<entity_type>> getPreviousState() { return m_previousState; }
};


template<class entity_type>
inline StateMachine<entity_type>::StateMachine(entity_type * owner) :m_owner(owner), m_previousState(NULL), m_currentState(NULL)
{
}

template<class entity_type>
inline void StateMachine<entity_type>::changeState(std::shared_ptr<State<entity_type>> newState)
{
	if (newState)
	{
		//Zodat er terug kan worden gegaan naar de vorige state
		m_previousState = m_currentState;

		//Roep de exit method aan op de state die gaat eindigen
		m_currentState->exit(m_owner);

		//Wissel de state
		m_currentState = newState;

		//Roep de enter method aan op de nieuwe state
		m_currentState->enter(m_owner);
	}
	else
	{
		std::cout << "Invalid newState value for changeState function" << std::endl;
	}
}

template<class entity_type>
inline void StateMachine<entity_type>::revert()
{
	changeState(m_previousState);
}

template<class entity_type>
inline void StateMachine<entity_type>::update(double deltaTime)
{
	if (m_currentState) {
		m_currentState->execute(m_owner, deltaTime);
	}
}
