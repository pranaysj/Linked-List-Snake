#pragma once
#include <vector>
#include <SFML/System/Vector2.hpp>
#include"../header/Player/SnakeController.h"

namespace Player
{
	class SnakeController;

	class PlayerService
	{
	private:

		SnakeController* snake_controller;

		void createController();

		void destory();

	public:

		PlayerService();
		~PlayerService();

		void initialize();
		void update();
		void render();

		void spawnPlayer(LinkedListType level_type);

		int getPlayerScore();

		TimeComplexity getTimeComplexity();
		LinkedListOperations getLastOperation();

		std::vector<sf::Vector2i> getCurrentSnakePositionList();
	};
}