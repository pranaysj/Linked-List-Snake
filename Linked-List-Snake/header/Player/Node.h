#pragma once
#include"../header/Player/BodyPart.h"

namespace Player
{
	struct Node
	{
		BodyPart bodypart;
		Node* node = nullptr;


	};
}