#include "../header/Player/SnakeController.h"
#include "../header/Global/ServiceLocator.h"
#include "../header/Event/EventService.h"

namespace Player
{
	using namespace Global;
	using namespace Event;

	SnakeController::SnakeController()
	{
		single_linked_list = nullptr;

		createLinkedList();
	}

	SnakeController::~SnakeController()
	{
		destroy();
	}

	void SnakeController::createLinkedList()
	{
		single_linked_list = new SingleLinkedList;
	}

	void SnakeController::initialize()
	{
		float width = ServiceLocator::getInstance()->getLevelService()->getCellWidth();
		float height = ServiceLocator::getInstance()->getLevelService()->getCellHeight();

		single_linked_list->initialize(width, height, default_position, default_direction);
	}

	void SnakeController::spawnSnake()
	{
		for (int i = 0; i < initial_snake_length; i++)
		{
			single_linked_list->insertNodeAtTail();
		}
	}

	void SnakeController::respawnSnake()
	{
	}

	void SnakeController::setSnakeState(SnakeState state)
	{
		current_snake_state = state;
	}

	SnakeState SnakeController::getSnakeState()
	{
		return current_snake_state;
	}

	void SnakeController::processPlayerInput()
	{
		EventService *event = ServiceLocator::getInstance()->getEventService();

		if (event->pressedUpArrowKey() && current_snake_dircetion != Direction::DOWN)
		{
			current_snake_dircetion = Direction::UP;
		}
		else if (event->pressedDownArrowKey() && current_snake_dircetion != Direction::UP)
		{
			current_snake_dircetion = Direction::DOWN;
		}
		else if (event->pressedRightArrowKey() && current_snake_dircetion != Direction::LEFT)
		{
			current_snake_dircetion = Direction::RIGHT;
		}
		else if (event->pressedLeftArrowKey() && current_snake_dircetion != Direction::RIGHT)
		{
			current_snake_dircetion = Direction::LEFT;
		}
	}

	void SnakeController::updateSnakeDirection()
	{
	}

	void SnakeController::moveSnake()
	{
	}

	void SnakeController::processSnakeCollision()
	{
	}

	void SnakeController::handleRestart()
	{
	}

	void SnakeController::reset()
	{
	}

	void SnakeController::destroy()
	{
		delete (single_linked_list);
	}

	void SnakeControlller::updateNodeDirection(Direction direction_to_set)
	{
		Node *cur_node = head_node;

		while (cur_node->next != nullptr)
		{
			Dircetion previous_direction = cur_node->bodypart.getDirection();
			cur_node->bodypart.setDirection(dircetion_to_set);
			direction_to_set = previous_direction;
			cur_node = cur_node->next;
		}
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

	void SnakeController::update()
	{
		switch (current_snake_state)
		{
		case SnakeState::ALIVE:
			processPlayerInput();
			updateSnakeDirection();
			processSnakeCollision();
			moveSnake();
			break;

		case SnakeState::DEAD:
			handleRestart();
			break;
		}
	}

	void SnakeController::render()
	{
		single_linked_list->render();
	}
}