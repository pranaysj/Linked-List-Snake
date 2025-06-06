#include "../header/Element/ElementService.h"
#include "../header/Element/Obstcale.h"
#include "../header/Element/ElementData.h"
#include "../header/Element/ElementService.h"

namespace Element
{
	ElementService::ElementService() = default;
	ElementService::~ElementService() = default;

	void ElementService::initialize()
	{
	}

	void ElementService::spawnObstacle(sf::Vector2i position, float cell_width, float cell_height)
	{
		Obstcale *obstacle = new Obstcale();

		obstacle->initialize(position, cell_width, cell_height);
		obstacle_list.push_back(obstacle);
	}

	bool ElementService::processElementsCollision(LinkedListLib::Node *head_node)
	{
		for (int i = 0; i < obstacle_list.size(); i++)
		{
			if (obstacle_list[i]->getObstaclePosition() == head_node->bodypart.getNextPosition() || obstacle_list[i]->getObstaclePosition() == head_node->bodypart.getPosition())
			{
				return true;
			}
		}

		return false;
	}

	const void ElementService::spawnElements(std::vector<ElementData> &element_data_list, float cell_width, float cell_height)
	{
		for (int i = 0; i < element_data_list.size(); i++)
		{
			switch (element_data_list[i].element_type)
			{
			case ElementType::OBSTACLE:
				spawnObstacle(element_data_list[i].position, cell_width, cell_height);
				break;
			}
		}
	}

	std::vector<sf::Vector2i> ElementService::getElementsPositionList()
	{
		std::vector<sf::Vector2i> elements_position_list;

		for (int i = 0; i < obstacle_list.size(); i++)
		{
			elements_position_list.push_back(obstacle_list[i]->getObstaclePosition());
		}

		return elements_position_list;
	}

	void ElementService::update()
	{
		for (int i = 0; i < obstacle_list.size(); i++)
		{
			obstacle_list[i]->update();
		}
	}

	void ElementService::render()
	{
		for (int i = 0; i < obstacle_list.size(); i++)
		{
			obstacle_list[i]->render();
		}
	}
}