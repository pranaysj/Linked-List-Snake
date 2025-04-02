#pragma once
#include <vector>
#include <random>
#include <SFML/System/Vector2.hpp>
#include "../header/Food/FoodItem.h"

namespace Food
{
	class FoodService
	{
	private:
		FoodItem* current_food_item;

		float cell_width;
		float cell_height;

		std::default_random_engine random_engine;
		std::random_device random_device;

		void destroyFood();
		void reset();

		void spawnFood();

		FoodItem* createFood(sf::Vector2i position, FoodType type);

		sf::Vector2i getRandomPosition();

		FoodType getRandomFoodType();

	public:
		FoodService();
		~FoodService();

		void initialize();
		void update();
		void render();

		void startFoodSpawning();

		bool isValidPosition(std::vector<sf::Vector2i> position_data, sf::Vector2i food_position);

		sf::Vector2i getValidSpawnPosition();
	};
}