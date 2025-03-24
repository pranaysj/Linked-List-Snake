#include "../../header/Level/LevelView.h"
#include "../../header/Global/ServiceLocator.h"

namespace Level
{
	using namespace Global;

	LevelView::LevelView()
	{
		background_rectangle = new RectangleShapeView();
	}

	LevelView::~LevelView()
	{
		delete(background_rectangle);
	}

	void LevelView::initialize()
	{
		initializeBackground();
		calculateGridExtents();
		initializeBorder();
	}

	void LevelView::initializeBackground()
	{
		sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

		sf::Vector2f background_size = sf::Vector2f(game_window->getSize().x, game_window->getSize().y);

		background_rectangle->initialize(background_size, sf::Vector2f(0, 0), 0, background_color);

		background_rectangle->show();
	}

	void LevelView::initializeBorder()
	{
		sf::Vector2f border_size = sf::Vector2f(grid_width, grid_height);
		sf::Vector2f border_position = sf::Vector2f(border_offset_left, border_offset_top);

		border_rectangle->initialize(border_size, border_position, border_thickness, sf::Color::Transparent, border_color);
		border_rectangle->show();
	}

	void LevelView::calculateGridExtents()
	{
		sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

		grid_width = game_window->getSize().x - 2 * border_offset_left;
		grid_height = game_window->getSize().y - 2 * border_offset_top;
	}

	void LevelView::destory()
	{
		delete(background_rectangle);
		delete(border_rectangle);
	}

	float LevelView::getGridWidth()
	{
		return grid_width;
	}

	float LevelView::getGridHeight()
	{
		return grid_height;
	}

	void LevelView::update()
	{
		background_rectangle->update();
	}

	void LevelView::render()
	{
		background_rectangle->render();
	}
}
