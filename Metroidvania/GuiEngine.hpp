#ifndef SK9K_GUIENGINE_HPP
#define SK9K_GUIENGINE_HPP

//#include "NewModel/ResourceManager.hpp"
#include <SFML/Graphics.hpp>
#include <map>


class GuiScreen;

class GuiEngine
{
public:
	static const int Tickrate = 30;

	GuiEngine(sf::RenderWindow& _window);
	void registerScreen(int _id, GuiScreen* _screen);
	void setActiveScreen(int _id);
	void setActiveScreen(GuiScreen* _screen);
	void mainLoop();
	void exit();
	void setResolution(int option);
	void znajdywanieAutomatyczne(bool a);
	bool czyAutomatyczne();
	bool isAsyncKeyPressed(sf::Keyboard::Key _key) const;
	sf::Vector2f getMousePos() const;
	const sf::Font& getDefaultFont() const;
	void drawRosette(sf::RenderTarget& _target, sf::Vector2f _center, float _radius, int _strips, float _startAlfa = 0.f);
	void drawMenuCommon(sf::RenderTarget& _target);

protected:
	sf::Color calcBackgroundColor(float _time);

protected:
	sf::RenderWindow& m_window;
	GuiScreen* m_activeScreen;
	std::map<int, GuiScreen*> m_knownScreens;
	sf::Font m_defaultFont;
	int kolor = 2;
	bool automatyczne = 1;
	sf::Clock m_tickClock;
	sf::Clock m_masterClock;
	sf::Texture m_gameLogo;

};


#endif // SK9K_GUIENGINE_HPP
