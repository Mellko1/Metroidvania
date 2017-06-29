#include "ScreenMenu.hpp"
#include "AppScreens.hpp"
#include <cmath>


ScreenMenu::ScreenMenu(GuiEngine& _engine)
	: GuiScreen(_engine)
{
}


void ScreenMenu::onRender(sf::RenderTarget& _target) //override
{
	const auto wndSize = _target.getDefaultView().getSize();

	m_engine.drawMenuCommon(_target);

	const char* menuOpts[] =
	{
		"Start Game",
		"Options",
		"Quit"
	};

	for (int i = 0; i < 3; ++i)
	{
		sf::Text menu1(menuOpts[i], m_engine.getDefaultFont(), 22);
		sf::FloatRect titleRect = menu1.getGlobalBounds();
		menu1.setPosition((wndSize.x - titleRect.width) / 2, (wndSize.y - titleRect.height + i * 60) / 2);
		menu1.setFillColor(chosenoption == i ? sf::Color::Yellow : sf::Color::Red);
		_target.draw(menu1);
	}
}


void ScreenMenu::onEvent(const sf::Event& _event) //override
{

	if (_event.type == sf::Event::KeyPressed)
	{
		if (_event.key.code == sf::Keyboard::Down)
			this->chosenoption = (this->chosenoption + 1) % 3;
		else if (_event.key.code == sf::Keyboard::Up)
			this->chosenoption = (this->chosenoption + 2) % 3;

		//obsluga wyborow z menu glownego
		else if (_event.key.code == sf::Keyboard::Return)
		{
			if (chosenoption == 0)
				m_engine.setActiveScreen(screens::Gameplay);
			else if (chosenoption == 1)
			{
				m_engine.setActiveScreen(screens::Options);
			}
			else if (chosenoption == 2)
				m_engine.exit();
		}
	}

	if (_event.type == sf::Event::TextEntered && _event.text.unicode == 'd')
		daciukActivated = !daciukActivated;
}
