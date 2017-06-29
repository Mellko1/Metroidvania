#include "ScreenGameplay.hpp"
#include "AppScreens.hpp"
#include <cmath>
#include <iostream>


ScreenGameplay::ScreenGameplay(GuiEngine& _engine)
	: GuiScreen(_engine)
{

}


void ScreenGameplay::onRender(sf::RenderTarget& _target)
{

}


void ScreenGameplay::onEvent(const sf::Event& _event) //override
{

}


void ScreenGameplay::onTick(float _dt) //override
{
	
}


void ScreenGameplay::onScreenActivate() //override
{
	m_timerTextTime = sf::Time::Zero;
}


