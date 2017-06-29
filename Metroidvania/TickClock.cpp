#include "TickClock.hpp"


TickClock::TickClock(int _tickrate)
	: m_tickDur(sf::seconds(1.f / _tickrate))
	, m_acum(sf::Time::Zero)
{
	m_clock.restart();
}


bool TickClock::passTime()
{
	m_acum += m_clock.restart();

	if (m_acum >= m_tickDur)
	{
		m_acum -= m_tickDur;
		return true;
	}

	return false;
}


float TickClock::getTickDuration() const
{
	return m_tickDur.asSeconds();
}

