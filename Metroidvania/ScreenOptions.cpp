#include "ScreenOptions.hpp"
#include "AppScreens.hpp"
#include <cmath>
#include <iostream>


ScreenOptions::ScreenOptions(GuiEngine& _engine)
	: GuiScreen(_engine)
{
	tabOpcji1[0] = "640x480";
	tabOpcji1[1] = "800x600";
	tabOpcji2[0] = "White";
	tabOpcji2[1] = "Black";
	tabOpcji2[2] = "Glowing";
	tabOpcji3[0] = "Brak";
	tabOpcji3[1] = "Nie ma";

}


void ScreenOptions::onRender(sf::RenderTarget& _target) //override
{
	const auto wndSize = _target.getDefaultView().getSize();
	const auto time = m_clock.getElapsedTime().asSeconds();

	m_engine.drawMenuCommon(_target);

	sf::Text menu1("Resolution: ", m_engine.getDefaultFont(), 22);
	sf::FloatRect titleRect = menu1.getGlobalBounds();
	menu1.setPosition((wndSize.x - titleRect.width) / 2, (wndSize.y - titleRect.height + 60) / 2);

	sf::Text opcja1(tabOpcji1[wybranaOpcja1], m_engine.getDefaultFont(), 22);
	opcja1.setPosition((wndSize.x - titleRect.width + 400) / 2, (wndSize.y - titleRect.height + 60) / 2);

	if (chosenoptionOpcji == 0)
	{
		menu1.setFillColor(sf::Color::Yellow);
		opcja1.setFillColor(sf::Color::Yellow);
	}
	else
	{
		menu1.setFillColor(sf::Color::Red);
		opcja1.setFillColor(sf::Color::Red);
	}

	sf::Text menu3("Krew: ", m_engine.getDefaultFont(), 22);
	menu3.setPosition((wndSize.x - titleRect.width) / 2, (wndSize.y - titleRect.height + 120) / 2);

	sf::Text opcja3(tabOpcji3[wybranaOpcja3], m_engine.getDefaultFont(), 22);
	opcja3.setPosition((wndSize.x - titleRect.width + 400) / 2, (wndSize.y - titleRect.height + 120) / 2);

	if (chosenoptionOpcji == 1)
	{
		menu3.setFillColor(sf::Color::Yellow);
		opcja3.setFillColor(sf::Color::Yellow);
	}
	else
	{
		menu3.setFillColor(sf::Color::Red);
		opcja3.setFillColor(sf::Color::Red);
	}

	sf::Text menu4("Powrot", m_engine.getDefaultFont(), 22);
	menu4.setPosition((wndSize.x - titleRect.width) / 2, (wndSize.y - titleRect.height + 180) / 2);
	menu4.setFillColor(chosenoptionOpcji == 2 ? sf::Color::Yellow : sf::Color::Red);

	_target.draw(menu1);
	_target.draw(opcja1);
	_target.draw(menu3);
	_target.draw(opcja3);
	_target.draw(menu4);

}


void ScreenOptions::onEvent(const sf::Event& _event) //override
{

	if (_event.type == sf::Event::KeyPressed)
	{
		if (_event.key.code == sf::Keyboard::Down)
			chosenoptionOpcji = (chosenoptionOpcji + 1) % 3;
		else if (_event.key.code == sf::Keyboard::Up)
			chosenoptionOpcji = (chosenoptionOpcji + 2) % 3;

		if (_event.key.code == sf::Keyboard::Right)
		{
			if (chosenoptionOpcji == 0)
			{
				this->wybranaOpcja1 = (this->wybranaOpcja1 + 1) % 2;
				m_engine.setResolution(wybranaOpcja1);
			}
			else if (chosenoptionOpcji == 1)
			{
				this->wybranaOpcja3 = (this->wybranaOpcja3 + 1) % 2;
				m_engine.znajdywanieAutomatyczne(!wybranaOpcja3);
			}
		}

		if (_event.key.code == sf::Keyboard::Left)
		{
			if (chosenoptionOpcji == 0)
			{
				this->wybranaOpcja1 -= 1;
				if (this->wybranaOpcja1 == -1)
					this->wybranaOpcja1 = 1;
				m_engine.setResolution(wybranaOpcja1);
			}
			else if (chosenoptionOpcji == 1)
			{
				this->wybranaOpcja3 -= 1;
				if (this->wybranaOpcja3 == -1)
					this->wybranaOpcja3 = 1;

				m_engine.znajdywanieAutomatyczne(!wybranaOpcja3);
			}
		}

		else if (_event.key.code == sf::Keyboard::Return && this->chosenoptionOpcji == 2)
			m_engine.setActiveScreen(screens::MainMenu);
	}
}


