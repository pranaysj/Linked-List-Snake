#include "../../header/Level/LevelService.h"
#include "../../header/Global/ServiceLocator.h"

namespace Level
{
	using namespace Global;

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
		spawnLevelElements(level_to_create);
		spawnPlayer();
	}

	float LevelService::getCellWidth()
	{
		return level_controller->getCellWidth();
	}

	float LevelService::getCellHeight()
	{
		return level_controller->getCellHeight();
	}

	void LevelService::spawnPlayer()
	{
		ServiceLocator::getInstance()->getPlayerService()->spawnPlayer();
	}

	void LevelService::spawnLevelElements(LevelNumber level_to_load)
	{
		float cell_width = level_controller->getCellWidth();
		float cell_height = level_controller->getCellHeight();

		std::vector<ElementData> element_data_list = level_controller->getElementDataList((int)level_to_load);
		ServiceLocator::getInstance()->getElementService()->spawnElements(element_data_list, cell_width, cell_height);

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

