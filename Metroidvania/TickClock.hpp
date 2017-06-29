#ifndef SK9K_TICKCLOCK_HPP
#define SK9K_TICKCLOCK_HPP

#include <SFML/System/Clock.hpp>


class TickClock
{
public:
	TickClock(int _tickrate);
	bool passTime();
	float getTickDuration() const;

protected:
	const sf::Time m_tickDur;
	sf::Time m_acum;
	sf::Clock m_clock;

};

#endif // SK9K_TICKCLOCK_HPP
