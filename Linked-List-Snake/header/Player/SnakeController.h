#pragma once
#include <SFML/System/Vector2.hpp>
#include "../header/Player/Direction.h"
#include "../header/LinkedListLib/LinkedList.h"
#include "../header/Food/FoodType.h"
#include "../header/Level/LevelConfig.h"

namespace Player
{
	using namespace LinkedListLib;
	using namespace Food;
	using namespace Level;

	enum class SnakeState
	{
		ALIVE,
		DEAD
	};

	enum class InputState
	{
		WAITING,
		PROCESSING
	};

	enum class TimeComplexity
	{
		NONE,
		ONE,
		N,
	};

	enum class LinkedListOperations
	{
		NONE,
		INSERT_AT_HEAD,
		INSERT_AT_TAIL,
		INSERT_AT_MID,
		REMOVE_AT_HEAD,
		REMOVE_AT_TAIL,
		REMOVE_AT_MID,
		DELETE_HALF_LIST,
		REVERSE_LIST,
	};

	class SnakeController
	{
	private:
		const int initial_snake_length = 10;
		float movement_frame_duration = 0.1f;
		const float restart_duration = 2.0f;

		int playe_score = 0;

		const sf::Vector2i default_position = sf::Vector2i(25, 13);
		const Direction default_direction = Direction::RIGHT;

		float elapsed_duration;
		float restart_counter;

		SnakeState current_snake_state;
		Direction current_snake_dircetion;
		InputState current_input_state;

		LinkedList* linked_list;
		
		TimeComplexity time_complexity;
		LinkedListOperations last_linked_list_operation;
		

		void initializeLinkedList();

		void processPlayerInput();
		void updateSnakeDirection();
		void moveSnake();
		void handleRestart();
		void reset();

		void processSnakeCollision();
		void processBodyCollision();
		void processElementsCollision();
		void processFoodCollision();

		void OnFoodCollected(FoodType food_type);

		void destroy();

	public:
		SnakeController();
		~SnakeController();

		void initialize();
		void update();
		void render();

		void createLinkedList(LinkedListType level_type);

		void spawnSnake();
		void respawnSnake();

		void setSnakeState(SnakeState state);
		SnakeState getSnakeState();

		int getPlayerScore();

		TimeComplexity getTimeComplexity();
		LinkedListOperations getLastOperation();

		void delayedUpdate();

		std::vector<sf::Vector2i> getCurrentSnakePositionList();

		bool isSnakeDead();

		void getSnakeLength();
	};
}