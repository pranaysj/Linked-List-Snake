#pragma once
#include "../header/LinkedList/Node.h"

namespace LinkedList
{
	enum class Operation
	{
		HEAD,
		MID,
		TAIL,
	};

	class SingleLinkedList
	{
	private:
		int linked_list_size;

		Node *head_node;

		float node_width;
		float node_height;

		sf::Vector2i default_position;
		Direction default_direction;

		Node *createNode();
		void initializeNode(Node* new_node, Node* reference_node, Operation operation);

		sf::Vector2i getNewNodePosition(Node *reference_node, Operation operation);

		void removeNodeAtHead();

	public:
		SingleLinkedList();
		~SingleLinkedList();

		void initialize(float width, float height, sf::Vector2i position, Direction dir);
		void render();

		void insertNodeAtTail();
		void insertNodeAtHead();
		int findMiddleNode();
		void insertNodeAtMiddle();
		void insertNodeAtIndex(int index);

		void shiftNodesAfterInsertion(Node* new_node, Node* cur_node, Node* prev_node);

		void updateNodeDirection(Direction direction_to_set);
		void updateNodePosition();

		bool processNodeCollision();
		void removeAllNodes();

		Node *getHeadNode();
		std::vector<sf::Vector2i> getNodesPositionList();
	};
}