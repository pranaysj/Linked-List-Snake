#include"../header/LinkedList/SingleLinkedList.h"

namespace LinkedList
{
	SingleLinkedList::SingleLinkedList()
	{
		head_node = nullptr;
	}

	SingleLinkedList::~SingleLinkedList()
	{
		delete(head_node);
	}

	void SingleLinkedList::initialize(float width, float height, sf::Vector2i position, Direction dir)
	{
		node_width = width;
		node_height = height;
		default_position = position;
		default_direction = dir;
	}

	Node* SingleLinkedList::createNode()
	{
		return new Node;
	}

	sf::Vector2i SingleLinkedList::getNewNodePosition(Node* reference_node)
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
			return sf::Vector2i(reference_position.x - 1, reference_position.y);
			break;
		case Player::Direction::RIGHT:
			return sf::Vector2i(reference_position.x + 1, reference_position.y);
			break;
		}
 
		return default_position;
	}

	void SingleLinkedList::insertNodeAtTail()
	{
		Node* new_node = new Node();
		Node* cur_node = head_node;

		if (cur_node == nullptr) {
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

	void SingleLinkedList::render()
	{
		Node* cur_node = head_node;

		while (cur_node->next != nullptr)
		{
			cur_node->bodypart.render();
			cur_node = cur_node->next;
		}
	}
}