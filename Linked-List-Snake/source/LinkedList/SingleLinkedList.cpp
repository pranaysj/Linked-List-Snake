#include "../header/LinkedList/SingleLinkedList.h"

namespace LinkedList
{
	SingleLinkedList::SingleLinkedList()
	{
		head_node = nullptr;
	}

	SingleLinkedList::~SingleLinkedList()
	{
		delete (head_node);
	}

	void SingleLinkedList::initialize(float width, float height, sf::Vector2i position, Direction dir)
	{
		node_width = width;
		node_height = height;
		default_position = position;
		default_direction = dir;
	}

	Node *SingleLinkedList::createNode()
	{
		return new Node;
	}

	sf::Vector2i SingleLinkedList::getNewNodePosition(Node *reference_node)
	{
		sf::Vector2i reference_position = reference_node->bodypart.getPosition();
		Direction reference_direction = reference_node->bodypart.getDirection();

		switch (reference_direction)
		{
		case Player::Direction::UP:
			return sf::Vector2i(reference_position.x, reference_position.y - 1);
			break;
		case Player::Direction::DOWN:
			return sf::Vector2i(reference_position.x, reference_position.y + 1);
			break;
		case Player::Direction::LEFT:
			return sf::Vector2i(reference_position.x + 1, reference_position.y);
			break;
		case Player::Direction::RIGHT:
			return sf::Vector2i(reference_position.x - 1, reference_position.y);
			break;
		}

		return default_position;
	}

	void SingleLinkedList::insertNodeAtTail()
	{
		Node *new_node = new Node();
		Node *cur_node = head_node;

		if (cur_node == nullptr)
		{
			head_node = new_node;
			new_node->bodypart.inititlize(node_width, node_height, default_position, default_direction);
			return;
		}

		while (cur_node->next != nullptr)
		{
			cur_node = cur_node->next;
		}

		cur_node->next = new_node;
		new_node->bodypart.inititlize(node_width, node_height, getNewNodePosition(cur_node), cur_node->bodypart.getDirection());
	}

	void SingleLinkedList::updateNodeDirection(Direction direction_to_set)
	{
		Node *cur_node = head_node;

		while (cur_node->next != nullptr)
		{
			Direction previous_direction = cur_node->bodypart.getDirection();
			cur_node->bodypart.setDirection(direction_to_set);
			direction_to_set = previous_direction;
			cur_node = cur_node->next;
		}
	}

	bool SingleLinkedList::processNodeCollision()
	{
		if (head_node == nullptr)
		{
			return false;
		}

		sf::Vector2i predicted_position = head_node->bodypart.getNextPosition();

		Node *cur_node = head_node->next;

		while (cur_node != nullptr)
		{
			if (cur_node->bodypart.getPosition() == predicted_position)
			{
				return true;
			}

			cur_node = cur_node->next;
		}

		return false;
	}

	void SingleLinkedList::removeNodeAtHead()
	{
		Node *cur_node = head_node;
		head_node = cur_node->next;

		cur_node->next = nullptr;
		delete (cur_node);
	}

	void SingleLinkedList::removeAllNodes()
	{
		while (head_node != nullptr)
		{
			if (head_node == nullptr)
			{
				return;
			}

			removeNodeAtHead();
		}
	}

	std::vector<sf::Vector2i> SingleLinkedList::getNodesPositionList()
	{
		std::vector<sf::Vector2i> nodes_position_list;

		Node *cur_node = head_node;

		while (cur_node != nullptr)
		{
			nodes_position_list.push_back(cur_node->bodypart.getPosition());
			cur_node = cur_node->next;
		}

		return nodes_position_list;
	}

	Node *SingleLinkedList::getHeadNode()
	{
		return head_node;
	}

	void SingleLinkedList::updateNodePosition()
	{
		Node *cur_node = head_node;

		while (cur_node != nullptr)
		{
			cur_node->bodypart.updatePosition();
			cur_node = cur_node->next;
		}
	}

	void SingleLinkedList::render()
	{
		Node *cur_node = head_node;

		while (cur_node->next != nullptr)
		{
			cur_node->bodypart.render();
			cur_node = cur_node->next;
		}
	}
}