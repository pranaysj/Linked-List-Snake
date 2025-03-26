#pragma once
#include"../header/UI/UIElement/ImageView.h"
#include"../header/Player/Direction.h"

namespace Player
{
	using namespace UI::UIElement;

	class BodyPart
	{
	private:
		ImageView* bodypart_image;

		sf::Vector2f grid_position;
		Direction direction;

		float bodypart_width;
		float bodypart_height;
	};
	
}