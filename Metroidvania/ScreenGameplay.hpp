#include <SFML/Graphics.hpp>
#include "GuiScreen.hpp"
#include <memory>


class ScreenGameplay
	: public GuiScreen
{
public:
	ScreenGameplay(GuiEngine& _engine);
	void onRender(sf::RenderTarget& _target);
	void onEvent(const sf::Event& _event) override;
	void onTick(float _dt) override;
	void onScreenActivate() override;

protected:

	sf::Clock m_clock;
	sf::Vector2f m_lastSceneOffset;

	sf::Time m_timerTextTime;
};
