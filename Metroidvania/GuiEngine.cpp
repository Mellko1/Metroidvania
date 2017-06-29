#define _USE_MATH_DEFINES
#include "GuiEngine.hpp"
#include "GuiScreen.hpp"
//#include "SfmlExt.hpp"
#include "TickClock.hpp"
#include <cmath>


GuiEngine::GuiEngine(sf::RenderWindow& _window)
	: m_window(_window)
	, m_activeScreen(nullptr)
{
	m_defaultFont.loadFromFile("data/04B_03.TTF");
	m_gameLogo.loadFromFile("data/images/sk9k_logo.png");
	m_masterClock.restart();
}


void GuiEngine::registerScreen(int _id, GuiScreen* _screen)
{
	m_knownScreens[_id] = _screen;
}


void GuiEngine::setActiveScreen(int _id)
{
	setActiveScreen(m_knownScreens.at(_id));
}


void GuiEngine::setActiveScreen(GuiScreen* _screen)
{
	if (m_activeScreen)
		m_activeScreen->onScreenDeactivate();

	m_activeScreen = _screen;

	if (m_activeScreen)
		m_activeScreen->onScreenActivate();
}


void GuiEngine::mainLoop()
{
	TickClock tickClock(Tickrate);
	m_window.setFramerateLimit(70);

	while (m_window.isOpen())
	{
		sf::Event event;

		while (m_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				m_window.close();
			else
				if (m_activeScreen && m_window.hasFocus())
					m_activeScreen->onEvent(event);
		}

		while (tickClock.passTime())
			if (m_activeScreen)
				m_activeScreen->onTick(tickClock.getTickDuration());

		m_window.clear(calcBackgroundColor(m_masterClock.getElapsedTime().asSeconds()));

		if (m_activeScreen)
			m_activeScreen->onRender(m_window);

		m_window.display();
	}

	setActiveScreen(nullptr);
}


void GuiEngine::setResolution(int option)
{
	if (option == 0)
		m_window.setSize(sf::Vector2u(640, 480));
	else if (option == 1)
		m_window.setSize(sf::Vector2u(800, 600));

}

void GuiEngine::znajdywanieAutomatyczne(bool a)
{
	this->automatyczne = a;
}

bool GuiEngine::czyAutomatyczne()
{
	return this->automatyczne;
}


bool GuiEngine::isAsyncKeyPressed(sf::Keyboard::Key _key) const
{
	return m_window.hasFocus() && sf::Keyboard::isKeyPressed(_key);
}


sf::Vector2f GuiEngine::getMousePos() const
{
	return m_window.mapPixelToCoords(sf::Mouse::getPosition(m_window));
}


void GuiEngine::exit()
{
	m_window.close();
}


const sf::Font& GuiEngine::getDefaultFont() const
{
	return m_defaultFont;
}


void GuiEngine::drawRosette(sf::RenderTarget& _target, sf::Vector2f _center, float _radius, int _strips, float _startAlfa)
{
	sf::VertexArray va(sf::Triangles);
	sf::Vertex v, c;
	c.position = _center;
	c.color = sf::Color(0, 0, 0, 128);
	v.color = sf::Color::Transparent;

	for (int i = 0; i < _strips; ++i)
	{
		va.append(c);
		const float a0 = _startAlfa + (i * 2 + 0) * M_PI / (_strips);
		const float a1 = _startAlfa + (i * 2 + 1) * M_PI / (_strips);
		v.position = _center + _radius * sf::Vector2f(cos(a0), sin(a0));
		va.append(v);
		v.position = _center + _radius * sf::Vector2f(cos(a1), sin(a1));
		va.append(v);
	}

	_target.draw(va);
}


void GuiEngine::drawMenuCommon(sf::RenderTarget& _target)
{
	const auto wndSize = _target.getDefaultView().getSize();
	const auto logoDispFactor = sf::Vector2f(0.5f, 0.25f);

	sf::Sprite sprite;
	sprite.setTexture(m_gameLogo);
	auto a = sprite.getLocalBounds();
	sprite.setOrigin(sf::Vector2f(a.width * 0.5f, a.height * 0.5f));
	sprite.scale(0.4f, 0.4f);
	auto b = sf::Vector2f(wndSize.x * logoDispFactor.x, wndSize.y * logoDispFactor.y);
	sprite.setPosition(b);
	drawRosette(_target, b, wndSize.y, 30, m_masterClock.getElapsedTime().asSeconds() * 0.3f);
	_target.draw(sprite);
}


sf::Color GuiEngine::calcBackgroundColor(float _time)
{
	const float V = 0.9, S = 0.8, Gr = 5;

	const float h = std::fmod(_time, Gr) * 6 / Gr;
	const float f = h - (int)h;
	const float p = V * (1 - S);
	const float q = V * (1 - S * f);
	const float t = V * (1 - S * (1 - f));

	float r, g, b;

	switch ((int)h)
	{
	case 0:  r = V, g = t, b = p; break;
	case 1:  r = q, g = V, b = p; break;
	case 2:  r = p, g = V, b = t; break;
	case 3:  r = p, g = q, b = V; break;
	case 4:  r = t, g = p, b = V; break;
	default: r = V, g = p, b = q; break;
	}

	return sf::Color(255 * r, 255 * g, 255 * b, 255);
}
