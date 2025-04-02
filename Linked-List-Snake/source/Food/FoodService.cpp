#include"../header/Food/FoodService.h"
#include"../header/Global/ServiceLocator.h"

namespace Food
{
	using namespace Global;

	FoodService::FoodService()
	{
		current_food_item = nullptr;
	}

	FoodService::~FoodService()
	{
		destroyFood();
	}

	void FoodService::destroyFood()
	{
		if (current_food_item)
		{
			delete(current_food_item);
		}
	}

	void FoodService::initialize()
	{

	}

	void FoodService::startFoodSpawning()
	{
		cell_width = ServiceLocator::getInstance()->getLevelService()->getCellWidth();
		cell_height = ServiceLocator::getInstance()->getLevelService()->getCellHeight();

		spawnFood();
	}

	void FoodService::spawnFood()
	{
		current_food_item = createFood(sf::Vector2i(4, 6), FoodType::BURGER);
	}

	FoodItem* FoodService::createFood(sf::Vector2i position, FoodType type)
	{
		FoodItem* food_item = new FoodItem();
		food_item->initialize(position, cell_width, cell_height, type);

		return food_item;
	}

	void FoodService::reset()
	{
	}

	void FoodService::update()
	{
		if (current_food_item)
		{
			current_food_item->update();
		}
	}

	void FoodService::render()
	{
		if (current_food_item)
		{
			current_food_item->render();
		}
	}
}