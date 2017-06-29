#ifndef	SK9K_SCREENOPTIONS_HPP
#define	SK9K_SCREENOPTIONS_HPP

#include "GuiScreen.hpp"
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>


class ScreenOptions
	: public GuiScreen
{
public:
	ScreenOptions(GuiEngine& _engine);
	void onRender(sf::RenderTarget& _target) override;
	void onEvent(const sf::Event& _event) override;


protected:
	sf::Clock m_clock;
	int chosenoption = 0;
	int chosenoptionOpcji = 0;
	char *tabOpcji1[2];
	char *tabOpcji2[3];
	char *tabOpcji3[2];
	int wybranaOpcja1 = 1;
	int wybranaOpcja2 = 0;
	int wybranaOpcja3 = 0;

};


#endif // SK9K_SCREENMENU_HPP
