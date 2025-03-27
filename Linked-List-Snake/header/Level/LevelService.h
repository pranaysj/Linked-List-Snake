#pragma once
#include"../../header/Level/LevelController.h"
#include"../../header/Level/LevelNumber.h"

namespace Level 
{
	class LevelService 
	{
	private:
		LevelController* level_controller;
		LevelNumber current_level;

		void createLevelController();

		void destory();

		void spawnPlayer();

	public:
		LevelService();
		~LevelService();

		void initialize();
		void update();
		void render();

		void createLevel(LevelNumber level_to_create);
		
		float getCellWidth();
		float getCellHeight();
	};
}