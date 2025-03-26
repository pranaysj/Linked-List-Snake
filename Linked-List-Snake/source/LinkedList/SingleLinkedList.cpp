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

	void SingleLinkedList::createHeadNode()
	{
		head_node = createNode();
		head_node->bodypart.inititlize(node_width, node_height, default_position, default_direction);
	}

	Node* SingleLinkedList::createNode()
	{
		return new Node;
	}

	void SingleLinkedList::render()
	{
		head_node->bodypart.render();
	}
}