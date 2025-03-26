#include"../header/LinkedList/SingleLinkedList.h"

namespace LinkedList
{
	SingleLinkedList::SingleLinkedList()
	{
		head_node = nullptr;
	}

	SingleLinkedList::~SingleLinkedList()
	{
	}

	void SingleLinkedList::initialize(float width, float height, sf::Vector2i position, Direction dir)
	{
		node_widtgh = width;
		node_height = height;
		default_position = position;
		default_direction = dir;
	}

	Node* SingleLinkedList::createNode()
	{
		return new Node;
	}

	void SingleLinkedList::render()
	{
	}
}