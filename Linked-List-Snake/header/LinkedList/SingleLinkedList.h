#pragma once
#include"../header/LinkedList/Node.h"

namespace LinkedList
{
	class SingleLinkedList
	{
	private:
		Node* head_node;

		float nod_widtgh;
		float nod_height;

		sf::Vector2i default_position;
		Direction default_direction;

	public:
		SingleLinkedList();
		~SingleLinkedList();

		void initialize();
		void render();
	};
}