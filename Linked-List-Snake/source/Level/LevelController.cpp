#include "../../header/Level/LevelController.h"
#include "../../header/Level/LevelView.h"

namespace Level
{
	LevelController::LevelController()
	{
		level_view = new LevelView();
		level_model = new LevelModel();
	}

	LevelController::~LevelController()
	{
		delete(level_view);
		delete(level_model);
	}

	void LevelController::initialize()
	{
		level_view->initialize();
		level_model->initialize(level_view->getGridWidth(), level_view->getGridHeight());
	}

	float LevelController::getCellWidth()
	{
		return level_model->getCellWidth();
	}

	float LevelController::getCellHeight()
	{
		return level_model->getCellHeight();
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
