#include"../header/Player/PlayerService.h"
#include"../header/Player/SnakeController.h"

namespace Player
{
	PlayerService::PlayerService()
	{
		snake_controller = nullptr;

		createController();
	}

	PlayerService::~PlayerService()
	{
		destory();
	}

	void PlayerService::destory()
	{
		delete(snake_controller);
	}

	void PlayerService::createController()
	{
		snake_controller = new SnakeController();
	}

	void PlayerService::initialize()
	{
		snake_controller->initialize();
	}

	void PlayerService::spawnPlayer()
	{
	}

	void PlayerService::update()
	{
		snake_controller->update();
	}

	void PlayerService::render()
	{
		snake_controller->render();
	}
}