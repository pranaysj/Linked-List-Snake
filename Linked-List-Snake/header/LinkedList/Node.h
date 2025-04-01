#pragma once
#include"../header/Player/BodyPart.h"

namespace LinkedList
{
	using namespace Player;

	struct Node
	{
		BodyPart bodypart;
		Node* next = nullptr;
	};
}