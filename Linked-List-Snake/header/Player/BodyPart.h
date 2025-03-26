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

		sf::Vector2i grid_position;
		Direction direction;

		float bodypart_width;
		float bodypart_height;
		
		void createBodyPartImage();
		void initializeBodyPartImage();
		sf::Vector2f getBodyPartScreenPosition();
		float getRotationAngle();

		sf::Vector2i getNextPosition();

		sf::Vector2i getNextPositionRight();
		sf::Vector2i getNextPositionDown();
		sf::Vector2i getNextPositionLeft();
		sf::Vector2i getNextPositionUp();


		void destory();

	public:

		BodyPart();
		~BodyPart();

		void inititlize(float width, float height, sf::Vector2i position, Direction dir);
		void updatePosition();
		void render();

		void setDirection(Direction direction);
		void setPosition(sf::Vector2i position);

		Direction getDirection();
		sf::Vector2i getPosition();
	};
	
}