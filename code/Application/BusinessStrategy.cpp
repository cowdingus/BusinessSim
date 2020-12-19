#include "Application/BusinessStrategy.hpp"

#include "Application/States/MainState.hpp"

BusinessStrategy::BusinessStrategy()
	: Game(sf::VideoMode(300, 500), "TestGame")
	, gui(window)
{
	gameStateManager.push(std::make_unique<MainState>(gameStateManager, gui));
	window.setFramerateLimit(60);
}

void BusinessStrategy::handleEvent(sf::Event event)
{
	gui.handleEvent(event);
	gameStateManager.handleEvent(event);

	switch (event.type)
	{
	case sf::Event::Resized:
	{
		sf::Vector2f windowSize = static_cast<sf::Vector2f>(window.getSize());
		window.setView(sf::View({0, 0, windowSize.x, windowSize.y}));
		gui.setView(sf::View({0,0,windowSize.x,windowSize.y}));
		break;
	}
	case sf::Event::Closed:
	{
		window.close();
		break;
	}
	default:
		break;
	}
}

void BusinessStrategy::update(const sf::Time& time)
{
	gameStateManager.update(time);
}

void BusinessStrategy::draw() const
{
	window.clear();
	gui.draw();
	gameStateManager.draw(window);
	window.display();
}