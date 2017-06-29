#ifndef	SK9K_GUISCREEN_HPP
#define	SK9K_GUISCREEN_HPP

#include "GuiEngine.hpp"
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Window/Event.hpp>


class GuiScreen
{
public:
	GuiScreen(GuiEngine& _engine);

	virtual ~GuiScreen();
	virtual void onRender(sf::RenderTarget& _target);
	virtual void onEvent(const sf::Event& _event);
	virtual void onTick(float _dt);
	virtual void onScreenActivate();
	virtual void onScreenDeactivate();

protected:
	GuiEngine& m_engine;
	sf::Clock m_clock;
};

#endif // SK9K_GUISCREEN_HPP
