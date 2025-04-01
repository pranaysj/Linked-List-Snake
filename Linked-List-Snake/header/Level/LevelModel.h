#pragma once
#include <vector>
#include <SFML/System/Vector2.hpp>
#include "../header/Level/LevelData.h"
#include "../header/Element/ElementData.h"

namespace Level 
{
	using namespace Element;

	class LevelModel 
	{
	private:

		std::vector<Element::ElementData> level_one_element_list;
		std::vector<Element::ElementData> level_two_element_list;
		std::vector<LevelData> level_configurations;

		float cell_width;
		float cell_height;

		void initializeLevelData();

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

		const std::vector<ElementData>& getElementDataList(int level_to_load);

	};
}