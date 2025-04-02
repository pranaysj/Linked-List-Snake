#include"../header/Food/FoodService.h"
#include"../header/Global/ServiceLocator.h"
#include"../header/Level/LevelModel.h"

namespace Food
{
	using namespace Global;
	using namespace Level;

	FoodService::FoodService():random_engine(random_device())
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

	void FoodService::updateElapsedDuration()
	{
		elapsed_duration += ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
	}

	void FoodService::initialize()
	{
		elapsed_duration = spawn_duration;
	}

	void FoodService::startFoodSpawning()
	{
		current_spawning_status = FoodSpawningStatus::ACTIVE;

		cell_width = ServiceLocator::getInstance()->getLevelService()->getCellWidth();
		cell_height = ServiceLocator::getInstance()->getLevelService()->getCellHeight();

	}

	void FoodService::stopFoodSpawning()
	{
		current_spawning_status = FoodSpawningStatus::IN_ACTIVE;
		destroyFood();
		reset();
	}

	bool FoodService::isValidPosition(std::vector<sf::Vector2i> position_data, sf::Vector2i food_position)
	{
		for (int i = 0; i < position_data.size(); i++)
		{
			if (food_position == position_data[i])
			{
				return false;
			}
		}
		return true;
	}

	sf::Vector2i FoodService::getValidSpawnPosition()
	{
		std::vector<sf::Vector2i> player_position_data = ServiceLocator::getInstance()->getPlayerService()->getCurrentSnakePositionList();
		std::vector<sf::Vector2i> elements_position_data = ServiceLocator::getInstance()->getElementService()->getElementsPositionList();

		sf::Vector2i spawn_position;

		do
		{
			spawn_position = getRandomPosition();

		} while (!isValidPosition(player_position_data, spawn_position) || !isValidPosition(elements_position_data, spawn_position));

		return spawn_position;

	}

	void FoodService::spawnFood()
	{
		current_food_item = createFood(getValidSpawnPosition(), getRandomFoodType());
	}

	FoodItem* FoodService::createFood(sf::Vector2i position, FoodType type)
	{
		FoodItem* food_item = new FoodItem();
		food_item->initialize(position, cell_width, cell_height, type);

		return food_item;
	}

	sf::Vector2i FoodService::getRandomPosition()
	{
		// Coordinate distribution for selecting a random position for food
		std::uniform_int_distribution<int> x_distribution(0, LevelModel::number_of_columns - 1);
		std::uniform_int_distribution<int> y_distribution(0, LevelModel::number_of_rows - 1);

		int x_position = x_distribution(random_engine);
		int y_position = y_distribution(random_engine);

		return sf::Vector2i(x_position, y_position);
	}

	FoodType FoodService::getRandomFoodType()
	{
		std::uniform_int_distribution<int> distribution(0, FoodItem::number_of_foods - 1);
		return static_cast<FoodType>(distribution(random_engine));
	}

	void FoodService::handleFoodSpawning()
	{
		if (elapsed_duration >= spawn_duration)
		{
			destroyFood();
			reset();
			spawnFood();
		}
	}

	void FoodService::reset()
	{
		elapsed_duration = 0.f;
	}

	void FoodService::update()
	{
		if (current_spawning_status == FoodSpawningStatus::ACTIVE)
		{
			updateElapsedDuration();
			handleFoodSpawning();
		}

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