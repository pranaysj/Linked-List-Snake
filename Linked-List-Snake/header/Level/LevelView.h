#pragma once
#include"../../header/UI/UIElement/RectangleShapeView.h"
namespace Level 
{
	using namespace UI::UIElement;

	class LevelView 
	{
		RectangleShapeView* background_rectangle;
		RectangleShapeView* border_rectangle;
		
		const sf::Color background_color = sf::Color(180, 200, 160);
		const sf::Color border_color = sf::Color::Black;

		float grid_width;
		float grid_height;
		
		void initializeBackground();
		void initializeBorder();

		void calculateGridExtents();

		void destory();

	public:
		static const int border_thickness = 10;
		static const int border_offset_left = 40;
		static const int border_offset_top = 40;

		LevelView();
		~LevelView();

		void initialize();
		void update();
		void render();

		float getGridWidth();
		float getGridHeight();
	};
}