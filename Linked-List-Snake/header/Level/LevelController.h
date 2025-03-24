#pragma once
#include"../header/Level/LevelView.h"

namespace Level 
{
	class LevelController 
	{
	private:
		LevelView* level_view;

	public:
		LevelController();
		~LevelController();

		void initialize();
		void update();
		void render();
	};
}