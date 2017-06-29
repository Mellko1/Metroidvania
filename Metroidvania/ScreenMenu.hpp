#ifndef	SK9K_SCREENMENU_HPP
#define	SK9K_SCREENMENU_HPP

#include "GuiScreen.hpp"
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>


class ScreenMenu
	: public GuiScreen
{
public:
	ScreenMenu(GuiEngine& _engine);
	void onRender(sf::RenderTarget& _target) override;
	void onEvent(const sf::Event& _event) override;

protected:
	int chosenoption = 0;
	bool daciukActivated = false;
};


#endif // SK9K_SCREENMENU_HPP
