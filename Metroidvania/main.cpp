#include "GuiEngine.hpp"
#include "ScreenMenu.hpp"
#include "ScreenOptions.hpp"
#include "ScreenGameplay.hpp"
#include "AppScreens.hpp"
#include <SFML\Graphics.hpp>


int main()
{
	sf::RenderWindow okno(sf::VideoMode(800, 600), "Metroidvania");
	GuiEngine engine(okno);

	ScreenMenu mainMenu(engine);
	engine.registerScreen(screens::MainMenu, &mainMenu);

	ScreenOptions options(engine);
	engine.registerScreen(screens::Options, &options);

	ScreenGameplay gameplay(engine);
	engine.registerScreen(screens::Gameplay, &gameplay);


	engine.setActiveScreen(screens::MainMenu);
	engine.mainLoop();
}
