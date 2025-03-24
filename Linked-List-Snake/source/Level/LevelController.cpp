#include "../../header/Level/LevelController.h"

namespace Level
{
	LevelController::LevelController()
	{
		level_view = new LevelView();
	}

	LevelController::~LevelController()
	{
		delete(level_view);
	}

	void LevelController::initialize()
	{
		level_view->initialize();
	}

	void LevelController::update()
	{
		level_view->update();
	}

	void LevelController::render()
	{
		level_view->render();
	}
}
