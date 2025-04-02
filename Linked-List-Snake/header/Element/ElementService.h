#pragma once
#include <vector>
#include <SFML/System/Vector2.hpp>

namespace Element
{
	class Obstcale;
	struct ElementData;

	class ElementService
	{
	private:
		std::vector<Obstcale*> obstacle_list;

		void spawnObstacle(sf::Vector2i position, float cell_width, float cell_height);

	public:
		ElementService();
		~ElementService();

		void initialize();
		void update();
		void render();

		const void spawnElements(std::vector<ElementData>& element_data_list, float cell_width, float cell_height);
	};
}