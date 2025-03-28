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
		DEAD,
	};

	class SnakeController
	{
	private:
		const int initial_snake_length = 10;

		const sf::Vector2i default_position = sf::Vector2i(25, 13);
		const Direction default_direction = Direction::RIGHT;

		float elapsed_duration = 0.0f;
		float movement_frame_duration = 0.1f;

		SnakeState current_snake_state;
		Direction current_snake_dircetion;

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
	};
}