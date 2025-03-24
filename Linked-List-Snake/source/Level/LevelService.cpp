#include "../../header/Level/LevelService.h"

namespace Level {
	LevelService::LevelService()
	{
		level_controller = nullptr;

		createLevelController();
	}

	LevelService::~LevelService()
	{
		destory();
	}

	void LevelService::initialize()
	{
		level_controller->initialize();
	}

	void LevelService::createLevelController()
	{
		level_controller = new LevelController();
	}

	void LevelService::createLevel(LevelNumber level_to_create)
	{
		current_level = level_to_create;
	}

	void LevelService::update()
	{
		level_controller->update();
	}

	void LevelService::render()
	{
		level_controller->render();
	}

	void LevelService::destory()
	{
		delete(level_controller);
	}
}

