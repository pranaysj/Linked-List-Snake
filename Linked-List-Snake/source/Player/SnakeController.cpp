#include "../header/Player/SnakeController.h"
#include "../header/Global/ServiceLocator.h"
#include "../header/Sound/SoundService.h"
#include "../header/Event/EventService.h"
#include "../header/Element/ElementService.h"
#include "../header/Food/FoodService.h"
#include "../header/LinkedListLib/SingleLinked/SingleLinkedList.h"
#include "../header/LinkedListLib/DoubleLinked/DoubleLinkedList.h"
#include "../header/Player/SnakeController.h"

namespace Player
{
	using namespace Global;
	using namespace Event;
	using namespace Sound;
	using namespace Element;
	using namespace Food;
	using namespace LinkedListLib::SingleLinked;
	using namespace LinkedListLib::DoubleLinked;

	SnakeController::SnakeController()
	{

	}

	SnakeController::~SnakeController()
	{
		destroy();
	}

	void SnakeController::createLinkedList(LinkedListType level_type)
	{
		switch (level_type)
		{
		case LinkedListType::SINGLE_LINKED_LIST:
			linked_list = new SingleLinkedList();
			break;
		case LinkedListType::DOUBLE_LINKED_LIST:
			linked_list = new DoubleLinkedList();
			break;
		}

		initializeLinkedList();
	}

	void SnakeController::initializeLinkedList()
	{
		float width = ServiceLocator::getInstance()->getLevelService()->getCellWidth();
		float height = ServiceLocator::getInstance()->getLevelService()->getCellHeight();

		reset();
		linked_list->initialize(width, height, default_position, default_direction);
	}

	void SnakeController::initialize()
	{

	}

	void SnakeController::spawnSnake()
	{
		for (int i = 0; i < initial_snake_length; i++)
		{
			linked_list->insertNodeAtTail();
		}
	}

	void SnakeController::respawnSnake()
	{
		linked_list->removeAllNodes();
		reset();
		spawnSnake();
	}

	void SnakeController::setSnakeState(SnakeState state)
	{
		current_snake_state = state;
	}

	SnakeState SnakeController::getSnakeState()
	{
		return current_snake_state;
	}

	int SnakeController::getPlayerScore()
	{
		return playe_score;
	}

	TimeComplexity SnakeController::getTimeComplexity()
	{
		return time_complexity;
	}

	LinkedListOperations SnakeController::getLastOperation()
	{
		return last_linked_list_operation;
	}

	void SnakeController::processPlayerInput()
	{
		if (current_input_state == InputState::PROCESSING)
		{
			return;
		}

		EventService *event = ServiceLocator::getInstance()->getEventService();

		if (event->pressedUpArrowKey() && current_snake_dircetion != Direction::DOWN)
		{
			current_snake_dircetion = Direction::UP;
			current_input_state = InputState::PROCESSING;
		}
		else if (event->pressedDownArrowKey() && current_snake_dircetion != Direction::UP)
		{
			current_snake_dircetion = Direction::DOWN;
			current_input_state = InputState::PROCESSING;
		}
		else if (event->pressedRightArrowKey() && current_snake_dircetion != Direction::LEFT)
		{
			current_snake_dircetion = Direction::RIGHT;
			current_input_state = InputState::PROCESSING;
		}
		else if (event->pressedLeftArrowKey() && current_snake_dircetion != Direction::RIGHT)
		{
			current_snake_dircetion = Direction::LEFT;
			current_input_state = InputState::PROCESSING;
		}
	}

	void SnakeController::updateSnakeDirection()
	{
		linked_list->updateNodeDirection(current_snake_dircetion);
	}

	void SnakeController::moveSnake()
	{
		linked_list->updateNodePosition();
	}

	void SnakeController::processSnakeCollision()
	{
		processBodyCollision();
		processElementsCollision();
		processFoodCollision();
	}

	void SnakeController::processBodyCollision()
	{
		if (linked_list->processNodeCollision())
		{
			current_snake_state = SnakeState::DEAD;
			ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
		}
	}

	void SnakeController::processElementsCollision()
	{
		ElementService *event_service = ServiceLocator::getInstance()->getElementService();

		if (event_service->processElementsCollision(linked_list->getHeadNode()))
		{
			current_snake_state = SnakeState::DEAD;
			ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
		}
	}

	void SnakeController::processFoodCollision()
	{
		FoodService *food_service = ServiceLocator::getInstance()->getFoodService();
		FoodType foodtype;

		if (food_service->processFoodCollision(linked_list->getHeadNode(), foodtype))
		{
			ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK); // PICKUP

			food_service->destroyFood();
			OnFoodCollected(foodtype);

			playe_score++;
		}
	}

	void SnakeController::OnFoodCollected(Food::FoodType food_type)
	{
		switch (food_type)
		{
		case FoodType::PIZZA:
			// Insert At Tail
			linked_list->insertNodeAtTail();
			time_complexity = TimeComplexity::N;
			last_linked_list_operation = LinkedListOperations::INSERT_AT_TAIL;
			break;

		case FoodType::BURGER:
			// Insert At Head
			linked_list->insertNodeAtHead();
			time_complexity = TimeComplexity::ONE;
			last_linked_list_operation = LinkedListOperations::INSERT_AT_HEAD;
			break;

		case FoodType::CHEESE:
			// Insert in Middle
			linked_list->insertNodeAtMiddle();
			time_complexity = TimeComplexity::N;
			last_linked_list_operation = LinkedListOperations::INSERT_AT_MID;
			break;

		case FoodType::APPLE:
			// Delete at Head
			linked_list->removeNodeAtHead();
			time_complexity = TimeComplexity::ONE;
			last_linked_list_operation = LinkedListOperations::REMOVE_AT_HEAD;
			break;

		case FoodType::MANGO:
			// Delete at Middle
			linked_list->removeNodeAtMiddle();
			time_complexity = TimeComplexity::N;
			last_linked_list_operation = LinkedListOperations::REMOVE_AT_MID;
			break;

		case FoodType::ORANGE:
			// Delete at Tail
			linked_list->removeNodeAtTail();
			time_complexity = TimeComplexity::N;
			last_linked_list_operation = LinkedListOperations::REMOVE_AT_TAIL;
			break;

		case FoodType::POISION:
			// Delete half the snake
			linked_list->removeHalfNodes();
			time_complexity = TimeComplexity::N;
			last_linked_list_operation = LinkedListOperations::DELETE_HALF_LIST;
			break;

		case FoodType::ALCOHOL:
			// Reverse the snake
			current_snake_dircetion = linked_list->reverse();
			time_complexity = TimeComplexity::N;
			last_linked_list_operation = LinkedListOperations::REVERSE_LIST;
			break;
		}
	}
	void SnakeController::reset()
	{
		current_snake_state = SnakeState::ALIVE;
		current_snake_dircetion = Direction::RIGHT;
		elapsed_duration = 0.0f;
		restart_counter = 0.0f;
		current_input_state = InputState::WAITING;
		playe_score = 0;
	}

	void SnakeController::destroy()
	{
		delete (linked_list);
	}

	void SnakeController::delayedUpdate()
	{
		elapsed_duration += ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		if (elapsed_duration >= movement_frame_duration)
		{
			elapsed_duration = 0.0f;
			updateSnakeDirection();
			processSnakeCollision();

			if (current_snake_state != SnakeState::DEAD)
			{
				moveSnake();
			}

			current_input_state = InputState::WAITING;
		}
	}

	std::vector<sf::Vector2i> SnakeController::getCurrentSnakePositionList()
	{
		return linked_list->getNodesPositionList();
	}

	bool SnakeController::isSnakeDead()
	{
		return current_snake_state == SnakeState::DEAD;
	}

	void SnakeController::handleRestart()
	{
		restart_counter += ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		if (restart_counter >= restart_duration)
		{
			respawnSnake();
		}
	}

	void SnakeController::update()
	{
		switch (current_snake_state)
		{
		case SnakeState::ALIVE:
			processPlayerInput();
			delayedUpdate();
			break;

		case SnakeState::DEAD:
			handleRestart();
			break;
		}
	}

	void SnakeController::render()
	{
		linked_list->render();
	}
}