#pragma once
#include"../header/Level/LevelModel.h"
#include "../header/Element/ElementData.h"


namespace Level 
{
	class LevelView;

	using namespace Element;
	class LevelController 
	{
	private:
		LevelModel* level_model;
		LevelView* level_view;

	public:
		LevelController();
		~LevelController();

		void initialize();
		void update();
		void render();

		float getCellWidth();
		float getCellHeight();

		const std::vector<ElementData>& getElementDataList(int level_to_load);

	};
}