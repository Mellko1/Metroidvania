#include "GuiScreen.hpp"


GuiScreen::GuiScreen(GuiEngine& _engine)
	: m_engine(_engine)
{
}


GuiScreen::~GuiScreen()
{
}


void GuiScreen::onRender(sf::RenderTarget& _target)
{
}


void GuiScreen::onEvent(const sf::Event& _event)
{
}


void GuiScreen::onTick(float _dt)
{
}


void GuiScreen::onScreenActivate()
{
}


void GuiScreen::onScreenDeactivate()
{
}
