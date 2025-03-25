#pragma once

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

		void spawnPlayer();
	};
}