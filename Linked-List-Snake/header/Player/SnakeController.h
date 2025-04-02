#pragma once
#include <SFML/System/Vector2.hpp>
#include "../header/Player/Direction.h"
#include "../header/LinkedList/SingleLinkedList.h"

namespace Player
{
	using namespace LinkedList;

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

	class SnakeController
	{
	private:
		const int initial_snake_length = 10;
		float movement_frame_duration = 0.1f;
		const float restart_duration = 2.0f;

		const sf::Vector2i default_position = sf::Vector2i(25, 13);
		const Direction default_direction = Direction::RIGHT;

		float elapsed_duration;
		float restart_counter;

		SnakeState current_snake_state;
		Direction current_snake_dircetion;
		InputState current_input_state;

		SingleLinkedList *single_linked_list;

		void processPlayerInput();
		void updateSnakeDirection();
		void moveSnake();
		void processSnakeCollision();
		void handleRestart();
		void reset();

		void createLinkedList();

		void destroy();

	public:
		SnakeController();
		~SnakeController();

		void initialize();
		void update();
		void render();

		void spawnSnake();
		void respawnSnake();

		void setSnakeState(SnakeState state);
		SnakeState getSnakeState();

		void delayedUpdate();

		std::vector<sf::Vector2i> getCurrentSnakePositionList();

	};
}