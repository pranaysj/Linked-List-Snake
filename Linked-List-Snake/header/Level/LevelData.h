#pragma once
#include"../../header/Level/LevelNumber.h"

namespace Level {

	struct LevelData 
	{
		LevelData(LevelNumber index) 
		{
			level_number = index;
		}

		LevelNumber level_number;
	};
}