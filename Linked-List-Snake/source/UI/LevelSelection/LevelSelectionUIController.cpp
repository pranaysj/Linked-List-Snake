#include"../header/Global/Config.h"
#include"../header/Global/ServiceLocator.h"
#include "../header/UI/LevelSelection/LevelSelectionUIController.h"
#include "../header/Main/GameService.h"
#include "../header/Sound/SoundService.h"


namespace UI
{
	using namespace Global;
	using namespace Main;
	using namespace Sound;

	namespace LevelSelection
	{
		LevelSelectionUIController::LevelSelectionUIController()
		{
			createImage();
			createButtons();
		}

		LevelSelectionUIController::~LevelSelectionUIController()
		{
			destory();
		}

		void LevelSelectionUIController::destory()
		{
			delete(background_image);
			delete(level_one_button);
			delete(level_two_button);
			delete(menu_button);
		}

		void LevelSelectionUIController::createImage()
		{
			background_image = new ImageView();
		}

		void LevelSelectionUIController::createButtons()
		{
			level_one_button = new ButtonView();
			level_two_button = new ButtonView();
			menu_button = new ButtonView();
		}

		void LevelSelectionUIController::initialize()
		{
			initializeBackgroundImage();
			initializeButtons();
			registerButtonCallback();
		}

		void LevelSelectionUIController::initializeBackgroundImage()
		{
			sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

			background_image->initialize(Config::background_texture_path, game_window->getSize().x, game_window->getSize().y, sf::Vector2f(0, 0));
			background_image->setImageAlpha(background_alpha);
		}

		void LevelSelectionUIController::initializeButtons()
		{
			level_one_button->initialize("Level One Button", Config::level_one_button_texture_path, button_width, button_height, sf::Vector2f(0, level_one_button_y_position));
			level_two_button->initialize("Level Two Button", Config::level_two_button_texture_path, button_width, button_height, sf::Vector2f(0, level_two_button_y_position));
			menu_button->initialize("Manu Button", Config::menu_button_texture_path, button_width, button_height, sf::Vector2f(0, menu_button_y_position));

			level_one_button->setCentreAlinged();
			level_two_button->setCentreAlinged();
			menu_button->setCentreAlinged();
		}

		void LevelSelectionUIController::registerButtonCallback()
		{
			level_one_button->registerCallbackFuntion([this] { singleLinkedListButtonCallback(); });
			level_two_button->registerCallbackFuntion([this] { doubleLinkedListButtonCallback(); });
			menu_button->registerCallbackFuntion([this] { menuButtonCallback(); });
		}

		void LevelSelectionUIController::singleLinkedListButtonCallback()
		{
			GameService::setGameState(GameState::GAMEPLAY);
			ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
			ServiceLocator::getInstance()->getLevelService()->createLevel(Level::LevelNumber::ONE);
		}

		void LevelSelectionUIController::doubleLinkedListButtonCallback()
		{
			GameService::setGameState(GameState::GAMEPLAY);
			ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
			ServiceLocator::getInstance()->getLevelService()->createLevel(Level::LevelNumber::TWO);
		}

		void LevelSelectionUIController::menuButtonCallback()
		{
			GameService::setGameState(GameState::MAIN_MENU);
			ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
		}

		void LevelSelectionUIController::update()
		{
			background_image->update();
			level_one_button->update();
			level_two_button->update();
			menu_button->update();
		}

		void LevelSelectionUIController::render()
		{
			background_image->render();
			level_one_button->render();
			level_two_button->render();
			menu_button->render();
		}

		void LevelSelectionUIController::show()
		{
			background_image->show();
			level_one_button->show();
			level_two_button->show();
			menu_button->show();
		}
	}
}
