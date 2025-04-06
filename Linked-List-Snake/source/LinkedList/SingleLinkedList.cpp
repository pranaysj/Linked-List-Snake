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
		linked_list_size = 0;
	}

	Node *SingleLinkedList::createNode()
	{
		return new Node;
	}

	void SingleLinkedList::initializeNode(Node* new_node, Node* reference_node, Operation operation)
	{
		if (reference_node == nullptr)
		{
			new_node->bodypart.inititlize(node_width, node_height, default_position, default_direction);
			return;
		}

		sf::Vector2i position = getNewNodePosition(reference_node, operation);

		new_node->bodypart.inititlize(node_width, node_height, position, reference_node->bodypart.getDirection());

	}

	sf::Vector2i SingleLinkedList::getNewNodePosition(Node *reference_node, Operation operation)
	{
		switch (operation)
		{
		case Operation::HEAD:
			return reference_node->bodypart.getNextPosition();
		case Operation::TAIL:
			return reference_node->bodypart.getPrevPosition();
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

	void SingleLinkedList::insertNodeAtHead()
	{
		linked_list_size++;

		Node* new_node = createNode();
		
		if (head_node == nullptr)
		{
			head_node = new_node;
			initializeNode(new_node, nullptr, Operation::HEAD);
			return;
		}

		initializeNode(new_node, head_node, Operation::HEAD);
		new_node->next = head_node;
		head_node = new_node;
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