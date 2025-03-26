#include "../header/Player/BodyPart.h"
#include "../header/Global/Config.h"
#include "../header/Level/LevelView.h"

namespace Player
{
	using namespace Global;
	using namespace Level;

	BodyPart::BodyPart()
	{
		grid_position = sf::Vector2i(0, 0);

		createBodyPartImage();
	}

	BodyPart::~BodyPart()
	{
		destory();
	}

	void BodyPart::destory()
	{
		delete(bodypart_image);
	}

	void BodyPart::createBodyPartImage()
	{
		bodypart_image = new ImageView();
	}

	void BodyPart::inititlize(float width, float height, sf::Vector2i position, Direction dir)
	{
		bodypart_width = width;
		bodypart_height = height;
		grid_position = position;
		direction = dir;

		initializeBodyPartImage();
	}

	void BodyPart::initializeBodyPartImage()
	{
		bodypart_image->initialize(Config::snake_body_texture_path, bodypart_width, bodypart_height, getBodyPartScreenPosition());
	}

	sf::Vector2f BodyPart::getBodyPartScreenPosition()
	{
		float x_screen_position = LevelView::border_offset_left + (grid_position.x + bodypart_width) + (bodypart_width / 2);
		float y_screen_position = LevelView::border_offset_top + (grid_position.y + bodypart_height) + (bodypart_height / 2);
		
		return sf::Vector2f(x_screen_position, y_screen_position);
	}

	void BodyPart::update()
	{
		bodypart_image->update();
	}

	void BodyPart::render()
	{
		bodypart_image->render();
	}
}

