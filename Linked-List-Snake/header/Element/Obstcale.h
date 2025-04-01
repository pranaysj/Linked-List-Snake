#pragma once
#include "../header/UI/UIElement/ImageView.h"

namespace Element
{
	using namespace UI::UIElement;

	class Obstcale
	{
	private:
		ImageView* obstcale_image;
		sf::Vector2i grid_position;
		float cell_width;
		float cell_height;

		void initializeObstacleImage();
		sf::Vector2f getObstacleImagePosition();

	public:
		Obstcale();
		~Obstcale();

		void initialize(sf::Vector2i grid_pos, float width, float height);
		void update();
		void render();
	};
}
