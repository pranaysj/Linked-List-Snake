#pragma once
#include <vector>
#include <SFML/System/Vector2.hpp>
#include "LevelData.h"

namespace Level 
{
	class LevelModel 
	{
	private:
		std::vector <LevelData> level_configuration;

		float cell_width;
		float cell_height;

	public:

		static const int number_of_rows = 28;
		static const int number_of_columns = 50;

		LevelModel();
		~LevelModel();

		void initialize(int width, int height);
		void update();
		void render();

		float getCellWidth();
		float getCellHeight();
	};
}