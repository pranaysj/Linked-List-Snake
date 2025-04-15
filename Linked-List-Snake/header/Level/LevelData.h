#pragma once
#include"../../header/Level/LevelConfig.h"
#include"../../header/Element/ElementData.h"

namespace Level {

	struct LevelData 
	{
		LevelData(LevelNumber index, std::vector<Element::ElementData>* data_list)
		{
			level_number = index;
			element_data_list = data_list;
		}

		LevelNumber level_number;
		std::vector<Element::ElementData>* element_data_list;
	};
}