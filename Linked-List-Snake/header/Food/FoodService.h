#pragma once
#include "../header/Food/FoodItem.h"
namespace Food
{
	class FoodService
	{
	private:
		FoodItem* current_food_item;
		
		float cell_width;
		float cell_height;

		void destroyFood();
		void reset();

		void spawnFood();
		FoodItem* createFood(sf::Vector2i position, FoodType type);

	public:
		FoodService();
		~FoodService();

		void initialize();
		void update();
		void render();

		void startFoodSpawning();
	};
}