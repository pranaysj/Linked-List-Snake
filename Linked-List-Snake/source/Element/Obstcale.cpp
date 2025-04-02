#include "../header/Element/Obstcale.h"
#include "../header/Global/Config.h"
#include "../header/Level/LevelView.h"

namespace Element
{
	using namespace Global;
	using namespace Level;

	Obstcale::Obstcale()
	{
		obstcale_image = new ImageView();
	}

	Obstcale::~Obstcale()
	{
		delete(obstcale_image);
	}

	void Obstcale::initialize(sf::Vector2i grid_pos, float width, float height)
	{
		grid_position = grid_pos;
		cell_width = width;
		cell_height = height;

		initializeObstacleImage();
	}

	void Obstcale::initializeObstacleImage()
	{
		sf::Vector2f screen_position = getObstacleImagePosition();
		obstcale_image->initialize(Config::obstacle_texture_path, cell_width, cell_height, screen_position);
		obstcale_image->show();
	}

	sf::Vector2f Obstcale::getObstacleImagePosition()
	{
		float screen_position_x = LevelView::border_offset_left + (grid_position.x * cell_width);
		float screen_position_y = LevelView::border_offset_top+ (grid_position.y * cell_height);

		return sf::Vector2f(screen_position_x, screen_position_y);
	}

	void Obstcale::update()
	{
		obstcale_image->update();
	}

	void Obstcale::render()
	{
		obstcale_image->render();
	}
}

